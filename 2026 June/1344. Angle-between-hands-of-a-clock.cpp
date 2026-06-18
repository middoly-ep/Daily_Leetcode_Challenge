#include <cmath>
#include <algorithm>

using namespace std;

class Solution {
public:
    double angleClock(int hour, int minutes) {
        double hour_angle = (hour % 12) * 30 + (minutes * 1.0f / 2);
        double minute_angle = minutes * 6;
        double angle = abs(hour_angle - minute_angle);

        return min(angle, 360.0f - angle);
    }
};
