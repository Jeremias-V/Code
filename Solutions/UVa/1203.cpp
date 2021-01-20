#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

struct Query{
    int id;
    int period;
    int period_copy;
};

bool compare(Query e1, Query e2){
    if(e1.period == e2.period){
        return e1.id < e2.id;
    }
    return e1.period < e2.period;
}

int main(){
    int qNum, id, period, count = 1, seconds = 1, iterQ = 0;
    bool first = true;
    string reg;
    cin >> reg;
    Query queries[1001];
    while(reg != "#"){
        if(first){
            cin >> queries[iterQ].id >> queries[iterQ].period;
            queries[iterQ].period_copy = queries[iterQ].period;
            iterQ++;
            first = false;
        }else{
            cin >> reg;
            if(reg == "#"){
                break;
            }
            cin >> queries[iterQ].id >> queries[iterQ].period;
            queries[iterQ].period_copy = queries[iterQ].period;
            iterQ++;
        }
    }
    sort(queries, queries+iterQ, compare);
    cin >> qNum;
    while(count <= qNum){
        for(int i = 0; i < iterQ; i++){
            if(queries[i].period == seconds){
                cout << queries[i].id << endl;
                queries[i].period += queries[i].period_copy;
                count++;
                if(count > qNum){
                    break;
                    cout << endl;
                }
            }
        }
        sort(queries, queries+iterQ, compare);
        seconds++;
    }
    return 0; 
}