
// Problem link - https://leetcode.com/problems/k-closest-points-to-origin/description/

#include<bits/stdc++.h>
using namespace std;

// Point class to store x, y coordinates and distance from the origin
class Point {
public:
    int x, y;
    double distance;

    Point(int xi, int yi){
        this->x = xi;
        this->y = yi;
        this->distance = sqrt(x*x + y*y);
    }
};

// Comparator class for the priority queue to order points by distance (min-heap)
class Comparator {
public:
    bool operator()(Point const& p1, Point const& p2){
        return p1.distance > p2.distance;
    }
};

vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
    // Priority queue (min-heap) to store points by their distance from the origin
    priority_queue<Point, vector<Point>, Comparator> hp;

    // insert all points into the priority queue
    for(auto& point : points){
        hp.emplace(point[0], point[1]);
    }

    // retrieve the k closest points
    vector<vector<int>> res;
    for(int i=0; i<k; i++){
        Point closest = hp.top();
        hp.pop();
        res.push_back({ closest.x, closest.y});
    }

    // return result array 'res' of k-close points
    return res;
}

int main(){
    vector<vector<int>> points = {{1, 3}, {-2, 2}, {5, 8}, {0, 1}};
    int k = 2;

    vector<vector<int>> closestPoints = kClosest(points, k);
    cout << "The " << k << " closest points to the origin are: ";
    for (auto& point : closestPoints) {
        cout << "[" << point[0] << ", " << point[1] << "]";
    }
    cout<<endl;
    return 0;
}