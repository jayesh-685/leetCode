class Solution {
public:
//     keep in mind you can make a pig drink mulitple buckets before waiting to die.
//     no of tests is minutsToTest/minutesToDie + 1 (+1 because if there are 5 buckest then we can check the first 4 and if the pig doesn't die we can conclude 5th bucket is the poisonous one without testing it)
//     consider no of buckets=15, mT=60, mD=15. No of tests = 60/15+1 = 5.
//     arrange the buckes in a 3 by 5 row (5 columns = no of tests)
//     pig 1 will take 15 mins to test 4 coumns (drinking the whole column at once). If it doesn't die the poisonous buckes is in the last column. Similarly for each row. Intersection of row and column gives us the poisonous bucket.
//     no of pigs is still 2 for 25 buckets(5*5) (or 5^2 where the base is no of tests and the power tells is the no of pigs)
//     for 125 buckets, visualize it as a 5*5*5 grid so 5^3 so no of pigs required is 3
    int poorPigs(int buckets, int minutesToDie, int minutesToTest) {
        int pigs=0, tests=minutesToTest/minutesToDie + 1;
        while (pow(tests, pigs) < buckets)
            pigs++;
        
        return pigs;
    }
};