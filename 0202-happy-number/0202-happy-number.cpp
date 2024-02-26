class Solution {
public:
    bool isHappy(int n) {
        
        
        //TC: O(logN)
        
        int slow = n;
        int fast = n;
        
        do{
            slow = sqSum(slow);
            fast = sqSum(sqSum(fast));
        }while(slow != fast);
            
            
        //If its stuck in 1
        return slow == 1;
    }
    
    int sqSum(int num){
        
        int sum =0;
        
        while(num>0){
            int digit = num %10;
            sum += digit*digit;
            
            num = num/10;
        }
        
        
        return sum;
    }
};