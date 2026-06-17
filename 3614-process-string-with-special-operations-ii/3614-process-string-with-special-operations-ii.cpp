class Solution {
public:
    char processStr(string s,long long k) {
        int n=s.size();
        vector<long long> len(n+1,0);

        for(int i=0;i<n;i++){
            if(islower(s[i])){
                len[i+1]=len[i]+1;
            }
            else if(s[i]=='*'){
                len[i+1]=max(0LL,len[i]-1);
            }
            else if(s[i]=='#'){
                len[i+1]=min((long long)1e15,len[i]*2);
            }
            else{
                len[i+1]=len[i];
            }
        }

        if(k>=len[n]) return '.';

        for(int i=n-1;i>=0;i--){
            char ch=s[i];

            if(islower(ch)){
                if(k==len[i+1]-1){
                    return ch;
                }
            }
            else if(ch=='#'){
                if(k>=len[i]){
                    k-=len[i];
                }
            }
            else if(ch=='%'){
                k=len[i]-1-k;
            }
        }

        return '.';
    }
};