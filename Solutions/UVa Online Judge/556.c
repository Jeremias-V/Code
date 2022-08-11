#include<stdio.h>

int main(){
    int rows, cols, i, j, robotPos_i, robotPos_j,
    zero, one, two, three, four;
    char input, orientation;
    scanf("%d %d", &rows, &cols);
    while(rows != 0 && cols != 0){
        zero = 0, one = 0, two = 0, three = 0, four = 0;
        orientation = 'E';
        robotPos_i = rows-1;
        robotPos_j = 0;
        char maze[rows][cols];
        int path[rows][cols];
        for(i = 0; i < rows; i++){
            for(j = 0; j < cols; j++){
                input = getchar();
                while(input == '\n'){
                    input = getchar();
                }
                maze[i][j] = input;
                if(input == '1'){
                    path[i][j] = -1;
                }else{
                    path[i][j] = 0;
                }
            }
        }
        while(1){
            if(orientation == 'E'){
                if(maze[robotPos_i][robotPos_j+1] == '0' && robotPos_j+1 < cols){
                    robotPos_j++;
                    path[robotPos_i][robotPos_j]++;
                    if(maze[robotPos_i+1][robotPos_j] == '0'){
                        orientation = 'S';
                    }
                }else{
                    orientation = 'N';
                }
            }else if(orientation == 'N'){
                if(maze[robotPos_i-1][robotPos_j] == '0' && robotPos_i-1 >= 0){
                    robotPos_i--;
                    path[robotPos_i][robotPos_j]++;
                    if(maze[robotPos_i][robotPos_j+1] == '0'){
                        orientation = 'E';
                    }
                }else{
                    orientation = 'W';
                }
            }else if(orientation == 'W'){
                if(maze[robotPos_i][robotPos_j-1] == '0' && robotPos_j-1 >= 0){
                    robotPos_j--;
                    path[robotPos_i][robotPos_j]++;
                    if(maze[robotPos_i-1][robotPos_j] == '0'){
                        orientation = 'N';
                    }
                }else{
                    orientation = 'S';
                }
            }else if(orientation == 'S'){
                if(maze[robotPos_i+1][robotPos_j] == '0' && robotPos_i+1 < rows){
                    robotPos_i++;
                    path[robotPos_i][robotPos_j]++;
                    if(maze[robotPos_i][robotPos_j-1] == '0'){
                        orientation = 'W';
                    }
                }else{
                    orientation = 'E';
                }
            }
            if(robotPos_i == rows-1 && robotPos_j == 0){
                break;
            }
        }
        for(i = 0; i < rows; i++){
            for(j = 0; j < cols; j++){
                if(path[i][j] == 0){
                    zero++;
                }else if(path[i][j] == 1){
                    one++;
                }else if(path[i][j] == 2){
                    two++;
                }else if(path[i][j] == 3){
                    three++;
                }else if(path[i][j] == 4){
                    four++;
                }
            }
        }
        printf("%3d%3d%3d%3d%3d\n", zero, one, two, three, four);
        scanf("%d %d", &rows, &cols);
    }
    return 0;
}