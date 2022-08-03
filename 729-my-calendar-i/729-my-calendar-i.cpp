class MyCalendar {
public:
//     brute force
//     for two intervals to overlap, end of first interval >= start of second interval and start of first <= end of second
//     if start second < end first then it is also possible that end second < start first which will make it a valid interval so both conditions are required
    vector <pair<int, int>> v;
    MyCalendar() {
        
    }
    
    bool book(int start, int end) {
        for (auto it: v) {
            if (it.second>start && it.first<end)
                return false;
        }
        v.push_back({start, end});
        return true;
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */