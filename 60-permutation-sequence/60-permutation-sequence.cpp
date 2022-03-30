class Solution {
public:
    string getPermutation(int n, int k) {
        
        vector<int> vec;
        
        int block =1; //factorial (n-1)!
        for(int i=1; i<n; i++){
            vec.push_back(i);
            block *= i;
        }
        
        //add the missing number
        vec.push_back(n);
            
        string ans ="";
        k=k-1;
        while(1){
            
            
            ans = ans +to_string(vec[k/block]);
            
            vec.erase(vec.begin()+ (k/block));
            
            if(vec.size()==0)
                break;
            
            k = k%block;
            
            block = block/vec.size();
            
        }
        
        
        return ans;
    }
};