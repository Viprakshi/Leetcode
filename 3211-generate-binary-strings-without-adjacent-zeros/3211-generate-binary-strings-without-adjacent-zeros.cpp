class Solution {
public:
    void generate(int n, vector<string>& ans,string curr,int i){
        if(i==n){
            ans.push_back(curr);
            return;
        }
        generate(n,ans,curr+"1",i+1);
        if(curr=="" || curr[curr.size()-1]!='0'){
            generate(n,ans,curr+"0",i+1);
        }
    }
    vector<string> validStrings(int n) {
        vector<string> ans;
        generate(n,ans,"",0);
        return ans;
    }
};