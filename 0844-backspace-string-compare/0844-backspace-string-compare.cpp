class Solution {
public:
    int getNextIndex(string &s, int idx){
        
        int cnt =0;
        
        while(idx>=0){
            
            if(s[idx]=='#'){
                cnt++;
                idx--;
            }else if(cnt>0){
                idx--;
                cnt--;
            }else{
                return idx;
            }
            
        }
        
        return idx;
    }
    
    bool backspaceCompare(string s, string t) {
        
        //Method 1
        //Build the string first 
        
        /*
            Method2
            build the string on the run , from left to right
        */
        
        int N1 = s.size()-1;
        int N2 = t.size()-1;
        
        //get next Index to compare
        while(N1>=0 && N2>=0){
            
            //cout<<N1<<" "<<N2<<endl;
            int idx1 = getNextIndex(s, N1);
            int idx2 = getNextIndex(t, N2);
            
            //ut<<idx1<<" "<<idx2<<endl;
            if(idx1<0 && idx2<0)
                return true;
            
            if(idx1<0 || idx2<0)
                return false;
            
            if(s[idx1]!=t[idx2])
                return false;
            
            N1=idx1-1;
            N2=idx2-1;
        }
        
        if(N1<0 &&N2<0)
            return true;
        
        if(N1<0)
            N2= getNextIndex(t, N2);
        else
            N1=getNextIndex(s, N1);
        
        if(N1<0 &&N2<0)
            return true;
        else
            return false;
    }
};