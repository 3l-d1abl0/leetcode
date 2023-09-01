class Solution {
public:
    
    int recur(string &colors, vector<int>& neededTime, int idx, int prev_idx, unordered_map<string, int> &mp){
        
        if(idx==colors.size()){
            return 0;
        }
        
        string key = to_string(idx)+"-"+to_string(prev_idx);
        
        if(mp.find(key)!= mp.end()){
            return mp[key];
        }
        
        if(prev_idx!=-1 && colors[idx]== colors[prev_idx]){
            
            //int choice1 = recur(colors, neededTime, idx+1, prev_idx )+neededTime[idx]; //idx removed
            //int choice2 = recur(colors, neededTime, idx+1, idx)+neededTime[prev_idx]; //prev removed
            //return mp[key] = min(choice1, choice2);
            
            if(neededTime[idx]< neededTime[prev_idx]){
                //pop idx
                return mp[key] = neededTime[idx]+recur(colors, neededTime, idx+1, prev_idx, mp);
            }else{
                //pop prev_idx
                return mp[key] = neededTime[prev_idx]+recur(colors, neededTime, idx+1, idx, mp);
            }
        }else{
            return mp[key] = recur(colors, neededTime, idx+1, idx, mp);
        }
    }
    
    
    int method1(string &colors, vector<int>& neededTime){
        
         /*
            call to implicitly deleted default constructor
            unordered_map<pair<int, int>, int> mp;
        */
        unordered_map<string, int> mp; 
        return recur(colors, neededTime, 0, -1, mp);
        
    }
    
    int method2(string &colors, vector<int>& nT){
        
        int N = nT.size();
        int prev_idx=-1;
        int ans =0;
        
        for(int idx=0; idx<N; idx++){
            
            if(prev_idx !=-1 && colors[idx]== colors[prev_idx]){
                
                
                if(nT[prev_idx]< nT[idx]){
                
                    //pop the prev
                    ans+= nT[prev_idx];
                    prev_idx= idx;
                }else{
                    //pop the idx
                    ans+= nT[idx];
                }
                
            }else{
                prev_idx=idx;
            }
        }//for 
        
    
        return ans;
    }
    
    int method3(string &colors, vector<int>& nT){
        
        int N = nT.size();
        stack<int> prev;
        int ans =0;
        
        prev.push(0);
        for(int idx=1; idx<N; idx++){
            
            if(colors[prev.top()] == colors[idx]){
                
                if(nT[prev.top()] < nT[idx]){
                    //pop prev
                    ans += nT[prev.top()];
                    prev.pop();
                    prev.push(idx);
                }else{
                    //pop idx
                    ans+=nT[idx];
                }
            }else{
                prev.push(idx);
            }
        }//for
        
        
        return ans;
    }
    
    int minCost(string colors, vector<int>& neededTime) {
        
        
        //recursion
        //return method1(colors, neededTime);
        
        //Linear
        //return method2(colors, neededTime);
        
        //stack
        return method3(colors, neededTime);
    }
};