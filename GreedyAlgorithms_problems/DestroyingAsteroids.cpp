
// Problem link - https://leetcode.com/problems/destroying-asteroids/description/?envType=daily-question&envId=2026-05-31

#include<bits/stdc++.h>
using namespace std;

bool asteroidsDestroyed(int mass, vector<int>& asteroids) {
    // step 1 - sort asteroids to process smaller asteroids first
    sort(asteroids.begin(), asteroids.end());

    // keep track of total mass with the ship's starting mass
    long long int totalMass = mass;

    // step 2 - process each asteroid in ascending order
    for(int &m : asteroids){
        // check if the current asteroid is heavier than the total mass, 
        // we cannot destroy it
        if(totalMass < m){
            return false;
        }
        // otherwise, absorb the asteroid and add its mass to the total
        totalMass += m;
    }

    // step 3 - return true as all asteroids destroyed successfully
    return true;
}

int main(){
    // int mass = 10;
    // vector<int> asteroids = {3,9,19,5,21};

    int mass = 5;
    vector<int> asteroids = {4,9,23,4};
    bool res = asteroidsDestroyed(mass, asteroids);
    res ? cout<<"true":cout<<"false";
    return 0;
}