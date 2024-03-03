class Solution:
    def subarraysWithKDistinct(self, A: List[int], K: int) -> int:
        counter = {}
        pre_cnt = 0
        l = 0
        res = 0
        for r in range(len(A)):
            counter[A[r]] = counter.get(A[r], 0) + 1
            if len(counter) > K:
                counter.pop(A[l]) # counter[A[l]] is always 1
                l += 1
                pre_cnt = 0 # reset pre_cnt here
            
            
            if len(counter) == K:
                
                while counter[A[l]] > 1:
                    counter[A[l]] -= 1
                    pre_cnt += 1
                    l += 1
                
                res += pre_cnt + 1
        
        return res