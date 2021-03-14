#include<cstdio>
#include<algorithm>
using namespace std;

char board[82][82];
bool visitedFirst[82][82], visitedSecond[82][82];
int moveRow[] = {-1, 0, 1, 0};
int moveCol[] = {0, 1, 0, -1};
int N, ansCode;

void DFS(int i, int j, char ignoreP, bool (&visited)[82][82]){
    int k, newI, newJ;
    visited[i][j] = true;

    for(k = 0; k < 4; k++){
        newI = i + moveRow[k];
        newJ = j + moveCol[k];
        if(newI >= 0 && newI < N && newJ >= 0 && newJ < N &&
        !visited[newI][newJ] && board[newI][newJ] != ignoreP && board[newI][newJ] != 'U'){
            
            visited[newI][newJ] = true;
            
            if(newJ == N-1 && ignoreP != 'W'){
                ansCode = 1;
                return;
            }else if(newI == N-1 && ignoreP != 'B'){
                ansCode = 2;
                return;
            }

            DFS(newI, newJ, ignoreP, visited);
        }
    }
}

void fillVisited(bool (&visited)[82][82]){
    int i;
    for(i = 0; i < N; i++){
        fill(visited[i], visited[i] + N, false);
    }
}

void fillLeftRight(){
    int i = 0;
    while(i < N){
        if(board[i][0] == 'W'){
            DFS(i, 0, 'B', visitedFirst);
        }
        i += 1;
    }
}

void fillRightLeft(){
    int i = 0;
    while(i < N){
        if(board[i][N-1] == 'W'){
            DFS(i, N-1, 'B', visitedSecond);
        }
        i += 1;
    }
}

void checkWhite(){
    int i, j, k, newI, newJ, tmpLeft, tmpRight;
    bool foundLeft, foundRight;
    for(i = 0; i < N; i++){
        for(j = 0; j < N; j++){
            if(board[i][j] == 'U'){
                tmpLeft = j-1;
                tmpRight = j+1;
                foundLeft = foundRight = false;
                if(tmpLeft >= 0 && tmpLeft < N && j == N-1){
                    if(visitedFirst[i][tmpLeft] || visitedSecond[i][tmpLeft]){
                        ansCode = 3;
                        return;
                    }
                }else if(tmpRight >= 0 && tmpRight < N && j == 0){
                    if(visitedFirst[i][tmpRight] || visitedSecond[i][tmpRight]){
                        ansCode = 3;
                        return;
                    }
                }else{
                    for(k = 0; k < 4; k++){
                        newI = i + moveRow[k];
                        newJ = j + moveCol[k];
                        if(newI >= 0 && newI < N && newJ >= 0 && newJ < N &&
                        visitedFirst[newI][newJ] && !foundLeft){
                            foundLeft = true;
                        }
                        if(newI >= 0 && newI < N && newJ >= 0 && newJ < N &&
                        visitedSecond[newI][newJ] && !foundRight){
                            foundRight = true;
                        }
                    }
                    if(foundLeft && foundRight){
                        ansCode = 3;
                        return;
                    }
                }
            }
        }
    }
    ansCode = 0;
}

void fillTopBottom(){
    int j = 0;
    while(j < N){
        if(board[0][j] == 'B'){
            DFS(0, j, 'W', visitedFirst);
        }
        j += 1;
    }
}

void fillBottomTop(){
    int j = 0;
    while(j < N){
        if(board[N-1][j] == 'B'){
            DFS(N-1, j, 'W', visitedSecond);
        }
        j += 1;
    }
}

void checkBlack(){
    int i, j, k, newI, newJ, tmpUp, tmpDown;
    bool foundLeft, foundRight;
    for(i = 0; i < N; i++){
        for(j = 0; j < N; j++){
            if(board[i][j] == 'U'){
                foundLeft = foundRight = false;
                tmpUp = i-1;
                tmpDown = i+1;
                if(tmpUp >= 0 && tmpUp < N && i == N-1){
                    if(visitedFirst[tmpUp][j] || visitedSecond[tmpUp][j]){
                        ansCode = 4;
                        return;
                    }
                }else if(tmpDown >= 0 && tmpDown < N && i == 0){
                    if(visitedFirst[tmpDown][j] || visitedSecond[tmpDown][j]){
                        ansCode = 4;
                        return;
                    }
                }else{
                    for(k = 0; k < 4; k++){
                        newI = i + moveRow[k];
                        newJ = j + moveCol[k];
                        if(newI >= 0 && newI < N && newJ >= 0 && newJ < N &&
                        visitedFirst[newI][newJ] && !foundLeft){
                            foundLeft = true;
                        }
                        if(newI >= 0 && newI < N && newJ >= 0 && newJ < N &&
                        visitedSecond[newI][newJ] && !foundRight){
                            foundRight = true;
                        }
                    }
                    if(foundLeft && foundRight){
                        ansCode = 4;
                        return;
                    }
                }
            }
        }
    }
    ansCode = 0;
}

void printAns(int n){
    switch (n){
    case 1:
        printf("White has a winning path.\n");
        break;
    case 2:
        printf("Black has a winning path.\n");
        break;
    case 3:
        printf("White can win in one move.\n");
        break;
    case 4:
        printf("Black can win in one move.\n");
        break;
    default:
        printf("There is no winning path.\n");
        break;
    }
}

int main(){
    int i, j, tmpAns;
    bool found;
    char tmp;
    scanf("%d\n", &N);
    while(N != 0){
        for(i = 0; i < N; i++){
            for(j = 0; j < N; j++){
                tmp = getchar();
                if(tmp != 'W' && tmp != 'B' && tmp != 'U'){
                    tmp = getchar();
                }
                board[i][j] = tmp;
            }
        }
        ansCode = 0;
        if(N == 1){
            if(board[0][0] == 'W'){
                ansCode = 1;
            }else if(board[0][0] == 'U'){
                ansCode = 3;
            }else{
                ansCode = 2;
            }
            printAns(ansCode);
        }else{
            fillVisited(visitedFirst);
            fillLeftRight();
            if(ansCode != 0){
                printAns(ansCode);
            }else{
                fillVisited(visitedSecond);
                fillRightLeft();
                checkWhite();
                if(ansCode != 0){
                    printAns(ansCode);
                }else{
                    fillVisited(visitedFirst);
                    fillTopBottom();
                    if(ansCode != 0){
                        printAns(ansCode);
                    }else{
                        fillVisited(visitedSecond);
                        fillBottomTop();
                        checkBlack();
                        printAns(ansCode);
                    }
                }
            }
        }
        scanf("%d\n", &N);
    }
    return 0;
}
