
// Problem link - https://leetcode.com/problems/minimum-cost-to-convert-string-ii/description/?envType=daily-question&envId=2026-01-30

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll, string> P;
ll BIG_VALUE = 1e10;
unordered_map<string, vector<pair<string, ll>>> adj; //Graph

//start -> end -> anser
unordered_map<string, unordered_map<string, ll>> dijkstraMemo;

vector<ll> dpMemo;

string sourceStr;
string targetStr;
set<int> validLengths;

ll dijkstra(string& start, string& end) {

    if (dijkstraMemo[start].count(end)) {
        return dijkstraMemo[start][end];
    }

    //{cost, string}
    priority_queue<P, vector<P>, greater<P>> pq;
    //vector<int> result(n, INT_MAX)
    unordered_map<string, ll> result; //source to string ka cost stored
    result[start] = 0;
    pq.push({ 0, start });

    while (!pq.empty()) {
        ll currCost = pq.top().first;
        string node = pq.top().second;
        pq.pop();

        if (node == end) {
            break;
        }

        for (auto& edge : adj[node]) {
            string adjNode = edge.first;
            ll edgeCost = edge.second;

            if (!result.count(adjNode) || currCost + edgeCost < result[adjNode]) {
                result[adjNode] = currCost + edgeCost;
                pq.push({ currCost + edgeCost, adjNode });
            }
        }
    }

    ll finalCost = result.count(end) ? result[end] : BIG_VALUE;

    return dijkstraMemo[start][end] = finalCost;

}

ll solve(int idx) {
    if (idx >= sourceStr.length())
        return 0;
    if (dpMemo[idx] != -1)
        return dpMemo[idx];

    ll minCost = BIG_VALUE;

    if (sourceStr[idx] == targetStr[idx])
        minCost = solve(idx + 1);

    for (auto& len : validLengths) {
        if (idx + len > sourceStr.length()) {
            break;
        }

        string srcSub = sourceStr.substr(idx, len);
        string tgtSub = targetStr.substr(idx, len);

        if (!adj.count(srcSub)) {
            continue;
        }

        ll minPathCost = dijkstra(srcSub, tgtSub);
        if (minPathCost == BIG_VALUE)
            continue;

        minCost = min(minCost, minPathCost + solve(idx + len));
    }

    return dpMemo[idx] = minCost;
}

long long minimumCost(string source, string target, vector<string>& original, vector<string>& changed, vector<int>& cost) {
    sourceStr = source;
    targetStr = target;

    dpMemo.assign(10001, -1);

    for (int i = 0; i < original.size(); i++) {
        adj[original[i]].push_back({ changed[i], cost[i] });
    }

    for (auto& s : original) {
        validLengths.insert(s.length());
    }

    ll result = solve(0);

    return result == BIG_VALUE ? -1 : result;
}


int main() {
    string source = "abcd", target = "acbe";
    vector<string> original = { "a","b","c","c","e","d" }, changed = { "b","c","b","e","b","e" };
    vector<int> cost = { 2,5,5,1,2,20 };
    cout << minimumCost(source, target, original, changed, cost);
    return 0;
}