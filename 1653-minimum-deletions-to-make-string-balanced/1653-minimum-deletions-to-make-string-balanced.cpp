class Solution {
public:
    int minimumDeletions(string s) {
        int count=0;     
        int count_b=0;
        
        for (int i=0;i<s.length();i++) {
            if (s[i]=='b'){
                count_b++; 
            } 
            else{
                count = min(count + 1, count_b);
            }
        }
        return count;
    }
};
