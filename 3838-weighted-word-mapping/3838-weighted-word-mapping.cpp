class Solution {
public:
    string mapWordWeights(vector<string>& words, vector<int>& weights) {
       vector<int> vals;
        for(auto word: words){
            int val=0;
            for(auto letter: word){
                val+=weights[letter-'0'-49];
            }
            vals.push_back(val);
        }

        string ans="";
        for(auto val:vals){
            val=val%26;
            char x=('a'+(25-val));
            ans+=x;
        }
        return ans;
    }
};