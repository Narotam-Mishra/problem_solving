
// Disjoint Set Union (DSU) implementation

#include<bits/stdc++.h>
using namespace std;

class DSU {
public:
    vector<int> parent;
    vector<int> size;

    DSU(int n){
        parent.resize(n);
        size.resize(n, 1);
        for(int i=0; i<n; i++){
            parent[i] = i;
        }
    }

    // utility method for find
    int find(int x){
        if(parent[x] != x){
            // x is not parent of itself

            // then find the parent of x and attach it to parent
            // by using path compression
            parent[x] = find(parent[x]);
        }
        return parent[x];
    }

    // utility method for union
    void union_sets(int x, int y){
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
};

int main(){
    DSU dsu(6);
    dsu.union_sets(0, 1);
    dsu.union_sets(2, 3);
    dsu.union_sets(4, 5);

    for (int i = 0; i < 6; i++) {
        cout<<dsu.parent[i]<<" ";
    }
    cout<<endl;

    for (int i = 0; i < 6; i++) {
        cout<<dsu.size[i]<<" ";
    }
    cout<<endl;

    return 0;
}