
// Problem link - https://leetcode.com/problems/design-movie-rental-system/?envType=daily-question&envId=2025-09-21

package Design_problems;

import java.util.*;

class MovieRentingSystem {
    // map for movie mapping with price and shop ordered pairs
    // movie -> {{price1,shop1}, {price2,shop2}}, 
    // using this we can efficiently perform search operation
    private Map<Integer, TreeSet<PriceShop>> availableMap;
    
    // ordered set of tuple for price, shop, & movie
    // ordered set -> {price,shop,movie}
    // using this we can efficiently perform report()
    private TreeSet<PriceShopMovie> rentedMovies;
    
    // map for movie mapping with shop and price ordered pairs
    // movie -> {{shop1,price1}, {shop2,price2}},
    // using this we can perform rent() efficiently
    private Map<Integer, Map<Integer, Integer>> movieShopPriceMap;

    // helper class for {price,shop} pairing
    class PriceShop implements Comparable<PriceShop> {
        int price, shop;
        
        PriceShop(int price, int shop) {
            this.price = price;
            this.shop = shop;
        }
        
        @Override
        public int compareTo(PriceShop other) {
            // sorting based on price
            if (this.price != other.price) return Integer.compare(this.price, other.price);
            
            // if price is same then sort on the basis of shop id
            return Integer.compare(this.shop, other.shop);
        }
    }

    // helper class for {price,shop,movie} triplet
    class PriceShopMovie implements Comparable<PriceShopMovie> {
        int price, shop, movie;
        
        PriceShopMovie(int price, int shop, int movie) {
            this.price = price;
            this.shop = shop;
            this.movie = movie;
        }
        
        @Override
        public int compareTo(PriceShopMovie other) {
            // sorting based on price
            if (this.price != other.price) return Integer.compare(this.price, other.price);

            // if price is same then sort on the basis of shop id
            if (this.shop != other.shop) return Integer.compare(this.shop, other.shop);

            // if price & shop both are same then sort on the basis of movie id
            return Integer.compare(this.movie, other.movie);
        }
    }

    // TC - O(logn) for insertion into the set
    public MovieRentingSystem(int n, int[][] entries) {
        // initialization
        availableMap = new HashMap<>();
        rentedMovies = new TreeSet<>();
        movieShopPriceMap = new HashMap<>();

        // iterate on entries list and extract shop, movie & price
        for(int[] entry : entries){
            int shop = entry[0];
            int movie = entry[1];
            int price = entry[2];

            // store movie -> {price,shop} entry into availableMap
            availableMap.computeIfAbsent(movie, k -> new TreeSet<>()).add(new PriceShop(price, shop));

            // store movie -> {shop,price} entry into movieShopPriceMap
            movieShopPriceMap.computeIfAbsent(movie, k -> new HashMap<>()).put(shop, price);
        }
    }
    
    // TC - O(5) equivalent to O(1), since we are searching top 5 movies only
    public List<Integer> search(int movie) {
        // store final result into `res`
        List<Integer> res = new ArrayList<>();
        // counter to track top 5 movies
        int cnt = 0;

        // check if this movie is available in `availableMap`
        TreeSet<PriceShop> availableSet = availableMap.get(movie);
        if (availableSet != null) {
            // extract price and shop from `availableMap`
            for (PriceShop ps : availableSet) {
                // store corresponding shop into `res`
                res.add(ps.shop);
                
                // increment counter
                cnt++;
                
                // break the loop since we need top 5 movies
                if (cnt >= 5) {
                    break;
                }
            }
        }

        // return final result `res`
        return res;
    }
    
    // TC - log(n), for insertion and erase operation
    public void rent(int shop, int movie) {
        // in order to rent a movie, first we need to find this movie in movieShopPriceMap value
        // as we are using TreeSet (sorted by default)
        int price = movieShopPriceMap.get(movie).get(shop);

        // since this movie is now rented,
        // so remove it from `availableMap`
        availableMap.get(movie).remove(new PriceShop(price, shop));  // O(log n)

        // update rentedMovies ordered set as well, as this movie is now rented
        rentedMovies.add(new PriceShopMovie(price, shop, movie));    // O(log n)
    }
    
    // TC - log(n), for insertion and erase operation
    public void drop(int shop, int movie) {
        // return rented movie back to the shop from where it was rented

        // extract price from `movieShopPriceMap` - O(1) lookup
        int price = movieShopPriceMap.get(movie).get(shop);

        // since this movie is now available in the shop
        // so add this movie in `availableMap`
        availableMap.get(movie).add(new PriceShop(price, shop));   // O(log n)

        // remove this movie from rentedMovies, as this movie is not rented anymore
        rentedMovies.remove(new PriceShopMovie(price, shop, movie));  // O(log n)
    }
    
    // TC - O(5) equivalent to O(1), since we are reporting top 5 cheapest movies only
    public List<List<Integer>> report() {
        // store final result into `res`
        List<List<Integer>> res = new ArrayList<>();

        // counter to track top 5 cheapest movies
        int cnt = 0;
        
        // extract price,shop & movie from `rentedMovies`
        for (PriceShopMovie psm : rentedMovies) {
            // store corresponding shop & movie into `res`
            res.add(Arrays.asList(psm.shop, psm.movie));
            
            // increment counter
            cnt++;
            
            // break the loop since we need 5 cheapest movies
            if (cnt >= 5) {
                break;
            }
        }
        
        // return final result `res`
        return res;
    }
}

public class DesignMovieRentalSystem {
    public static void main(String[] args) {
        // test case
        int[][] entries = {
            {0, 1, 5}, {0, 2, 6}, {0, 3, 7},
            {1, 1, 4}, {1, 2, 7}, {2, 1, 5}
        };
        
        // constructor call
        MovieRentingSystem system = new MovieRentingSystem(3, entries);
        
        // test search
        System.out.println("Search movie 1: " + system.search(1)); // [1, 0, 2]
        System.out.println("Search movie 2: " + system.search(2)); // [0, 1]
        System.out.println("Search movie 17: " + system.search(17)); // []
        
        // test rent
        system.rent(0, 1); // Rent movie 1 from shop 0
        system.rent(1, 2); // Rent movie 2 from shop 1
        
        // test report
        System.out.println("Report: " + system.report()); // [[1, 2], [0, 1]]
        
        // test drop
        system.drop(1, 2); // Return movie 2 to shop 1
        
        // test search after drop
        System.out.println("Search movie 2 after drop: " + system.search(2)); // [0, 1]
        
        // test report after drop
        System.out.println("Report after drop: " + system.report()); // [[0, 1]]
    }
}
