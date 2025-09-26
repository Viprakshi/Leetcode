class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int,int> map;
        map[0]=1;
        int count=0;
        int curr_sum=0;
        for(int i=0;i<nums.size();i++){
            curr_sum+=nums[i];
            int to_find=curr_sum-k;
            if(map.find(to_find)!=map.end()){
                count+=map[to_find];
            }
            map[curr_sum]++;
        }
        return count;


}

int main()
{
    vector arr = {3, 1, 2, 4};
    int k = 6;
    int cnt = subarraySum(arr, k);
    cout << "The number of subarrays is: " << cnt << "\n";
    return 0;
    }
};