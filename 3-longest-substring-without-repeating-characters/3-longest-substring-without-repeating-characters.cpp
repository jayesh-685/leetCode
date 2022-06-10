class Solution {
public:
    int lengthOfLongestSubstring(string s) {
	vector <int> lastOcc (130, -1);
	int l=0, r=0;
	int res = 0, length = 0;
	int n = s.length();
	while (r<n) {
		if (lastOcc[s[r]] != -1) {
			l = max(l, lastOcc[s[r]]+1);
		}
		lastOcc[s[r]] = r;
		length = r-l+1;
		res = max(res, length);
        r++;
	}

	return res;
}
};