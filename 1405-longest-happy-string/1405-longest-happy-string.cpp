class Solution {
public:
    string longestDiverseString(int a, int b, int c) {
        
        priority_queue<pair<int, char>> mxHeap;
        
        if(a!=0)
            mxHeap.push({a, 'a'});
        if(b!=0)
            mxHeap.push({b, 'b'});
        if(c!=0)
            mxHeap.push({c, 'c'});
        
        
        vector<char> ans;
        
        bool repeat =false;
        
        while (!mxHeap.empty()){
            
            
            auto ele = mxHeap.top();
            mxHeap.pop();
            
            
            
            
            
            if(ans.size()==0){
                ans.push_back(ele.second);
                //cout<<ele.second<<"1 ";
                
                if(ele.first-1 !=0)
                    mxHeap.push({ele.first-1, ele.second});
            }else if(ans.back() == ele.second){
                
                
                if(repeat==true){
                    
                    
                    if(mxHeap.empty())
                        break;
                    
                    auto anotherEle = mxHeap.top();
                    mxHeap.pop();
                    ans.push_back(anotherEle.second);
                    //cout<<anotherEle.second<<"2 ";
                    if(anotherEle.first-1 !=0)
                        mxHeap.push({anotherEle.first-1, anotherEle.second});
                    
                    mxHeap.push(ele);
                    
                    repeat= false;
                }else{
                    
                    repeat=true;
                    ans.push_back(ele.second);
                    //cout<<ele.second<<"3 ";
                    if(ele.first-1 !=0)
                        mxHeap.push({ele.first-1, ele.second});
                }
            }else{//normal
                ans.push_back(ele.second);
               // cout<<ele.second<<"4 ";
                if(ele.first-1 !=0)
                    mxHeap.push({ele.first-1, ele.second});
                repeat= false;
            }
        }//while
        
        
        string str(ans.begin(), ans.end()); 
        return str;
    }
};