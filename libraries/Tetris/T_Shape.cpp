#include "T_Shape.h"

#ifndef ARDUINO
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#endif


Shape::Shape(int row, int col) {
    init(row, col);
    initPieceRand();
}

Shape::Shape(int type, int row, int col) {
    init(row, col);
    initPieceType(type);
}

Shape::~Shape(){
    for(int i = 0; i < 7; i++){
        for(int j = 0; j < 4; j++){
            for(int k = 0; k < 4; k++){
                delete[] layout[i][j][k];
            }
            delete[] layout[i][j];
        }
        delete[] layout[i];
    }
    delete[] layout;
}

void Shape::init(int row, int col) {
    pos_row = row;
    pos_col = col;
    shape_type = 0;
    orient = 0;

    initShapes();
}

void Shape::initPieceRand() {
#ifdef ARDUINO
    int r = random(7);
#else
    srand(time(NULL));
    int r = rand() % 7;
#endif
    initPieceType(r);
}

void Shape::initPieceType(int type) {
#ifdef ARDUINO
    int r = random(4);
#else
    srand(time(NULL));
    int r = rand() % 4;
#endif
    orient = r; //random orient
    shape_type = type;

}


char** Shape::getPiece() {
    return layout[shape_type][orient];
}

char** Shape::getPieceRot(){
    int rotOrient = (orient + 1) % 4;
    return layout[shape_type][rotOrient];
}



void Shape::initShapes() {
    layout = new char***[7];

    pieceO = new char**[4];
    pieceO[0] = new char*[4];
    pieceO[1] = new char*[4];
    pieceO[2] = new char*[4];
    pieceO[3] = new char*[4];

    pieceO[0][0] = new char[4] {0, 0, 0, 0};
    pieceO[0][1] = new char[4] {0, 2, 2, 0};
    pieceO[0][2] = new char[4] {0, 2, 2, 0};
    pieceO[0][3] = new char[4] {0, 0, 0, 0};

    pieceO[1][0] = new char[4] {0, 0, 0, 0};
    pieceO[1][1] = new char[4] {0, 2, 2, 0};
    pieceO[1][2] = new char[4] {0, 2, 2, 0};
    pieceO[1][3] = new char[4] {0, 0, 0, 0};

    pieceO[2][0] = new char[4] {0, 0, 0, 0};
    pieceO[2][1] = new char[4] {0, 2, 2, 0};
    pieceO[2][2] = new char[4] {0, 2, 2, 0};
    pieceO[2][3] = new char[4] {0, 0, 0, 0};

    pieceO[3][0] = new char[4] {0, 0, 0, 0};
    pieceO[3][1] = new char[4] {0, 2, 2, 0};
    pieceO[3][2] = new char[4] {0, 2, 2, 0};
    pieceO[3][3] = new char[4] {0, 0, 0, 0};


    pieceI = new char**[4];
    pieceI[0] = new char*[4];
    pieceI[1] = new char*[4];
    pieceI[2] = new char*[4];
    pieceI[3] = new char*[4];

    pieceI[0][0] = new char[4] {0, 0, 0, 0};
    pieceI[0][1] = new char[4] {3, 3, 3, 3};
    pieceI[0][2] = new char[4] {0, 0, 0, 0};
    pieceI[0][3] = new char[4] {0, 0, 0, 0};

    pieceI[1][0] = new char[4] {0, 0, 3, 0};
    pieceI[1][1] = new char[4] {0, 0, 3, 0};
    pieceI[1][2] = new char[4] {0, 0, 3, 0};
    pieceI[1][3] = new char[4] {0, 0, 3, 0};

    pieceI[2][0] = new char[4] {0, 0, 0, 0};
    pieceI[2][1] = new char[4] {3, 3, 3, 3};
    pieceI[2][2] = new char[4] {0, 0, 0, 0};
    pieceI[2][3] = new char[4] {0, 0, 0, 0};

    pieceI[3][0] = new char[4] {0, 0, 3, 0};
    pieceI[3][1] = new char[4] {0, 0, 3, 0};
    pieceI[3][2] = new char[4] {0, 0, 3, 0};
    pieceI[3][3] = new char[4] {0, 0, 3, 0};


    pieceS = new char**[4];
    pieceS[0] = new char*[4];
    pieceS[1] = new char*[4];
    pieceS[2] = new char*[4];
    pieceS[3] = new char*[4];

    pieceS[0][0] = new char[4] {0, 0, 0, 0};
    pieceS[0][1] = new char[4] {0, 0, 4, 4};
    pieceS[0][2] = new char[4] {0, 4, 4, 0};
    pieceS[0][3] = new char[4] {0, 0, 0, 0};

    pieceS[1][0] = new char[4] {0, 0, 4, 0};
    pieceS[1][1] = new char[4] {0, 0, 4, 4};
    pieceS[1][2] = new char[4] {0, 0, 0, 4};
    pieceS[1][3] = new char[4] {0, 0, 0, 0};

    pieceS[2][0] = new char[4] {0, 0, 0, 0};
    pieceS[2][1] = new char[4] {0, 0, 4, 4};
    pieceS[2][2] = new char[4] {0, 4, 4, 0};
    pieceS[2][3] = new char[4] {0, 0, 0, 0};

    pieceS[3][0] = new char[4] {0, 0, 4, 0};
    pieceS[3][1] = new char[4] {0, 0, 4, 4};
    pieceS[3][2] = new char[4] {0, 0, 0, 4};
    pieceS[3][3] = new char[4] {0, 0, 0, 0};

    pieceZ = new char**[4];
    pieceZ[0] = new char*[4];
    pieceZ[1] = new char*[4];
    pieceZ[2] = new char*[4];
    pieceZ[3] = new char*[4];

    pieceZ[0][0] = new char[4] {0, 0, 0, 0};
    pieceZ[0][1] = new char[4] {0, 5, 5, 0};
    pieceZ[0][2] = new char[4] {0, 0, 5, 5};
    pieceZ[0][3] = new char[4] {0, 0, 0, 0};

    pieceZ[1][0] = new char[4] {0, 0, 0, 5};
    pieceZ[1][1] = new char[4] {0, 0, 5, 5};
    pieceZ[1][2] = new char[4] {0, 0, 5, 0};
    pieceZ[1][3] = new char[4] {0, 0, 0, 0};

    pieceZ[2][0] = new char[4] {0, 0, 0, 0};
    pieceZ[2][1] = new char[4] {0, 5, 5, 0};
    pieceZ[2][2] = new char[4] {0, 0, 5, 5};
    pieceZ[2][3] = new char[4] {0, 0, 0, 0};

    pieceZ[3][0] = new char[4] {0, 0, 0, 5};
    pieceZ[3][1] = new char[4] {0, 0, 5, 5};
    pieceZ[3][2] = new char[4] {0, 0, 5, 0};
    pieceZ[3][3] = new char[4] {0, 0, 0, 0};


    pieceL = new char**[4];
    pieceL[0] = new char*[4];
    pieceL[1] = new char*[4];
    pieceL[2] = new char*[4];
    pieceL[3] = new char*[4];

    pieceL[0][0] = new char[4] {0, 0, 0, 0};
    pieceL[0][1] = new char[4] {0, 6, 6, 6};
    pieceL[0][2] = new char[4] {0, 6, 0, 0};
    pieceL[0][3] = new char[4] {0, 0, 0, 0};

    pieceL[1][0] = new char[4] {0, 0, 6, 0};
    pieceL[1][1] = new char[4] {0, 0, 6, 0};
    pieceL[1][2] = new char[4] {0, 0, 6, 6};
    pieceL[1][3] = new char[4] {0, 0, 0, 0};

    pieceL[2][0] = new char[4] {0, 0, 0, 6};
    pieceL[2][1] = new char[4] {0, 6, 6, 6};
    pieceL[2][2] = new char[4] {0, 0, 0, 0};
    pieceL[2][3] = new char[4] {0, 0, 0, 0};

    pieceL[3][0] = new char[4] {0, 6, 6, 0};
    pieceL[3][1] = new char[4] {0, 0, 6, 0};
    pieceL[3][2] = new char[4] {0, 0, 6, 0};
    pieceL[3][3] = new char[4] {0, 0, 0, 0};


    pieceJ = new char**[4];
    pieceJ[0] = new char*[4];
    pieceJ[1] = new char*[4];
    pieceJ[2] = new char*[4];
    pieceJ[3] = new char*[4];

    pieceJ[0][0] = new char[4] {0, 0, 0, 0};
    pieceJ[0][1] = new char[4] {0, 7, 7, 7};
    pieceJ[0][2] = new char[4] {0, 0, 0, 7};
    pieceJ[0][3] = new char[4] {0, 0, 0, 0};

    pieceJ[1][0] = new char[4] {0, 0, 7, 7};
    pieceJ[1][1] = new char[4] {0, 0, 7, 0};
    pieceJ[1][2] = new char[4] {0, 0, 7, 0};
    pieceJ[1][3] = new char[4] {0, 0, 0, 0};

    pieceJ[2][0] = new char[4] {0, 7, 0, 0};
    pieceJ[2][1] = new char[4] {0, 7, 7, 7};
    pieceJ[2][2] = new char[4] {0, 0, 0, 0};
    pieceJ[2][3] = new char[4] {0, 0, 0, 0};

    pieceJ[3][0] = new char[4] {0, 0, 7, 0};
    pieceJ[3][1] = new char[4] {0, 0, 7, 0};
    pieceJ[3][2] = new char[4] {0, 7, 7, 0};
    pieceJ[3][3] = new char[4] {0, 0, 0, 0};

    pieceT = new char**[4];
    pieceT[0] = new char*[4];
    pieceT[1] = new char*[4];
    pieceT[2] = new char*[4];
    pieceT[3] = new char*[4];

    pieceT[0][0] = new char[4] {0, 0, 0, 0};
    pieceT[0][1] = new char[4] {0, 8, 8, 8};
    pieceT[0][2] = new char[4] {0, 0, 8, 0};
    pieceT[0][3] = new char[4] {0, 0, 0, 0};

    pieceT[1][0] = new char[4] {0, 0, 8, 0};
    pieceT[1][1] = new char[4] {0, 0, 8, 8};
    pieceT[1][2] = new char[4] {0, 0, 8, 0};
    pieceT[1][3] = new char[4] {0, 0, 0, 0};

    pieceT[2][0] = new char[4] {0, 0, 8, 0};
    pieceT[2][1] = new char[4] {0, 8, 8, 8};
    pieceT[2][2] = new char[4] {0, 0, 0, 0};
    pieceT[2][3] = new char[4] {0, 0, 0, 0};

    pieceT[3][0] = new char[4] {0, 0, 8, 0};
    pieceT[3][1] = new char[4] {0, 8, 8, 0};
    pieceT[3][2] = new char[4] {0, 0, 8, 0};
    pieceT[3][3] = new char[4] {0, 0, 0, 0};

    layout[0] = pieceO;
    layout[1] = pieceI;
    layout[2] = pieceS;
    layout[3] = pieceZ;
    layout[4] = pieceL;
    layout[5] = pieceJ;
    layout[6] = pieceT;
}


void Shape::debugShape() {
#ifdef ARDUINO
    Serial.println("---------");
    for (int i = 0; i < 4; i++) {
        Serial.print(" ");
        for (int j = 0; j < 4; j++) {
            Serial.print(layout[shape_type][orient][i][j]);
        }
        Serial.println("");
    }
    Serial.println("---------");
#else
    printf("---------\n");
    for (int i = 0; i < 4; i++) {
        printf(" ");
        for (int j = 0; j < 4; j++) {
            printf("%d", layout[shape_type][orient][i][j]);
        }
        printf("\n");
    }
    printf("---------\n");
#endif
}


