class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int score=0;
        
        for(int i=0;i<k;i++){
            score+=cardPoints[i];
        }
        int left=0, right=k-1;
        int n=cardPoints.size();
        int max_score=score;
        while(right!=n-1){
            
            score-=cardPoints[right];
            if(right-1<0){
                right=((right-1 % n) + n) %n;
            }
            else{
                right=(right-1) % n;
            }
            
            if(left-1<0){
                left=((left-1 % n) + n) %n;
            }
            else{
                left=(left-1) % n;
            }
            score+=cardPoints[left];
            max_score=max(max_score, score);

        }
        return max_score;
       
    }
};