class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int five=0, ten=0, twenty=0; 
	for(int i=0; i<bills.size();i++){
		if(bills[i]==5)five++;

		if(bills[i]==10){
			if(five>=1){
				five--;
				ten+=1;
			}
			else{
				return false;
			}
		}
		if(bills[i]==20){
			if(ten && five){
				twenty++;
				ten--;
				five--;
			}
			else if(!ten && five>=3){
				twenty++;
				five=five-3;
			}
			else{
				return false;
			}
		}
	}
	return true;
    }
};