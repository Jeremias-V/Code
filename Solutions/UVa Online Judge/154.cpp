#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;

int main(){
    vector<vector<string>> blocks;
    vector<string> buffer;
    string buff = "";
    unsigned maxBlock, score, lastScore;
    char input = getchar();
    while(input != '#'){
        score = 0;
        while(input != 'e'){
            if(input == ','){
                buffer.push_back(buff);
                buff = "";
            }else if(input == '\n'){
                buffer.push_back(buff);
                blocks.push_back(buffer);
                buffer.clear();
                buff = "";
            }else{
                buff += input;
            }
            input = getchar();
        }
        if(input == 'e'){
            if(blocks.size() == 1){
                cout << 1 << endl;
            }
            else{
                maxBlock = 1;
                for(int i = 0; i < blocks.size(); i++){
                    lastScore = 0;
                    for(int j = 0; j < blocks[i].size(); j++){
                        for(vector<vector<string>>::iterator it = blocks.begin(); it != blocks.end(); it++){
                            lastScore += count((*it).begin(), (*it).end(), blocks[i][j]);
                        }
                    }
                    if(lastScore > score){
                        score = lastScore;
                        maxBlock = i+1;
                    }
                }
                cout << maxBlock << endl;
            }
            while(input != '\n'){
                input = getchar();
            }
            buffer.clear();
            blocks.clear();
        }
        input = getchar();
    }
    return 0;
}