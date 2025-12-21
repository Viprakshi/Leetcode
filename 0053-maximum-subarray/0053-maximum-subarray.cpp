class Solution {
public:
    int maxSubArray(vector<int>& arr) {
        int max_ending=arr[0],res=arr[0];
        for(int i=1;i<arr.size();i++){
            max_ending=max(max_ending+arr[i],arr[i]);
            res=max(max_ending,res);
        }
        return res;
    }
};