class Solution {
public:
    
//     Time Complexity: O(nlog(n) + nll)
    // l : length of string
// O(nlog(n)) for sorting
// O(nll): n for each loop, l for inner loop and l for string concatenation.
// Space Complexity: O(nl)
    int longestStrChain(vector<string>& words) {
	unordered_map <string, int> dp;
	int answer = 1;
	sort(words.begin(), words.end(), [] (const string &s1, const string &s2) {return s1.length() < s2.length();});

	for (string word: words) {
		dp[word] = 1;
		for (int i=0; i<word.length(); i++) {
			string prev = word.substr(0, i) + word.substr(i+1);
			if (dp.find(prev) != dp.end()) {
				dp[word] = max(dp[word], dp[prev]+1);
			}
			answer = max(answer, dp[word]);
		}
	}

	return answer;
}
};