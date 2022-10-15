class Solution {
public:
    
    int getHr(string &time){
        
        if(time[0]=='?' && time[1]=='?'){
            return 24;
        }else if(time[0]=='0' && time[1]=='?'){
            return 10;
        }else if(time[0]=='1' && time[1]=='?'){
            return 10;
        }else if(time[0]=='2' && time[1]=='?'){
            return 4;
        }else if(time[0]=='?' && time[1]>='5'){
            return 2;
        }else if(time[0]=='?' && time[1]=='4'){
            return 2;
        }else if(time[0]=='?' && time[1]<='3'){
            return 3;
        }else{
            return 1;
        }
        
    }
    
    
    int getMin(string &time){
        
        if(time[3]=='?' && time[4]=='?'){
            return 60;
        }else if(time[3]=='?'){
            return 6;
        }else if(time[4]=='?'){
            return 10;
        }else{
            return 1;
        }
        
    }
    
    int countTime(string time) {
        
        
        int hr =getHr(time);
        
        int mi=getMin(time);
        
        //cout<<hr<<" "<<mi<<endl;
        return hr*mi;
        
    }
};