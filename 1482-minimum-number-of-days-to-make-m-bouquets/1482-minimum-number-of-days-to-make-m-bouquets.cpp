class Solution {
public:
    bool days(vector<int>& arr, int num_bouquets, int flowers_req,int days_given){
        int i=0; 
        int x=flowers_req, bou_made=0;
        while(i<arr.size()){
            if(arr[i]==0) i++;
            else if(arr[i]<=days_given && x==flowers_req){
                while(i<arr.size() && arr[i]<=days_given){
                    i++;
                    x--;
                    if(x==0){
                        bou_made++;
                        x=flowers_req;
                    } 
                }
                
            }
            x=flowers_req;
            i++;
            
        }
        if(bou_made>=num_bouquets) return true;
        return false;
    }
    int minDays(vector<int>& bloomDay, int m, int k) {
        int left=1, right=*max_element(bloomDay.begin(), bloomDay.end());
        int ans=-1;
        while(left<=right){
            int mid=left+(right-left)/2;
            bool is_possible=days(bloomDay,m,k,mid);
            if(is_possible){
                ans=mid;
                right=mid-1;
            }
            else{
                left=mid+1;
            }

        }
        return ans;
    }
};