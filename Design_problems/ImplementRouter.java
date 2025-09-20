
// Problem link - https://leetcode.com/problems/implement-router/?envType=daily-question&envId=2025-09-20

package Design_problems;

import java.util.*;

class Router {
    // map for packet mapping
    private Map<String, int[]> packetMap;

    // queue for storage and forwarding the next packet
    private Queue<String> packetQueue;

    // map for destination and timestamp mapping
    // this will help to find the number of packets currently stored in the router efficiently
    private Map<Integer, List<Integer>> desTimeMap;

    // maxSize for maximum number of packets the router can store
    private int maxSize;

    public Router(int memoryLimit) {
        // initialization
        this.maxSize = memoryLimit;
        this.packetMap = new HashMap<>();
        this.packetQueue = new LinkedList<>();
        this.desTimeMap = new HashMap<>();
    }
    
    public boolean addPacket(int source, int destination, int timestamp) {
        // make key using source, destination & timestamp
        String key = source + "_" + destination + "_" + timestamp;

        // check if current packent already exist in packetMap
        if(packetMap.containsKey(key)){
            // return false in this case
            return false;
        }

        // check if queue size is exceeded the maximum size of router
        if(packetQueue.size() >= maxSize){
            // then remove oldest packet using `forwardPacket`
            forwardPacket();
        }

        // otherwise add this packet into packetMap
        // this for easily duplicate packet detection
        packetMap.put(key, new int[]{source, destination, timestamp});

        // also add this packet into the packetQueue
        packetQueue.add(key);

        // add current destination entry in desTimeMap
        desTimeMap.putIfAbsent(destination, new ArrayList<>());
        desTimeMap.get(destination).add(timestamp);

        // return true once packet is added successfully
        return true;
    }
    
    public int[] forwardPacket() {
        // check if packetMap is mepty
        if(packetMap.isEmpty()){
            // then return empty array
            return new int[]{};
        }

        // otherwise retrieve current packet from queue
        String key = packetQueue.poll();

        // retrive packet detail from packetMap
        int[] packet = packetMap.get(key);
        // remove this packet from packetMap after retrieval
        packetMap.remove(key);

        // extract destination from packet triplet
        int destination = packet[1];
        // and remove corresponding first timestamp from `desTimeMap`
        List<Integer> timestamps = desTimeMap.get(destination);
        if(timestamps != null && !timestamps.isEmpty()){
            timestamps.remove(0);
        }

        // return packet details
        return packet;
    }

    // helper: find first index >= target
    private int lowerBound(List<Integer> list, int target) {
        int lo = 0, hi = list.size();
        while (lo < hi) {
            int mid = (lo + hi) / 2;
            if (list.get(mid) < target) {
                lo = mid + 1;
            } else {
                hi = mid;
            }
        }
        return lo;
    }

    // helper: find first index > target
    private int upperBound(List<Integer> list, int target) {
        int lo = 0, hi = list.size();
        while (lo < hi) {
            int mid = (lo + hi) / 2;
            if (list.get(mid) <= target) {
                lo = mid + 1;
            } else {
                hi = mid;
            }
        }
        return lo;
    }
    
    public int getCount(int destination, int startTime, int endTime) {
        // find timestamp from `desTimeMap` using destination,  D -> {t1,t2,t3}
        List<Integer> timestamps = desTimeMap.get(destination);

        // check if destination doesn't exist in desTimeMap
        // or the corresponding timestamps to this destination is empty
        if(timestamps == null || timestamps.isEmpty()){
            return 0;
        }

        // get lower bound timestamp index from timestamps 
        int s = lowerBound(timestamps, startTime);

        // get upper bound timestamp index from timestamps 
        int e = upperBound(timestamps, endTime);

        // return packet count between given time range
        return e - s;
    }
}

public class ImplementRouter {
    public static void main(String[] args) {
        System.out.println("Testing Router Implementation in Java");
        System.out.println("====================================");
        
        // create router with memory limit of 3
        Router router = new Router(3);
        
        // test adding packets
        System.out.println("Adding packets:");
        System.out.println("addPacket(1, 10, 100): " + router.addPacket(1, 10, 100)); // true
        System.out.println("addPacket(2, 10, 110): " + router.addPacket(2, 10, 110)); // true
        System.out.println("addPacket(3, 20, 120): " + router.addPacket(3, 20, 120)); // true
        System.out.println("addPacket(1, 10, 100): " + router.addPacket(1, 10, 100)); // false (duplicate)
        
        // test getCount
        System.out.println("\nTesting getCount:");
        System.out.println("getCount(10, 100, 115): " + router.getCount(10, 100, 115)); // 2
        System.out.println("getCount(20, 120, 130): " + router.getCount(20, 120, 130)); // 1
        System.out.println("getCount(30, 100, 200): " + router.getCount(30, 100, 200)); // 0
        
        // add another packet (should trigger removal of oldest)
        System.out.println("\nAdding packet to trigger memory limit:");
        System.out.println("addPacket(4, 30, 130): " + router.addPacket(4, 30, 130)); // true
        
        // forward packets
        System.out.println("\nForwarding packets:");
        int[] packet1 = router.forwardPacket();
        System.out.println("forwardPacket(): " + Arrays.toString(packet1)); // [2, 10, 110]
        
        int[] packet2 = router.forwardPacket();
        System.out.println("forwardPacket(): " + Arrays.toString(packet2)); // [3, 20, 120]
        
        // test getCount after forwarding
        System.out.println("\nTesting getCount after forwarding:");
        System.out.println("getCount(10, 100, 115): " + router.getCount(10, 100, 115)); // 0
        System.out.println("getCount(30, 120, 140): " + router.getCount(30, 120, 140)); // 1
        
        // forward remaining packet
        int[] packet3 = router.forwardPacket();
        System.out.println("forwardPacket(): " + Arrays.toString(packet3)); // [4, 30, 130]
        
        // try to forward when empty
        int[] emptyPacket = router.forwardPacket();
        System.out.println("forwardPacket() when empty: " + Arrays.toString(emptyPacket)); // []
    }
}
