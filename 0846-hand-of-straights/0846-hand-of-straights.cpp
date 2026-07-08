class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        if(hand.size()%groupSize!=0) return false;
        unordered_map<int,int> mpp;
        for(int num:hand){
            mpp[num]++;
        }
        priority_queue<int, vector<int>, greater<int>> pq;

        for(auto it : mpp)
            pq.push(it.first);
        while(!pq.empty()){
            int x=pq.top();
            for(int i=x;i<x+groupSize;i++){
                if(mpp[i]==0) return false;
                mpp[i]--;

                if(mpp[i] == 0) {

                    if(i != pq.top())
                        return false;

                    pq.pop();
                }
            }
        }
        return true;
    }
};