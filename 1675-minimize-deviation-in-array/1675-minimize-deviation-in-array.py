class Solution:
    def minimumDeviation(self, nums: List[int]) -> int:
        maxH = []
        minE = float('inf')
        
        for ele in nums:
            if ele % 2 == 1:  # odd - can be doubled
                ele *= 2
            
            minE = min(minE, ele)  # keep track of min ele so far
            heapq.heappush(maxH, -ele)  # push negative to simulate max-heap
        
        minDev = float('inf')
        
        while -maxH[0] % 2 == 0:
            maxE = -heapq.heappop(maxH)  # pop the largest element (simulating max-heap)
            minDev = min(minDev, maxE - minE)
            maxE //= 2
            minE = min(minE, maxE)
            heapq.heappush(maxH, -maxE)
        
        return min(minDev, -maxH[0] - minE)