class Solution {
public:
//     first sort in decreasing order
//     for every element [h, k] insert at kth index
//     since we have already inserted larger elements so value of k will be true
//     if we later insert some other element at the same index then we have to move back the larger elements but since we are inserting smaller elements their position will still be valid.
    
//     or we can sort in increasing order and insert each element after k empty spaces (for the k larger elements)
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        sort (people.begin(), people.end(), [](vector<int>p1, vector<int>p2) {
            return p1[0]==p2[0]?p1[1]<p2[1]:p1[0]>p2[0];
        });
        
        // for (auto p: people)
            // cout << p[0] << " " << p[1] << " ";
        
        vector <vector <int>> ans;
        
        for (auto p: people) {
            ans.insert(ans.begin()+p[1], p);
        }
        
        return ans;
    }
};