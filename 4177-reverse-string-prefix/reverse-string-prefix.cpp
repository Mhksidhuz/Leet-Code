class Solution {
public:
    string reversePrefix(string s, int k) {
        
        int right = 0;
        int left = k-1;

        while(right<left){
            swap(s[right],s[left]);
            right++;
            left--;
        }
        return s;
    }
};