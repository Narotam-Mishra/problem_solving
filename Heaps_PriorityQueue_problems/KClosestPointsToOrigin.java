
// Problem link - https://leetcode.com/problems/k-closest-points-to-origin/description/

package Heaps_PriorityQueue_problems;

import java.util.*;

class Point {
    int x, y;
    double distance;

    public Point(int x, int y){
        this.x = x;
        this.y = y;
        this.distance = Math.sqrt(x * x + y * y);
    }
}

public class KClosestPointsToOrigin {

    public static int[][] kClosest(int[][] points, int k) {
        // created min-heap to store points by their distance from the origin
        PriorityQueue<Point> hp = new PriorityQueue<>(new Comparator<Point>() {
            @Override
            public int compare(Point p1, Point p2){
                return Double.compare(p1.distance, p2.distance);
            }
        });

        // insert all points into the min-heap
        for(int[] point : points){
            hp.add(new Point(point[0], point[1]));
        }

        // retrieve the k closest points
        int[][] result = new int[k][2];
        for(int i=0; i<k; i++){
            Point closest = hp.poll();
            result[i][0] = closest.x;
            result[i][1] = closest.y;
        }
        return result;
    }

    public static void main(String[] args) {
        int[][] points = {{1, 3}, {-2, 2}, {5, 8}, {0, 1}};
        int k = 2;

        // int[][] points = {{1,3}, {-2,2}};
        // int k = 1;
        int[][] closestPoints = kClosest(points, k);

        System.out.print("The " + k + " closest points to the origin are:");
        for (int[] point : closestPoints) {
            System.out.print("[" + point[0] + ", " + point[1] + "]");
        }
    }
}