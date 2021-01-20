#include<iostream>
#include<string>
#include<map>
#include<vector>
using namespace std;

struct Info{
	string name;
	int balance = 0;
	int money;
	int gives;
	vector<string> friends;
};

int main(){
	string name, tempFriend;
	bool first = true;
	int nGroups, gives;
	cin >> nGroups;
	while(!cin.eof()){
		if(!first){
			cout << endl;
		}
		first = false;
		map<string, Info> person;
		Info info;
		vector<string> nameOrder;
		for(int i = 0; i < nGroups; i++){
			cin >> name;
			nameOrder.push_back(name);
			person.insert(make_pair(name, info));
			person[name].name = name;
		}
		for (int i = 0; i < nGroups; i++){
			cin >> name;
			cin >> person[name].money;
			cin >> gives;
			person[name].gives = gives;
			for(int j = 0; j < gives; j++){
				cin >> tempFriend;
				person[name].friends.push_back(tempFriend);
				person[person[name].friends[j]].balance += person[name].money/person[name].gives;
				person[name].balance -= person[name].money/person[name].gives;
			}
		}
		for(int i = 0; i < nameOrder.size(); i++){
			cout << person[nameOrder[i]].name << " " << person[nameOrder[i]].balance << endl;
		}
		cin >> nGroups;
	}
	return 0;
}