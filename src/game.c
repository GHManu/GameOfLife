#include "game.h"

//This function checks if the coordinates go outside the grid
_sshort out_of_grid(_sshort x, _sshort y){

    //positive coordinates
    if(x >= COLS)
        x %= COLS;  //41%40 = 1; 42%40 = 2 --> ci dà già l'offset 
    if(y >= ROWS)
        y %= ROWS;

    //negative coordinates
    if(x < 0){
        x %= COLS;
        x += COLS; 
    }
    if(y < 0){
        y %= ROWS;
        y += ROWS; 
    }

    return x+(y*COLS);
}

//This function sets a cell in the grid in coordinates (x,y) with the value of the state
void set_cell_grid(Grid* grid, _sshort x, _sshort y, _schar state){
    //se ho una 3x3, se voglio (2,2), farà 2*20= 40 quindi alla seconda riga della griglia, poi la x sarà diquanto mi sposto a destra
    //grid->cells[y*COLS+x] = state;
    grid->cells[out_of_grid(x,y)] = state;
}

//This function return a cell in the grid in coordinates (x,y) with the value of the state
_schar get_cell_grid(Grid* grid, _sshort x, _sshort y){
    return grid->cells[out_of_grid(x,y)];
} 

//This function update the cells of grid to state
void update_grid(Grid* grid, _schar state){
    _sshort i;
    _sshort j;
    for(i = 0; i < ROWS; i++){
        for(j = 0; j<COLS; j++){
            set_cell_grid( grid, j, i, state);
        }
    }
}

//This function print the entire grid
void print_grid(Grid* grid){
    _sshort i;
    _sshort j;
    for(i = 0; i < ROWS; i++){
        for(j = 0; j<COLS; j++){
            printf("%c",get_cell_grid( grid, j, i));
        }
        printf("\n");
    }
}

//This function implements the algorithm of Game Of Life
void set_life(Grid* old, Grid* new){
    _sshort i;
    _sshort j;
    for(i = 0; i < ROWS; i++){
        for(j = 0; j<COLS; j++){
            _schar n = get_count_cells_alive_around(old, j, i);
            _schar new_state = DEAD;
            if(get_cell_grid(old, j, i) == ALIVE){
                if(n == 2 || n == 3)  new_state = ALIVE;
            }
            else
            {
                if(n == 3)  new_state = ALIVE;
            }
            set_cell_grid(new, j, i, new_state);
        }
    }
}

//This function returns the number of alive cells around the cell
_schar get_count_cells_alive_around(Grid* grid, _sshort x,_sshort y){
    _sshort start_x, start_y, end_x = x + 1, end_y = y+1;
    _schar count = 0;

   for(start_y = y-1; start_y<= end_y; start_y++){
        for(start_x = x - 1; start_x <= end_x; start_x++){
            if( get_cell_grid(grid, start_x, start_y) == ALIVE && !(start_x == x && start_y == y))
                count++;
        }
    }

    return count;
}
