#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;

typedef tree<
    pair<int,int>,
    null_type,
    less<pair<int,int>>,
    rb_tree_tag,
    tree_order_statistics_node_update
> ordered_set;

class Solution {
public:
    long long countMajoritySubarrays(vector<int>& nums, int target) {
        ordered_set os;
        long long ans = 0;
        int pref = 0;

        os.insert({0, 0});

        for (int i = 0; i < nums.size(); i++) {
            pref += (nums[i] == target ? 1 : -1);

            ans += os.order_of_key({pref, -1});

            os.insert({pref, i + 1});
        }

        return ans;
    }
};