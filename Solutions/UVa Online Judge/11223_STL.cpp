#include<iostream>
#include<string>
#include<algorithm>
#include<cstdio>
using namespace std;

string getMorse(string buffer){
    string result = "";
    const string morse[] = {".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..", ".---",
                            "-.-", ".-..", "--", "-.", "---", ".--.", "--.-", ".-.", "...", "-",
                            "..-", "...-", ".--", "-..-", "-.--", "--..", "-----", ".----", "..---",
                            "...--", "....-", ".....", "-....", "--...", "---..", "----.", ".-.-.-", "--..--",
                            "..--..", ".----.", "-.-.--", "-..-.", "-.--.", "-.--.-", ".-...", "---...", "-.-.-.",
                            "-...-", ".-.-.", "-....-", "..--.-", ".-..-.", ".--.-."};
    const short morse_size = sizeof(morse)/sizeof(string);
    const char translation[] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M',
                                'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z',
                                '0', '1', '2', '3', '4', '5', '6', '7', '8', '9', '.', ',', '?',
                                char(39), '!', '/', '(', ')', '&', ':', ';', '=', '+', '-', '_', '"', '@'};
    const short tra_size = sizeof(translation)/sizeof(char);
    auto it = find(morse, morse+morse_size, buffer);
    if(it == morse+morse_size){
        return result;
    }else{
        result += translation[it-morse];
        return result;
    }
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