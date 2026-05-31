class Solution {
public:
    int matchPlayersAndTrainers(vector<int>& players, vector<int>& trainers) {
        sort(players.begin(), players.end());
        sort(trainers.begin(), trainers.end());
        int left=0, right=0, ans=0;
        while(left<players.size() && right<trainers.size()){
            if(players[left]<=trainers[right]){
                ans++;
                left++;
            }
            right++;
        }
        return ans;
    }
};