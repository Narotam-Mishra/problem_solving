
// Implement Shortest Path Dijkstra's Algorithm

package Graph_problems;

import java.util.*;

// using custom min-Heap (priority queue)
class CustomHeap<T>{
    private List<T> heap;
    private Comparator<T> comparator;

    public CustomHeap(Comparator<T> comparator){
        this.heap = new ArrayList<>();
        this.comparator = comparator;
    }

    // up heapify operation for insertion
    private void upHeapify(int idx){
        while (idx > 0) {
            int pi = (idx - 1) / 2;
            if (comparator.compare(heap.get(pi), heap.get(idx)) > 0) {
                Collections.swap(heap, pi, idx);
                idx = pi;
            } else {
                break;
            }
        }
    }

    // utility method to insert into heap
    public void insert(T data) {
        heap.add(data);
        upHeapify(heap.size() - 1);
    }

    // down heapify operation for deletion
    private void downHeapify(int idx) {
        int size = heap.size();
        while (idx < size) {
            int lcIdx = 2 * idx + 1;
            int rcIdx = 2 * idx + 2;
            int minIdx = idx;

            if (lcIdx < size && comparator.compare(heap.get(minIdx), heap.get(lcIdx)) > 0) {
                minIdx = lcIdx;
            }

            if (rcIdx < size && comparator.compare(heap.get(minIdx), heap.get(rcIdx)) > 0) {
                minIdx = rcIdx;
            }

            if (minIdx == idx) break;

            Collections.swap(heap, idx, minIdx);
            idx = minIdx;
        }
    }

    // utility method to remove element from heap
    public T remove() {
        if (heap.isEmpty()) return null;

        T root = heap.get(0);
        T last = heap.remove(heap.size() - 1);

        if (!heap.isEmpty()) {
            heap.set(0, last);
            downHeapify(0);
        }

        return root;
    }

    // utility method to find peak element of heap
    public T peek() {
        return heap.isEmpty() ? null : heap.get(0);
    }

    // utility method to find size of heap
    public int size() {
        return heap.size();
    }
}

public class DijkstraAlgorithm {
    public static int[][] findShortestPathUsingDijkstra(int n, List<int[]>[] graph, int src){
        // using min-priority queue
        CustomHeap<int[]> pq = new CustomHeap<>(Comparator.comparingInt(a -> a[1]));

        // to track already visited nodes, we will use visited set
        Set<Integer> visited = new HashSet<>();
        
        // to track via path mapping 
        int[] via = new int[n];
        
        // to track distance (weight cost) for each node/vertex
        int[] distances = new int[n];
        
        // fill via and distances array with default values
        Arrays.fill(via, -1);
        Arrays.fill(distances, Integer.MAX_VALUE);

        // initially via path for src node is -1 and distance (weight cost) is 0
        distances[src] = 0;

        // we will insert pair of node and distance inside the min-priority queue
        pq.insert(new int[]{src, 0});

        // traverse priority queue
        while(pq.size() > 0){
            // get the topmost root node
            int[] topmost = pq.remove();

            //get node and distance (distance from source to current node)
            int node = topmost[0];
            int distance = topmost[1];

            // if we have already visited this node then ignore it because it is stale entry
            if(visited.contains(node)) continue;

            // mark the node as visited
            visited.add(node);

            // traverse all the neighbors of current node
            for(int[] neighbour : graph[node]){
                // get neighbour's node and distance
                int neighbourNode = neighbour[0];
                int neighbourDistance = neighbour[1];

                // if neighbour node is already visited then we skip it
                if(visited.contains(neighbourNode)) continue;

                if(distances[neighbourNode] > distance + neighbourDistance){
                    // previous found distance was greater than the current distance

                    // update the via mapping
                    via[neighbourNode] = node;

                    // update distance
                    distances[neighbourNode] = distance + neighbourDistance;
                    
                    // insert updated distance and neighbour node into priority queue
                    pq.insert(new int[]{neighbourNode, distances[neighbourNode]});
                }
            }
        }
        // return distances and via arrays
        return new int[][]{distances, via};
    }

    public static void main(String[] args) {
        // create graph and check above algorithm on it
        int n = 5;

        @SuppressWarnings("unchecked")
        List<int[]>[] graph = new ArrayList[n];
        for (int i = 0; i < n; i++) graph[i] = new ArrayList<>();

        graph[0].add(new int[]{1, 4});
        graph[0].add(new int[]{2, 8});
        graph[1].add(new int[]{0, 4});
        graph[1].add(new int[]{2, 2});
        graph[1].add(new int[]{3, 5});
        graph[2].add(new int[]{0, 8});
        graph[2].add(new int[]{1, 2});
        graph[2].add(new int[]{3, 5});
        graph[3].add(new int[]{1, 5});
        graph[3].add(new int[]{2, 5});
        graph[3].add(new int[]{4, 6});
        graph[4].add(new int[]{3, 6});

        int[][] res = findShortestPathUsingDijkstra(n, graph, 0);
        System.out.println("Distances are: " + Arrays.toString(res[0]));
        System.out.println("Via array is: " + Arrays.toString(res[1]));
    }
}