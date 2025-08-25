class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        if(stones.size()==1)return stones[0];
        int n=stones.size();
        int active_stones=n;
        while(active_stones>1){
            sort(stones.begin(),stones.end());
            if(stones[n-1]==stones[n-2]){
                stones[n-1]=INT_MIN;
                stones[n-2]=INT_MIN;
                active_stones-=2;
            }
            if(stones[n-1]!=stones[n-2]){
                stones[n-1]=stones[n-1]-stones[n-2];
                stones[n-2]=INT_MIN;
                active_stones--;
            }
            
        }
        int last=0;
    for(int stone:stones){
        if(stone!=INT_MIN){
            last=stone;
            break;
        } 
    
    }
    return last;
};};
