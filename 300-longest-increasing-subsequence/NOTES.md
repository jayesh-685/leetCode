approach 1:
for every value, if it is greater than prev value, you can include it or not include it. Return max of both cases. If it's not greater return res obtained by not including it.
we pass the index of prev element and not the value so that it can be memoized easily.
​
in memo table dp[i][j] is length of lis starting with i with prev element j