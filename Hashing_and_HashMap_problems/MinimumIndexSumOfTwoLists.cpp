
#include<bits/stdc++.h>
using namespace std;

vector<string> findRestaurant(vector<string>& list1, vector<string>& list2) {
    // step 1 - create map to store index of each word in list1
    unordered_map<string, int> map;
    for (int i = 0; i < list1.size(); i++) {
        map[list1[i]] = i;
    }

    // store minimum index sum
    int minIndexSum = INT_MAX;

    // store words with the least index sum
    vector<string> res;

    // step 2 - iterate through list2 and find common words
    for (int j = 0; j < list2.size(); j++) {
        // check if the list2 word exists in list1
        if (map.find(list2[j]) != map.end()) {
            // get index from list1
            int i = map[list2[j]];

            // calculate index sum
            int indexSum = i + j;

            // step 3 - update minimum index sum and store corresponding word
            if (indexSum < minIndexSum) {
                minIndexSum = indexSum;
                // reset result with the new least sum word
                res.clear();
                res.push_back(list2[j]);
            }
            else if (indexSum == minIndexSum) {
                res.push_back(list2[j]);
            }
        }
    }

    // step 4 - return all common words with the least index sum
    return res;
}

void printVector(vector<string>& vec){
    cout << "[";
    for (size_t i = 0; i < vec.size(); ++i) {
        cout<<vec[i];
        if (i < vec.size() - 1) {
            cout<<",";
        }
    }
    cout<< "]" <<endl;
}

int main(){
    // vector<string> list1 = {"Shogun","Tapioca Express","Burger King","KFC"};
    // vector<string> list2 = {"Piatti","The Grill at Torrey Pines","Hungry Hunter Steakhouse","Shogun"};

    // vector<string> list1 = {"Shogun","Tapioca Express","Burger King","KFC"};
    // vector<string> list2 = {"KFC","Shogun","Burger King"};

    vector<string> list1 = {"happy","sad","good"};
    vector<string> list2 = {"sad","happy","good"};
    vector<string> res = findRestaurant(list1, list2);
    printVector(res);
    return 0;
}