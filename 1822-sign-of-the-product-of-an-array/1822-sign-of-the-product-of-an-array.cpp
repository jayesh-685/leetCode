class Solution {
public:
    int arraySign(vector<int>& nums) {
        int nn=0;
        for (auto num: nums) {
            if (num==0) return 0;
            else if (num<0) nn++;
        }
        
        if (nn%2)   return -1;
        return 1;
        
    }
};