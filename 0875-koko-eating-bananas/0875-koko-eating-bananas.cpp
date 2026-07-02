class Solution {
public:
    long long cal(vector<int>& piles, int x){
        long long ans=0; 
        for(int i=0;i<piles.size();i++){
            int y=piles[i]/x;
            if(piles[i]%x>0) ans++;
            ans+=(long long)y;
        }
        return ans;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int maxi=*max_element(piles.begin(), piles.end());
        int left=1, right=maxi;
        int ans=-1;
        while(left<=right){
            int mid=left+(right-left)/2;
            long long hours=cal(piles, mid);
            if(hours<=h){
                ans=mid;
                right=mid-1;
            }
            else left=mid+1;
        }
        return ans;
    }
};