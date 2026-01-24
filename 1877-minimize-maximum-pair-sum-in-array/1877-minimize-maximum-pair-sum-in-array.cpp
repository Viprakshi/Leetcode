class Solution {
public:
    int minPairSum(vector<int>& nums) {
        // 2 3 4 4 5 6 
        vector<vector<int>> pairs;
        sort(nums.begin(), nums.end());
        int i=0, j= nums.size()-1;
        while(i<j){
            pairs.push_back({nums[i],nums[j]});
            i++;
            j--;
        }
        int sum=INT_MIN;
        for(auto& pair:pairs){
            sum=max(sum,(pair[0]+pair[1]));
        }
        return sum;
    }
};