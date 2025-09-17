
// Problem link - https://leetcode.com/problems/design-a-food-rating-system/?envType=daily-question&envId=2025-09-17

package Design_problems;

import java.util.*;

class FoodRatings {
    private class FoodItem implements Comparable<FoodItem>{
        int rating;
        String foodName;

        FoodItem(int rating, String foodName){
            this.rating = rating;
            this.foodName = foodName;
        }

        // custom comparator
        @Override
        public int compareTo(FoodItem fi){
            // first compare by rating (descending order)
            if(this.rating != fi.rating){
                return Integer.compare(fi.rating, this.rating);
            }

            // if ratings are equal, compare by name (ascending order)
            return this.foodName.compareTo(fi.foodName);
        }
    }

    // map for food-rating mapping
    private Map<String, Integer> foodRating;

    // map for food-cuisine mapping along with rating
    // TreeSet maintains elements in sorted order (by rating desc, then by name asc)
    private Map<String, TreeSet<FoodItem>> cuisineRatingFood;

    // map for food-cuisine mapping
    private Map<String, String> foodCuisine;

    public FoodRatings(String[] foods, String[] cuisines, int[] ratings) {
        // get size of food array
        int n = foods.length;

        // initialize 
        foodRating = new HashMap<>();
        cuisineRatingFood = new HashMap<>();
        foodCuisine = new HashMap<>();

        // fetch each food, cuisine & rating from respective foods, cuisines & ratings
        for(int i=0; i<n; i++){
            String food = foods[i];
            String cuisine = cuisines[i];
            int rating = ratings[i];

            // initialize TreeSet for cuisine if not exists
            cuisineRatingFood.putIfAbsent(cuisine, new TreeSet<>());

            // add food item to cuisine set
            cuisineRatingFood.get(cuisine).add(new FoodItem(rating, food));

            // store food-cuisine mapping
            foodCuisine.put(food, cuisine);

            // store food-rating mapping
            foodRating.put(food, rating);
        }
    }
    
    public void changeRating(String food, int newRating) {
        // in order to change rating first we need to find cuisine for this food
        String cuisine = foodCuisine.get(food);

        // get current rating
        int currRating = foodRating.get(food);

        // update new rating
        foodRating.put(food, newRating);

        // remove old food item's rating from cuisine set
        cuisineRatingFood.get(cuisine).remove(new FoodItem(currRating, food));

        // update new food item's rating in cuisine set as well
        cuisineRatingFood.get(cuisine).add(new FoodItem(newRating, food));
    }
    
    public String highestRated(String cuisine) {
        // get the first (highest rated) food item from the cuisine set
        return cuisineRatingFood.get(cuisine).first().foodName;
    }
}

public class DesignFoodRatingSystem {
    public static void main(String[] args) {
        String[] foods1 = {"kimchi", "miso", "sushi", "moussaka", "ramen", "bulgogi"};
        String[] cuisines1 = {"korean", "japanese", "japanese", "greek", "japanese", "korean"};
        int[] ratings1 = {9, 12, 8, 15, 14, 7};
        
        FoodRatings foodRatings1 = new FoodRatings(foods1, cuisines1, ratings1);
        
        System.out.println("Highest rated Korean food: " + foodRatings1.highestRated("korean")); // Expected: kimchi
        System.out.println("Highest rated Japanese food: " + foodRatings1.highestRated("japanese")); // Expected: ramen
        
        foodRatings1.changeRating("sushi", 16);
        System.out.println("After changing sushi rating to 16:");
        System.out.println("Highest rated Japanese food: " + foodRatings1.highestRated("japanese")); // Expected: sushi
        
        foodRatings1.changeRating("ramen", 16);
        System.out.println("After changing ramen rating to 16 (tie with sushi):");
        System.out.println("Highest rated Japanese food: " + foodRatings1.highestRated("japanese")); // Expected: ramen
    }
}
