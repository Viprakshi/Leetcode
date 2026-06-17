class Solution {
public:
    int minBitFlips(int start, int goal) {
        int z=start^goal;
        int ans;
        while(z!=0){
            if(z%2==1) ans++;
            z=z/2; 
        }
        return ans;
    }
};