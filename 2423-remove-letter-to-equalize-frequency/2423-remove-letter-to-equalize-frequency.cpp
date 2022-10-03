class Solution {
public:
    bool equalFrequency(string word) {
        
        int N = word.size();
        
        
        unordered_map<char, int> mp;
        
        for(char ch:word){
            mp[ch]++;
        }
        
        auto it = mp.begin();
        int freq = (*it).second;
        
        //cout<<"f "<<freq<<endl;
        int ctr =0;
        
        it++;
        for(; it!=mp.end(); it++){
            
            if(freq != (*it).second ){
                
                if( abs(freq - (*it).second) ==1){
                    if(ctr>0){
                        cout<<"qq"<<endl;
                        return false;
                    }
                    
                    ctr++;
                    freq = min(freq, (*it).second);
                    
                }else if(abs(freq - (*it).second) >1){
                    cout<<"ww"<<endl;
                    return false;
                }
                
            }
        }
        
        cout<<"ctr "<<ctr<<endl;
        if(ctr==1)
         return true;
        else{
            if(freq==1)
                return true;
            if(mp.size() == 1)
                return true;
         return false;
        }
    }
};