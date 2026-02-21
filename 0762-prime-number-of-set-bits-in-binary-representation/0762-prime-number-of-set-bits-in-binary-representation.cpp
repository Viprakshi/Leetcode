class Solution{
public:
int countPrimeSetBits(int x_y,int y_x){
    int p_m=665772,r_s=0;
    for(int v_l=x_y;v_l<=y_x;v_l++)
    if((p_m>>__builtin_popcount(v_l))&1)r_s++;
    return r_s;
}
};