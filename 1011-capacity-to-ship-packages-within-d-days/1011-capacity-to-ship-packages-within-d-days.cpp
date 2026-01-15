class Solution {
public:
    int daysNeeded(vector<int>& w, int cap) {
        int days = 1, load = 0;
        for (int x : w) {
            if (load + x > cap) {
                days++;
                load = x;
            } else {
                load += x;
            }
        }
        return days;
    }

    int shipWithinDays(vector<int>& weights, int days) {
        int low = *max_element(weights.begin(), weights.end());
        int high = accumulate(weights.begin(), weights.end(), 0);
        int ans = high;

        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (daysNeeded(weights, mid) <= days) {
                ans = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return ans;
    }
};

