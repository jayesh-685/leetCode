class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        for (int i=0; i<size(flowerbed) && n>0; i++) {
            if (flowerbed[i]==0) {
                if ((i==0||flowerbed[i-1]==0) && (i==size(flowerbed)-1||flowerbed[i+1]==0)) {
                    n--;
                    flowerbed[i]=1;
                }
            }
        }
        
        return !n;
    }
};