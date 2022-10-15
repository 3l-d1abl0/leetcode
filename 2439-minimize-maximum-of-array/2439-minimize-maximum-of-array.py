from math import ceil
from typing import List


class Solution:
    """
    Time:   O(n)
    Memory: O(1)
    """

    def minimizeArrayValue(self, nums: List[int]) -> int:
        cum_sum = maximum = 0

        for i, num in enumerate(nums, start=1):
            cum_sum += num
            maximum = max(ceil(cum_sum / i), maximum)

        return maximum