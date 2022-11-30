class Solution {
public:
    int minSubArrayLen(int K, vector<int>& A) {
        
        int n = A.size();
                
        // use multimap to store previous prefix sums. using set has
        // advantage of being sorted, so it is possible find 
        // sums in range in logN rather than N (with unsorted container)
        // we also store index of the sum so subarray len can be calculated       
        multimap<long long int, int> prefSumsSoFar;
        prefSumsSoFar.insert({0, -1});
        
        long long int prefSumI = 0;
        int res = INT_MAX;
        for(int i = 0; i < n; i++)
        {
            // calculate pref sum so far and store it
            prefSumI += A[i];
            prefSumsSoFar.insert({prefSumI, i});
                
            // since prefSumI - prefSumJ >= K, prefSumJ <= prefSumI - K,
            // so we find all prefSums that satisfy this condition
            auto prefSumJ_uppBnd = prefSumsSoFar.upper_bound(prefSumI - K);
            // if no sum satisfies above condition, continue to next element
            if(prefSumJ_uppBnd == prefSumsSoFar.begin()) continue;

            // loop trough all sums that are <= prefSumI - K and find one with 
            // min distance to current element
            for(auto it = prefSumsSoFar.begin(); it != prefSumJ_uppBnd; it++)
                res = min(res, i - it->second);

            // sums that we found we dont need to consider anymore, since even
            // if they can satisfy prefSumI - prefSumJ >= K for latter prefSumI (ie next elements)
            // resulting subarray will be larger than current result. So, delete them.
            // This is crucial to not have N^2 buth rather NlogN time complexity
            prefSumsSoFar.erase(prefSumsSoFar.begin(), prefSumJ_uppBnd);       
        }
        
        if(res == INT_MAX) return 0;
        else return res;
        
    }
};