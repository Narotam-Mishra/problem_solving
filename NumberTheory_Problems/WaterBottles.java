package NumberTheory_Problems;

public class WaterBottles {
    public static int numWaterBottles(int numBottles, int numExchange) {
        // step 1 - start with drinking all initial bottles
        int totalDrink = numBottles;

        // step 2 - now we have numBottles empty bottles to work with
        int emptyBottles = numBottles;

        // step 3 - keep exchanging while we have enough empty bottles
        while (emptyBottles >= numExchange) {
            // step 4 - exchange: get new full bottles
            int newBottles = emptyBottles / numExchange;

            // step 5 - drink the new bottles immediately
            totalDrink += newBottles;

            // step 6 - update empty bottles: leftover + newly drunk bottles
            emptyBottles = emptyBottles % numExchange + newBottles;
        }

        // step 7 - return the maximum number of water bottles we can drink
        return totalDrink;
    }

    public static void main(String[] args) {
        // int numBottles = 9, numExchange = 3;
        int numBottles = 15, numExchange = 4;

        System.out.println(numWaterBottles(numBottles, numExchange));
    }
}
