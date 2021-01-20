#include<iostream>
#include<string>
#include<vector>
using namespace std;

int main(){
    int wireLen;
    vector<string> segment;
    string orientation, bend, buffer;
    cin >> wireLen;
    while(wireLen != 0){
        segment.clear();
        getchar();
        getline(cin, bend);
        bend += '\n';
        buffer = "";
        for(int i = 0; i < bend.size(); i++){
            if(bend[i] != ' ' && bend[i] != '\n'){
                buffer += bend[i];
            }else{
                segment.push_back(buffer);
                buffer = "";
            }
        }
        orientation = "+x";
        for(int i = 0; i < segment.size(); i++){
            if(orientation == "+x"){
                if(segment[i] == "+z"){
                    orientation = "+z";
                }else if(segment[i] == "-z"){
                    orientation = "-z";
                }else if(segment[i] == "+y"){
                    orientation = "+y";
                }else if(segment[i] == "-y"){
                    orientation = "-y";
                }
            }else if(orientation == "-x"){
                if(segment[i] == "+z"){
                    orientation = "-z";
                }else if(segment[i] == "-z"){
                    orientation = "+z";
                }else if(segment[i] == "+y"){
                    orientation = "-y";
                }else if(segment[i] == "-y"){
                    orientation = "+y";
                }
            }else if(orientation == "+y"){
                if(segment[i] == "+y"){
                    orientation = "-x";
                }else if(segment[i] == "-y"){
                    orientation = "+x";
                }
            }else if(orientation == "-y"){
                if(segment[i] == "+y"){
                    orientation = "+x";
                }else if(segment[i] == "-y"){
                    orientation = "-x";
                }
            }else if(orientation == "+z"){
                if(segment[i] == "+z"){
                    orientation = "-x";
                }else if(segment[i] == "-z"){
                    orientation = "+x";
                }
            }else if(orientation == "-z"){
                if(segment[i] == "+z"){
                    orientation = "+x";
                }else if(segment[i] == "-z"){
                    orientation = "-x";
                }
            }
        }
        cout << orientation << endl;
        cin >> wireLen;
    }
    return 0;
}