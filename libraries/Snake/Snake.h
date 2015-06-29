
#ifdef ARDUINO
#include <LinkedList.h>
#include <Arduino.h>
#else
#include "../LinkedList/LinkedList.h"
#include <stdio.h>
#endif

#define HEIGHT 20
#define WIDTH 10


typedef struct Segment{
    int col, row;
} Segment;

typedef struct Food {
    int col, row;
} Food;

class Snake{
    private:
        LinkedList<Segment>* SnakeQueue;
        
        //0 is up
        //1 is right
        //2 is left
        //3 is down
        int direction;
        Food food;

        void setNewFood();

    public:
        Snake();
        ~Snake();
        void test();
        
};
