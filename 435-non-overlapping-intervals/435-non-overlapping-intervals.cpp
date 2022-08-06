class Solution {
public:
//     greedy approach
//     sort by start vale, if two intervals merge, remove the one with minimum end time
//     since we have to return the count instead of deleting we will just keep track of count of deleted intervals and lastinterval to compare which intervals are conflicting
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), [](vector<int>& v1, vector<int>& v2){
            return v1[0]<v2[0];
        });
        int n=intervals.size(), lastEnd=intervals[0][1], ans=0;

        
        for (int i=1; i<n; i++) {   
            if (intervals[i][0] >= lastEnd) {
//                 i.e not conflicting, just update the lastEnd
                lastEnd = intervals[i][1];
            } else {
                cout << lastEnd << endl;
                ans++;
                lastEnd = min(lastEnd, intervals[i][1]);
            }
        }
        
        return ans;
    }
};