class Solution {
public:
    int canEat (int k, vector<int>& piles, int hours) {
        long long h=0;
        for (auto pile: piles) 
            h += ceil((double)pile/k);
        
        return h<=hours;
    }
    
    int minEatingSpeed(vector<int>& piles, int h) {
        int l=1, r=*max_element(piles.begin(), piles.end());
        while (l<=r) {
            int m=l+(r-l)/2;
            if (canEat(m, piles, h))    r=m-1;
            else                        l=m+1;
        }
        
        return l;
        
    }
};