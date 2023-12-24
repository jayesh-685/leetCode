class Solution {
public:
    int minOperations(string s) {
        int initialVal = 0;
        
        int op1=0, op2=0;
        
        for (auto c: s) {
            if (c-'0' != initialVal)  op1++;
            initialVal = !initialVal;
        }
        
        initialVal = 1;
        for (auto c: s) {
            if (c-'0' != initialVal) op2++;
            initialVal = !initialVal;
        }
        
        return min(op1, op2);
    }
};