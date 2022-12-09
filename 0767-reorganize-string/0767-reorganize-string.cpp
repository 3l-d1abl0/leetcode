class Solution {
public:
    string reorganizeString(string s) {
        
        
        unordered_map<char, int> mp;
        
        int freq =-1;
        for(char c: s){
            
            mp[c]++;
            freq = max(freq, mp[c]);
            
        }
        
        if(freq > (s.size()+1) /2)
            return "";
        
        
        priority_queue<pair<int, int>> maxH;
        
        unordered_map<char, int>::iterator it;  //freq, char
        for(it = mp.begin(); it!= mp.end(); it++ ){
            maxH.push({it->second, it->first});
            //cout<<it->first<<" , "<<it->second<<" ";
        }
        //cout<<endl;
        
        string ans ="";
        int idx =0;
        while(!maxH.empty()){
            
            pair<int, char > top = maxH.top(); maxH.pop();
            if(idx==0){
                
                ans.push_back(top.second);
                
                idx++;
                
                if(--top.first >0){
                    maxH.push(top);
                }
                
                //cout<<"1. "<<top.first<<" "<<top.second<<endl;
                
            }else if(top.second != ans[idx-1]){
                
                ans.push_back(top.second);
                
                idx++;
                
                if(--top.first >0){
                    maxH.push(top);
                }
                //cout<<"2. "<<top.first<<" "<<top.second<<endl;
                
            }else{
                
                pair<int, char> second = maxH.top(); maxH.pop();
                
                ans.push_back(second.second);
                
                idx++;
                
                if(--second.first >0){
                    maxH.push(second);
                }
                
                //cout<<"3. "<<second.first<<" "<<second.second<<endl;
                
                
                maxH.push(top);
            }
            
            
        }//while
        
        return ans;
    }
};