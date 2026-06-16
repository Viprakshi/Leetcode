class Solution {
public:
    string processStr(string s) {
        string ans="";
        for(int i=0;i<s.size();i++){
            if(s[i]>='a' && s[i]<='z'){
                ans+=s[i];
            }
            else if(s[i]=='*'){
                //remove last chr
                if(ans!="") ans.pop_back();
            }
            else if(s[i]=='#') ans+=ans;
            else{
                //if(ans!="")
                reverse(ans.begin(), ans.end());
            }
        }
        return ans;
    }
};