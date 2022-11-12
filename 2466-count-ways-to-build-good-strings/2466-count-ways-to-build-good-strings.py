class Solution:
    def countGoodStrings(self, low: int, high: int, zero: int, one: int) -> int:
        LIM = (20**5)+5
        MOD = (10**9)+7
        RANGE = (10**5)+5
        
        ans = [0]*LIM
        
        #print(len(ans))
        
        ans[0] = 1
        for idx in range(0, RANGE):
            #print(idx+zero)
            ans[idx+zero] %=MOD
            ans[idx+zero] +=ans[idx]
            
            ans[idx+one] %=MOD
            ans[idx+one] +=ans[idx]
            
        sum =0;
        for idx in range(low, high+1):
            sum = (sum+ans[idx])%MOD
            
            
        return sum
            
        
        