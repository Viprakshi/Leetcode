class Solution {
public:
    bool judgeCircle(string moves) {
        int meow=0, centre=0;
        for(char move: moves){
            if(move=='U') centre++;
            if(move=='D') centre--;
            if(move=='L') meow++;
            if(move=='R') meow--;
        }
        if(meow==0 && centre==0) return true;
        else return false;
    }
};