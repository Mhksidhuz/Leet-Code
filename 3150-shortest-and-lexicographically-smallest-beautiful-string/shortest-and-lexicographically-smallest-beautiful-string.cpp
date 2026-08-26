class Solution {
public:
    string shortestBeautifulSubstring(string s, int k) {
        
        int left = 0;
        int right = 0;
        int cnt1 = 0;
        string ans = "";

        while(right<s.size()){
            if(s[right]=='1') cnt1++;


            while(cnt1>k){
                if(s[left]=='1') cnt1--;
                left++;
            }
            if(cnt1==k){
                 while (left < right && s[left] == '0') {
                    left++;
                }

                string cur = s.substr(left, right - left + 1);

                if (ans == "" || cur.size() < ans.size() ||
                    (cur.size() == ans.size() && cur < ans)) {

                    ans = cur;
                }
            }
            right++;
        }
        return ans;
    }
};