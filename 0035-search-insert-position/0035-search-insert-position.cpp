class Solution {
public:
    
    //lower bound
    
    int searchInsert(vector<int>& arr, int x) {
        
        	int left =-1, right =arr.size();

        while (right-left>1) {
        
			int mid = left + (right-left)/2;

                        if (arr[mid] >= x) {
							right = mid;
                        } else {
							left =mid;
						}
        }

	return right;
        
    }
};