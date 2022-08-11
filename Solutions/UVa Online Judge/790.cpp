#include<iostream>
#include<vector>
#include<string>
#include<sstream>
#include<algorithm>
#include<iomanip>
#include<queue>
using namespace std;

class Submission{

    public:

    int teamID;
    int time;
    char problem;
    char accepted;

    Submission(int t, string tmpTime, char p, char acc){
        teamID = t;
        problem = p;
        time = 0;
        accepted = acc;
        string tmp = "";
        for(int i = 0; i <= tmpTime.size(); i++){
            if(i == tmpTime.size()){
                time += stoi(tmp);
            }
            else if(tmpTime[i] != ':'){
                tmp += tmpTime[i];
            }else{
                time += (stoi(tmp)*60);
                tmp = "";
            }
        }
    }

};

class Team{

    public:

    int team;
    int time;
    vector<char> solved;
    vector<char> rejected;

    Team(){
        time = 0;
    }

};

bool cmp(Team t1, Team t2){
    if(t1.solved.size() == t2.solved.size()){
        if(t1.time == t2.time)
            return t1.team < t2.team;
        else
            return t1.time < t2.time;
    }else{
        return t1.solved.size() > t2.solved.size();
    }
}

bool operator==(Team t, char p){
    vector<char>::iterator it = t.solved.begin();
    it = find(t.solved.begin(), t.solved.end(), p);
    if(it != t.solved.end()){
        return true;
    }else{
        return false;
    }
}

bool operator<(Submission s1, Submission s2){
    if(s1.time == s2.time){
        if(s1.teamID == s2.teamID){
            if(s1.problem == s2.problem){
                return s1.accepted > s2.accepted;
            }else{
                return s1.problem < s2.problem;
            }
        }else{
            return s1.teamID > s2.teamID;
        }
    }
    return s1.time > s2.time;
}

int main(){
    cin.tie(NULL);
    priority_queue<Submission> submissions;
    vector<Team> teams;
    vector<Team>::iterator it, next_it;
    vector<char>::iterator itc;
    int testCases, tmpTeam, rank, lastRank, max = -1, i;
    char tmpProblem, tmpSolved;
    bool nextEqual;
    string tmpTime, outSolved, outTime;
    cin >> testCases;
    getchar(), getchar();
    string input;
    while(testCases > 0){

        getline(cin, input);

        if(input == ""){

            teams = vector<Team>(max);

            for(i = 0; i < teams.size(); i++){
                teams[i].team = i+1;
            }
            while(!submissions.empty()){
                i = submissions.top().teamID - 1;
                if(!(teams[i] == submissions.top().problem) && submissions.top().accepted == 'Y'){
                    teams[i].solved.push_back(submissions.top().problem);
                    teams[i].time += submissions.top().time;
                    for(itc = teams[i].rejected.begin(); itc != teams[i].rejected.end(); itc++){
                        if(*itc == submissions.top().problem)
                            teams[i].time += 20;
                    }
                }else if(submissions.top().accepted == 'N'){
                    teams[i].rejected.push_back(submissions.top().problem);
                }

                submissions.pop();

            }

            rank = 1;
            lastRank = 1;
            sort(teams.begin(), teams.end(), cmp);
            cout << "RANK TEAM PRO/SOLVED TIME\n";
            for(it = teams.begin(); it != teams.end(); it++){
                next_it = next(it, 1);
                nextEqual = false;
                if(next_it != teams.end()){
                    if((next_it->solved.size() == it->solved.size()) && (next_it->time == it->time))
                        nextEqual = true;
                }
                outSolved = (it->solved.size() > 0) ? to_string(it->solved.size()) : "";
                outTime = (it->solved.size() > 0) ? to_string(it->time) : "";
                cout << setw(4) << right << rank << setw(5) << right << it->team;
                if(outSolved != ""){
                    cout << setw(5) << right << outSolved << setw(11) << right << outTime<< endl;
                }else{
                    cout << endl;
                }
                lastRank++;
                if(!nextEqual) rank = lastRank;
            }

            testCases--;
            max = -1;
            if(testCases > 0) cout << "\n";

        }else{

            stringstream s(input);
            s >> tmpTeam >> tmpProblem >> tmpTime >> tmpSolved;
            max = (tmpTeam > max) ? tmpTeam : max; 
            submissions.push(Submission(tmpTeam, tmpTime, tmpProblem, tmpSolved));

        }

    }
    return 0;
}
