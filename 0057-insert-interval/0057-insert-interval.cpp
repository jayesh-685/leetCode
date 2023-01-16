class Solution {
public:
//     finding the first conflicting interval then merging it with the last one and deleting it in between
    
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        int n=intervals.size(), start=newInterval[0], end=newInterval[1];
        int i=0;
//         finding the first conflicting interval
        for(i=0; i<n; i++) {
            if (intervals[i][1]>=start && intervals[i][0]<=end)
                break;
        }
        
//         incase there are no conflicting intervals insert at correct position and return
        if (i==n) {
            int k=0;
            for (k=0; k<n; k++) {
                if (intervals[k][0] > start)
                    break;
            }
            intervals.insert(intervals.begin()+k, newInterval);
            return intervals;
        }
        
//         finding the last conflicting interval
        int j=i;
        while (j<n && intervals[j][1]>=start && intervals[j][0]<=end)
            j++;
        
        // cout << i << " " << j << " " << endl;
        
//         merging conflicting intervals
        intervals[i][1] = max(intervals[j-1][1], end);
        intervals[i][0] = min(intervals[i][0], start);
//         deleting conflicting intervals
        intervals.erase(intervals.begin()+i+1, intervals.begin()+j);
        
        return intervals;
    }
};