class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        vector<int> change(2,0);
        for(int i=0;i<bills.size();i++){
            if(bills[i]==5)
            {
               change[0]++; 
            } 
            if(bills[i]==10){
                change[1]++;
                if(change[0]==0) return false;
                change[0]--;
            }        
            if(bills[i]==20){
                if (change[0] > 0 && change[1] > 0) {
                    change[0]--; 
                    change[1]--;  
                } 
                else if (change[0] >= 3) {
                    change[0] -= 3; 
                } 
                else {
                    return false; 
                }
            }
        }
        return true;
    }
};