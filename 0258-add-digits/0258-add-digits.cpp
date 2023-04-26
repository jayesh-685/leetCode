class Solution {
public:
    int getSum (int num) {
        int sum=0;
        while (num) {
            sum += num%10;
            num /= 10;
        }
        return sum;
    }
    int addDigits(int num) {
        int ans = getSum(num);
        while (ans >= 10) {
            num = ans;
            ans = getSum(num);
        }
        
        return ans;
    }
};