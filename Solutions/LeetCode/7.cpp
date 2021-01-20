class Solution {
public:
    
    int reverse(int x) {
        int ans = 0, sum;
        while(x){
            if (ans > 214748364 || ans < -214748364) return 0;
            sum = x%10;
            ans = ans * 10 + sum;
            x /= 10;
        }
        return ans;
    }
    
};
