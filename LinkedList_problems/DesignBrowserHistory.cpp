
// Problem link - https://leetcode.com/problems/design-browser-bw/

#include<bits/stdc++.h>
using namespace std;

class BrowserHistory{
private:
    class Node{
    public:
        string url;
        Node* back;
        Node* next;

        Node(string url){
            this->url = url;
            this->back = nullptr;
            this->next = nullptr;
        }
    };

    Node* page;

public:
    BrowserHistory(string homepage){
        this->page = new Node(homepage);
    }

    void visit(string url){
        this->page->next = new Node(url);
        this->page->next->back = this->page;
        this->page = this->page->next;
    }

    string back(int steps){
        while(steps && this->page->back != nullptr){
            this->page = this->page->back;
            steps--;
        }
        return this->page->url;
    }

    string forward(int steps){
        while(steps && this->page->next != nullptr){
            this->page = this->page->next;
            steps--;
        }
        return this->page->url;
    }
};

int main(){
    BrowserHistory history("leetcode.com");
    history.visit("google.com");
    history.visit("facebook.com");
    history.visit("youtube.com");

    cout << history.back(2) << endl; // Output: google.com
    cout << history.back(1) << endl; // Output: leetcode.com
    cout << history.forward(2) << endl; // Output: facebook.com
    cout << history.back(3) << endl; // Output: leetcode.com
    cout << history.forward(7) << endl; // Output: youtube.com

    history.visit("hackerrank.com");
    return 0;
}

