class Solution {
public:
    int minStoneSum(vector<int>& piles, int k) {
        
        int sum = accumulate(piles.begin(), piles.end(), 0);
        
        priority_queue<int> pq(piles.begin(), piles.end());
        
        while(k--){
            
            int top = pq.top(); pq.pop();
            int num = top/2;
            
            sum -= num;
            
            pq.push(top-num);
            
        }
        
        
        return sum;
        
    }
};