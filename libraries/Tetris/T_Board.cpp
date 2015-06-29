#include "T_Board.h"

Board::Board(){
    board = new char*[WIDTH]();

    for(int i = 0; i < WIDTH; i++){
        board[i] = new char[HEIGHT]();
    }
    board[1][2] = 1;
}

Board::~Board(){
    for(int i = 0; i < WIDTH; i++){
        delete[] board[i];
    }
    delete[] board;
}


bool Board::canMoveLeft(Shape* shape){
    int col = shape->getCol();
    int row = shape->getRow();
    char** arr = shape->getPiece();

    for(int i = 0; i < 4; i++){
        for(int j = 0; j < 4; j++){
            if((arr[j][i] > 1 && i+col <= 0) || (arr[j][i] > 1 && board[i+col-1][j+row] == 1)){
                return false;
            }
        }
    }

    return true;
}

bool Board::canMoveRight(Shape* shape){
    int col = shape->getCol();
    int row = shape->getRow();
    char** arr = shape->getPiece();

    for(int i = 0; i < 4; i++){
        for(int j = 0; j < 4; j++){
            if((arr[j][i] > 1 && i+col >= WIDTH-1) || (arr[j][i] > 1 && board[i+col+1][j+row] == 1)){
                return false;
            }
        }
    }

    return true;
}

bool Board::canMoveDown(Shape* shape){
    int col = shape->getCol();
    int row = shape->getRow();
    char** arr = shape->getPiece();

    for(int i = 0; i < 4; i++){
        for(int j = 0; j < 4; j++){
            if((arr[j][i] > 1 && j+row >= HEIGHT-1) || (arr[j][i] > 1 && board[i+col][j+row+1] == 1)){
                return false;
            }
        }
    }

    return true;
}

bool Board::moveLeft(Shape* shape){
    if(!canMoveLeft(shape)){
        return false;
    }
    shape->moveLeft();
    return true;
}

bool Board::moveRight(Shape* shape){
    if(!canMoveRight(shape)){
        return false;
    }
    shape->moveRight();
    return true;
}

bool Board::moveDown(Shape* shape){
    if(!canMoveDown(shape)){
        return false;
    }
    shape->moveDown();
    return true;
}

bool Board::canRotate(Shape* shape){
    char** arr = shape->getPieceRot();
    int col = shape->getCol();
    int row = shape->getRow();

    for(int i = 0; i < 4; i++){
        for(int j = 0; j < 4; j++){
            //if((arr[j][i] > 1 && (j+row >= HEIGHT-1 || j+row < 0 || i+col >= WIDTH-1 || i+col < 0))){
                //printf("j: %d, i: %d, J+row: %d, i+col: %d\n", j,i,j+row,i+col);
            if((arr[j][i] > 1 && (j+row >= HEIGHT-1 || j+row < 0 || i+col >= WIDTH-1 || i+col < 0)) || ((arr[j][i] > 1 && board[i+col][j+row]))){
                return false;
            }
        }
    }
    return true;
}

bool Board::rotate(Shape* shape){
    if(!canRotate(shape)){
        return false;
    }
    shape->rotate();
    return true;
}

bool Board::drop(Shape* shape){
    while(moveDown(shape)); //just move it all the way down
    return true;
}


#ifndef ARDUINO
void Board::printBoardWithShape(Shape* shape){
    int row = shape->getRow();
    int col = shape->getCol();
    char** arr = shape->getPiece();

    printf("-------------------------------\n");
    for(int i = 0; i < HEIGHT; i++){ //loop through the  board
        int s_i = i - row;
        for(int j = 0; j < WIDTH; j++){
            int s_j = j - col; //get the offsetted values of the shape's i and j in the board
            if(s_i >= 0 && s_i < 4 && s_j >= 0 && s_j < 4){ //check the boundaries
                if(arr[s_i][s_j] > 1){
                    printf("%d ", arr[s_i][s_j]);
                }
                else {
                    printf("%d ", board[j][i]);
                }
            }
            else {
                printf("%d ", board[j][i]);
            }
        }
        printf("\n");
    }
    printf("-------------------------------\n");

}

#endif

