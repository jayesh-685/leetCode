class Solution {
public:
//     one solution is to use to arrays, first iterate from left to right and if rating[i]>rating[i-1] then candy[i]=candy[i-1]+1 and similary iterate from right to left.
//     can be further optimized to use single array
//     solution in single traversal and one variable:
//     plot the ratings on a graph. if you are on a peak then the no of candies for you would max of depth of valley on both sides. so if you are going up a peak maintain height of peak and keep it adding to the total. when going down a valley keep track of depth of valley and keep on adding it to the total. when you reach the bottom subtract min of peak height and valley depth from the total. total is initialized to n since each kid needs atleast one candy.
    int candy(vector<int>& arr) {
        int n=arr.size();
        int peak=0, valley=0, total=n;
        int i=1;
        
        while (i<n) {
            
            if (arr[i] == arr[i-1]) {
                i++; continue;
            }
            
            while (i<n && arr[i]>arr[i-1]) {
                peak++; 
                total+=peak;
                i++;
            }
            
            while (i<n && arr[i]<arr[i-1]) {
                valley++;
                total += valley;
                i++;
            }
            
            total -= min(valley, peak);
            peak = valley = 0;
        }
        
        return total;
    }
};