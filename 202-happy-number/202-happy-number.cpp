class Solution {
public:
    bool isHappy(int n) {
        
        int slow = n;
        int fast = n;
        
        do{
            slow = sqSum(slow);
            fast = sqSum(sqSum(fast));
        }while(slow != fast);
            
            
            
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