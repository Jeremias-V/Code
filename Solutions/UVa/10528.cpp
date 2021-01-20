#include<iostream>
#include<string>
#include<vector>
#include<algorithm>

using namespace std;

vector<string> divide(string p){
	vector<string> result;
	string temp;
	for(int i = 0; i < p.size(); i++){
		if(p.at(i) == ' '){
			result.push_back(temp);
			temp.clear();
		}
		else if(p.at(i) == '|'){
			result.push_back(temp);
			temp.clear();
		}
		else{
			temp += p.at(i);
		}
	}
    return result;
}

string allScalesN(string n){
    if(n == "C")
    return "C C# D# F G G# A# ";
    else if(n == "C#")
    return "C# D E F# G# A B ";
    else if(n == "D")
    return "C D D# F G A A# ";
    else if(n == "D#")
    return "C# D# E F# G# A# B ";
    else if(n == "E")
    return "C D E F G A B ";
    else if(n == "F")
    return "C C# D# F F# G# A# ";
    else if(n == "F#")
    return "C# D E F# G A B ";
    else if(n == "G")
    return "C D D# F G G# A# ";
    else if(n == "G#")
    return "C# D# E F# G# A B ";
    else if(n == "A")
    return "C D E F G A A# ";
    else if(n == "A#")
    return "C# D# F F# G# A# B ";
    else if(n == "B")
    return "C D E F# G A B ";
    else
    return " ";
}

void getResult(string n, int repeat){
    string print = "";
    if(repeat == 1){
        cout << n;
    }
    else if(repeat > 1){
        n += "|";
        vector<string> result = divide(n);
        int coun = 0;
        for(int i = 0; i < result.size(); i++){
            string last = result[i];
            coun = count(result.begin()+i, result.end(), last);
            if(coun == repeat){
                print += last + " ";
                coun = 0;
            }
            else{
                coun = 0;
            }
        }
        if(print.size() > 1){
            print.erase(print.size()-1);
            cout << print;
        }        
    }
}

void filter(string n){
    vector<string> result = divide(n);
    string temp;
    for(int i = 0; i < result.size(); i++){
        temp += allScalesN(result[i]);
    }
    temp.erase(temp.size()-1);
    getResult(temp, result.size());
}

int main(){
    string input;
    getline(cin, input);
    while(input.compare("END")){
        input += "|";
        filter(input);
        cout << endl;
        getline(cin, input);
    }
    return 0;
}