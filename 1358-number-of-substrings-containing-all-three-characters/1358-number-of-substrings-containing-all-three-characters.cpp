class Solution {
public:
    int atmost(string s, int k){
        unordered_map<char, int> mpp;
        int i=0, j=0, ans=0;
        while(j<s.length()){
            mpp[s[j]]++;
            while(mpp.size()>k){
                mpp[s[i]]--;
                if(mpp[s[i]]==0) mpp.erase(s[i]);
                i++;
            }
            ans+=(j-i+1);
            j++;
        }
        return ans;
    }
    int numberOfSubstrings(string s) {
        return atmost(s,3)-atmost(s,2);
    }
};