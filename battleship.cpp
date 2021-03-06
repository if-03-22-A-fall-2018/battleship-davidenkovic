/*-----------------------------------------------------------------------------
 *				HTBLA-Leonding / Class: <your class name here>
 *-----------------------------------------------------------------------------
 * Exercise Number: #exercise_number#
 * File:			battleship.c
 * Author(s):		Peter Bauer
 * Due Date:		#due#
 *-----------------------------------------------------------------------------
 * Description:
 * <your description here>
 *-----------------------------------------------------------------------------
*/
#include <stdio.h>
#include <stdlib.h>

#include "battleship.h"

CellContent my[FIELDSIZE][FIELDSIZE];
CellContent op[FIELDSIZE][FIELDSIZE];
CellContent gu[FIELDSIZE][FIELDSIZE];


void load_game(){
  FILE* fd_my = fopen("battleship.my", "r");
  for (int i = 0; i < FIELDSIZE; i++) {
    for (int j = 0; j < FIELDSIZE; j++) {
      fread(&my[i][j],sizeof(CellContent),1,fd_my);
    }
  }
  FILE* fd_op = fopen("battleship.op", "r");
  for (int x = 0; x < FIELDSIZE; x++) {
    for (int y = 0; y < FIELDSIZE; y++) {
      fread(&op[x][y],sizeof(CellContent),1,fd_op);
    }
  }
  for (int a = 0; a < FIELDSIZE; a++) {
    for (int b = 0; b < FIELDSIZE; b++) {
      gu[a][b] = Unknown;
    }
  }
  fclose(fd_op);
  fclose(fd_my);
}

CellContent get_shot(int row, int col){
  if ((row<FIELDSIZE && row>-1 )&& (col<FIELDSIZE && col >-1)) {
    return my[row][col];
  }
  return OutOfRange;
}

bool shoot(int row, int col){
  if ((row<FIELDSIZE && row>-1) && (col<FIELDSIZE && col >-1)) {
    for (int i = -1; i <= 1; ++i) {
      for (int j = -1; j <= 1; ++j) {
       if (row+i>-1 && row+i<FIELDSIZE && col+j>-1&&col+j<FIELDSIZE) {
          gu[row+i][col+j] = op[row+i][col+j];
        }
      }
    }
    return true;
  }
  return false;
}
CellContent get_my_guess(int row, int col){
  if (row<FIELDSIZE && row>-1 && col<FIELDSIZE && col >-1) {
    return gu[row][col];
  }
  return OutOfRange;
}
