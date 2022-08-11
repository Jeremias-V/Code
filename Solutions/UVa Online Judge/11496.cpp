#include<iostream>
#include<vector>

using namespace std;

int main(){
    
    int N, i, peaks, tmpNum;
    bool increasing, decreasing, isNegative;
    string input, tmp;

    while(scanf("%d\n", &N) && N != 0){

        vector<int> samples;
        peaks = 0;
        increasing = decreasing = isNegative = false;
        getline(cin, input);
        tmp = "";

        for(i = 0; i <= input.size(); i++){
            if(input[i] == '-'){
                isNegative = true;
            }else if(input[i] >= '0' && input[i] <= '9'){
                tmp += input[i];
            }else if(input[i] == ' ' || i == input.size()){
                tmpNum = stoi(tmp);
                if(isNegative) samples.push_back((tmpNum * -1));
                else samples.push_back(tmpNum);
                tmp = "";
                isNegative = false;
            }
        }

        if(samples[N-1] < samples[0]) increasing = true;
        else decreasing = true;
        samples.push_back(samples[0]);

        for(i = 1; i <= N; i++){
            if(samples[i-1] < samples[i] && decreasing){
                decreasing = false;
                increasing = true;
                peaks++;
            }else if(samples[i-1] > samples[i] && increasing){
                increasing = false;
                decreasing = true;
                peaks++;
            }
        }

        cout << peaks << '\n';
    }
    return 0;
}