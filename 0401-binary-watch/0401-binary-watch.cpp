class Solution {
public:
    vector<string> readBinaryWatch(int turned_on) {
        vector<string> result;
        
        for (int hour = 0; hour < 12; ++hour) {
            for (int minute = 0; minute < 60; ++minute) {
                
                int hour_bits = __builtin_popcount(hour);
                int minute_bits = __builtin_popcount(minute);
                if (hour_bits + minute_bits == turned_on) {
                    string time_string = to_string(hour) + ":" +
                                        (minute < 10 ? "0" : "") +
                                        to_string(minute);
                    result.push_back(time_string);
                }
            }
        }
        
        return result;
    }
};