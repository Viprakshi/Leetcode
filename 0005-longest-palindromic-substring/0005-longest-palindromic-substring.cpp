class Solution {
public:
    string longestPalindrome(string s) {
        string ans="";
        int length=0;
        for(int i=0;i<s.length();i++){
            //odd length
            int left=i, right=i;
            while(left>=0 && right<s.length() && s[left]==s[right]){
                left--;
                right++;
            }
            if(right-left-1>length) ans=s.substr(left+1,right-left-1);
            length=max(length, right-left-1);

            //even length
            left=i, right=i+1;
            while(left>=0 && right<s.length() && s[left]==s[right]){
                left--;
                right++;
            }
            if(right-left-1>length) ans=s.substr(left+1,right-left-1);
            length=max(length,right-left-1);
        }
        return ans;
    }
};