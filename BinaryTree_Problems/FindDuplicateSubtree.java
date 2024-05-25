
// Problem link - https://leetcode.com/problems/find-duplicate-subtrees/description/

package BinaryTree_Problems;

import java.util.*;

public class FindDuplicateSubtree {

    private static List<Integer> treeToArray(TreeNodeUtil root){
        List<Integer> res = new ArrayList<>();
        List<TreeNodeUtil> queue = new ArrayList<>();
        queue.add(root);
        while (!queue.isEmpty()) {
            TreeNodeUtil node = queue.remove(0);
            if(node != null){
                res.add( node.val);
                queue.add(node.left);
                queue.add(node.right);
            }else{
                res.add(null);
            }
        }
        while(res.get(res.size() - 1) == null){
            res.remove(res.size() - 1);
        }
        return res;
    }

    public static List<List<Integer>> convertTreesToArrays(List<TreeNodeUtil> trees){
        List<List<Integer>> res = new ArrayList<>();
        for(TreeNodeUtil tree : trees){
            res.add(treeToArray(tree));
        }
        return res;
    }

    private static String serializeBT(TreeNodeUtil node, Map<String, Integer> nodeMap, List<TreeNodeUtil> res){
        // base case: if tree node has no child then return '#' to indicate null
        if(node == null) return "#";

        // recursive case: recursively traverse left and right subtrees
        String lst = serializeBT(node.left, nodeMap, res);
        String rst = serializeBT(node.right, nodeMap, res);

        // arrange node's value
        String str = "" + node.val + "," + lst + "," + rst;

        // maitain node's value entry in map 'nodeMap'
        nodeMap.put(str, nodeMap.getOrDefault(str, 0) + 1);

        // if there is a duplicate of node's val then store its root into result list 'res'
        if(nodeMap.get(str) == 2){
            res.add(node);
        }
        // return
        return str;
    }
    @SuppressWarnings("unchecked")
    public static List<TreeNodeUtil> findDuplicateSubtrees(TreeNodeUtil root) {
        @SuppressWarnings("rawtypes")
        Map mp = new HashMap<>();
        List<TreeNodeUtil> res = new ArrayList<>();
        serializeBT(root, mp, res);
        return res;
    }

    public static void main(String[] args) {
        BinaryTreeUtil bt = new BinaryTreeUtil();
        int[] arr = {1,2,3,4,2,4,4};
        bt.initializeTree(arr);
        List<TreeNodeUtil> duplicates = findDuplicateSubtrees(bt.root);
        List<List<Integer>> res = convertTreesToArrays(duplicates);
        // print duplicate subtree's node value
        System.out.println("Duplicate Subtree: "+res);
        
    }
}