
#include<bits/stdc++.h>
using namespace std;

int calPoints(vector<string>& operations) {
    // using stack to perform each operation
    stack<int> score;

    // step 1 - iterate on each operation `op`
    for (string op : operations) {
        // step 2 - perform each operation in stack `score`
        if (op == "+") {
            // for `+` add sum of previous two scores
            int top1 = score.top(); score.pop();
            int top2 = score.top();
            int newScore = top1 + top2;
            score.push(top1);
            score.push(newScore);
        }
        else if (op == "C") {
            // cancel (remove) the previous score
            score.pop();
        }
        else if (op == "D") {
            // add double of previous score
            int newScore = score.top() * 2;
            score.push(newScore);
        }
        else {
            // it's an integer - add new score to stack `score` record
            int num = stoi(op);
            score.push(num);
        }
    }
    int sum = 0;
    while (!score.empty()) {
        sum += score.top();
        score.pop();
    }
    return sum;
}

int main(){
    // vector<string> ops = {"5","2","C","D","+"};

    vector<string> ops = {"5","-2","4","C","D","9","+","+"};
    cout<<calPoints(ops)<<endl;
    return 0;
}