#include <iostream>
#include <list>
using namespace std;

int main(){
    list<char> lst;
    list<char>::iterator it = lst.end();
    char currentChar = getchar();
    while(currentChar != EOF){
        while(currentChar != '\n'){
            if(currentChar == '['){
                it = lst.begin();
            }else if(currentChar == ']'){
                it = lst.end();
            }else{
                lst.insert(it, currentChar);
            }
            currentChar = getchar();
        }
        for(it = lst.begin(); it != lst.end(); it++){
            cout << *it;
        }
        cout << endl;
        lst.clear();
        it = lst.end();
        currentChar = getchar();
    }
    return 0;
}
