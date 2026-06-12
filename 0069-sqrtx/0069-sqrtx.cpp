class Solution {
public:
    int mySqrt(int x) {
        int left=1, right=x/2;
        int ans;
        while(left<=right){
            int mid=left+(right-left)/2;
            long long sq = 1LL * mid * mid;
            if(sq==x) return mid;
            else if(sq>x) right=mid-1;
            else{
                ans=mid;
                left=mid+1;
            } 
        }
        
        return ans;
    }
};
