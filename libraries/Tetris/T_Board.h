#ifndef T_BOARD_H
#define T_BOARD_H

#include "T_Shape.h"

#ifdef ARDUINO
#include "Arduino.h"
#else
#include <stdio.h>
#endif

#define WIDTH 10
#define HEIGHT 20

class Board{
    private:
        char** board;
        bool canMoveLeft(Shape* shape);
        bool canMoveRight(Shape* shape);
        bool canMoveDown(Shape* shape);
        bool canRotate(Shape* shape);


    public:
        int getWidth(){
            return WIDTH;
        }
        int getHeight(){
            return HEIGHT;
        }
        Board();
        ~Board();
        
        bool moveLeft(Shape* shape);
        bool moveRight(Shape* shape);
        bool moveDown(Shape* shape);
        bool rotate(Shape* shape);
        bool drop(Shape* shape);
        bool placeInBoard(Shape* shape);

#ifndef ARDUINO
        void printBoardWithShape(Shape* shape);
#endif
};

#endif //T_BOARD_H
