class Solution {
public:
    vector<int> replaceElements(vector<int>& arr) {
        int maxs=-1;
        for (int i=arr.size()-1; i>=0; i--) {
            int temp=arr[i];
            arr[i]=maxs;
            maxs = max(maxs, temp);
        }
        
        return arr;
    }
};