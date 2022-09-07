class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t ans=0;
        
        for (uint32_t i=0; i<32; i++) {
            uint32_t currBit=32-i-1;
            if (n&(1<<currBit)) {
                ans = ans | 1<<i;
            }
        }
        
        return ans;
    }
};