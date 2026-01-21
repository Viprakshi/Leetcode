class Solution {
public:
    int isWinner(vector<int>& player1, vector<int>& player2) {
            int player_1=player1[0], player_2=player2[0];
            for(int i=1;i<player1.size();i++){
                if((i==1 && player1[i-1]==10) || (i>=2 && (player1[i-1]==10 || player1[i-2]==10))) player_1+=2*player1[i];
                
                else player_1+=player1[i];
            }
            for(int i=1;i<player2.size();i++){
                if((i==1 && player2[i-1]==10) || (i>=2 && (player2[i-1]==10 || player2[i-2]==10))) player_2+=2*player2[i];
                else player_2+=player2[i];
            }
            if(player_1==player_2) return 0;
            else if(player_2>player_1) return 2;
            else return 1;

    }
};