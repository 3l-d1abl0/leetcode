class Solution {
public:
    
    bool method1(vector<int> &nums){
        
        int N = nums.size();
        int minni = INT_MAX;
        
        for(int j=0; j<N-1; j++){
            
            minni = min(minni, nums[j]);
            
            for(int k=j+1; k<N; k++){
                
                if(nums[j] > nums[k] && nums[k]> minni){
                    return true;
                }
            }
        }//for
   
        return false;
        
    }
    
    bool method2(vector<int> &nums){
        
        int N = nums.size();
        int firstMax = INT_MIN; //from left
        int secondMax = INT_MIN;
        
        for(int i=N-1; i>=0; i--){
            
            if(nums[i]> firstMax){
                secondMax = firstMax;
                firstMax = nums[i];
            }else if(nums[i] < secondMax){
                return true;
            }
        }
        
        
        
        firstMax = INT_MIN; //from left
        secondMax = INT_MIN;
        for(int i=0; i<N; i++){
            
            if(nums[i]> firstMax){
                secondMax = firstMax;
                firstMax = nums[i];
            }else if(nums[i] > secondMax){
                
                //cout<<secondMax<<" "<<nums[i]<<endl;
                return true;
            }
        }
        
        return false;
    }
    
    bool method3(vector<int> &nums){
        
        int N = nums.size();
        stack<int> st;
        int firstMax = INT_MIN;
        
        for(int i=N-1; i>=0; i--){
            
            //top is firstMax //if current ele is > firstMax
            while(!st.empty() && nums[i]> st.top()){
                
                firstMax = st.top();
                st.pop();
            }
            
            //fix ele as firstmax
            if(nums[i] > firstMax)
                st.push(nums[i]);
            
            if(nums[i]<firstMax)
                return true;
        }
        
        return false;
    }
    
    bool find132pattern(vector<int>& nums) {
     
        //return method1(nums); //TLE
        
        //return method2(nums); //WA\
        
        return method3(nums);
    }    
};


/*
4 3 2 6 7 8 9 5

*/