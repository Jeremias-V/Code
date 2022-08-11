#include<iostream>
#include<vector>
#include<string>
using namespace std;

void efficientCIN(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    return;
}

int main(){
    efficientCIN();
    string card;
    cin >> card;
    vector<vector<string>> cards;
    vector<vector<string>>::iterator it;
    while(card.at(0) != '#'){
        cards.clear(), cards.resize(52);
        it = cards.begin();
        it->push_back(card);
        it++;
        while(it != cards.end()){
            cin >> card;
            (it++)->push_back(card);
        }
        it = cards.begin();
        while(it != cards.end()){
            if(it-3 >= cards.begin()){
                if(it->back()[0] == (it-3)->back()[0] || it->back()[1] == (it-3)->back()[1]){
                    (it-3)->push_back((it)->back());
                    it->pop_back();
                    if(it->empty()){
                        cards.erase(it);
                    }
                    it-=4;
                }
            }if(it-1 >= cards.begin()){
                if(it->back()[0] == (it-1)->back()[0] || it->back()[1] == (it-1)->back()[1]){
                    (it-1)->push_back(it->back());
                    it->pop_back();
                    if(it->empty()){
                        cards.erase(it);
                    }
                it-=2;
                }
            }
            it++;
        }
        if(cards.size() > 1){
            cout << cards.size() << " piles remaining:";
        }else{
            cout << cards.size() << " pile remaining:";
        }
        for(it = cards.begin(); it != cards.end(); it++){
            cout << " " << it->size();
        }
        cout << endl;
        cin >> card;
    }
    return 0;
}