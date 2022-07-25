class Solution {
public:
//     brute force way is to count bits for each number individually
//     better way is that: odd nos have their lsb as 1 and even nos have it as 1. Dividing a no by 2 is left shifting by 1. If no is even and we divide it by 0 then we lose a 0 so no of bits in x is same as that of x/2. If no is odd then on dividing by 2 we loose a 1 so no of bits in x is 1 + no of bits in x/2
    vector<int> countBits(int n) {
        vector <int> ans (n+1);
        ans[0] = 0;
        for (int i=1; i<=n; i++) {
            if (i%2)
                ans[i] = ans[i/2]+1;
            else
                ans[i] = ans[i/2];
        }
        
        return ans;
        
    }
};