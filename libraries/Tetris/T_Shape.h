#ifndef T_SHAPE_H
#define T_SHAPE_H

#ifdef ARDUINO
#include "Arduino.h"
#else
#include <stdio.h>
#endif

class Shape {
    private:
        /*
         * The 2 fields denote where the piece is in relation to the game board.  
         * pos_row and pos_col denote the bottom left corner of the piece and where that is in the
         * board.  
         */
        int pos_row;
        int pos_col;
        
        
        int shape_type;
        int orient; //0-3 for which way the shape is rotated

        void initPieceRand(); //initializes with a random piece
        void initPieceType(int type); //initializes a specific piece type

        
        char**** layout;
        char*** pieceO;
        char*** pieceI;
        char*** pieceS;
        char*** pieceZ;
        char*** pieceL;
        char*** pieceJ;
        char*** pieceT;
        
        void initShapes();
        void init(int row, int col);

    public:
        Shape(int row, int col);
        Shape(int type, int row, int col);
        ~Shape();
        char** getPiece();
        char** getPieceRot();
        void debugShape();

        int getOrient(){
            return orient;
        }
        int getShapeType(){
            return shape_type;
        }
        int getRow(){
            return pos_row;
        }
        int getCol(){
            return pos_col;
        }
        void moveLeft(){
            pos_col--;
        }
        void moveRight(){
            pos_col++;
        }
        void moveDown(){
            pos_row++;
        }

        void rotate(){
            orient = (orient + 1) % 4;
        }

};

#endif //T_SHAPE_H
