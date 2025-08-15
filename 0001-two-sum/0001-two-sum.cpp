class Solution {
public:
    vector<int> twoSum(vector<int>& arr, int target) {
        unordered_map<int, int> mpp;
        vector<int> ans;

	for(int i=0; i<arr.size();i++){
		int need=target-arr[i];
		if(mpp.find(need)!=mpp.end()){
            ans.push_back(i);
            ans.push_back(mpp[need]);
            break;
        }
		mpp[arr[i]]=i;
	}
	return ans;
    }
};
