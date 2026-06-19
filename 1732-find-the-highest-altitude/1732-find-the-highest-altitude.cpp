class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int ans=0;
        int sum=0;
        for(int g:gain){
            sum+=g;
            ans=max(ans,sum);
        }
        return ans;
    }
};