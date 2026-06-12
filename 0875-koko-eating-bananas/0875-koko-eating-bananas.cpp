class Solution {
public:
    long long  hours(vector<int>& piles, int speed){
        long long  hours=0; 
        for(int i=0;i<piles.size();i++){
            hours += (piles[i] + speed - 1) / speed;
        }
        return hours;
    }

    int minEatingSpeed(vector<int>& piles, int h) {
       
        int left=1, right= *max_element(piles.begin(), piles.end());
        int ans=right;
        while(left<=right){
            int mid=left+(right-left)/2;
            long long taken_time=hours(piles, mid);
            if(taken_time>h) left=mid+1;
            else if(taken_time<=h){
                ans=mid;
                right=mid-1;
            }
        }
        return ans;
    }
};