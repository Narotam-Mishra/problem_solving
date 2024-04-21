
// Problem link - https://leetcode.com/problems/design-browser-bw/

package LinkedList_problems;

class BrowserHistory {
    class Node{
        String url;
        Node back;
        Node next;

        public Node(String url){
            this.url = url;
            this.back = null;
            this.next = null;
        }
    }

    Node page;

    public BrowserHistory(String homeaPage){
        this.page = new Node(homeaPage);
    }

    public void visit(String url){
        this.page.next = new Node(url);
        this.page.next.back = this.page;
        this.page = this.page.next;
    }

    public String back(int steps){
        while (this.page.back != null && steps > 0) {
            this.page = this.page.back;
            steps--;
        }
        return this.page.url;
    }

    public String forward(int steps){
        while (this.page.next != null && steps > 0) {
            this.page = this.page.next;
            steps--;
        }
        return this.page.url;
    }
}

public class DesignBwoserHistory{
    public static void main(String[] args) {
        BrowserHistory bw = new BrowserHistory("leetcode.com");
        bw.visit("google.com");
        bw.visit("facebook.com");
        bw.visit("youtube.com");

        System.out.println(bw.back(2)); // Output: google.com
        System.out.println(bw.back(1)); // Output: leetcode.com
        System.out.println(bw.forward(2)); // Output: facebook.com
        System.out.println(bw.back(3)); // Output: leetcode.com
        System.out.println(bw.forward(7)); // Output: youtube.com

        bw.visit("hackerrank.com");
    }
}
