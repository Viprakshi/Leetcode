class Solution {
public:
    string longestPalindrome(string s) {
        int maxi=0;
        string ans;
        for(int i=0;i<s.length();i++){
            
            int x=i, y=i;
            while(x>=0 && y<s.length() && s[x]==s[y]){
                int len=y-x+1;
                if(len>maxi){
                    maxi=len;
                    ans=s.substr(x,len);
                }
                x--;
                y++;
            }
            if(i<s.length()-1 && s[i]==s[i+1]){
                x=i, y=i+1;
                while(x>=0 && y<s.length() && s[x]==s[y]){
                    int len=y-x+1;
                if(len>maxi){
                    maxi=len;
                    ans=s.substr(x,len);
                }
                x--;
                y++; 
                }
            }
        }
        return ans;
    }
};