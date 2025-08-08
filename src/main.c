#include"game.h"

int main(void){
    srand(time(NULL));
    Grid old, new;
    char comando[16];
    char textColor;
    _sshort x, y;
    _sshort i, n;
    update_grid(&old, DEAD);
    update_grid(&new, DEAD);

    _schar c;
    printf("Welcome to Game Of Life!\nDo you want to do it randomly? [s/n]:\n");
    scanf("%c", &c);

    if(c == 's'){
        n = 100;
        for(i = 0; i<n; i++){
            x = rand() % COLS; 
            y = rand() % ROWS; 
            set_cell_grid(&old, x, y, ALIVE);
            printf("You brought the coordinate to life: (%hd,%hd)\n", x, y);
        }
        system("pause");
    }
    else{
        // Gosper Glider Gun
        set_cell_grid(&old, 1, 25, ALIVE);
        set_cell_grid(&old, 2, 25, ALIVE);
        set_cell_grid(&old, 1, 26, ALIVE);
        set_cell_grid(&old, 2, 26, ALIVE);

        set_cell_grid(&old, 11, 25, ALIVE);
        set_cell_grid(&old, 11, 26, ALIVE);
        set_cell_grid(&old, 11, 27, ALIVE);
        set_cell_grid(&old, 12, 24, ALIVE);
        set_cell_grid(&old, 12, 28, ALIVE);
        set_cell_grid(&old, 13, 23, ALIVE);
        set_cell_grid(&old, 13, 29, ALIVE);
        set_cell_grid(&old, 14, 23, ALIVE);
        set_cell_grid(&old, 14, 29, ALIVE);
        set_cell_grid(&old, 15, 26, ALIVE);
        set_cell_grid(&old, 16, 24, ALIVE);
        set_cell_grid(&old, 16, 28, ALIVE);
        set_cell_grid(&old, 17, 25, ALIVE);
        set_cell_grid(&old, 17, 26, ALIVE);
        set_cell_grid(&old, 17, 27, ALIVE);
        set_cell_grid(&old, 18, 26, ALIVE);

        set_cell_grid(&old, 21, 23, ALIVE);
        set_cell_grid(&old, 21, 24, ALIVE);
        set_cell_grid(&old, 21, 25, ALIVE);
        set_cell_grid(&old, 22, 23, ALIVE);
        set_cell_grid(&old, 22, 24, ALIVE);
        set_cell_grid(&old, 22, 25, ALIVE);
        set_cell_grid(&old, 23, 22, ALIVE);
        set_cell_grid(&old, 23, 26, ALIVE);

        set_cell_grid(&old, 25, 21, ALIVE);
        set_cell_grid(&old, 25, 22, ALIVE);
        set_cell_grid(&old, 25, 26, ALIVE);
        set_cell_grid(&old, 25, 27, ALIVE);

        set_cell_grid(&old, 35, 23, ALIVE);
        set_cell_grid(&old, 35, 24, ALIVE);
        set_cell_grid(&old, 36, 23, ALIVE);
        set_cell_grid(&old, 36, 24, ALIVE);

    }


    while(1){
        set_life(&old, &new);
        print_grid(&new);
        
        #ifdef _WIN32
            Sleep(500);
        #else
            sleep(0.5);
        #endif
        textColor = rand() % 16; // generates a number from 0 to 15

        sprintf(comando, "color 0%X", textColor);
        system(comando);
        
        set_life(&new, &old);
        print_grid(&old);

        #ifdef _WIN32
            Sleep(500);
        #else
            sleep(0.5);
        #endif

        textColor = rand() % 16; // generates a number from 0 to 15

        sprintf(comando, "color 0%X", textColor);
        system(comando);

    }
    
    return 0;
}