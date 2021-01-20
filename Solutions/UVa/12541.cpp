#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
using namespace std;

class BirthDates{
    public:
    string name;
    unsigned day, month, year;
};

bool comp(BirthDates b1, BirthDates b2){
    if(b1.year != b2.year){
        return b1.year < b2.year;
    }else if(b1.month != b2.month){
        return b1.month < b2.month;
    }else{
        return b1.day < b2.day;
    }
}

int main(){
    unsigned testCases, dd, mm, yyyy;
    string tempName;
    cin >> testCases;
    vector<BirthDates> dates(testCases);
    for(int i = 0; i < testCases; i++){
        cin >> dates[i].name >> dates[i].day >> dates[i].month >> dates[i].year;
    }
    sort(dates.begin(), dates.end(), comp);
    cout << dates[testCases-1].name << endl << dates[0].name << endl;
    return 0;
}