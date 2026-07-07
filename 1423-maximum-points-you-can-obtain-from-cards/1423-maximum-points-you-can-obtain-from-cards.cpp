class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int sum=accumulate(cardPoints.begin(), cardPoints.begin()+k, 0);
        int i=k-1, j=cardPoints.size()-1, curr=accumulate(cardPoints.begin(), cardPoints.begin()+k, 0);
        while(i>=0){
            curr=curr+cardPoints[j]-cardPoints[i];
            sum=max(sum,curr);
            i--;
            j--;
        }
        return sum;
    }
};