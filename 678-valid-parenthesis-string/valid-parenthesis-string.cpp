class Solution {
public:
    bool checkValidString(string s) {
        
        int maxi = 0;
        int mini = 0;

        for(auto ch : s){

            if(ch=='('){
                mini = mini+1;
                maxi = maxi+1;
            }
            else if(ch==')'){
                mini = mini-1;
                maxi = maxi-1;
            }
            else{
                mini = mini-1;
                maxi = maxi+1;
            }
            if(mini<0) mini=0;
            if(maxi<0) return false;
        }
        return mini==0;
    }
};