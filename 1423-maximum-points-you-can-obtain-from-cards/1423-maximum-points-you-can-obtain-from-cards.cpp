class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int sum=0, n=cardPoints.size();
        for (int i=0; i<n; i++) {
            sum += cardPoints[i];
        }
        
        int l=0, r=0, currSum=0;
        for (r=0; r<n-k; r++)
            currSum += cardPoints[r];
        
        int minSum = currSum;
        while (r<n) {
            currSum += cardPoints[r++];
            currSum -= cardPoints[l++];
            minSum = min(minSum, currSum);
        }
        
        return sum-minSum;
    }
};