class Solution {
public:
    
    int recur(int idx, vector<int> &num, int x, vector<int> &memo) {

        if(idx == num.size())
            return 0;

        if(memo[idx]!= -1)
            return memo[idx];

        int N = num.size();
        int len =0, maxx= INT_MIN, maxSum= INT_MIN;
        for (int i= idx; i< min(idx+x, N); i++) {

            len++;
            maxx = max(maxx, num[i]);
            int Sum = (len*maxx) + recur(i+1, num, x, memo);

            maxSum = max(maxSum, Sum);
        }//for


        return memo[idx] = maxSum;
    }
    
    int maxSumAfterPartitioning(vector<int>& num, int k) {
     
            vector<int> memo(num.size(), -1);
            return recur(0, num, k, memo);
        
    }
};