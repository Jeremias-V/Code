#include<iostream>
#include<queue>
#include<vector>
using namespace std;

int main(){
    int input, temp, sum, ans;
    vector <int> result;
    cin >> input;
    while(input != 0){
        result.clear();
        priority_queue <int, vector<int>, greater<int>> numbers;
        for(int i = 1; i <= input; i++){
            cin >> temp;
            numbers.push(temp);
        }
        ans = 0;
        while(numbers.size() > 1){
            sum = numbers.top();
            numbers.pop();
            sum += numbers.top();
            numbers.pop();
            numbers.push(sum);
            result.push_back(sum);
            ans += sum;
        }
        cout << ans << endl;
        cin >> input;
    }
    return 0;
}
