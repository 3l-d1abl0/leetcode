import heapq

class Solution:
    def medianSlidingWindow(self, nums: List[int], k: int) -> List[float]:
        result = []
        i = j = 0
        small, large = [], []
        lenNums = len(nums)
        while j < lenNums:
          heapq.heappush(small, -nums[j])
          if small and large and (-small[0] > large[0]):
            heapq.heappush(large, -heapq.heappop(small))

          if len(small) > len(large) + 1:
            heapq.heappush(large, -heapq.heappop(small))

          if len(large) > len(small) + 1:
            heapq.heappush(small, -heapq.heappop(large))

          if j - i + 1 == k:
            if len(small) == len(large):
              result.append((-small[0]+ large[0])/2)
            elif len(small) > len(large):
              result.append(-small[0])
            else:
              result.append(large[0])

            remNum = nums[i]

            if -remNum in small:
              numIndex = small.index(-remNum)
              small[numIndex] = small[-1]
              small.pop()
              if numIndex < len(small):
                  heapq._siftup(small, numIndex)
                  heapq._siftdown(small, 0, numIndex)

            elif remNum in large:
              numIndex = large.index(remNum)
              large[numIndex] = large[-1]
              large.pop()
              if numIndex < len(large):
                  heapq._siftup(large, numIndex)
                  heapq._siftdown(large, 0, numIndex)
            i += 1
          j += 1
        return result