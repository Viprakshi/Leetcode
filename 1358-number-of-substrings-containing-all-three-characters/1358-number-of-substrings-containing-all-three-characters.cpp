class Solution {
public:
    int numberOfSubstrings(string s) {
        int a=0, b=0, c=0;
        int l=0, r=0;
        int count=0;
        while(l<=r && r<s.length() ){
            if(s[r]=='a') a++;
            if(s[r]=='c') c++;
            if(s[r]=='b') b++;
            
            while(a>0 && b>0 && c>0){
                count+=(s.length()-r);
                if(s[l]=='a') a--;
                if(s[l]=='c') c--;
                if(s[l]=='b') b--;
                l++;
            }
            r++;
        }
        return count;
    }
};
