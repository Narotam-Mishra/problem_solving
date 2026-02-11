
#include <bits/stdc++.h>
using namespace std;

class SegmentTree {
    vector<int> tree;
    int n;

public:
    SegmentTree(vector<int>& nums) {
        n = nums.size();
        tree.resize(4 * n);   // safe size
        build(nums, 0, 0, n - 1);
    }

    // Build the tree
    void build(vector<int>& nums, int node, int start, int end) {
        if (start == end) {
            tree[node] = nums[start];   // leaf node
        } else {
            int mid = (start + end) / 2;

            build(nums, 2 * node + 1, start, mid);
            build(nums, 2 * node + 2, mid + 1, end);

            tree[node] = tree[2 * node + 1] + tree[2 * node + 2];
        }
    }

    // Query sum in range [L, R]
    int query(int node, int start, int end, int L, int R) {

        // No overlap
        if (R < start || L > end)
            return 0;

        // Complete overlap
        if (L <= start && end <= R)
            return tree[node];

        // Partial overlap
        int mid = (start + end) / 2;

        int leftSum = query(2 * node + 1, start, mid, L, R);
        int rightSum = query(2 * node + 2, mid + 1, end, L, R);

        return leftSum + rightSum;
    }

    // Public wrapper for query
    int rangeQuery(int L, int R) {
        return query(0, 0, n - 1, L, R);
    }

    // Update element at index idx
    void update(int node, int start, int end, int idx, int value) {

        if (start == end) {
            tree[node] = value;
        } else {
            int mid = (start + end) / 2;

            if (idx <= mid)
                update(2 * node + 1, start, mid, idx, value);
            else
                update(2 * node + 2, mid + 1, end, idx, value);

            tree[node] = tree[2 * node + 1] + tree[2 * node + 2];
        }
    }

    // Public wrapper for update
    void pointUpdate(int idx, int value) {
        update(0, 0, n - 1, idx, value);
    }
};

int main() {

    vector<int> nums = {1, 3, 5, 7, 9, 11};

    SegmentTree segTree(nums);

    cout << "Initial Range Sum Queries:\n";
    cout << "Sum [0, 2] = " << segTree.rangeQuery(0, 2) << endl;
    cout << "Sum [1, 4] = " << segTree.rangeQuery(1, 4) << endl;
    cout << "Sum [3, 5] = " << segTree.rangeQuery(3, 5) << endl;

    cout << "\nUpdating index 2 to value 10...\n";
    segTree.pointUpdate(2, 10);

    cout << "\nAfter Update:\n";
    cout << "Sum [0, 2] = " << segTree.rangeQuery(0, 2) << endl;
    cout << "Sum [1, 4] = " << segTree.rangeQuery(1, 4) << endl;
    cout << "Sum [3, 5] = " << segTree.rangeQuery(3, 5) << endl;

    return 0;
}
