#include<stdio.h>

int main(){
    int rows, cols, instructions, i, j, init_i, init_j, sticker;
    char input, orientation;
    scanf("%d %d %d", &rows, &cols, &instructions);
    while(rows && cols && instructions){
        sticker = 0;
        input = getchar();
        char maze[rows][cols];
        for(i = 0; i < rows; i++){
            for(j = 0; j < cols; j++){
                input = getchar();
                if(input == 'N' || input == 'S' || input == 'L' || input == 'O'){
                    orientation = input;
                    init_i = i;
                    init_j = j;
                }
                maze[i][j] = input;
            }
            input = getchar();
        }
        for(i = 0; i < instructions; i++){
            input = getchar();
            switch(input){
                case 'D':
                if(orientation == 'N'){
                    orientation = 'L';
                }else if(orientation == 'L'){
                    orientation = 'S';
                }else if(orientation == 'S'){
                    orientation = 'O';
                }else if(orientation == 'O'){
                    orientation = 'N';
                }
                break;
                case 'E':
                if(orientation == 'N'){
                    orientation = 'O';
                }else if(orientation == 'O'){
                    orientation = 'S';
                }else if(orientation == 'S'){
                    orientation = 'L';
                }else if(orientation == 'L'){
                    orientation = 'N';
                }
                break;
                case 'F':
                if(orientation == 'N'){
                    if(maze[init_i-1][init_j] != '#' && init_i-1 >= 0){
                        init_i--;
                        if(maze[init_i][init_j] == '*'){
                            sticker++;
                            maze[init_i][init_j] = '.';
                        }
                    }
                }else if(orientation == 'S'){
                    if(maze[init_i+1][init_j] != '#' && init_i+1 < rows){
                        init_i++;
                        if(maze[init_i][init_j] == '*'){
                            sticker++;
                            maze[init_i][init_j] = '.';
                        }
                    }
                }else if(orientation == 'L'){
                    if(maze[init_i][init_j+1] != '#' && init_j+1 < cols){
                        init_j++;
                        if(maze[init_i][init_j] == '*'){
                            sticker++;
                            maze[init_i][init_j] = '.';
                        }
                    }
                }else if(orientation == 'O'){
                    if(maze[init_i][init_j-1] != '#' && init_j-1 >= 0){
                        init_j--;
                        if(maze[init_i][init_j] == '*'){
                            sticker++;
                            maze[init_i][init_j] = '.';
                        }
                    }
                }
                break;
            }
        }
        printf("%d\n", sticker);
        scanf("%d %d %d", &rows, &cols, &instructions);
    }
    return 0;
}