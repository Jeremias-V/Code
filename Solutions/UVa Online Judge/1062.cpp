#include<iostream>
#include<string>
#include<stack>
#include<queue>
#include<vector>

using namespace std;

int main(){
    string input;
    int caseCount = 1;
    queue<char> arrival;
    vector<stack<char>> minStacks;
    bool foundSpace = false;
    int i;

    cin >> input;
    while(input != "end"){

        for(int i = 0; i < input.size(); i++){
            arrival.push(input[i]);
        }

        stack<char> tmp;
        tmp.push(arrival.front());
        arrival.pop();
        minStacks.push_back(tmp);

        while(!arrival.empty()){
            i = 0;
            while(i < minStacks.size() && !arrival.empty()){
                if(arrival.front() <= minStacks[i].top()){
                    foundSpace = true;
                    minStacks[i].push(arrival.front());
                    arrival.pop();
                    i = 0;
                }else{
                    i++;
                }
            }
            if(!foundSpace && !arrival.empty()){
                tmp = stack<char>();
                tmp.push(arrival.front());
                arrival.pop();
                minStacks.push_back(tmp);
            }
            foundSpace = false;
        }

        cout << "Case " << caseCount++ << ": " << minStacks.size() << endl;
        minStacks.clear();
        cin >> input;
    }
    return 0;
}