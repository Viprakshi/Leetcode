class Solution {
public:
    int earliestFinishTime(vector<int>& landStartTime,
                           vector<int>& landDuration,
                           vector<int>& waterStartTime,
                           vector<int>& waterDuration) {
        
        int ans = INT_MAX;

        int earliestLandEnd = INT_MAX;
        for (int i = 0; i < landStartTime.size(); i++) {
            earliestLandEnd = min(
                earliestLandEnd,
                landStartTime[i] + landDuration[i]
            );
        }

        for (int j = 0; j < waterStartTime.size(); j++) {
            int finishTime =
                max(earliestLandEnd, waterStartTime[j]) +
                waterDuration[j];

            ans = min(ans, finishTime);
        }

        // Water -> Land
        int earliestWaterEnd = INT_MAX;
        for (int i = 0; i < waterStartTime.size(); i++) {
            earliestWaterEnd = min(
                earliestWaterEnd,
                waterStartTime[i] + waterDuration[i]
            );
        }

        for (int j = 0; j < landStartTime.size(); j++) {
            int finishTime =
                max(earliestWaterEnd, landStartTime[j]) +
                landDuration[j];

            ans = min(ans, finishTime);
        }

        return ans;
    }
};