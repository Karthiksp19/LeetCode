class Solution {
public:
    double angleClock(int hour, int minutes) {
        hour = hour % 12;
        float minA = 6 * minutes; // 360 / 60 
        float hrA = hour * 30 + minutes * 0.5;  // 360 / 12 for hr and 60 / 30 for mov of hr per min
        return min(fabs(minA - hrA), 360 - fabs(minA - hrA));
    }
};