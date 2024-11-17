class Solution {
public:
    
    bool valid(string &chunk){
	    
        if(chunk =="") return false;
        //cout<<":: "<<chunk;
    int ip = stoi(chunk);
        
    //zero in digit
    if(ip == 0 && chunk.size()>1)
        return false;
        
    //chunk cannot start with zero
    if(ip>0 && chunk[0]=='0')
        return false;
    
        //within 0-255
    if( ip>=0 && ip<=255 )
		return true;

	return false;
}

void rec(int idx, string s, vector<string> &ans, string ip, int &dott, string chunk){
	
    //if(!valid(chunk))
      //  return;
    
	
		if(s.size()==idx){
            
            //add digits +  dots
			if(dott==4 && ip.size()==idx+dott){
                //cout<<idx<<" :: "<<ip<<endl;
				ip.pop_back();  //pop the last dot
				ans.push_back(ip);
				return;
			}
			else return;
		}
		
    
    //cout<<dott<<" "<<chunk<<"  :: "<<ip<<endl;

    chunk.push_back(s[idx]);
    //cout<<": "<<chunk<<endl;
	if(valid(chunk)){
		
        
		//ip+=chunk;
    //    ip.push_back('.');
		
        dott+=1;
		rec(idx+1, s, ans, ip+chunk+'.', dott, "");
		//ip.pop_back();
        //ip.erase(chunk.size()-1);
		dott--;
        
        
        rec(idx+1, s, ans, ip, dott, chunk);
	}
	//ip.pop_back();
    
	
	
}
    
    
    vector<string> restoreIpAddresses(string s) {
        		vector<string> ans;
		string ip;
		int dott=0;
        
        string chunk ="";
		rec(0, s, ans, ip, dott, chunk);
	return ans;
    }
};