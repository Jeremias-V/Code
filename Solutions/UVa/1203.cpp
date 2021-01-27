#include<iostream>
#include<queue>
#include<string>

using namespace std;

class Query{
    public:
    int qnum;
    int period;
    int ogPeriod;

    Query(int q, int p){
        qnum = q;
        period = p;
        ogPeriod = p;
    };
    
};

bool operator<(const Query& q1, const Query& q2){
    
    if(q1.period == q2.period){
        return q1.qnum > q2.qnum;
    }else{
        return q1.period > q2.period;
    }

}

int main(){

    string input, tmp;
    int i, K, tmpID, tmpPeriod;
    bool first;
    priority_queue<Query> queries;

    while(getline(cin, input)){

        if(input[0] == '#'){

            cin >> K;
            while(K-- > 0){
                Query tmpQ = queries.top();
                cout << tmpQ.qnum << endl;
                queries.pop();
                tmpQ.period += tmpQ.ogPeriod;
                queries.push(tmpQ);
            }

        }else if(input[0] == 'R'){

            tmp = "";
            first = true;
            for(i = 9; i <= input.size(); i++){
                if((input[i] == ' ' || i == input.size()) && tmp != ""){
                    if(first){
                        first = false;
                        tmpID = stoi(tmp);
                    }else{
                        tmpPeriod = stoi(tmp);
                    }
                    tmp = "";
                }else if(input[i] != ' '){
                    tmp += input[i];
                }
            }
            queries.push(Query(tmpID, tmpPeriod));
            
        }
    }
    return 0;
}