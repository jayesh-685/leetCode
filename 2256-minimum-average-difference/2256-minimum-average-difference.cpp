class Solution {
public:
    int minimumAverageDifference(vector<int>& nums) {
        long long n=nums.size();
        vector<long long> pre(n, 0);
        pre[0] = nums[0];
        
        for (int i=1; i<n; i++)
            pre[i] = pre[i-1] + nums[i];
        
        vector<long long> suff(n, 0);
        suff[n-1] = nums[n-1];
        for (int i=n-2; i>=0; i--)
            suff[i] = suff[i+1] + nums[i];
        
        long long ans = INT_MAX;
        int ansi=0;
        
        for (int i=0; i<n; i++) {
            int ps = pre[i]/(i+1);
            int ss = i==n-1 ? 0 : suff[i+1]/(n-i-1);
            int avg = abs(ps - ss);
            if (avg < ans) {
                ans = avg;
                ansi = i;
            }
        }
        
        return ansi;
    }
};