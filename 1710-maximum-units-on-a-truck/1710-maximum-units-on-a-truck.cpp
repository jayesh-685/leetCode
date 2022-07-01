// since the constraints are small you can use an array to store units per box for each product in a 1000 sized array and you won't need to sort making the solution O(n)
class Solution {
public:
    
    static bool mysort (vector<int>& v1, vector<int>& v2) {
        return v1[1]>v2[1];
    }
    
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
        sort(boxTypes.begin(), boxTypes.end(), mysort);
        
        int units=0, i=0;
        while (i<boxTypes.size() && truckSize) {
            if (boxTypes[i][0]<=truckSize) {
                truckSize -= boxTypes[i][0];
                units += boxTypes[i][0]*boxTypes[i][1];
                i++;
            } else {
                units += truckSize*boxTypes[i][1];
                truckSize = 0;
            }
        }
        
        return units;
    }
};