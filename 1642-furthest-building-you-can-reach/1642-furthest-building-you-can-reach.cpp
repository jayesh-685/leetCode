class Solution {
public:
//     use ladder for large jumps
//     bricks for small jumps
//     if k is the no of ladders then use a priority queue to find k largest jumps as you iterate over the array and for remaining jumps subtract from bricks till you run out of the bricks.
    int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
        priority_queue <int, vector<int>, greater<int>> pq;
        
        for (int i=0; i<heights.size()-1; i++) {
            if (heights[i]<heights[i+1]) {
                pq.push(heights[i+1]-heights[i]);
                if (pq.size()>ladders) {
                    int top = pq.top();
                    pq.pop();
                    bricks -= top;
                    if (bricks < 0) {
                        return i;
                    }
                }
            }
        }
        
        return heights.size()-1;
    }
};