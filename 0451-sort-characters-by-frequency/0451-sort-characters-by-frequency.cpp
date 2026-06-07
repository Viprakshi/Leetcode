class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char, int> mpp; 
        for(char ch: s){
            mpp[ch]++;
        }
        priority_queue<pair<int,char>> pq;
        for(auto& [ch,freq]:mpp){
            pq.push({freq,ch});
        }
        string res="";
        while(!pq.empty()){
            auto [ch,f]=pq.top();
            pq.pop();
            res+=string(ch,f);
        }
        return res;
    }
};