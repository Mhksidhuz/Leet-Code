class Solution {
public:
    int smallestNumber(int n, int t) {
        
        int ans = n;

        while(true){
            int product = 1;
            int number = ans;

            while(number){
                product  *= (number%10);
                number/=10;
            }
            if(product%t==0) break;
            else ans++;
        }
        return ans;
    }
};