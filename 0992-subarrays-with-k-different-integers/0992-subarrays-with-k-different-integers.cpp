class Solution {
public:
    int subarraysWithKDistinct(vector<int>& A, int K) {
        
         int res = 0, prefix = 0;
        int start = 0;
        int distinctCount = 0;
        unordered_map<int, int> countMap;

        for (int right = 0; right < A.size(); right++) {
            int rightNum = A[right];

            if (countMap.find(rightNum) == countMap.end() || countMap[rightNum] == 0) {
                distinctCount++;
            }

            countMap[rightNum] = countMap[rightNum] + 1;

            if (distinctCount > K) {
                int startNum = A[start];
                start++;
                prefix = 0;
                countMap[startNum] = countMap[startNum] - 1;
                distinctCount--;
            }

            while (countMap[A[start]] > 1) {
                int startNum = A[start++];
                countMap[startNum] = countMap[startNum] - 1;
                prefix++;
            }

            if (distinctCount == K) {
                res += prefix + 1;
            }
        }

        return res;
        
    }
};