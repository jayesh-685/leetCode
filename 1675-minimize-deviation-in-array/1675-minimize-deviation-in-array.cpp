class Solution {
public:
    // if we have both options available to use (dec and inc) it would be difficult to implement so we find max values of all nos (by doubling all odd values) and then start decreasing the nos (starting from the largest). use priority_queue for the same and proceed till are nos are odd (min).
    int minimumDeviation(vector<int>& nums) {
        priority_queue<int> evens;
        int minimum = INT_MAX;
        for (int num : nums) {
            if (num % 2 == 0) {
                evens.push(num);
                minimum = min(minimum, num);
            } else {
                evens.push(num * 2);
                minimum = min(minimum, num * 2);
            }
        }
        int minDeviation = INT_MAX;
        while (!evens.empty()) {
            int currentValue = evens.top();
            evens.pop();
            minDeviation = min(minDeviation, currentValue - minimum);
            if (currentValue % 2 == 0) {
                evens.push(currentValue / 2);
                minimum = min(minimum, currentValue / 2);
            } else {
                // if the maximum is odd, break and return
                break;
            }
        }
        return minDeviation;
    }
};