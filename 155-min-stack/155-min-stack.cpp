class node {
    public:
        int val, min;
        node* prev;
        node (int v, int m, node* p) {
            val = v; min = m; prev = p;
        }
};

class MinStack {
public:
    
    node* head;
    
    MinStack() {
        head = NULL;
    }
    
    void push(int val) {
        if (head == NULL) {
            head = new node (val, val, NULL);
        } else {
            node* temp = new node (val, min(val, head->min), head);
            head = temp;
        }
    }
    
    void pop() {
        node* temp = head;
        head = head->prev;
        delete temp;
    }
    
    int top() {
        return head->val;
    }
    
    int getMin() {
        return head->min;
    }
};



/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */