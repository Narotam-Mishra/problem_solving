
// Problem link - https://leetcode.com/problems/design-movie-rental-system/?envType=daily-question&envId=2025-09-21

#include<bits/stdc++.h>
using namespace std;

class MovieRentingSystem {
    // map for movie mapping with price and shop ordered pairs
    // movie -> {{price1,shop1}, {price2,shop2}}, 
    // using this we can efficiently perform search operation
    unordered_map<int, set<pair<int,int>>> availableMap;

    // ordered set of tuple for price, shop, & movie
    // ordered set -> {price,shop,movie}
    // using this we can efficiently perform report()
    set<tuple<int,int,int>> rentedMovies;

    // map for movie mapping with shop and price ordered pairs
    // movie -> {{shop1,price1}, {shop2,price2}},
    // using this we can perform rent() efficiently
    unordered_map<int, set<pair<int,int>>> movieShopPriceMap;
public:
    // TC - O(logn) for insertion into the set
    MovieRentingSystem(int n, vector<vector<int>>& entries) {
        // initialization
        // iterate on entries list and extract shop, movie & price
        for(auto &entry : entries){
            int shop = entry[0];
            int movie = entry[1];
            int price = entry[2];

            // store movie -> {price,shop} entry into availableMap
            availableMap[movie].insert({price,shop});

            // store movie -> {shop,price} entry into movieShopPriceMap
            movieShopPriceMap[movie].insert({shop,price});
        }
    }

    // TC - O(5) equivalent to O(1), since we are searching top 5 movies only
    vector<int> search(int movie) {
        // store final result into `res`
        vector<int> res;
        // counter to track top 5 movies
        int cnt = 0;

        // check if this movie is available in `availableMap`
        if(availableMap.count(movie)){  // O(1)
            // extract price and shop from `availableMap`
            for(auto &[price, shop] : availableMap[movie]){
                // store corresponding shop into `res`
                res.push_back(shop);

                // increment counter
                cnt++;

                // break the loop since we need top 5 movies
                if(cnt >= 5){
                    break;
                }
            }
        }

        // return final result `res`
        return res;
    }
    
    // TC - log(n), for insertion and erase operation
    void rent(int shop, int movie) {
        // in order to rent a movie, first we need to find this movie in movieShopPriceMap value of ordered set
        // as we are using ordered set (sorted by default) we can use lower bound to find corresponding shop & price
        auto mspIt = movieShopPriceMap[movie].lower_bound({shop, INT_MIN}); // log(n)

        // since this movie is now rented,
        // so remove it is from `availableMap`
        // extract price 
        int price = mspIt->second;
        availableMap[movie].erase({price,shop});   // log(n)

        // update rentedMovies ordered set as well, as this movie is now rented
        rentedMovies.insert({price,shop,movie});    // log(n)
    }
    
    // TC - log(n), for insertion and erase operation
    void drop(int shop, int movie) {
        // return rented movie back to the shop from where it was rented

        // since this movie is now available in the shop
        // so add this movie in `availableMap`
        // extract price from `movieShopPriceMap`
        auto mspIt = movieShopPriceMap[movie].lower_bound({shop, INT_MIN});  // log(n)
        int price = mspIt->second;
        availableMap[movie].insert({price,shop});   // log(n)

        // remove this movie from rentedMovies, as this movie is not rented anymore
        rentedMovies.erase({price,shop,movie});  // log(n)
    }
    
    // TC - O(5) equivalent to O(1), since we are reporting top 5 cheapest movies only
    vector<vector<int>> report() {
        // store final result into `res`
        vector<vector<int>> res;

        // counter to track top 5 cheapest movies
        int cnt = 0;

        // extract price,shop & movie from `rentedMovies`
        for(auto &[price,shop,movie] : rentedMovies){
            // store corresponding shop & movie into `res`
            res.push_back({shop,movie});

            // increment counter
            cnt++;

            // break the loop since we need 5 cheapest movies
            if(cnt >= 5){
                break;
            }
        }

        // return final result `res`
        return res;
    }
};

// helper function to print vector<int>
void printVector(const vector<int>& vec) {
    cout << "[";
    for (int i = 0; i < vec.size(); i++) {
        cout << vec[i];
        if (i < vec.size() - 1) cout << ", ";
    }
    cout << "]" << endl;
}

// helper function to print vector<vector<int>>
void printVectorOfVectors(const vector<vector<int>>& vec) {
    cout << "[";
    for (int i = 0; i < vec.size(); i++) {
        cout << "[";
        for (int j = 0; j < vec[i].size(); j++) {
            cout << vec[i][j];
            if (j < vec[i].size() - 1) cout << ", ";
        }
        cout << "]";
        if (i < vec.size() - 1) cout << ", ";
    }
    cout << "]" << endl;
}

int main(){
    // test case
    vector<vector<int>> entries = {
        {0, 1, 5}, {0, 2, 6}, {0, 3, 7},
        {1, 1, 4}, {1, 2, 7}, {2, 1, 5}
    };
    
    // calling constructor
    MovieRentingSystem system(3, entries);
    
    // test search
    cout << "Search movie 1: ";
    printVector(system.search(1)); // [1, 0, 2]
    
    cout << "Search movie 2: ";
    printVector(system.search(2)); // [0, 1]
    
    cout << "Search movie 17: ";
    printVector(system.search(17)); // []
    
    // test rent
    system.rent(0, 1); // Rent movie 1 from shop 0
    system.rent(1, 2); // Rent movie 2 from shop 1
    
    // test report
    cout << "Report: ";
    printVectorOfVectors(system.report()); // [[1, 2], [0, 1]]
    
    // test drop
    system.drop(1, 2); // Return movie 2 to shop 1
    
    // test search after drop
    cout << "Search movie 2 after drop: ";
    printVector(system.search(2)); // [0, 1]
    
    // test report after drop
    cout << "Report after drop: ";
    printVectorOfVectors(system.report()); // [[0, 1]]

    return 0;
}