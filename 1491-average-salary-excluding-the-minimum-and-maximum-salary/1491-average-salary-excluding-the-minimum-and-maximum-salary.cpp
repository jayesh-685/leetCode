class Solution {
public:
    double average(vector<int>& salary) {
        int sum = accumulate(begin(salary), end(salary), 0);
        sum -= *min_element(begin(salary), end(salary));
        sum -= *max_element(begin(salary), end(salary));
        
        double ans = (double)sum/(size(salary)-2);
        return ans;
    }
};