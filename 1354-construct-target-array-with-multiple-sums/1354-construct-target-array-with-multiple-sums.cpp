class Solution {
public:
//     from given array try creating array with all elements 1
//     take the largest element and subtract from it the sum of remaining elements, if possible. If not possible return false. Continue till max element is 1
    bool isPossible(vector<int>& target) {
        priority_queue <long long> pq;
        long long sum=0;
        for (long long i=0; i<target.size(); i++) {
            sum += target[i];
            pq.push(target[i]);
        }
        
        // cout << pq.top().first << endl;
        
        while (true) {
            long long a = pq.top(); pq.pop();
            sum -= a;
            // cout << "Sum= " << sum << endl;
            if (a==1 || sum==1)
                return true;
            if (sum>a || sum==0 || a%sum==0)
                return false;
            
            a %= sum;
            pq.push(a);
            sum += a;
        }
        
        return false;
    }
};