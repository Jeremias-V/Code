#include<stdio.h>

int main(){
    int testCases, rows, cols, i, j, posRow, posCol;
    char orientation, move, input;
    scanf("%d", &testCases);
    while(testCases--){
        orientation = 'N';
        scanf("%d %d", &rows, &cols);
        char maze[rows][cols];
        for(i = 0; i < rows; i++){
            for(j = 0; j < cols; j++){
                input = getchar();
                while(input == '\n'){
                    input = getchar();
                }
                maze[i][j] = input;
            }
        }
        scanf("%d %d", &posRow, &posCol);
        --posRow; --posCol;
        move = getchar();
        while(move != 'Q'){
            switch(move){
                case 'R':
                    if(orientation == 'N'){
                        orientation = 'E';
                    }else if(orientation == 'E'){
                        orientation = 'S';
                    }else if(orientation == 'S'){
                        orientation = 'W';
                    }else if(orientation == 'W'){
                        orientation = 'N';
                    }
                    break;
                case 'L':
                    if(orientation == 'N'){
                        orientation = 'W';
                    }else if(orientation == 'W'){
                        orientation = 'S';
                    }else if(orientation == 'S'){
                        orientation = 'E';
                    }else if(orientation == 'E'){
                        orientation = 'N';
                    }
                    break;
                case 'F':
                    if(orientation == 'N' && maze[posRow-1][posCol] == ' ' && posRow > 0){
                        posRow--;
                    }else if(orientation == 'W' && maze[posRow][posCol-1] == ' ' && posCol > 0){
                        posCol--;
                    }else if(orientation == 'S' && maze[posRow+1][posCol] == ' ' && posRow+1 < rows){
                        posRow++;
                    }else if(orientation == 'E' && maze[posRow][posCol+1] == ' ' && posCol+1 < cols){
                        posCol++;
                    }
                    break;
                default:
                    break;
            }
            move = getchar();
        }
        if(testCases > 0){
            printf("%d %d %c\n\n", posRow+1, posCol+1, orientation);
        }else{
            printf("%d %d %c\n", posRow+1, posCol+1, orientation);

        }
    }
    return 0;
}