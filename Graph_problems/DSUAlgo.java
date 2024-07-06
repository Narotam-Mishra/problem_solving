
// Disjoint Set Union (DSU) implementation

package Graph_problems;

import java.util.*;

public class DSUAlgo {
    int[] parent;
    int[] size;
    
    public DSUAlgo(int n){
        parent = new int[n];
        size = new int[n];
        for(int i=0; i<n; i++){
            parent[i] = i;
            size[i] = 1;
        }
    }

    // utility method for find
    public int find(int x){
        if(parent[x] != x){
            // x is not parent of itself

            // then find the parent of x and attach it to parent
            // by using path compression
            parent[x] = find(parent[x]);
        }
        return parent[x];
    }

    // utility method for union
    public void union(int x, int y){
        int xRoot = find(x);
        int yRoot = find(y);

        if(xRoot == yRoot) return;
        // x and y are always in same set

        if(size[xRoot] < size[yRoot]){
            // x is smaller than y
            parent[xRoot] = yRoot;
            size[yRoot] += size[xRoot];
        }else{
            // y is smaller than x
            parent[yRoot] = xRoot;
            size[xRoot] += size[yRoot];
        }
    }

    public static void main(String[] args) {
        DSUAlgo dsu = new DSUAlgo(6);
        dsu.union(0, 1);
        dsu.union(2, 3);
        dsu.union(4, 5);

        System.out.println(Arrays.toString(dsu.parent));
        System.out.println(Arrays.toString(dsu.size));
    }
}