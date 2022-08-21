class Solution {
public:
    int minNumberOfHours(int initialEnergy, int initialExperience, vector<int>& energy, vector<int>& experience) {
        
        
        long long sum_energy=0,sum_exp=initialExperience;
        long long ans1=0,ans2=0;
        
        for(auto ele: energy) sum_energy +=ele;
        
        if(sum_energy<initialEnergy)
            ans1=0;
        else
            ans1=sum_energy-initialEnergy+1;
        
        
        
        for(auto exp: experience){
            
            if(exp>=sum_exp){
                ans2+=exp-sum_exp+1;
                sum_exp+=exp+ans2;
                               
            }else{
                sum_exp+=exp;
            }
        }
        
        
        
        
        return ans1+ans2;
        
        
    }
};