class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        sort(people.begin(), people.end());
        int n=people.size(), l=0, r=n-1, count=0;
        
        while (l<r) {
            if (people[l]+people[r] <= limit) {
                l++; r--; 
                count++;
            } else {
                r--;
            }
        }
        
        return count + (n-count*2);
    }
};