
// Problem link - https://leetcode.com/problems/implement-router/?envType=daily-question&envId=2025-09-20

#include<bits/stdc++.h>
using namespace std;

class Router {
public:
    // map for packet mapping, key -> {S,D,T}
    unordered_map<string, vector<int>> packetMap;

    // queue for forwarding the next packet
    queue<string> packetQueue;

    // map for destination and timestamp mapping D -> {t1,t2,t3}
    // this will help to find the number of packets currently stored in the router efficiently
    unordered_map<int, vector<int>> desTimeMap;

    // max_size for maximum number of packets the router can store
    int max_size;

    Router(int memoryLimit) {
        max_size = memoryLimit;
    }
    
    // TC - log(sizeof(source + destination + timestamp))
    bool addPacket(int source, int destination, int timestamp) {
        // make key using source, destination & timestamp
        string key = to_string(source) + "_" + to_string(destination) + "_" + to_string(timestamp);

        // check if current packent already exist in packetMap
        if(packetMap.find(key) != packetMap.end()){
            // then return false in this case
            return false;
        }

        // check if queue size is exceeded the maximum size of router
        if(packetQueue.size() >= max_size){
            // remove oldest packet using `forwardPacket`
            forwardPacket();
        }

        // otherwise add this packet into packetMap
        // this for easily duplicate packet detection
        packetMap[key] = {source, destination, timestamp};

        // also add this packet into the packetQueue
        packetQueue.push(key);
        
        // add current destination entry in destimeMap
        desTimeMap[destination].push_back(timestamp);
        
        // return true once packet is added successfully
        return true;
    }
    
    // TC - O(k), where k is size of timestamps vector
    vector<int> forwardPacket() {
        // check if packetMap is empty
        if(packetMap.empty()){
            // then return empty vector
            return {};
        }

        // otherwise retrieve current packet from queue
        string key = packetQueue.front();
        // and remove this packet from queue
        packetQueue.pop();

        // retrive packet detail from packetMap
        vector<int> packet = packetMap[key];
        // remove this packet from packetMap
        packetMap.erase(key);

        // extract destination from packet triplet
        int d = packet[1];
        // and remove corresponding first timestamp from `desTimeMap`
        desTimeMap[d].erase(desTimeMap[d].begin());

        // return packet details
        return packet;
    }
    
    // TC - log(sizeof(timestamp vector))
    int getCount(int destination, int startTime, int endTime) {
        // find timestamp from `desTimeMap` using destination,  D -> {t1,t2,t3}
        auto tsIt = desTimeMap.find(destination);

        // check if destination doesn't exist in `desTimeMap`
        // or the corresponding timesteamps to this destination is empty
        if(tsIt == desTimeMap.end() || tsIt->second.empty()){
            // then return 0 
            return 0;
        }

        // otherwise, fetch timestamps for this destination
        // vector<int> timestamps = tsIt->second;

        // get lower bound timestamp index from timestamps 
        // int s = lower_bound(timestamps.begin(), timestamps.end(), startTime) - begin(timestamps);

        // get upper bound timestamp index from timestamps 
        // int e = upper_bound(timestamps.begin(), timestamps.end(), endTime) - begin(timestamps);

        // get lower bound timestamp index from timestamps 
        int s = lower_bound(tsIt->second.begin(), tsIt->second.end(), startTime) - begin(tsIt->second);

        // get upper bound timestamp index from timestamps 
        int e = upper_bound(tsIt->second.begin(), tsIt->second.end(), endTime) - begin(tsIt->second);

        // return packet count between given time range
        return e - s;
    }
};

int main(){
    cout << "Testing Router Implementation in C++" << endl;
    cout << "====================================" << endl;
    
    // create router with memory limit of 3
    Router router(3);
    
    // test adding packets
    cout << "Adding packets:" << endl;
    cout << "addPacket(1, 10, 100): " << (router.addPacket(1, 10, 100) ? "true" : "false") << endl; // true
    cout << "addPacket(2, 10, 110): " << (router.addPacket(2, 10, 110) ? "true" : "false") << endl; // true
    cout << "addPacket(3, 20, 120): " << (router.addPacket(3, 20, 120) ? "true" : "false") << endl; // true
    cout << "addPacket(1, 10, 100): " << (router.addPacket(1, 10, 100) ? "true" : "false") << endl; // false (duplicate)
    
    // test getCount
    cout << "\nTesting getCount:" << endl;
    cout << "getCount(10, 100, 115): " << router.getCount(10, 100, 115) << endl; // 2
    cout << "getCount(20, 120, 130): " << router.getCount(20, 120, 130) << endl; // 1
    cout << "getCount(30, 100, 200): " << router.getCount(30, 100, 200) << endl; // 0
    
    // add another packet (should trigger removal of oldest)
    cout << "\nAdding packet to trigger memory limit:" << endl;
    cout << "addPacket(4, 30, 130): " << (router.addPacket(4, 30, 130) ? "true" : "false") << endl; // true
    
    // forward packets
    cout << "\nForwarding packets:" << endl;
    vector<int> packet1 = router.forwardPacket();
    cout << "forwardPacket(): [" << packet1[0] << ", " << packet1[1] << ", " << packet1[2] << "]" << endl; // [2, 10, 110]
    
    vector<int> packet2 = router.forwardPacket();
    cout << "forwardPacket(): [" << packet2[0] << ", " << packet2[1] << ", " << packet2[2] << "]" << endl; // [3, 20, 120]
    
    // test getCount after forwarding
    cout << "\nTesting getCount after forwarding:" << endl;
    cout << "getCount(10, 100, 115): " << router.getCount(10, 100, 115) << endl; // 0
    cout << "getCount(30, 120, 140): " << router.getCount(30, 120, 140) << endl; // 1
    
    // forward remaining packet
    vector<int> packet3 = router.forwardPacket();
    cout << "forwardPacket(): [" << packet3[0] << ", " << packet3[1] << ", " << packet3[2] << "]" << endl; // [4, 30, 130]
    
    // try to forward when empty
    vector<int> emptyPacket = router.forwardPacket();
    cout << "forwardPacket() when empty: ";
    if (emptyPacket.empty()) {
        cout << "[]" << endl;
    } else {
        cout << "[" << emptyPacket[0] << ", " << emptyPacket[1] << ", " << emptyPacket[2] << "]" << endl;
    }

    return 0;
}