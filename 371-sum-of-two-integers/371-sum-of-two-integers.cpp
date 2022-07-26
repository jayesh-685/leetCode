class Solution {
public:
//     if any one of the bits are 1 then the result is 1 and if both are 0 or 1 then the result is 0 (with a carry in case of both 1) so the output resembles the xor operation except the carry part. For the carry part we take & of both and left shift by 1 since we will adding carry to the left bit and then add them again using xor. Repeat till carry is not 0.
    int getSum(int a, int b) {
        int ans = a ^ b;
        unsigned int c = a & b;
        while(c != 0) {
        c <<= 1;
        int ans_prim = ans ^ c;
        c = ans & c;
        ans = ans_prim;
        }
        return ans;
    }
};