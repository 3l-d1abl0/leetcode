from heapq import *

class Solution:
    def findClosestElements(self, arr: List[int], k: int, x: int) -> List[int]:
        maxHeap = []
        N = len(arr)

        for idx in range(k):

            heappush(maxHeap, ( - abs(x-arr[idx]), arr[idx]))


        for idx in range(k, N):

            if abs(x-arr[idx]) < -maxHeap[0][0]:
                heappush(maxHeap, ( - abs(x-arr[idx]), arr[idx]))

            if len(maxHeap)>k:
                heappop(maxHeap)

        ans = []

        while maxHeap:

            ans.append(heappop(maxHeap)[1])

        ans.sort()

        return ans