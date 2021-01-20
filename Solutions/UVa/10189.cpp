 #include<iostream>
using namespace std;

int main(){
    int row, col, count, field = 1;
    char temp;
    cin >> row >> col;
    while(row != 0 && col != 0){
        if(field > 1){
            cout << endl;
        }
        char board[101][101] = {0};
        for(int i = 0; i < row; i++){
            for(int j = 0; j < col; j++){
                cin >> temp;
                board[i][j] = temp;
            }
        }
        for(int i = 0; i < row; i++){
            for(int j = 0; j < col; j++){
                count = 0;
                if(board[i][j] != '*'){
                    if(i == 0){ 
                        if(j == 0){
                            if(board[i][j+1] == '*'){
                                count++;
                            }if(board[i+1][j] == '*'){
                                count++;
                            }if(board[i+1][j+1] == '*'){
                                count++;
                            }
                        }else if(j == col-1){
                            if(board[i][j-1] == '*'){
                                count++;
                            }if(board[i+1][j-1] == '*'){
                                count++;
                            }if(board[i+1][j] == '*'){
                                count++;
                            }
                        }else{
                            if(board[i][j-1] == '*'){
                                count++;
                            }if(board[i][j+1] == '*'){
                                count++;
                            }if(board[i+1][j-1] == '*'){
                                count++;
                            }if(board[i+1][j] == '*'){
                                count++;
                            }if(board[i+1][j+1] == '*'){
                                count++;
                            }
                        }
                    }else if(i == row-1){
                        if(j == 0){
                            if(board[i-1][j] == '*'){
                                count++;
                            }if(board[i-1][j+1] == '*'){
                                count++;
                            }if(board[i][j+1] == '*'){
                                count++;
                            }

                        }else if(j == col-1){
                            if(board[i-1][j-1] == '*'){
                                count++;
                            }if(board[i-1][j] == '*'){
                                count++;
                            }if(board[i][j-1] == '*'){
                                count++;
                            }
                        }else{
                            if(board[i-1][j-1] == '*'){
                                count++;
                            }if(board[i-1][j] == '*'){
                                count++;
                            }if(board[i-1][j+1] == '*'){
                                count++;
                            }if(board[i][j-1] == '*'){
                                count++;
                            }if(board[i][j+1] == '*'){
                                count++;
                            }
                        }
                    }else if(j == 0){
                        if(board[i-1][j] == '*'){
                            count++;
                        }if(board[i-1][j+1] == '*'){
                            count++;
                        }if(board[i][j+1] == '*'){
                            count++;
                        }if(board[i+1][j] == '*'){
                            count++;
                        }if(board[i+1][j+1] == '*'){
                            count++;
                        }
                    }else if(j == col-1){
                        if(board[i-1][j-1] == '*'){
                            count++;
                        }if(board[i-1][j] == '*'){
                            count++;
                        }if(board[i][j-1] == '*'){
                            count++;
                        }if(board[i+1][j-1] == '*'){
                            count++;
                        }if(board[i+1][j] == '*'){
                            count++;
                        }
                    }else if(i != 0 && j != 0 && i != row-1 && j != col-1){
                        if(board[i-1][j-1] == '*'){
                            count++;
                        }if(board[i-1][j] == '*'){
                            count++;
                        }if(board[i-1][j+1] == '*'){
                            count++;
                        }if(board[i][j-1] == '*'){
                            count++;
                        }if(board[i][j+1] == '*'){
                            count++;
                        }if(board[i+1][j-1] == '*'){
                            count++;
                        }if(board[i+1][j] == '*'){
                            count++;
                        }if(board[i+1][j+1] == '*'){
                            count++;
                        }
                    }
                    board[i][j] = char(count+48);
                }
            }
        }
        cout << "Field #" << field++ << ":" << endl;
        for(int i = 0; i < row; i++){
            if(i != 0){
                cout << endl;
            }
            for(int j = 0; j < col; j++){
                cout << board[i][j];
            }
        }
        cout << endl;
        cin >> row >> col;
    }
    return 0;
}
