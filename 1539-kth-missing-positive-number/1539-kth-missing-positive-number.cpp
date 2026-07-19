class Solution {
public:
    bool binarysearch(int i, vector<int>& arr){
        int left=0, right=arr.size()-1;
        while(left<=right){
            int mid=(left+right)/2;
            if(arr[mid]==i) return true;
            if(arr[mid]<i) left=mid+1;
            else right=mid-1;
        }
        return false;
    }
    int findKthPositive(vector<int>& arr, int k) {
        vector<int> missing;
        int i=1, x=0;
        while(x!=k){
             if(!binarysearch(i,arr)){
                missing.push_back(i);
                x++;
            }
            i++;
        }
        return missing[k-1];
    }
};