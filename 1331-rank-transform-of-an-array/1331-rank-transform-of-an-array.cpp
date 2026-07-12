class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        vector<pair<int,int>> x;
        for(int i=0;i<arr.size();i++){
            x.push_back({arr[i],i});
        }
        sort(x.begin(),x.end());
        int rank=1;
        for(int i=0;i<x.size();i++){
            if(i>0 && x[i-1].first!=x[i].first)
                rank++;
            arr[x[i].second]=rank;
        
        }
        return arr;
    }
};