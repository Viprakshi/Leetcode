class Solution {
public:
    int earliestFinishTime(vector<int>& landStartTime, vector<int>& landDuration,
                           vector<int>& waterStartTime, vector<int>& waterDuration) {
        
        int n = landStartTime.size();
        int m = waterStartTime.size();

        vector<int> landFinish(n), waterFinish(m);

        for (int i = 0; i < n; i++)
            landFinish[i] = landStartTime[i] + landDuration[i];

        for (int j = 0; j < m; j++)
            waterFinish[j] = waterStartTime[j] + waterDuration[j];

        vector<int> sortedLand = landFinish;
        vector<int> sortedWater = waterFinish;

        sort(sortedLand.begin(), sortedLand.end());
        sort(sortedWater.begin(), sortedWater.end());

        int minLandFinish = sortedLand[0];
        int minWaterFinish = sortedWater[0];

        long long ans = LLONG_MAX;

        // Land -> Water
        for (int j = 0; j < m; j++) {
            long long bestStartWater;

            if (minLandFinish <= waterStartTime[j]) {
                bestStartWater = waterStartTime[j];
            } else {
                auto it = upper_bound(sortedLand.begin(), sortedLand.end(),
                                      waterStartTime[j]);
                bestStartWater = *it;   // all land finishes are > waterStartTime[j]
            }

            ans = min(ans, bestStartWater + waterDuration[j]);
        }

        // Water -> Land
        for (int i = 0; i < n; i++) {
            long long bestStartLand;

            if (minWaterFinish <= landStartTime[i]) {
                bestStartLand = landStartTime[i];
            } else {
                auto it = upper_bound(sortedWater.begin(), sortedWater.end(),
                                      landStartTime[i]);
                bestStartLand = *it;    // all water finishes are > landStartTime[i]
            }

            ans = min(ans, bestStartLand + landDuration[i]);
        }

        return (int)ans;
    }
};