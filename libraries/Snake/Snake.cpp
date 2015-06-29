#include "Snake.h"

#ifndef ARDUINO
#include <stdlib.h>
#include <time.h>
#endif

Snake::Snake(){
    SnakeQueue = new LinkedList<Segment>();

    //0 is up
    //1 is right
    //2 is left
    //3 is down
    direction = 3; 

    //Initialize segments
    Segment seg = {WIDTH/2,HEIGHT/2};
    SnakeQueue->add(seg);
    seg = {WIDTH/2,(HEIGHT/2) + 1};
    SnakeQueue->add(seg);
    seg = {WIDTH/2,(HEIGHT/2) + 2};
    SnakeQueue->add(seg);
    setNewFood();
}

void Snake::setNewFood(){
#ifdef ARDUINO
    int col = random(WIDTH);
    int row = random(HEIGHT);
#else
    srand(time(NULL));
    int col = rand() % WIDTH;
    int row = rand() % HEIGHT;
#endif
    Segment seg = {col, row};

    bool conflicts = true;

    //This will only infinite loop when the player has managed to fill up the entire 
    //board with the snake.  In other words, it will never infinite loop
    while(conflicts){
        conflicts = false; //now assume we haven't conflicted
        //cycle through the segments and look to see if it's conflicting
        for(int i = 0; i < SnakeQueue->size(); i++){
            Segment queueSeg = SnakeQueue->get(i);
            if(seg.col == queueSeg.col && seg.row == queueSeg.col){ //conflicts
                conflicts = true;
                break;
            }
        }
    }
}

Snake::~Snake(){
    delete SnakeQueue;
}

void Snake::test(){
    Segment seg = {0,0};
    SnakeQueue->add(seg);
    seg = {0,1};
    SnakeQueue->add(seg);

    seg = SnakeQueue->peek();
    printf("Seg: %d, %d\n", seg.col, seg.row);
    seg = SnakeQueue->pop();
    printf("Seg: %d, %d\n", seg.col, seg.row);
}
