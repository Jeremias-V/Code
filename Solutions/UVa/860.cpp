#include<iostream>
#include<unordered_map>
#include<string>
#include<math.h>

using namespace std;

int main(){

    int i, totalWords = 0;
    double entropyT, entropyRel, entropyMax;
    unordered_map<string, int> words;
    unordered_map<string, int>::iterator it;
    string input, word;

    getline(cin, input);

    while(input != "****END_OF_INPUT****"){

        if(input == "****END_OF_TEXT****"){

            entropyT = 0.0;
            entropyMax = 0.0;
            entropyRel = 0.0;

            for(it = words.begin(); it != words.end(); it++){
                entropyT += ( (it->second) * (log10(totalWords) - log10(it->second)));
            }

            entropyT *= 1/(double)totalWords;
            entropyMax = log10(totalWords);
            entropyRel = (entropyT/entropyMax)*100.0;
            printf("%d %.1f %.0f\n", totalWords, entropyT, entropyRel);
            words = unordered_map<string, int>();
            totalWords = 0;

        }else{

            input += '.';
            word = "";

            for(i = 0; i < input.size(); i++){

                if(input[i] != ',' && input[i] != '.' &&
                   input[i] != ':' && input[i] != ';' && 
                   input[i] != '!' && input[i] != '?' &&
                   input[i] != '"' && input[i] != '(' &&
                   input[i] != ')' && input[i] != '\n' &&
                   input[i] != ' ' && input[i] != '\t'){

                       if(input[i] >= 'a' && input[i] <= 'z')
                            word += (input[i] - 32);
                        else
                            word += input[i];

                   }else if(word != ""){

                    totalWords++;
                    
                    if(words.find(word) == words.end())
                        words[word] = 1;
                    else
                        words[word]++;
                    
                    word = "";
                }
            }
        }
        getline(cin, input);
    }
    return 0;
}
