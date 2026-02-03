class Solution {
public:
    bool mergeTriplets(vector<vector<int>>& triplets, vector<int>& target) {
        bool a=false, b=false, c=false;
        for(auto& tr:triplets){
            int x=tr[0], y=tr[1], z=tr[2];
            if(x>target[0] || y>target[1] || z>target[2]) continue;
            if(x==target[0]) a=true;
            if(y==target[1]) b=true;
            if(z==target[2]) c=true;

        }
        
        if(a && b && c) return true;
        return false;
    }
};