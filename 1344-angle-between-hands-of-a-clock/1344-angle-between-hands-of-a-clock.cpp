class Solution {
public:
    double angleClock(int hour, int minutes) {

        double hour_degree=((hour%12)*30)+(0.5*minutes);
        double min_degree=minutes*6;
        return min(abs(min_degree-hour_degree), 360-abs(hour_degree-min_degree));
    }
};