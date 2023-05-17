class Solution {
public:
    int halveArray(vector<int>& nums) {
        
        
        int N = nums.size();
        
        priority_queue<double> pq(nums.begin(), nums.end()); //max
        
        
        double sum = accumulate(nums.begin(), nums.end(), 0.0);
        
        double currentSum = sum;
        int ctr = 0;
        sum /= 2;
        
        while(currentSum > sum){
            
            
            double num = (double)pq.top()/2;
            pq.pop();
            
            currentSum -= num;
            
            pq.push(num);
            
            ctr++;
        } 
        
        return ctr;
    }
};