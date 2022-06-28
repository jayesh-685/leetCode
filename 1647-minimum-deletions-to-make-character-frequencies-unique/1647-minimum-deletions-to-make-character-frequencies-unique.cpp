class Solution {
public:
    int minDeletions(string s) {
        vector <int> freqArr (26, 0);
        for (auto c: s)
            freqArr[c-'a']++;
        
        // for (auto c: freqArr)
            // cout << c << " ";
        
        sort (freqArr.begin(), freqArr.end(), greater<int>());
        int cost=0;
        
        for (int i=1; i<freqArr.size() && freqArr[i]!=0; i++) {
            if (freqArr[i] >= freqArr[i-1]) {
                int init = freqArr[i];
                freqArr[i] = freqArr[i-1]-1;
                if (freqArr[i]<0) {
                    freqArr[i]=0;
                }
                cost += init-freqArr[i];
            }
        }
        
        return cost;
        
    }
};