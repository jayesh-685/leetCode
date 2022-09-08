class Solution {
public:
/*  
start with the largest container l=0 r=n-1
if l<r then even if you decrease r area will only get smaller as you are decreasing width and if r increases it is limited by l and if r dec it is limited by r with less width
so moving l towards r makes sense
vice versa for when r<l
*/

    int maxArea(vector<int>& height) {
        int n=height.size(), l=0, r=n-1;
        int maxArea=0;
        
        while (l<r) {
            maxArea = max(maxArea, ( min(height[l],height[r]) * (r-l)) );
            if (height[l]<height[r])
                l++;
            else
                r--;
        }
        
        return maxArea;
    }
};