class Solution {
    public int reversePairs(int[] nums) {
        if (nums == null) {
            throw new IllegalArgumentException();
        }
        int[] sorted = Arrays.copyOf(nums, nums.length);
        Arrays.sort(sorted); // the sorted version
        int[] bit = new int[sorted.length + 1]; // the BIT
        /**
         * Process starts. 
         **/
        int ret = 0;
        for (int i = 0; i < nums.length; ++i) {
            // step #1: get (2 * nums[i])'s position in the sorted version of nums. Since nums may contain duplicates, so get the last position of the same number in a row. 
            int index = getLastSmallerEqualPos(sorted, 2L * nums[i]);
			// step #2: compute. Adding 1 on index due to the BIT is 1-indexed. getSumBIT returns the number of visited elements that are smaller or equal to (2 * nums[i]). i - getSumBIT returns what we need
            ret += i - getSumBIT(bit, index + 1);
			// step #3: find out the index in the sorted version where nums[i] should reside. 
            index = getLastSmallerEqualPos(sorted, nums[i]);
            // step #4:  as the func name says
            updateBIT(bit, index + 1);
        }
        return ret;
    }
    
    private void updateBIT(int[] bit, int index) {
        while (index < bit.length) {
            ++bit[index];
            index += index & (-index);
        }
    }
    
    private int getSumBIT(int[] bit, int index) {
        int sub = 0;
        while (index > 0) {
            sub += bit[index];
            index -= index & (-index);
        }
        return sub;
    }
    
    private int getLastSmallerEqualPos(int[] sorted, double searched) {
        int l = 0;
        int r = sorted.length - 1;
        while (l < r) {
            int mid = l + (r - l) / 2;
            if (sorted[mid] <= searched) {
                l = mid + 1;
            } else {
                r = mid;
            } 
        }
        return sorted[l] <= searched ? l : l - 1;
    }
}