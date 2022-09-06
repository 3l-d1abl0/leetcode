class Solution {
public:
    int rangeBitwiseAnd(int left, int right) {
        
        if(left==right) return right;
        if(left+1==right) return left&right;
        
        long long int digl= left==0?0:floor(log2(left));
        long long int digr= right==0?0:floor(log2(right));
        
        if(digl!=digr)
            return 0;
        //cout<<"Dig: "<<digl<<endl;
        
        int idx = min(30*1LL, min(digl,digr) );
        int ans =0;
        for(; idx>=0; idx--){
            
            //cout<<(1<<idx)<<endl;
            if( ((1<<idx & left) == (1<<idx & right)) && ((1<<idx & left) == 1<<idx)){
                ans = ans | (1<<idx);
            }else if( (1<<idx & left)==0 && (1<<idx & right)==0 ){
                continue;
            }else{
                //cout<<"idx = "<<idx<<endl;
                return ans;
            }
        }
        
        return 0;
    }
};