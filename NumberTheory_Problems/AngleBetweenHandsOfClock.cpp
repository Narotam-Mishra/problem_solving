
// Problem link - https://leetcode.com/problems/angle-between-hands-of-a-clock/description/?envType=daily-question&envId=2026-06-18

#include<bits/stdc++.h>
using namespace std;

double angleClock(int hour, int minutes) {
    // step 1 - convert hour to 12 to 0 because both represent the same position
    hour = hour % 12;

    // step 2 - calculate the hour hand's position in degrees
    double hourAngle = 30 * hour + 0.5 * minutes;

    // step 3 - calculate the minute hand's position in degrees
    double minuteAngle = 6 * minutes;

    // step 4 - find the absolute angle difference between the two hands
    double diff = abs(hourAngle - minuteAngle);

    // step 5 - return the smaller angle
    return min(diff, 360 - diff);
}

int main(){
    // int hour = 12, minutes = 30;

    // int hour = 3, minutes = 30;

    int hour = 3, minutes = 15;
    cout<<angleClock(hour, minutes);
    return 0;
}