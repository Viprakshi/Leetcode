class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        
        string pref=strs[0];
        for(int i=1;i<strs.size();i++){
            string comp=strs[i];
            int j=0;
            while(pref[j]==comp[j] && j<comp.length()){
                j++;
            }
            if(j==0) return "";
            pref=pref.substr(0,j);
        }
        return pref;
    }
};