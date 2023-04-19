/*
    Equipe:Ana Paula, Diovana, Luiz Guilherme.
    Projeto: Sudoku.
*/
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include <time.h>
#define SUBMATRIZ 3
#define MATRIZ SUBMATRIZ*SUBMATRIZ
#include <cstdlib>
#include <iostream>
#include <windows.h>

enum DOS_COLORS {
        BLACK, BLUE, GREEN, CYAN, RED, MAGENTA, BROWN,
        LIGHT_GRAY, DARK_GRAY, LIGHT_BLUE, LIGHT_GREEN, LIGHT_CYAN,
        LIGHT_RED, LIGHT_MAGENTA, YELLOW, WHITE };


void textcolor (DOS_COLORS iColor)
{
        HANDLE hl = GetStdHandle(STD_OUTPUT_HANDLE);
        CONSOLE_SCREEN_BUFFER_INFO bufferInfo;
        BOOL b = GetConsoleScreenBufferInfo(hl, &bufferInfo);
        bufferInfo.wAttributes &= 0x00F0;
        SetConsoleTextAttribute (hl, bufferInfo.wAttributes |= iColor);
}


int mat1[MATRIZ][MATRIZ]=
  {{ 4, 7, 5, 3, 9, 1, 6, 2, 8},
   { 8, 2, 3, 5, 4, 6, 7, 9, 1},
   { 1, 6, 9, 8, 7, 2, 3, 5, 4},
   { 5, 1, 8, 4, 6, 3, 2, 7, 9},
   { 3, 4, 6, 7, 2, 9, 1, 8, 5},
   { 7, 9, 2, 1, 5, 8, 4, 3, 6},
   { 2, 5, 1, 6, 8, 7, 9, 4, 3},
   { 6, 8, 7, 9, 3, 4, 5, 1, 2},
   { 9, 3, 4, 2, 1, 5, 8, 6, 7}};
int mat2[MATRIZ][MATRIZ]=
  {{ 6, 5, 2, 1, 4, 3, 7, 8, 9},
   { 9, 1, 4, 6, 8, 7, 5, 2, 3},
   { 8, 7, 3, 5, 2, 9, 6, 1, 4},
   { 3, 6, 1, 2, 9, 4, 8, 7, 5},
   { 2, 9, 8, 7, 5, 6, 3, 4, 1},
   { 7, 4, 5, 3, 1, 8, 2, 9, 6},
   { 5, 2, 9, 8, 3, 1, 4, 6, 7},
   { 4, 3, 7, 9, 6, 2, 1, 5, 8},
   { 1, 8, 6, 4, 7, 5, 9, 3, 2}};
int mat3[MATRIZ][MATRIZ]=
{{ 1, 9, 4, 2, 8, 7, 3, 5, 6},
   { 6, 2, 8, 5, 3, 4, 9, 1, 7},
   { 3, 5, 7, 1, 9, 6, 8, 2, 4},
   { 9, 6, 1, 7, 4, 3, 2, 8, 5},
   { 4, 7, 2, 8, 5, 1, 6, 3, 9},
   { 5, 8, 3, 6, 2, 9, 4, 7, 1},
   { 2, 3, 6, 9, 7, 5, 1, 4, 8},
   { 7, 4, 9, 3, 1, 8, 5, 6, 2},
   { 8, 1, 5, 4, 6, 2, 7, 9, 3}};
int mat4[MATRIZ][MATRIZ]=
{{ 3, 8, 5, 6, 9, 7, 4, 1, 2},
   { 1, 9, 2, 3, 4, 5, 8, 7, 6},
   { 6, 7, 4, 8, 2, 1, 9, 5, 3},
   { 2, 4, 3, 5, 7, 8, 1, 6, 9},
   { 9, 6, 7, 4, 1, 2, 5, 3, 8},
   { 8, 5, 1, 9, 6, 3, 7, 2, 4},
   { 7, 1, 8, 2, 3, 9, 6, 4, 5},
   { 4, 3, 9, 1, 5, 6, 2, 8, 7},
   { 5, 2, 6, 7, 8, 4, 3, 9, 1}};

int mat5[MATRIZ][MATRIZ]=
 {{ 5, 7, 1, 3, 4, 8, 2, 9, 6},
   { 9, 8, 2, 5, 6, 7, 3, 1, 4},
   { 3, 4, 6, 9, 2, 1, 5, 7, 8},
   { 4, 2, 5, 7, 3, 9, 8, 6, 1},
   { 7, 3, 8, 6, 1, 4, 9, 5, 2},
   { 6, 1, 9, 2, 8, 5, 4, 3, 7},
   { 2, 5, 4, 1, 9, 6, 7, 8, 3},
   { 1, 9, 3, 8, 7, 2, 6, 4, 5},
   { 8, 6, 7, 4, 5, 3, 1, 2, 9}};
int mat6[MATRIZ][MATRIZ]=
 {{ 9, 6, 7, 2, 8, 5, 4, 3, 1},
   { 5, 2, 4, 3, 1, 9, 8, 7, 6},
   { 3, 8, 1, 4, 6, 7, 5, 2, 9},
   { 7, 4, 8, 5, 2, 1, 6, 9, 3},
   { 1, 3, 6, 9, 4, 8, 2, 5, 7},
   { 2, 9, 5, 7, 3, 6, 1, 4, 8},
   { 8, 7, 9, 1, 5, 4, 3, 6, 2},
   { 4, 1, 3, 6, 7, 2, 9, 8, 5},
   { 6, 5, 2, 8, 9, 3, 7, 1, 4}};
int mat7[MATRIZ][MATRIZ]=
 {{ 9, 2, 4, 5, 8, 6, 7, 1, 3},
   { 1, 7, 8, 2, 3, 4, 6, 5, 9},
   { 5, 6, 3, 7, 1, 9, 4, 2, 8},
   { 8, 5, 6, 9, 7, 1, 3, 4, 2},
   { 7, 3, 2, 4, 5, 8, 9, 6, 1},
   { 4, 1, 9, 6, 2, 3, 8, 7, 5},
   { 3, 9, 7, 1, 6, 5, 2, 8, 4},
   { 6, 8, 5, 3, 4, 2, 1, 9, 7},
   { 2, 4, 1, 8, 9, 7, 5, 6, 6}};
int mat8[MATRIZ][MATRIZ]=
{{ 4, 1, 8, 6, 9, 7, 5, 3, 2},
   { 7, 6, 3, 2, 5, 1, 9, 8, 4},
   { 9, 5, 2, 3, 8, 4, 6, 1, 7},
   { 8, 2, 5, 9, 4, 6, 3, 7, 1},
   { 1, 3, 9, 7, 2, 8, 4, 5, 6},
   { 6, 4, 7, 1, 3, 5, 8, 2, 9},
   { 3, 7, 4, 5, 1, 9, 2, 6, 8},
   { 5, 9, 1, 8, 6, 2, 7, 4, 3},
   { 2, 8, 6, 4, 7, 3, 1, 9, 5}};
int mat9[MATRIZ][MATRIZ]=
  {{ 2, 8, 6, 3, 5, 4, 7, 1, 9},
   { 4, 7, 1, 9, 2, 8, 3, 6, 5},
   { 3, 9, 5, 1, 7, 6, 4, 2, 8},
   { 6, 4, 7, 8, 1, 3, 9, 5, 2},
   { 9, 2, 3, 5, 6, 7, 8, 4, 1},
   { 5, 1, 8, 4, 9, 2, 6, 7, 3},
   { 7, 3, 2, 6, 8, 5, 1, 9, 4},
   { 8, 6, 9, 2, 4, 1, 5, 3, 7},
   { 1, 5, 4, 7, 3, 9, 2, 8, 6}};
int mat10[MATRIZ][MATRIZ]=
{{ 5, 8, 3, 7, 9, 1, 6, 2, 4},
   { 6, 7, 4, 3, 2, 5, 9, 8, 1},
   { 9, 2, 1, 4, 8, 6, 3, 7, 5},
   { 8, 4, 6, 5, 1, 9, 7, 3, 2},
   { 3, 5, 2, 8, 6, 7, 1, 4, 9},
   { 7, 1, 9, 2, 3, 4, 8, 5, 6},
   { 4, 6, 8, 9, 5, 3, 2, 1, 7},
   { 1, 3, 5, 6, 7, 2, 4, 9, 8},
   { 2, 9, 7, 1, 4, 8, 5, 6, 3}};
int mat11[MATRIZ][MATRIZ]=
 {{ 9, 8, 5, 1, 3, 2, 4, 7, 6},
   { 3, 6, 2, 4, 7, 9, 1, 5, 8},
   { 4, 7, 1, 5, 8, 6, 2, 9, 3},
   { 2, 1, 3, 7, 4, 5, 8, 6, 9},
   { 7, 5, 6, 9, 2, 8, 3, 1, 4},
   { 8, 9, 4, 6, 1, 3, 7, 2, 5},
   { 6, 2, 8, 3, 9, 1, 5, 4, 7},
   { 5, 3, 7, 2, 6, 4, 9, 8, 1},
   { 1, 4, 9, 8, 5, 7, 6, 3, 3}};
int mat12[MATRIZ][MATRIZ]=
{{ 6, 5, 4, 1, 9, 7, 2, 3, 8},
   { 7, 3, 8, 6, 4, 2, 1, 9, 5},
   { 1, 2, 9, 3, 5, 8, 7, 6, 4},
   { 9, 8, 5, 2, 7, 6, 4, 1, 3},
   { 2, 6, 1, 4, 3, 9, 8, 5, 7},
   { 3, 4, 7, 5, 8, 1, 9, 2, 6},
   { 4, 7, 2, 9, 6, 3, 5, 5, 1},
   { 5, 9, 6, 8, 1, 4, 3, 7, 2},
   { 8, 1, 3, 7, 2, 5, 6, 4, 9}};
int mat13[MATRIZ][MATRIZ]=
{{ 8, 7, 9, 1, 3, 6, 4, 2, 5},
   { 3, 4, 5, 8, 2, 7, 9, 1, 6},
   { 6, 2, 1, 5, 4, 9, 8, 7, 3},
   { 9, 1, 2, 4, 7, 5, 6, 3, 8},
   { 5, 6, 8, 3, 1, 2, 7, 9, 4},
   { 7, 3, 4, 9, 6, 8, 2, 5, 1},
   { 1, 9, 6, 2, 5, 4, 3, 8, 7},
   { 4, 8, 3, 7, 9, 1, 5, 6, 2},
   { 2, 5, 7, 6, 8, 3, 1, 4, 9}};
int mat14[MATRIZ][MATRIZ]=
 {{ 2, 1, 9, 5, 7, 4, 6, 8, 3},
   { 5, 4, 6, 8, 3, 9, 2, 1, 7},
   { 7, 8, 3, 2, 1, 6, 4, 5, 9},
   { 6, 9, 7, 4, 5, 8, 3, 2, 1},
   { 1, 5, 8, 3, 6, 2, 7, 9, 4},
   { 3, 2, 4, 7, 9, 1, 8, 6, 5},
   { 4, 6, 5, 1, 8, 7, 9, 3, 2},
   { 9, 3, 2, 6, 4, 5, 1, 7, 8},
   { 8, 7, 1, 9, 2, 3, 5, 4, 6}};
int mat15[MATRIZ][MATRIZ]=
{{ 7, 2, 6, 5, 4, 1, 9, 3, 8},
   { 1, 9, 5, 2, 3, 8, 6, 7, 4},
   { 8, 4, 3, 9, 7, 6, 1, 5, 2},
   { 9, 5, 7, 1, 8, 3, 4, 2, 6},
   { 4, 3, 1, 6, 2, 5, 8, 9, 7},
   { 6, 8, 2, 7, 9, 4, 3, 1, 5},
   { 2, 1, 4, 3, 6, 7, 5, 8, 9},
   { 3, 6, 9, 8, 5, 2, 7, 4, 1},
   { 5, 7, 8, 4, 1, 9, 2, 6, 3}};
int mat16[MATRIZ][MATRIZ]=
{{ 5, 2, 7, 8, 4, 1, 6, 9, 3},
   { 9, 1, 8, 6, 5, 3, 7, 2, 4},
   { 6, 4, 3, 9, 7, 3, 1, 5, 8},
   { 8, 3, 2, 4, 6, 5, 9, 7, 1},
   { 4, 5, 6, 7, 1, 9, 3, 8, 2},
   { 7, 9, 1, 2, 3, 8, 5, 4, 6},
   { 1, 8, 4, 5, 9, 6, 2, 3, 7},
   { 2, 6, 5, 3, 8, 7, 4, 1, 9},
   { 3, 7, 9, 1, 2, 4, 8, 6, 5}};
int mat17[MATRIZ][MATRIZ]=
{{ 4, 7, 2, 9, 6, 3, 8, 5, 1},
   { 9, 3, 8, 7, 1, 5, 4, 2, 6},
   { 1, 6, 5, 8, 2, 4, 3, 7, 9},
   { 5, 8, 6, 2, 3, 9, 1, 4, 7},
   { 2, 9, 4, 1, 8, 7, 6, 3, 5},
   { 3, 1, 7, 5, 4, 6, 2, 9, 8},
   { 6, 5, 3, 4, 9, 8, 7, 1, 2},
   { 7, 4, 1, 6, 5, 2, 9, 8, 3},
   { 8, 2, 9, 3, 7, 1, 5, 6, 4}};
int mat18[MATRIZ][MATRIZ]=
 {{ 9, 1, 6, 3, 5, 4, 7, 8, 2},
   { 2, 7, 4, 6, 8, 9, 5, 1, 3},
   { 3, 8, 5, 2, 1, 7, 6, 9, 4},
   { 5, 9, 7, 1, 4, 3, 2, 6, 8},
   { 6, 4, 8, 7, 2, 5, 9, 3, 1},
   { 1, 2, 3, 9, 6, 8, 4, 5, 7},
   { 4, 5, 1, 8, 9, 2, 3, 7, 6},
   { 7, 6, 2, 5, 3, 1, 8, 4, 9},
   { 8, 3, 9, 4, 7, 6, 1, 2, 5}};
int mat19[MATRIZ][MATRIZ]=
{{ 5, 4, 9, 7, 3, 1, 2, 8, 6},
   { 1, 3, 8, 6, 2, 4, 7, 5, 9},
   { 6, 2, 7, 8, 5, 9, 3, 4, 1},
   { 7, 9, 1, 2, 6, 9, 4, 3, 5},
   { 4, 8, 5, 3, 1, 7, 6, 9, 2},
   { 3, 6, 2, 9, 4, 5, 1, 7, 8},
   { 8, 5, 6, 1, 7, 3, 9, 2, 4},
   { 2, 7, 4, 5, 9, 6, 8, 1, 3},
   { 9, 1, 3, 4, 8, 2, 5, 6, 7}};
int mat20[MATRIZ][MATRIZ]=
{{ 2, 5, 7, 9, 6, 8, 1, 4, 3},
   { 8, 1, 9, 7, 4, 3, 2, 6, 5},
   { 4, 3, 6, 5, 2, 1, 7, 9, 8},
   { 9, 6, 1, 3, 5, 4, 8, 7, 2},
   { 5, 8, 2, 1, 7, 6, 4, 3, 9},
   { 3, 7, 4, 8, 9, 2, 6, 5, 1},
   { 6, 4, 3, 2, 1, 9, 5, 8, 7},
   { 1, 9, 5, 6, 8, 7, 3, 2, 4},
   { 7, 2, 8, 4, 3, 5, 9, 1, 6}};
int mat21[MATRIZ][MATRIZ]=
{{ 1, 8, 7, 6, 9, 2, 5, 4, 3},
   { 6, 2, 5, 4, 3, 1, 9, 8, 7},
   { 4, 3, 9, 5, 8, 7, 1, 2, 6},
   { 8, 4, 1, 3, 5, 6, 2, 7, 9},
   { 7, 6, 3, 8, 2, 9, 4, 5, 1},
   { 5, 9, 2, 7, 1, 4, 3, 6, 8},
   { 3, 1, 6, 2, 4, 8, 7, 9, 5},
   { 2, 5, 8, 9, 7, 3, 6, 1, 4},
   { 9, 7, 4, 1, 6, 5, 8, 3, 2}};
int mat22[MATRIZ][MATRIZ]=
{{ 8, 7, 2, 6, 9, 1, 4, 2, 5},
   { 5, 1, 4, 2, 8, 7, 9, 6, 3},
   { 9, 2, 6, 5, 3, 4, 8, 7, 1},
   { 3, 4, 5, 1, 6, 8, 7, 9, 2},
   { 6, 8, 7, 9, 5, 2, 3, 1, 4},
   { 2, 9, 1, 7, 4, 3, 6, 5, 8},
   { 7, 5, 8, 3, 2, 6, 1, 4, 9},
   { 4, 6, 2, 8, 1, 9, 5, 3, 7},
   { 1, 3, 9, 4, 7, 5, 2, 8, 6}};
int mat23[MATRIZ][MATRIZ]=
{{ 7, 6, 8, 4, 2, 3, 9, 5, 1},
   { 1, 4, 3, 8, 9, 5, 7, 6, 2},
   { 2, 5, 9, 1, 6, 7, 3, 8, 4},
   { 6, 8, 5, 2, 7, 9, 1, 4, 3},
   { 9, 3, 7, 5, 1, 4, 8, 2, 6},
   { 4, 1, 2, 3, 8, 6, 5, 7, 9},
   { 8, 2, 4, 7, 3, 1, 6, 9, 5},
   { 3, 7, 6, 9, 5, 2, 4, 1, 8},
   { 5, 9, 1, 6, 4, 8, 2, 3, 7}};
int mat24[MATRIZ][MATRIZ]=
 {{ 5, 9, 4, 8, 1, 2, 7, 3, 6},
   { 1, 2, 7, 4, 3, 6, 9, 5, 8},
   { 8, 6, 3, 9, 7, 5, 1, 4, 2},
   { 7, 5, 8, 3, 2, 9, 4, 6, 1},
   { 6, 1, 9, 7, 5, 4, 2, 8, 3},
   { 4, 3, 2, 6, 8, 1, 5, 7, 9},
   { 9, 4, 5, 2, 6, 3, 8, 1, 7},
   { 3, 8, 1, 5, 9, 7, 6, 2, 4},
   { 2, 7, 6, 1, 4, 8, 3, 9, 5}};
int mat25[MATRIZ][MATRIZ]=
{{ 4, 1, 3, 5, 8, 2, 9, 7, 6},
   { 6, 8, 7, 9, 4, 1, 2, 3, 5},
   { 2, 9, 5, 6, 3, 7, 8, 1, 4},
   { 5, 3, 6, 2, 9, 4, 1, 8, 7},
   { 8, 2 ,1, 3, 7, 6, 4, 5, 9},
   { 7, 4, 9, 1, 5, 8, 6, 2, 3},
   { 9, 7, 4, 8, 1, 3, 5, 6, 2},
   { 1, 5, 2, 7, 6, 9, 3, 4, 8},
   { 3, 6, 8, 4, 2, 5, 7, 9, 1}};
int mat26[MATRIZ][MATRIZ]=
{{ 9, 1, 4, 8, 2, 6, 5, 7, 3},
   { 6, 7, 2, 1, 3, 5, 9, 8, 4},
   { 3, 8, 5, 9, 4, 7, 2, 1, 6},
   { 1, 4, 3, 2, 8, 9, 6, 5, 7},
   { 8, 6, 7, 3, 5, 4, 1, 9, 2},
   { 5, 2, 9, 7, 6, 1, 3, 4, 8},
   { 7, 9, 8, 6, 1, 3, 4, 2, 5},
   { 4, 3, 1, 5, 7, 2, 8, 6, 9},
   { 2, 5, 6, 4, 9, 8, 7, 3, 1}};
int mat27[MATRIZ][MATRIZ]=
{{ 2, 3, 4, 7, 1, 5, 6, 8, 9},
   { 9, 7, 8, 6, 2, 4, 5, 1, 3},
   { 6, 1, 5, 3, 8, 9, 4, 7, 2},
   { 1, 6, 9, 5, 3, 2, 8, 4, 7},
   { 5, 2, 3, 4, 7, 8, 9, 6, 1},
   { 8, 4, 7, 1, 9, 6, 2, 3, 5},
   { 7, 9, 6, 2, 4, 1, 3, 5, 8},
   { 3, 5, 2, 8, 6, 7, 1, 9, 4},
   { 4, 8, 1, 9, 5, 3, 7, 2, 6}};
int mat28[MATRIZ][MATRIZ]=
  {{ 6, 4, 8, 1, 3, 2, 5, 9, 7},
   { 3, 2, 1, 7, 5, 9, 6, 8, 4},
   { 7, 5, 9, 8, 4, 6, 3, 2, 1},
   { 2, 1, 7, 3, 6, 8, 4, 5, 9},
   { 8, 6, 4, 9, 1, 5, 7, 3, 2},
   { 9, 3, 5, 2, 7, 4, 8, 1, 6},
   { 5, 7, 3, 6, 2, 1, 9, 4, 8},
   { 4, 8, 2, 5, 9, 7, 1, 6, 3},
   { 1, 9, 6, 4, 8, 3, 2, 7, 5}};
int mat29[MATRIZ][MATRIZ]=
  {{ 7, 6, 4, 8, 1, 2, 3, 5, 9},
   { 8, 9, 5, 4, 6, 3, 1, 7, 2},
   { 2, 3, 1, 5, 9, 7, 6, 8, 4},
   { 5, 2, 3, 9, 4, 1, 7, 6, 8},
   { 9, 7, 8, 2, 3, 6, 4, 1, 5},
   { 4, 1, 6, 7, 5, 8, 9, 2, 3},
   { 6, 8, 9, 1, 2, 4, 5, 3, 7},
   { 1, 4, 7, 3, 8, 5, 2, 9, 6},
   { 3, 5, 2, 6, 7, 9, 8, 4, 1}};
int mat30[MATRIZ][MATRIZ]=
  {{ 3, 5, 4, 6, 7, 8, 2, 1, 9},
   { 7, 1, 8, 2, 9, 5, 3, 6, 4},
   { 2, 6, 9, 4, 3, 1, 7, 5, 8},
   { 9, 8, 6, 5, 4, 2, 1, 7, 3},
   { 4, 2, 7, 3, 1, 6, 8, 9, 5},
   { 1, 3, 5, 9, 8, 7, 6, 4, 2},
   { 5, 4, 2, 7, 6, 3, 9, 8, 1},
   { 6, 9, 1, 8, 2, 4, 5, 3, 7},
   { 8, 7, 3, 1, 5, 9, 4, 2, 6}};
int mat31[MATRIZ][MATRIZ]=
  {{ 2, 4, 8, 1, 7, 9, 5, 6, 3},
   { 5, 6, 1, 4, 8, 3, 2, 9, 7},
   { 3, 9, 7, 5, 6, 2, 4, 1, 8},
   { 8, 7, 5, 9, 4, 1, 3, 2, 6},
   { 1, 3, 4, 2, 5, 6, 8, 7, 9},
   { 9, 2, 6, 7, 3, 8, 1, 5, 4},
   { 7, 1, 3, 6, 2, 4, 9, 8, 5},
   { 6, 8, 9, 3, 1, 5, 7, 4, 2},
   { 4, 5, 2, 8, 9, 7, 6, 3, 1}};
int mat32[MATRIZ][MATRIZ]=
  {{ 7, 4, 6, 5, 9, 8, 1, 2, 3},
   { 9, 2, 1, 7, 3, 4, 8, 6, 5},
   { 5, 3, 8, 2, 6, 1, 9, 7, 4},
   { 6, 7, 3, 1, 8, 9, 4, 5, 2},
   { 4, 9, 5, 3, 2, 7, 6, 8, 1},
   { 8, 1, 2, 4, 5, 6, 7, 3, 9},
   { 3, 6, 9, 8, 1, 2, 5, 4, 7},
   { 2, 8, 7, 9, 4, 5, 3, 1, 6},
   { 1, 5, 4, 6, 7, 3, 2, 9, 8}};
int mat33[MATRIZ][MATRIZ]=
  {{ 9, 1, 5, 8, 7, 3, 6, 4, 2},
   { 8, 6, 2, 4, 5, 9, 1, 3, 7},
   { 4, 7, 3, 2, 1, 6, 9, 8, 5},
   { 2, 3, 8, 1, 9, 7, 5, 6, 4},
   { 7, 9, 6, 5, 4, 2, 8, 1, 3},
   { 5, 4, 1, 6, 3, 8, 7, 2, 9},
   { 1, 8, 4, 7, 2, 5, 3, 9, 6},
   { 6, 5, 9, 3, 8, 4, 2, 7, 1},
   { 3, 2, 7, 9, 6, 1, 4, 5, 8}};
int mat34[MATRIZ][MATRIZ]=
  {{ 5, 6, 1, 2, 4, 9, 3, 7, 8},
   { 9, 2, 3, 7, 8, 6, 5, 1, 4},
   { 8, 4, 7, 5, 3, 1, 6, 2, 9},
   { 2, 5, 6, 9, 7, 3, 4, 8, 1},
   { 3, 7, 9, 8, 1, 4, 2, 6, 5},
   { 4, 1, 8, 6, 2, 5, 9, 3, 7},
   { 6, 8, 2, 4, 9, 7, 1, 5, 3},
   { 1, 9, 5, 3, 6, 8, 7, 4, 2},
   { 7, 3, 4, 1, 5, 2, 8, 9, 6}};
int mat35[MATRIZ][MATRIZ]=
  {{ 3, 8, 7, 1, 5, 4, 6, 9, 2},
   { 9, 4, 6, 8, 2, 3, 5, 1, 7},
   { 5, 1, 2, 7, 6, 9, 4, 8, 3},
   { 4, 2, 1, 5, 9, 7, 8, 3, 6},
   { 6, 9, 3, 4, 8, 1, 7, 2, 5},
   { 8, 7, 5, 2, 3, 6, 9, 4, 1},
   { 2, 3, 9, 6, 4, 5, 1, 7, 8},
   { 1, 5, 8, 9, 7, 2, 3, 6, 4},
   { 7, 6, 4, 3, 1, 8, 2, 5, 9}};
int mat36[MATRIZ][MATRIZ]=
  {{ 7, 3, 4, 2, 8, 6, 1, 5, 9},
   { 9, 1, 6, 7, 4, 5, 8, 3, 2},
   { 8, 2, 5, 1, 9, 3, 6, 7, 4},
   { 4, 5, 8, 3, 7, 9, 2, 6, 1},
   { 3, 6, 2, 5, 1, 4, 9, 8, 7},
   { 1, 7, 9, 8, 6, 2, 5, 4, 3},
   { 6, 4, 1, 9, 5, 7, 3, 2, 8},
   { 2, 8, 7, 6, 3, 1, 4, 9, 5},
   { 5, 9, 3, 4, 2, 8, 7, 1, 6}};
int mat37[MATRIZ][MATRIZ]=
  {{ 5, 6, 2, 1, 3, 7, 9, 4, 8},
   { 7, 4, 9, 2, 8, 5, 1, 6, 3},
   { 1, 3, 8, 9, 6, 4, 7, 2, 5},
   { 6, 5, 1, 4, 7, 2, 3, 8, 9},
   { 8, 9, 7, 3, 5, 6, 4, 1, 2},
   { 3, 2, 4, 8, 1, 9, 6, 5, 7},
   { 4, 7, 6, 5, 2, 3, 8, 9, 1},
   { 9, 8, 5, 7, 4, 1, 2, 3, 6},
   { 2, 1, 3, 6, 9, 8, 5, 7, 4}};
int mat38[MATRIZ][MATRIZ]=
  {{ 9, 8, 6, 3, 2, 1, 5, 7, 4},
   { 3, 5, 7, 4, 6, 8, 2, 1, 9},
   { 4, 1, 2, 9, 5, 7, 8, 3, 6},
   { 6, 7, 8, 1, 3, 5, 4, 9, 2},
   { 5, 3, 4, 6, 9, 2, 1, 8, 7},
   { 2, 9, 1, 7, 8, 4, 6, 5, 3},
   { 8, 4, 9, 2, 1, 3, 7, 6, 5},
   { 1, 2, 3, 5, 7, 6, 9, 4, 8},
   { 7, 6, 5, 8, 4, 9, 3, 2, 1}};
int mat39[MATRIZ][MATRIZ]=
  {{ 7, 4, 6, 9, 1, 3, 8, 5, 2},
   { 5, 3, 9, 2, 4, 8, 1, 7, 6},
   { 2, 8, 1, 5, 6, 7, 9, 3, 4},
   { 6, 7, 2, 4, 8, 9, 5, 1, 3},
   { 1, 9, 3, 6, 5, 2, 4, 8, 7},
   { 4, 5, 8, 7, 3, 1, 6, 2, 9},
   { 3, 6, 4, 8, 2, 5, 7, 9, 1},
   { 9, 2, 5, 1, 7, 4, 3, 6, 8},
   { 8, 1, 7, 3, 9, 6, 2, 4, 5}};
int mat40[MATRIZ][MATRIZ]=
  {{ 6, 7, 2, 4, 5, 8, 1, 3, 9},
   { 5, 8, 1, 2, 3, 9, 6, 7, 4},
   { 4, 9, 3, 7, 6, 1, 5, 8, 2},
   { 1, 4, 8, 3, 7, 2, 9, 5, 6},
   { 2, 6, 7, 9, 8, 5, 3, 4, 1},
   { 9, 3, 5, 6, 1, 4, 8, 2, 7},
   { 3, 5, 4, 1, 2, 6, 7, 9, 8},
   { 7, 1, 9, 8, 4, 3, 2, 6, 5},
   { 8, 2, 6, 5, 9, 7, 4, 1, 3}};

int matlac[MATRIZ][MATRIZ];
int matcopia[MATRIZ][MATRIZ];

int selecionardificuldade()
{
    int dificuldade;
    do
        {
        system("cls");
        printf("\n   ²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²² ");
        printf("\n   ²°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°² ");
        printf("\n   ²°°°ººººº°°°°ºº°°°°°°ºº°°°ººººººº°°°°°°°ººººººº°°°°°ºº°°°°ºº°°°ºº°°°°°°ºº°² ");
        printf("\n   ²°ººº°°°ºº°°°ºº°°°°°°ºº°°°ºº°°°°ºº°°°°°ºº°°°°°ºº°°°°ºº°°°ºº°°°°ºº°°°°°°ºº°² ");
        printf("\n   ²°ººº°°°°°°°°ºº°°°°°°ºº°°°ºº°°°°°ºº°°°ºº°°°°°°°ºº°°°ºº°°ºº°°°°°ºº°°°°°°ºº°² ");
        printf("\n   ²°°°ºººº°°°°°ºº°°°°°°ºº°°°ºº°°°°°ºº°°°ºº°°°°°°°ºº°°°ººººº°°°°°°ºº°°°°°°ºº°² ");
        printf("\n   ²°°°°°°ººº°°°ºº°°°°°°ºº°°°ºº°°°°°ºº°°°ºº°°°°°°°ºº°°°ºº°°ºº°°°°°ºº°°°°°°ºº°² ");
        printf("\n   ²°ººº°°ººº°°°°ºº°°°°ºº°°°°ºº°°°°ºº°°°°°ºº°°°°°ºº°°°°ºº°°°ºº°°°°°ºº°°°°ºº°°² ");
        printf("\n   ²°°ººººº°°°°°°°ºººººº°°°°°ººººººº°°°°°°°ººººººº°°°°°ºº°°°°ºº°°°°°ºººººº°°°² ");
        printf("\n   ²°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°² ");
        printf("\n   ²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²² ");
        printf("\n    ");
        printf("\n                      ²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²");
        printf("\n                      ²                            ²");
        printf("\n                      ²          1:Facil           ²");
        printf("\n                      ²          2:Medio           ²");
        printf("\n                      ²          3:Dificil         ²");
        printf("\n                      ²          4:Infernal        ²");
        printf("\n                      ²                            ²");
        printf("\n                      ²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²");
        printf("\n ");
        scanf("%d",&dificuldade);
        fflush(stdin);
        if(dificuldade<1 || dificuldade>4)
        {
            printf("\nOpcao invalida!\n");
            system("PAUSE");
        }
        }
        while(dificuldade<1 || dificuldade>4);
        return dificuldade;
}
void imprimirMatriz()
{
    system("cls");
    printf("°ººººººººººººººººººººººººººººººººº°\n° # ° 1  2  3 ° 4  5  6 ° 7  8  9 °\n°ºººººººººººººººººººººººººººººººº°\n");

    for(int linha = 0; linha < MATRIZ; linha++)
    {
    if(linha == 3 || linha == 6)
    {
        printf("°ººº°ººººººººº°ººººººººº°ººººººººº°\n");
    }

                for(int coluna = 0; coluna < MATRIZ; coluna++)
                {
                    if(coluna == 0)
                    {
                        //textcolor(2);
                        printf("º %d º", linha + 1);
                    }

                    if(matlac[linha][coluna] == 0)
                    {
                        printf("   ");
                    }
                    else
                    {
                        printf(" %d ", matlac[linha][coluna]);
                    }

                    if(coluna == 2 || coluna == 5)
                    {
                        printf("º");
                    }

                    if(coluna == 8)
                    {
                        printf("º\n");
                    }
                }

                if(linha == 8)
                {
                    printf("°ººººººººººººººººººººººººººººººººº°\n");
                }
            }
}
int copiarMatriz(int matEscolha[MATRIZ][MATRIZ])
{
    for(int linha=0;linha<MATRIZ;linha++)
        {
            for(int coluna=0;coluna<MATRIZ;coluna++)
            {
                matlac[linha][coluna]=matEscolha[linha][coluna];
                matcopia[linha][coluna]=matEscolha[linha][coluna];
            }
        }
}
void geraLacunas(int numeroDeLacunas)
{
    int linlac,collac, numlac;
    srand(time(NULL));

    for(int i=0;i<numeroDeLacunas;i++)
        {
            linlac=(rand()%9)+0;
            collac=(rand()%9)+0;
            matlac[linlac][collac]=0;


        }
}
void escolheMatriz(int dificuldade)
{
   int escolha,numeroDeLacunas=0;
   switch(dificuldade)
   {
    case 1:
    {
        srand(time(NULL));
        escolha=(rand()%9)+0;
        numeroDeLacunas=36;
        switch(escolha)
        {
            case 0:
            {
                copiarMatriz(mat1);
                break;
            }
            case 1:
            {
                copiarMatriz(mat2);
                break;
            }
            case 2:
            {
                copiarMatriz(mat3);
                break;
            }
            case 3:
            {
                copiarMatriz(mat4);
                break;
            }case 4:
            {
                copiarMatriz(mat5);
                break;
            }
            case 5:
            {
                copiarMatriz(mat6);
                break;
            }case 6:
            {
                copiarMatriz(mat7);
                break;
            }
            case 7:
            {
                copiarMatriz(mat8);
                break;
            }
            case 8:
            {
                copiarMatriz(mat9);
                break;
            }
            case 9:
            {
                copiarMatriz(mat10);
                break;
            }
        }
        geraLacunas(numeroDeLacunas);
        break;
    }
    case 2:
    {
        numeroDeLacunas=56;
        srand(time(NULL));
        escolha=(rand()%9)+0;
        switch(escolha)
        {
            case 0:
            {
                copiarMatriz(mat11);
                break;
            }
            case 1:
            {
                copiarMatriz(mat12);
                break;
            }
            case 2:
            {
                copiarMatriz(mat13);
                break;
            }
            case 3:
            {
                copiarMatriz(mat14);
                break;
            }case 4:
            {
                copiarMatriz(mat15);
                break;
            }
            case 5:
            {
                copiarMatriz(mat16);
                break;
            }case 6:
            {
                copiarMatriz(mat17);
                break;
            }
            case 7:
            {
                copiarMatriz(mat18);
                break;
            }
            case 8:
            {
                copiarMatriz(mat19);
                break;
            }
            case 9:
            {
                copiarMatriz(mat20);
                break;
            }
        }
         geraLacunas(numeroDeLacunas);
         break;
    }
    case 3:
    {
        srand(time(NULL));
        escolha=(rand()%9)+0;
        numeroDeLacunas=66;
        switch(escolha)
        {
            case 0:
            {
                copiarMatriz(mat21);
                break;
            }
            case 1:
            {
                copiarMatriz(mat22);
                break;
            }
            case 2:
            {
                copiarMatriz(mat23);
                break;
            }
            case 3:
            {
                copiarMatriz(mat24);
                break;
            }case 4:
            {
                copiarMatriz(mat25);
                break;
            }
            case 5:
            {
                copiarMatriz(mat26);
                break;
            }case 6:
            {
                copiarMatriz(mat27);
                break;
            }
            case 7:
            {
                copiarMatriz(mat28);
                break;
            }
            case 8:
            {
                copiarMatriz(mat29);
                break;
            }
            case 9:
            {
                copiarMatriz(mat30);
                break;
            }
        }
        geraLacunas(numeroDeLacunas);
         break;
    }
   case 4:
    {
        srand(time(NULL));
        escolha=(rand()%9)+0;
        numeroDeLacunas=78;
        switch(escolha)
        {
            case 0:
            {
                copiarMatriz(mat31);
                break;
            }
            case 1:
            {
                copiarMatriz(mat32);
                break;
            }
            case 2:
            {
                copiarMatriz(mat33);
                break;
            }
            case 3:
            {
                copiarMatriz(mat34);
                break;
            }case 4:
            {
                copiarMatriz(mat35);
                break;
            }
            case 5:
            {
                copiarMatriz(mat36);
                break;
            }case 6:
            {
                copiarMatriz(mat37);
                break;
            }
            case 7:
            {
                copiarMatriz(mat38);
                break;
            }
            case 8:
            {
                copiarMatriz(mat39);
                break;
            }
            case 9:
            {
                copiarMatriz(mat40);
                break;
            }
        }
        geraLacunas(numeroDeLacunas);
         break;
    }
   }
}
void imprimirFim()
{
            system("cls");
            printf("\n              ²²²²²²²²²²²²²²²²²²²²²²²²²²²²²                  ");
            printf("\n              ²ººººººººº²²ºº²²ººº²²²²²²ººº²                  ");
            printf("\n              ²ºº²²²²²²²²²ºº²²ºººº²²²²ºººº²                  ");
            printf("\n              ²ºº²²²²²²²²²ºº²²ºº²ºº²²ºº²ºº²                  ");
            printf("\n              ²ººººººº²²²²ºº²²ºº²²ºººº²²ºº²                  ");
            printf("\n              ²ºº²²²²²²²²²ºº²²ºº²²²ºº²²²ºº²                  ");
            printf("\n              ²ºº²²²²²²²²²ºº²²ºº²²²²²²²²ºº²                  ");
            printf("\n              ²ºº²²²²²²²²²ºº²²ºº²²²²²²²²ºº²                  ");
            printf("\n              ²²²²²²²²²²²²²²²²²²²²²²²²²²²²²                  ");
            printf("\n                                                             ");
            printf("\n           Obrigado por jogar nosso jogo!!!\n");





    getch();
}
int verificaLinha(int l, int c)
{
    int coluna,colunaErro=-1;
    for(coluna=0;coluna<MATRIZ;coluna++)
    {
        if(matlac[l][c]==matlac[l][coluna])
        {
            if(coluna!=c)
            {
                colunaErro=coluna;
            }

        }

    }
    return colunaErro;
}
int verificaColuna(int l, int c)
{
    int linha,linhaErro=-1;
    for(linha=0;linha<MATRIZ;linha++)
    {
        if(matlac[l][c]==matlac[linha][c])
        {
            if(linha!=l)
            {
                linhaErro=linha;
            }

        }

    }
    return linhaErro;
}
int verificaQuadranteErro(int l, int c, int quadranteErro)
{
    int linha=0,limiteLinha=2,limiteColuna=2,coluna=0,quadrante=-1,colunateste,inicioLinha,inicioColuna;
        linha=0;
        limiteLinha=2;
        switch(quadranteErro)
        {
        case 1:
            {
                inicioLinha=0;
                limiteLinha=2;
                inicioColuna=0;
                limiteColuna=2;
                break;
            }
        case 2:
            {
                inicioLinha=0;
                limiteLinha=2;
                inicioColuna=3;
                limiteColuna=5;
                break;
            }
        case 3:
            {
                inicioLinha=0;
                limiteLinha=2;
                inicioColuna=6;
                limiteColuna=8;
                break;
            }
        case 4:
            {
                inicioLinha=3;
                limiteLinha=5;
                inicioColuna=0;
                limiteColuna=2;
                break;
            }
        case 5:
            {
                inicioLinha=3;
                limiteLinha=5;
                inicioColuna=3;
                limiteColuna=5;
                break;
            }
        case 6:
            {
                inicioLinha=3;
                limiteLinha=5;
                inicioColuna=6;
                limiteColuna=8;
                break;
            }
        case 7:
            {
                inicioLinha=6;
                limiteLinha=8;
                inicioColuna=0;
                limiteColuna=2;
                break;
            }
        case 8:
            {
                inicioLinha=6;
                limiteLinha=8;
                inicioColuna=3;
                limiteColuna=5;
                break;
            }
        case 9:
            {
                inicioLinha=6;
                limiteLinha=8;
                inicioColuna=6;
                limiteColuna=8;
                break;
            }
        }
        for(coluna=inicioColuna;coluna<=limiteColuna;coluna++)
        {
            for(linha=inicioLinha;linha<=limiteLinha;linha++)
            {
                if(l!=linha || c!=coluna)

                {
                    if(matlac[l][c]==matlac[linha][coluna])
                    {
                        quadrante=quadranteErro;

                    }


                }
            }

        }

    return quadrante;
}
int verificaQuadrante(int l, int c)
{
    int linha,coluna,quadranteErro;
    if(l>=0 && l<=2)
    {
        if(c>=0 && c<=2)
        {
            quadranteErro=1;
        }
        else
        {
            if(c>=3 && c<=5)
            {
                quadranteErro=2;
            }
            else
            {
                if(c>=6 && c<=8)
                {
                    quadranteErro=3;
                }

            }
        }
    }
    else
    {
        if(l>=3 && l<=5)
        {
            if(c>=0 && c<=2)
            {
                quadranteErro=4;
            }
            else
            {
                if(c>=3 && c<=5)
                {
                    quadranteErro=5;
                }
                else
                {
                    if(c>=6 && c<=8)
                {
                    quadranteErro=6;
                }

                }
            }
        }
        else
        {
            if(l>=6 && l<=8)
            {
                if(c>=0 && c<=2)
                {
                    quadranteErro=7;
                }
                else
                {
                    if(c>=3 && c<=5)
                    {
                        quadranteErro=8;
                    }
                    else
                    {
                        if(c>=6 && c<=8)
                        {
                            quadranteErro=9;
                        }

                    }
                }
            }
        }
    }

        quadranteErro=verificaQuadranteErro(l,c,quadranteErro);

    return quadranteErro;
}


bool verifica(int dificuldade)
{
    int colunaErro, linhaErro, quadrante;
    bool ok=true;
    for(int l=0;l<MATRIZ;l++)
    {
        for(int c=0;c<MATRIZ;c++)
            {
                if(matcopia[l][c]!=matlac[l][c])
                    {
                        ok=false;
                        if(dificuldade==1 || dificuldade==2)
                        {
                            quadrante=verificaQuadrante(l,c);
                            colunaErro=verificaLinha(l,c);
                            linhaErro=verificaColuna(l,c);
                            if(colunaErro!=-1)
                            {
                                textcolor(LIGHT_RED);
                                printf("\nValor digitado %d  igual ao da linha %d coluna %d\n",matlac[l][c],l+1,colunaErro+1);
                            }
                            if(linhaErro!=-1)
                            {
                                textcolor(LIGHT_RED);
                                printf("\nValor digitado %d  igual ao da linha %d coluna %d\n",matlac[l][c],linhaErro+1,c+1);
                            }
                            if(quadrante!=-1)
                            {
                                textcolor(LIGHT_RED);
                                printf("\nValor digitado %d  esta repetindo no quadrante %d\n",matlac[l][c],quadrante);
                            }


                            textcolor(LIGHT_CYAN);
                            system("PAUSE");
                        }

                        matlac[l][c]=0;

                    }

            }
    }
    return ok;
}

bool lacuna()
{
    for(int linha=0;linha<MATRIZ;linha++)
    {
        for(int coluna=0;coluna<MATRIZ;coluna++)
        {
            if(matlac[linha][coluna]==0)
            {
                return true;
            }

        }
    }
    return false;
}
int validarEntrada()
{
   int valor;

   scanf("%d", &valor);
   fflush(stdin);

   if(valor>=1 && valor<=MATRIZ)
   {
       return valor;
   }
   printf("\nValor digitado invalido, digite um valor de 1 a 9: ");
   return validarEntrada();
}
void tabuleiro()
{
    int l,c;
    do
    {
            imprimirMatriz();
                printf("\n Informe a linha:  ");
                l = validarEntrada();

                printf("\n Informe a coluna:  ");
                c = validarEntrada();

                    if(matlac[l-1][c-1]!=0)
                    {
                        printf("\nPosicao ja preenchida!!\n");
                        system("PAUSE");
                    }
                    else
                    {
                            matlac[l-1][c-1]=0;
                            printf("\ninforme o valor desejado:  ");
                            matlac[l-1][c-1] = validarEntrada();

                    }

    }
    while(lacuna()==true);
    imprimirMatriz();

}
void menu()
{
    int op=0, dificuldade;
    do
    {
        system("cls");
        printf("\n   ²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²² ");
        printf("\n   ²°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°² ");
        printf("\n   ²°°°ººººº°°°°ºº°°°°°°ºº°°°ººººººº°°°°°°°ººººººº°°°°°ºº°°°°ºº°°°ºº°°°°°°ºº°² ");
        printf("\n   ²°ººº°°°ºº°°°ºº°°°°°°ºº°°°ºº°°°°ºº°°°°°ºº°°°°°ºº°°°°ºº°°°ºº°°°°ºº°°°°°°ºº°² ");
        printf("\n   ²°ººº°°°°°°°°ºº°°°°°°ºº°°°ºº°°°°°ºº°°°ºº°°°°°°°ºº°°°ºº°°ºº°°°°°ºº°°°°°°ºº°² ");
        printf("\n   ²°°°ºººº°°°°°ºº°°°°°°ºº°°°ºº°°°°°ºº°°°ºº°°°°°°°ºº°°°ººººº°°°°°°ºº°°°°°°ºº°² ");
        printf("\n   ²°°°°°°ººº°°°ºº°°°°°°ºº°°°ºº°°°°°ºº°°°ºº°°°°°°°ºº°°°ºº°°ºº°°°°°ºº°°°°°°ºº°² ");
        printf("\n   ²°ººº°°ººº°°°°ºº°°°°ºº°°°°ºº°°°°ºº°°°°°ºº°°°°°ºº°°°°ºº°°°ºº°°°°°ºº°°°°ºº°°² ");
        printf("\n   ²°°ººººº°°°°°°°ºººººº°°°°°ººººººº°°°°°°°ººººººº°°°°°ºº°°°°ºº°°°°°ºººººº°°°² ");
        printf("\n   ²°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°² ");
        printf("\n   ²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²² ");
        printf("\n    ");
        printf("\n                      ²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²");
        printf("\n                      ²                            ²");
        printf("\n                      ²          1:Regra           ²");
        printf("\n                      ²          2:Jogar           ²");
        printf("\n                      ²          3:Sair            ²");
        printf("\n                      ²                            ²");
        printf("\n                      ²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²");
        printf("\n ");
        scanf("%d",&op);
        fflush(stdin);
        switch(op)
        {
            case 1:
                {
                    printf("\n A ideia do jogo e' bem simples:\n completar todas as 81 celulas usando n£meros de 1 a 9,\n sem repetir os n£meros numa mesma linha, coluna ou grade (3x3).\n O jogo e' dividido em 4 dificuldades.\n Facil: Possui ate 36 lacunas e descreve onde voce errou, e porque errou.\n Medio: Possui ate 56 lacunas e escreve onde voce errou, e porque errou.\n Dificil: Possui ate 66 lacunas e nao apresenta dica alguma.\n Infernal: Possui ate78 lacunas, dicas? voce esta de brincadeira?\n");
                    system("PAUSE");
                    break;
                }
            case 2:
                {
                    dificuldade=selecionardificuldade();
                    escolheMatriz(dificuldade);
                    do
                    {

                        tabuleiro();
                    }
                    while(verifica(dificuldade)==false);
                    printf("\n *     *        *      *     *     *    *  *     *  *");
                    printf("\n    *      *        *      *     *        *   *   *");
                    printf("\n*   *Parabens jogo concluido com sucesso!!!   *   *  \n");
                    printf("\n *     *        *      *     *     *    *  *    * ");
                    printf("\n   *      *        *      *     *     *      *   *\n");
                    system("PAUSE");
                    break;

                }
            case 3:
                {
                    imprimirFim();
                    break;
                }
            default:
                {
                    printf("\nopcao invalida!!!\n");
                    system("PAUSE");
                }
        }

    }
    while(op!=3);
}
int main()
{
     system("COLOR 0B");
    menu();

}
