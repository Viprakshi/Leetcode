class Solution {
public:
    string frequencySort(string s) {
         unordered_map<char, int> mpp;
         for(char x:s){
            mpp[x]++;
         }
         priority_queue<pair<int, char>> pq;
         for(auto it:mpp){
            pq.push({it.second, it.first});
         }
         string res="";
         while(!pq.empty()){
            auto curr=pq.top();
            pq.pop();
            int freq=curr.first;
            int ch=curr.second;
            while(freq!=0){
                res+=ch;
                freq--;
            }
         }
         return res;
    }
};