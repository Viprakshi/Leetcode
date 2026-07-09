class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int five=0, ten=0;
        for(int bill:bills){
            if(bill==5) five++;
            else if(bill==10){
                ten++;
                if(five==0) return false;
                five--;
            }
            else if(bill==20){
                if(ten==0 && five<3) return false;
                if(ten>0 && five<1) return false;  
                if(ten>0 && five>0){
                    ten--;
                    five--;
                }
                else{
                    five=five-3;
                }
            }
        }
        return true;
    }
};