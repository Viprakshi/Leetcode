class Solution {
public:
    int findContentChildren(vector<int>& children, vector<int>& cookies) {
        sort(children.begin(), children.end());
	sort(cookies.begin(), cookies.end());
	int left=0, right=0,ans=0; 
	while(left<children.size() && right<cookies.size()){
		if(children[left]<=cookies[right]){
			ans++;
			right++;
            left++;

		}
		else{
			    right++;

		}
}
	return ans;
    }
};