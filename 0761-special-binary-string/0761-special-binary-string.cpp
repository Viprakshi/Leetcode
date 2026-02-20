class Solution{
public:
    string makeLargestSpecial(string s){
        if(s.empty()){
            return s;
        }

        vector<string>x_v;
        int x_bal=0;
        int x_st=0;

        for(int x_i=0;x_i<s.size();x_i++){
            x_bal+=(s[x_i]=='1')?1:-1;

            if(x_bal==0){
                string x_mid=s.substr(x_st+1,x_i-x_st-1);
                string x_cur="1"+makeLargestSpecial(x_mid)+"0";
                x_v.push_back(x_cur);
                x_st=x_i+1;
            }
        }

        sort(x_v.begin(),x_v.end(),greater<string>());

        string x_res="";
        for(auto&x_s:x_v){
            x_res+=x_s;
        }

        return x_res;
    }
};