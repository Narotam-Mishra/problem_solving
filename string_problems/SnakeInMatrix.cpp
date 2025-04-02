
#include<bits/stdc++.h>
using namespace std;

int finalPositionOfSnake(int n, vector<string>& commands) {
    // step 1 - initial position at top left corner (0, 0)
    int row = 0, col = 0;

    // step 2 - iterate through each comamnd
    for(string command : commands){
        // move one row up 
        if(command == "UP") row--;

        // move one row down 
        else if(command == "DOWN") row++;

        // move one column left 
        else if(command == "LEFT") col--;

        // move one column right
        else col++;
    }

    // step 3 - return final grid position
    return (row * n) + col;
}

int main(){
    // int n = 2;
    // vector<string> commands = {"RIGHT","DOWN"};

    int n = 1;
    vector<string> commands = {"DOWN","RIGHT","UP"};
    cout<<finalPositionOfSnake(n, commands)<<endl;
    return 0;
}