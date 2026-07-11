class Solution {
public:
    int candy(vector<int>& ratings) {
        int ans=0;
        vector<int> r(ratings.size(),1);
        for(int i=1;i<ratings.size();i++){
            if(ratings[i]>ratings[i-1]) r[i]=r[i-1]+1;
        }
        for(int i=ratings.size()-2;i>=0;i--){
            if(ratings[i]>ratings[i+1]) r[i]=max(r[i],r[i+1]+1);
        }
        for(int x:r) ans+=x;
        return ans;
    }
};