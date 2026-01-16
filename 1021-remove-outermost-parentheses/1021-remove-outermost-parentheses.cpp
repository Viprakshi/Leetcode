class Solution {
public:
    string removeOuterParentheses(string s) {
        int counter=0;
        string res="";
        for(int i=0;i<s.length();i++){
           if(s[i]=='('){
            if(counter>0){
                res+=s[i];
                counter++;
            }
            else{
                counter++;
            }
           }
           else{
            counter--;
            if(counter!=0){
                res+=s[i];
            }
           }
            

        }
        return res;
    }
};