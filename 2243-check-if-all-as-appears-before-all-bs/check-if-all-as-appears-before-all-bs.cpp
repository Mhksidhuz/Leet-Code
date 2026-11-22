class Solution {
public:
    bool checkString(string s) {
        
        int n = s.size();
        int index = -1;

        for(int i=0;i<n;i++){

            if(index==-1 && s[i]=='b'){
                index = i;
            }

            if(s[i]=='a' && index!=-1 && i>index){
                return false;
            }
        }
        return true;
    }
};