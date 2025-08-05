class Solution {
public:
    vector<string> generateParenthesis(int n) {
      vector<string> res;
      generate(n,"",res,0,0);
      return res;  
    }
    void generate(int n, string curr, vector<string>& res, int open_count,int close_count){
        if(curr.length()==2*n){
            res.push_back(curr);
            return;
        }
        if(open_count<n){
            generate(n,curr+"(",res,open_count+1,close_count);
        }
        if(close_count<open_count){
            generate(n,curr+")",res,open_count,close_count+1);
        }

    }
};