
// Problem link - https://leetcode.com/problems/design-a-food-rating-system/?envType=daily-question&envId=2025-09-17

#include<bits/stdc++.h>
using namespace std;

class FoodRatings {
    // map for food-rating mapping
    unordered_map<string, int> food_rating;

    // map for cuisine-food mapping along with rating
    // here we store rating with food in set of pair,
    // set element are ordered by default
    unordered_map<string, set<pair<int, string>>> cusine_ratings_food;

    // map for food-cuisine mapping 
    // using this we can find from which cuisine a particular food belong to
    unordered_map<string, string> food_cuisine;
public:
    FoodRatings(vector<string>& foods, vector<string>& cuisines, vector<int>& ratings) {
        // get size of foods
        int n = foods.size();

        // fetch each food, cuisine & rating from respective foods, cuisines & ratings
        for(int i=0; i<n; i++){
            string food = foods[i];
            string cuisine = cuisines[i];
            int rating = ratings[i];

            // insert value into cusine_ratings_food map along with rating
            cusine_ratings_food[cuisine].insert({-rating, food});

            // insert value into food_cuisine map
            food_cuisine[food] = cuisine;

            // insert value into food_rating map
            food_rating[food] = rating;
        }
    }
    
    void changeRating(string food, int newRating) {
        // in order to change rating first we need to find cuisine
        // in which the particular food belongs to
        string cuisine = food_cuisine[food];

        // get current rating
        int currRating = food_rating[food];

        // update new rating
        food_rating[food] = newRating;

        // remove current rating in cusine_ratings_food map
        cusine_ratings_food[cuisine].erase({-currRating, food});

        // then update new rating in cusine_ratings_food map as well
        cusine_ratings_food[cuisine].insert({-newRating, food});
    }
    
    string highestRated(string cuisine) {
        // since we store stored negative ratings in cusine_ratings_food map
        // so we get higest rating at beginning 
        // and then return the corresponding food
        return begin(cusine_ratings_food[cuisine])->second;
    }
};

int main(){
    vector<string> foods1 = {"kimchi", "miso", "sushi", "moussaka", "ramen", "bulgogi"};
    vector<string> cuisines1 = {"korean", "japanese", "japanese", "greek", "japanese", "korean"};
    vector<int> ratings1 = {9, 12, 8, 15, 14, 7};
    
    FoodRatings* foodRatings1 = new FoodRatings(foods1, cuisines1, ratings1);
    
    cout << "Highest rated Korean food: " << foodRatings1->highestRated("korean") << endl; // Expected: kimchi
    cout << "Highest rated Japanese food: " << foodRatings1->highestRated("japanese") << endl; // Expected: ramen
    
    foodRatings1->changeRating("sushi", 16);
    cout << "After changing sushi rating to 16:" << endl;
    cout << "Highest rated Japanese food: " << foodRatings1->highestRated("japanese") << endl; // Expected: sushi
    
    foodRatings1->changeRating("ramen", 16);
    cout << "After changing ramen rating to 16 (tie with sushi):" << endl;
    cout << "Highest rated Japanese food: " << foodRatings1->highestRated("japanese") << endl; // Expected: ramen (lexicographically smaller)
    
    delete foodRatings1;
    return 0;
}