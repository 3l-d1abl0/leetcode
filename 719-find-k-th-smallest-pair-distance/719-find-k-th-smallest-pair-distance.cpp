class Solution {
public:
    
    int noPairs(vector<int> &arr, int mid){

        int cnt = 0;
        int right = 0;
        for (int left = 0; left < arr.size(); left++){

            while (right < arr.size() && (arr[right] - arr[left] <= mid))
                right++;

            cnt += right - left - 1;
        }

        return cnt;
    }
    
    int smallestDistancePair(vector<int>& arr, int k) {
     
            sort(arr.begin(), arr.end());

            int l = -1, r = arr[arr.size() - 1] - arr[0] + 1;

            while (r - l > 1)
            {

                int mid = l + (r - l) / 2;

                if (noPairs(arr, mid) >= k)
                {
                    r = mid;
                }
                else
                {
                    l = mid;
                }
            }

            return r;
        
    }
};