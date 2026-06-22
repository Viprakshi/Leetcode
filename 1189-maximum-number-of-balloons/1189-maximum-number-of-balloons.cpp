class Solution {
public:
    int maxNumberOfBalloons(string text) {
        //balloon
        unordered_map<char,int> mpp;
        for(int i=0;i<text.length();i++){
            mpp[text[i]]++;
        }
        int ans=INT_MAX;
        string x="balloon";
        for(int i=0;i<x.length();i++){
            if(x[i]=='o' || x[i]=='l') ans=min(ans,mpp[x[i]]/2);
            ans=min(ans, mpp[x[i]]);
        }
        return ans;
        
    }
};