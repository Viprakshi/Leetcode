class Solution {
public:
    string largestOddNumber(string s) {
        string res;
        for(int i=s.length();i>=0;i--){
            if((s[i]-'0')%2==1){
             res=s.substr(0, i+1);
             break;
            }
        }
        return res;
    }

};
