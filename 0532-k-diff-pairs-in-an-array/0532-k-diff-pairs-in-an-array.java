class Solution {
    public int findPairs(int[] nums, int k) {
        
        //https://leetcode.com/problems/k-diff-pairs-in-an-array/discuss/1756933/An-explanation-Going-from-O(NlogN)-greater-O(N)
        
        Map<Integer, Integer> map = new HashMap<>();
        
        for(int num : nums){
            map.put(num, map.getOrDefault(num, 0) + 1);
        }
        int count = 0;
        for(int x : map.keySet()){
            if(k > 0 && map.containsKey(x - k) || k == 0 && map.get(x) > 1) count++;
        }
        return count;
        
        
    }
}