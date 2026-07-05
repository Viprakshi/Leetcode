class Solution {
public:
    void  generate(string num,int target,int pos,long long val,long long last_val, string temp,vector<string>& ans){
        if(pos==num.size()){
            if(target==val) ans.push_back(temp);
            return;
        }
        for(int i=pos;i<num.size();i++){
            if(i>pos && num[pos]=='0') break;
            string x=num.substr(pos,i-pos+1);
            long long y=stoll(x);
            if(pos==0){
                generate(num, target, i+1,y, y, x,ans);
            }
            else{
                generate(num, target, i+1,val+y, y,temp+"+"+x,ans);
                generate(num, target, i+1,val-y, -y,temp+"-"+x,ans);
                generate(num, target, i+1,val-last_val+last_val*y, last_val*y, temp+"*"+x,ans);
            }
        }
    }
    vector<string> addOperators(string num, int target) {
        vector<string> ans;
        generate(num, target, 0, 0, 0, "",ans);
        return ans;
    }
};