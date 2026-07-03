class Solution {
public:
    int romanToInt(string s) {
        unordered_map<char, int> mpp={{'I',1},{'V',5},{'X',10},{'L',50},{'C',100},{'D',500},{'M',1000}};
        int ans=mpp[s[0]];
        for(int i=1;i<s.length();i++){
            if(mpp[s[i]]<=mpp[s[i-1]]){
                ans+=mpp[s[i]];
            }
            else{
                ans+=mpp[s[i]];
                ans-=(2*mpp[s[i-1]]);
            }
        }
        return ans;

    }
};