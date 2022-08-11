#include<iostream>
#include<deque>
#include<algorithm>
#include<string>

using namespace std;

void processN(int &current, int &P, deque<int> &Q){
    deque<int>::iterator it;
    if(current > P){
        cout << Q.front() << endl;
        Q.push_back(Q.front());
        Q.pop_front();
    }else{
        it = find(Q.begin(), Q.end(), current);
        if(it != Q.end()){
            current++;
            processN(current, P, Q);
        }else{
            cout << current << endl;
            Q.push_back(current);
        }
    }
}

int main(){
    deque<int> Q, emergency;
    deque<int>::iterator it;
    int P, C, x, current, caseCount = 1;
    string instruction, tmp;
    cin >> P >> C;
    while(P && C){
        current = 1;
        cout << "Case " << caseCount++ << ':' << endl;
        while(C-- >= 0){
            getline(cin, instruction);
            if(instruction[0] == 'N'){
                if(!emergency.empty()){
                    cout << emergency.front() << endl;
                    it = find(Q.begin(), Q.end(), emergency.front());
                    if(it != Q.end()){
                        Q.erase(it);
                    }
                    Q.push_back(emergency.front());
                    emergency.pop_front();
                }else{
                    processN(current, P, Q);
                }
            }else if(instruction[0] == 'E'){
                tmp = instruction.substr(2, instruction.size());
                x = stoi(tmp, nullptr, 10);
                it = find(Q.begin(), Q.end(), x);
                if(it != Q.end()){
                    Q.erase(it);
                }
                it = find(emergency.begin(), emergency.end(), x);
                if(it != emergency.end()){
                    emergency.erase(it);
                }
                emergency.push_front(x);
            }
        }
        Q.clear();
        emergency.clear();
        cin >> P >> C;
    }
    return 0;
}