class Solution:
    def maxScore(self, nums1: List[int], nums2: List[int], k: int) -> int:
        
        nums3 = list(zip(nums1, nums2))
        nums3.sort(key=lambda x: x[1], reverse=True)
        
        running_sum =0
        min_heap =[]
        max_score = float('inf')
        for idx, (n1, n2) in enumerate(nums3):
            
            if idx <k:
                running_sum += n1
                heapq.heappush(min_heap, n1)
                max_score = running_sum * n2
            else:
                if len(min_heap) >0 and n1 > min_heap[0]:
                    
                    running_sum -= heapq.heappop(min_heap)
                    
                    heapq.heappush(min_heap, n1)
                    
                    running_sum += n1
                    
                    max_score = max(max_score, running_sum*n2)
            
        
        
        return max_score
        