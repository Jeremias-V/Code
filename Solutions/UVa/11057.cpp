#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int nBooks, temp, balance, i, j, lasti, lastj;
    vector <int> prices;
    while(cin >> nBooks){
        prices.clear();
        while(nBooks--){
            cin >> temp;
            prices.push_back(temp);
        }
        sort(prices.begin(), prices.end());
        cin >> balance;
        i = 0;
        j = prices.size()-1;
        while(i < j){
            if(prices[i] + prices[j] < balance){
                i++;
            }else if(prices[i] + prices[j] == balance){
                lasti = i++;
                lastj = j--; 
            }else{
                j--;
            }
        }
        cout << "Peter should buy books whose prices are " << prices[lasti] << " and " << prices[lastj] << ".\n\n";
    }
    return 0;
}