class SummaryRanges {
    set <int> st;
public:
    SummaryRanges() {
        
    }
    
    void addNum(int value) {
        st.insert(value);
    }
    
    vector<vector<int>> getIntervals() {
        vector<vector<int>> ans;
        
        int n=size(st);
        int left=-1, right=-1;
        for (auto num: st) {
            if (left==-1) {
                left=right=num;
            } else if (num==right+1) {
                right++;
            } else {
                ans.push_back({left, right});
                left = right = num;
            }
        }
        
        ans.push_back({left, right});
        return ans;
    }
};

/**
 * Your SummaryRanges object will be instantiated and called as such:
 * SummaryRanges* obj = new SummaryRanges();
 * obj->addNum(value);
 * vector<vector<int>> param_2 = obj->getIntervals();
 */