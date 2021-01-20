#include<iostream>
#include<string>
#include<cstdio>
#include<map>
using namespace std;

int main(){
    int testCases, numTeles;
    char input;
    bool found, first = true;
    string numTele;
    map <string, int> allTele;
    map <char, char> keypad = {{'A', '2'}, {'B', '2'}, {'C', '2'}
                             , {'D', '3'}, {'E', '3'}, {'F', '3'}
                             , {'G', '4'}, {'H', '4'}, {'I', '4'}
                             , {'J', '5'}, {'K', '5'}, {'L', '5'}
                             , {'M', '6'}, {'N', '6'}, {'O', '6'}
                             , {'P', '7'}, {'R', '7'}, {'S', '7'}
                             , {'T', '8'}, {'U', '8'}, {'V', '8'}
                             , {'W', '9'}, {'X', '9'}, {'Y', '9'}};
    cin >> testCases;
    while(testCases--){
        cin >> numTeles;
        getchar();
        found = false;
        if(!first){
            cout << endl;
        }else{
            first = false;
        }
        while(numTeles--){
            numTele = "";
            input = getchar();
            while(input != '\n'){
                while(input == '-' || input == ' '){
                    input = getchar();
                }
                if(input == '\n'){
                        break;
                    }
                if(input > 64 && input < 90 && input != 81){
                    input = keypad[input];
                }
                numTele += input;
                input = getchar();
                if(input == EOF){
                    break;
                }
            }
            if(allTele.find(numTele) == allTele.end()){
                allTele.insert(make_pair(numTele, 1));
            }else{
                allTele[numTele]++;
                found = true;
            }
        }
        if(found){
            for (auto const& tele : allTele){
            if(tele.second > 1){
                for(int i = 0; i < tele.first.size(); i++){
                    if(i == 3){
                        cout << '-';
                    }
                    cout << tele.first[i];
                }
                cout << " " << tele.second << endl;
            }
            }
        }else{
            cout << "No duplicates." << endl;
        }
        allTele.clear();
    }
    return 0;
}