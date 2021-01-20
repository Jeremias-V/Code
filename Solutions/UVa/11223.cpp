#include<iostream>
#include<string>
#include<cstdio>
using namespace std;

string getMorse(string buffer){
    string result = "";
    if(buffer == ".-"){
        result += 'A';
    }else if(buffer == "-..."){
        result += 'B';
    }else if(buffer == "-.-."){
        result += 'C';
    }else if(buffer == "-.."){
        result += 'D';
    }else if(buffer == "."){
        result += 'E';
    }else if(buffer == "..-."){
        result += 'F';
    }else if(buffer == "--."){
        result += 'G';
    }else if(buffer == "...."){
        result += 'H';
    }else if(buffer == ".."){
        result += 'I';
    }else if(buffer == ".---"){
        result += 'J';
    }else if(buffer == "-.-"){
        result += 'K';
    }else if(buffer == ".-.."){
        result += 'L';
    }else if(buffer == "--"){
        result += 'M';
    }else if(buffer == "-."){
        result += 'N';
    }else if(buffer == "---"){
        result += 'O';
    }else if(buffer == ".--."){
        result += 'P';
    }else if(buffer == "--.-"){
        result += 'Q';
    }else if(buffer == ".-."){
        result += 'R';
    }else if(buffer == "..."){
        result += 'S';
    }else if(buffer == "-"){
        result += 'T';
    }else if(buffer == "..-"){
        result += 'U';
    }else if(buffer == "...-"){
        result += 'V';
    }else if(buffer == ".--"){
        result += 'W';
    }else if(buffer == "-..-"){
        result += 'X';
    }else if(buffer == "-.--"){
        result += 'Y';
    }else if(buffer == "--.."){
        result += 'Z';
    }else if(buffer == "-----"){
        result += '0';
    }else if(buffer == ".----"){
        result += '1';
    }else if(buffer == "..---"){
        result += '2';
    }else if(buffer == "...--"){
        result += '3';
    }else if(buffer == "....-"){
        result += '4';
    }else if(buffer == "....."){
        result += '5';
    }else if(buffer == "-...."){
        result += '6';
    }else if(buffer == "--..."){
        result += '7';
    }else if(buffer == "---.."){
        result += '8';
    }else if(buffer == "----."){
        result += '9';
    }else if(buffer == ".-.-.-"){
        result += '.';
    }else if(buffer == "--..--"){
        result += ',';
    }else if(buffer == "..--.."){
        result += '?';
    }else if(buffer == ".----."){
        result += "'";
    }else if(buffer == "-.-.--"){
        result += '!';
    }else if(buffer == "-..-."){
        result += '/';
    }else if(buffer == "-.--."){
        result += '(';
    }else if(buffer == "-.--.-"){
        result += ')';
    }else if(buffer == ".-..."){
        result += '&';
    }else if(buffer == "---..."){
        result += ':';
    }else if(buffer == "-.-.-."){
        result += ';';
    }else if(buffer == "-...-"){
        result += '=';
    }else if(buffer == ".-.-."){
        result += '+';
    }else if(buffer == "-....-"){
        result += '-';
    }else if(buffer == "..--.-"){
        result += '_';
    }else if(buffer == ".-..-."){
        result += '"';
    }else if(buffer == ".--.-."){
        result += '@';
    }
    return result;
}

int main(){
    int testCases, count = 1, spaceCount;
    string result, buffer;
    char input;
    cin >> testCases;
    getchar();
    while(testCases--){
        result = "";
        buffer = "";
        spaceCount = 0;
        input = getchar();
        while(input != '\n'){
            if(input == ' '){
                spaceCount++;
                result += getMorse(buffer);
                if(spaceCount > 1){
                    result += ' ';
                    spaceCount = 0;
                }
                buffer = "";
            }else{
                spaceCount = 0;
                buffer += input;
            }
            if(spaceCount > 1){
                result += ' ';
            }
            input = getchar();
        }
        result += getMorse(buffer);
        cout << "Message #" << count++ << endl;
        cout << result << endl;
        if(testCases > 0){
            cout << endl; 
        }
    }
    return 0;
}