class Solution {
public:
    string reverseWords(string s) {
        string res="", temp="";
        for(int i=s.length()-1;i>=0;i--){
            if(s[i]==' '){
                if (temp != "") {
                    res += temp;
                    res += ' ';
                    temp = "";
                }
            }
            else{
                temp=s[i]+temp;
            }
        }
        if (temp != "") {
            res += temp;
        } else if (!res.empty()) {
            res.pop_back();
        }

        return res;
        
    }
};