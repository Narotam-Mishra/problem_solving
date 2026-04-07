
// Problem link - https://leetcode.com/problems/walking-robot-simulation-ii/description/?envType=daily-question&envId=2026-04-07

#include<bits/stdc++.h>
using namespace std;

class Robot {
public:
    // keep track of boundary cell position
    vector<vector<int>> pos;

    // keep track index in position grid
    int idx = 0;

    // keep track of movement
    bool moved = false;
    Robot(int width, int height) {

        // 0 -> East, 1 -> North
        // 2 -> West, 3 -> South
        // Bottom row (left to right, East-0)
        for(int x=0; x<width; x++){
            pos.push_back({x, 0, 0});
        }

        // Right column (bottom to top, North-1)
        for(int y=1; y<height; y++){
            pos.push_back({width-1, y, 1});
        }

        // Top row (right to left, West-2)
        for(int x=width-2; x>=0; x--){
            pos.push_back({x, height-1, 2});
        }

        // left column (top to bottom, South-3)
        for(int y=height-2; y>0; y--){
            pos.push_back({0, y, 3});
        }

        // handle corner case
        // make it south when robot came back to (0,0)
        pos[0][2] = 3;
    }
    
    void step(int num) {
        int n = pos.size();
        moved = true;
        idx = (idx + num) % n;
    }
    
    vector<int> getPos() {
        // get posiiton using idx
        return {pos[idx][0], pos[idx][1]};
    }
    
    string getDir() {
        // edge case
        if(!moved){
            return "East";
        }

        // get direction
        int dir = pos[idx][2];
        if(dir == 0) return "East";
        else if(dir == 1) return "North";
        else if(dir == 2) return "West";
        return "South";
    }
};

int main(){
    Robot robot(6, 3);

    robot.step(2);
    robot.step(2);

    auto p1 = robot.getPos();
    cout << "getPos: [" << p1[0] << ", " << p1[1] << "]\n";  // expected: [4, 0]
    cout << "getDir: " << robot.getDir() << "\n";              // expected: East

    robot.step(2);
    robot.step(1);
    robot.step(4);

    auto p2 = robot.getPos();
    cout << "getPos: [" << p2[0] << ", " << p2[1] << "]\n";  // expected: [1, 2]
    cout << "getDir: " << robot.getDir() << "\n";              // expected: West
    
    return 0;
}