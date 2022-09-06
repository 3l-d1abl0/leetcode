class Solution {
public:
    
    int XOR(int n){
        
        int mod =n%4;
        
        if(mod==0)
            return n;
        else if(mod==1)
            return 1;
        else if(mod==2)
            n+1;
        else //if(mod==3)
            return 0;
        
        return -1;
    }
    vector<int> decode(vector<int>& encoded) {
        
        int N= encoded.size()+1;
        
        int XORed = XOR(N);
        int XORe=0, XORo=0;
        
        for(int i=0; i<N-1; i++){
            if(i&1)
                XORo ^=encoded[i];
            else
                XORe ^=encoded[i];
        }
        
        vector<int> perm(N);
        perm[0] = XORed ^ XORo;
        perm[N-1] = XORed ^ XORe;
        
        for(int i=1; i<N-1; i++){
            perm[i]= encoded[i-1]^perm[i-1];
        }
        
        return perm;
    }
};