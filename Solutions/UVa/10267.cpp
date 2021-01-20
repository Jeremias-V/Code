#include<iostream>
#include<string>
using namespace std;


class Picture{
    private:

    char table[251][251];
    int m, n; // column m, row n 
    string fileName;

    public:

    void I_Create(int m, int n){
        this -> m = m;
        this -> n = n;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                table[i][j] = 'O';
            }
        }
    }

    void C_Clear(){
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                table[i][j] = 'O';
            }
        }
    }

    void L_ColorPixel(int x, int y, char c){
        table[y][x] = c;
    }

    void V_DrawVerticalSegment(int x, int y1, int y2, char c){
        if(y2 < y1){
            int temp = y2;
            y2 = y1;
            y1 = temp;
        }
        for(int i = y1; i <= y2; i++){
            table[i][x] = c;
        }
    }

    void H_DrawHorizontalSegment(int x1, int x2, int y, char c){
        if(x2 < x1){
            int temp = x2;
            x2 = x1;
            x1 = temp;
        }
        for(int i = x1; i <= x2; i++){
            table[y][i] = c;
        }
    }

    void K_DrawFilledRect(int x1, int y1, int x2, int y2, char c){
        if(x2 < x1){
            int temp = x2;
            x2 = x1;
            x1 = temp;
        }if(y2 < y1){
            int temp = y2;
            y2 = y1;
            y1 = temp;
        }
        for(int i = y1; i <= y2; i++){
            for(int j = x1; j <= x2; j++){
                table[i][j] = c;
            }
        }
    }

    void F_FillRegion(int x, int y, char c){ // no funciona del todo
        char temp = table[y][x];
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(table[i][j] == temp){
                    if(i == 0 && j == 0){ //superior izquierda
                        if(table[i+1][j] == temp || table[i][j+1] == temp){
                            table[i][j] = c;
                        }
                    }else if(i == 0 && j > 0 && j < m-1){ // primera fila sin pegarse a las paredes
                        if(table[i][j-1] == temp || table[i][j+1] == temp || table[i+1][j] == temp){
                            table[i][j] = c;
                        }
                    }else if(i > 0 && j > 0 && i < n-1 && j < m-1){ // cualquiera interno
                        if(table[i-1][j] == temp || table[i][j-1] == temp || table[i+1][j] == temp || table[i][j+1] == temp){
                            table[i][j] = c;
                        }
                    }else if()
                }
            }
        }
    }

    void S_SaveAndDisplay(string name){
        fileName = name;
        cout << fileName << endl;
        for(int i = 0; i < n; i++){
            if(i > 0){
                cout << endl;
            }
            for(int j = 0; j < m; j++){
                cout << table[i][j];
            }
        }
        cout << endl;
    }

};


int main(){
    Picture pic;
    char command, color;
    int arg1, arg2, arg3, arg4;
    string name;
    cin >> command;
    while(command != 'X'){
        switch (command){
            case 'I':
                cin >> arg1 >> arg2;
                pic.I_Create(arg1, arg2);
                break;
            case 'C':
                pic.C_Clear();
                break;
            case 'L':
                cin >> arg1 >> arg2 >> color;
                pic.L_ColorPixel(arg1-1, arg2-1, color);
                break;
            case 'V':
                cin >> arg1 >> arg2 >> arg3 >> color;
                pic.V_DrawVerticalSegment(arg1-1, arg2-1, arg3-1, color);
                break;
            case 'H':
                cin >> arg1 >> arg2 >> arg3 >> color;
                pic.H_DrawHorizontalSegment(arg1-1, arg2-1, arg3-1, color);
                break;
            case 'K':
                cin >> arg1 >> arg2 >> arg3 >> arg4 >> color;
                pic.K_DrawFilledRect(arg1-1, arg2-1, arg3-1, arg4-1, color);
                break;
            case 'F':
                cin >> arg1 >> arg2 >> color;
                pic.F_FillRegion(arg1-1, arg2-1, color);
                break;
            case 'S':
                cin >> name;
                pic.S_SaveAndDisplay(name);
                break;
            default:
                break;
        }
        cin >> command;
    }
    return 0;
}
