
/*
public int[] searchRange(int[] a, int target){
		
		int[] result = {-1, -1};
		
		if (a == null || a.length == 0)
			return result;
		
		result[0] = findStartPosition(a, target);
		result[1] = findEndPosition(a, target);
		
		return result;
}

public int findStartPosition(int[] a, int target){

	int left = 0;
	int right = a.length-1;
	int start =-1;
	
	while(left<= right){
	
		int mid = left+(right-left)/2;
		
		if (a[mid] == target){
				start = mid; // this is start
				right = mid-1; // lets see if there one more on the left
		}else if (target > a[mid]){
			left = mid+1;
		}else{
			right = mid-1;
		}
	}

	return start;
}

public int findEndPosition(int[] a, int target){
	int left = 0;
	int right = a.length-1;
	int end = -1;
	
	while(left <= right){
		int mid = left + (right-left)/2;
		
		if (a[mid] == target){
			end = mid;	  // this is the end
			left = mid+1; // lets see if there is one more on the right
		}else if (target > a[mid])
			left = mid +1;
		else 
			right = mid -1;
	
	}
	
	return end;
}
*/class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector <int> ans;
        int low=0, high=nums.size()-1;
        while (low<=high) {
            int mid=(low+high)/2;
            cout << low << " " << mid << " " << high << endl;
            if (nums[mid] == target) {
                if (mid==low || nums[mid-1]<target) {
                    ans.push_back(mid);
                    break;
                } else {
                    high = mid-1;
                }
            } else if (nums[mid] < target) {
                low = mid+1;
            } else {
                high = mid-1;
            }
        }
        if (!ans.size()) {
            vector <int> temp {-1, -1};
            return temp;
        }
        low=0, high=nums.size()-1;
        while (low<=high) {
            int mid=(low+high)/2;
            if (nums[mid] == target) {
                if (mid==high || nums[mid+1]>target) {
                    ans.push_back(mid);
                    break;
                } else {
                    low = mid+1;
                }
            } else if (nums[mid] < target) {
                low = mid+1;
            } else {
                high = mid-1;
            }
        }
        
        return ans;
    }
};