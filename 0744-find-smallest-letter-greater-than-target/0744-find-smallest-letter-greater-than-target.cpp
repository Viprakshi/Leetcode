class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        char ans=letters[0];
        sort(letters.begin(),letters.end());
        int max_len=INT_MAX;
        
        for(int i=letters.size()-1;i>=0;i--){
            int dist=(letters[i]-'A'+1) - (target-'A'+1);
            if( dist>0 && dist<max_len && letters[i]!=target){
                max_len=dist;
                ans=letters[i];
            }
        }
        return ans;
    }
};