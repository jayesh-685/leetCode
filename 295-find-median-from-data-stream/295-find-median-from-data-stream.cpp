class MedianFinder {
public:
    priority_queue <int, vector<int>, greater<>> h2;
    priority_queue <int> h1;
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        if (h1.empty()) {
            h1.push(num);
            return;
        }
        
        if (h1.size() > h2.size())
            h2.push(num);
        else
            h1.push(num);
        
        if (h1.top() > h2.top()) {
            // cout << "swapping " << h1.top() << " " << h2.top() << endl;
            int temp=h1.top(); h1.pop(); 
            h1.push(h2.top()); h2.pop();
            h2.push(temp);
            // cout << h1.top() << " " << h2.top();
        }
    }
    
    double findMedian() {
        if (h1.size() == h2.size()) {
            // cout << h1.top() << " " << h2.top() << endl;
            return (double)(h1.top()+h2.top())/2;
        }
        // cout << "hello " << endl;
        return h1.top();
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */