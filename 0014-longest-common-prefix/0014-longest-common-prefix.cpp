class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string pref=strs[0];
        for(int i=1;i<strs.size();i++){
            string curr=strs[i];
            int x=0;
            while(x<pref.size() && x<curr.size() &&  pref[x]==curr[x]){
                x++;
            }
            pref=pref.substr(0,x);
        }
        return pref;
    }
};