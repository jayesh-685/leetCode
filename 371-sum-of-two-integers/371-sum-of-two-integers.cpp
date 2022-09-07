class Solution {
public:
    int getSum(int a, int b) {
        
        while (b) {
            int tempa = a^b;
            int tempb = (unsigned)(a&b)<<1;
            a = tempa;
            b = tempb;
        }
        
        return a;
    }
};