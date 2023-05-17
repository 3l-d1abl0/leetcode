class Solution:
    def halveArray(self, nums: List[int]) -> int:
        
        totalSum = sum(nums)
        currentSum = totalSum
        totalSum /=2
        
        
        new_list = [-ele for ele in nums]
        
        heapify(new_list)
        
        ctr=0
        while currentSum > totalSum:
            
            #Make the new ele positive
            ele = - heappop(new_list) 
            
            ele /=2
            
            currentSum -= ele
            
            heappush(new_list, -ele)
            
            ctr+=1
            
            
        return ctr
            
        