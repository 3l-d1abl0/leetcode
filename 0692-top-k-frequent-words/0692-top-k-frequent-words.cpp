class Solution {
public:
    
    vector<string> method1(vector<string> &words, int k){
        
        unordered_map<string, int> mp;
        
        for(string ele: words){
            mp[ele]++;
        }
        
        vector< pair<int, string> > node;
        for(auto &[str, f]: mp){
            node.push_back({f, str});
        }
        
        
        sort(node.begin(), node.end(), [&](pair<int, string> a, pair<int, string> b){
            return a.first == b.first ? a.second < b.second : a.first > b.first;
        });
        
        
        vector<string> ans;
        int ctr =0;
        for(auto it = node.begin(); it!= node.end() && ctr<k; it++, ctr++){
            ans.push_back( (*it).second);
        }
        
        
        return ans;
        
    }
    
    
    struct CompareFn{
        
        bool operator()(pair<int, string> &a, pair<int, string> &b){
            return a.first == b.first ? a.second < b.second : a.first > b.first;
        }
    };
    
    vector<string> method2(vector<string> &words, int k){
        
        unordered_map<string, int> mp;
        
        for(string ele: words){
            mp[ele]++;
        }
        
        priority_queue<pair<int, string>, vector<pair<int, string> >, CompareFn> minHeap;
        
        int ctr =0;
        for(auto it= mp.begin(); it!= mp.end(); it++){
            
            if(ctr < k){
                minHeap.push({it->second, it->first});
                //cout<<" -> "<<it->second<<" "<<it->first<<endl;
            }else{
                
                //cout<<"( "<<it->second<<" "<<it->first<<") , "<<minHeap.top().first<<" "<<minHeap.top().second<<endl;
                
                if( (it->second > minHeap.top().first ) || (it->second == minHeap.top().first && it->first < minHeap.top().second) ){
                    minHeap.pop();
                    minHeap.push({it->second, it->first});
                    //cout<<" => "<<it->second<<" "<<it->first<<endl;
                }
            }
            ctr++;
        }//for
        
        vector<string> ans;
        while(!minHeap.empty()){
            ans.push_back(minHeap.top().second);
            minHeap.pop();
        }
        
        reverse(ans.begin(), ans.end());
        return ans;
        
    }
    
    vector<string> topKFrequent(vector<string>& words, int k) {
        
        
        //1. method1 - SORT - TC : O(NlogN)
        //return method1(words, k);
        
        //2. method2 - HEAP - TC : O(K) + O(NlogK)
        return method2(words, k);
    }
};