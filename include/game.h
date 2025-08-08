#ifndef GAME_H

#define GAME_H
#include<stdio.h>
#include<stdlib.h>
#include <time.h>

#ifdef _WIN32
    #include <Windows.h>
#else
    #include <unistd.h>
#endif

typedef signed char _schar;
typedef signed short _sshort;

#define COLS 0x28    //1*(16^1)+ 4 *(16^0) = 20
#define ROWS 0x28
#define ALIVE '*'
#define DEAD '.'

typedef struct{
    _schar cells[COLS*ROWS];    //400 celle
}Grid;

_sshort out_of_grid(_sshort x, _sshort y); //This function checks if the coordinates go outside the grid
void set_cell_grid(Grid* grid, _sshort x, _sshort y, _schar state);    //This function sets a cell in the grid in coordinates (x,y) with the value of the state
_schar get_cell_grid(Grid* grid, _sshort x, _sshort y);    //This function return a cell in the grid in coordinates (x,y) with the value of the state
void print_grid(Grid*);  //This function print the entire grid
void update_grid(Grid*, _schar);   //This function initialize the cells of grid to DEAD
void set_life(Grid*, Grid*);    //This function implements the algorithm of Game Of Life
_schar get_count_cells_alive_around(Grid* , _sshort ,_sshort);  //This function returns the number of alive cells around the cell
#endif