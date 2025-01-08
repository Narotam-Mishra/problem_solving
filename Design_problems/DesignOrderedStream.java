
// Problem link : https://leetcode.com/problems/design-an-ordered-stream/description/?envType=problem-list-v2&envId=design

package Design_problems;

import java.util.*;

class OrderedStream {
    // array to store values
    private String[] stream;
    
    // pointer to the smallest unprocessed ID
    private int ptr;
    public OrderedStream(int n) {
        // initialize the array of size `n`
        stream = new String[n];
        
        // start the pointer at the beginning
        ptr = 0;
    }
    
    public List<String> insert(int idKey, String value) {
        // convert idKey to zero-based index
        int index = idKey - 1;
        
        // store the value at the correct position
        stream[index] = value;

        // store result in `res` list
        List<String> res = new ArrayList<>();

        // collect contiguous values starting from `ptr`
        while(ptr < stream.length && stream[ptr] != null){
            // add the value to the result
            res.add(stream[ptr]);
            
            // move the pointer to the next unprocessed ID
            ptr++;
        }

        // return the collected chunk
        return res;
    }
}

public class DesignOrderedStream {
    public static void main(String[] args) {
        OrderedStream os = new OrderedStream(5);
        System.out.println(os.insert(3, "cc")); // []
        System.out.println(os.insert(1, "aa")); // ["aa"]
        System.out.println(os.insert(2, "bb")); // ["bb", "cc"]
        System.out.println(os.insert(5, "ee")); // []
        System.out.println(os.insert(4, "dd")); // ["dd", "ee"]
    }
}