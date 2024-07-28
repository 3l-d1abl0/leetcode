class Solution:
    def findLeastNumOfUniqueInts(self, arr: List[int], k: int) -> int:
        N = len(arr)
        
        if N <= k:
            return 0  # all removed

        freq = Counter(arr)
        
        min_heap = []
        dist = 0
        
        for key, count in freq.items():
            if count == 1:
                dist += 1
            else:
                heapq.heappush(min_heap, (count, key))
        
        if k <= dist:
            return len(freq) - k
        
        k -= dist
        
        while k > 0 and min_heap:
            count, _ = heapq.heappop(min_heap)
            if count > k:
                return len(min_heap) + 1
            k -= count
        
        return len(min_heap)