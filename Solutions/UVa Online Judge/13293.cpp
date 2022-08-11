#include<iostream>
#include<vector>
#include<string>
#include<algorithm>

using namespace std;

class Player{
    public:
    string name;
    string nameLower;
    int totalPoints;

    Player(string n, string nL){
        name = n;
        nameLower = nL;
        totalPoints = 0;
    }

};

bool cmp(Player p1, Player p2){
    if(p1.totalPoints == p2.totalPoints){
        return p1.nameLower < p2.nameLower;
    }else{
        return p1.totalPoints > p2.totalPoints;
    }
}

int main(){

    int testCases, caseCount = 1, i, j;
    string tmp, name, nameLower;
    vector<Player> players;

    while(cin >> testCases){

        getchar();
        players.clear();

        for(i = 0; i < testCases; i++){

            getline(cin, tmp);
            name = "";
            nameLower = "";

            for(j = 0; j < tmp.size(); j++){
                if(tmp[j] == ';'){
                    break;
                }
                if(tmp[j] >= 97 && tmp[j] <= 122){
                    nameLower += tmp[j];
                }else{
                    nameLower += (tmp[j] + 32);
                }
                name += tmp[j];
            }

            Player tmpPlayer(name, nameLower);
            players.push_back(tmpPlayer);

            for(j; j < tmp.size(); j++){
                if(tmp[j] == '1'){
                    if(tmp[j+1] == ';' || j+1 == tmp.size()){
                        players[i].totalPoints += 2;
                    }else{
                        players[i].totalPoints += 1;
                    }
                }
            }
        }

        sort(players.begin(), players.end(), cmp);
        cout << "Case " << caseCount++ << ":\n";
        for(int i = 0; i < players.size(); i++){
            cout << players[i].name << ' ' << players[i].totalPoints << '\n';
        }
    }
    return 0;
}