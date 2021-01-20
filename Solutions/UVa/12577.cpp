#include<iostream>
#include<string>
using namespace std;

int main(){
    int count = 0;
    string input;
    getline(cin, input);
    while(input.at(0) != '*'){
        if(input == "Hajj"){
            cout << "Case " << ++count << ": Hajj-e-Akbar" << endl;
        }else if(input == "Umrah"){
            cout << "Case " << ++count << ": Hajj-e-Asghar" << endl;
        }
        getline(cin, input);
    }
    return 0;
}