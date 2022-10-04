from bisect import bisect_right
from sortedcontainers import SortedList

class Solution:
    def numberOfPairs(self, nums1: List[int], nums2: List[int], diff: int) -> int:
        
        N = nums1.__len__() 
        
        sl = SortedList()
        ans = 0
        #for idx in range(0, N):
        for n1, n2 in zip(nums1, nums2):
            
            ans += sl.bisect_right(n1-n2+diff)
            sl.add(n1-n2)
            
            
        return ans
        '''
    
        deltas = SortedList()
        pairs = 0
        for num1, num2 in zip(nums1, nums2):
            delta = num1 - num2
            pairs += deltas.bisect_right(delta + diff)
            deltas.add(delta)
        return pairs'''
            