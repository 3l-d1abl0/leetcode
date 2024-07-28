class Solution {
public:
    int findLeastNumOfUniqueInts(vector<int>& arr, int k) {
        
        
        int N = arr.size();
        
        if(N<=k)
    	    return 0; //all removed
    	    
    	
    	unordered_map<int, int> freq;
    	for(int i=0; i<N; i++){
    	    freq[arr[i]]++;
    	}
    	
    	int sz = freq.size();
        
    	priority_queue< pair<int, int> , vector<pair<int, int> >, greater<pair<int, int>> > minHeap;
    	
    	int dist =0;
    	for(auto ele: freq){
    	    
    	    if(ele.second==1){
    	        dist++;
    	    }else{
    	        minHeap.push({ele.second, ele.first});
    	    }
    	}
        
        if(k<=dist){
            
            //sz-k  remove k eleements
            //return (dist-k)+(sz-dist);
            return sz-k;
        }
    	
        
        //remove the single frequency element first
        k-=dist;
    	
        //cout<<"K = "<<k<<" "<<minHeap.size()<<endl;
    	while(k>0 && !minHeap.empty()){
    	    
    	    
    	    auto ele = minHeap.top();
    	    
    	    //freq of eleemt is greater than k
    	    if( ele.first > k){
    	        return minHeap.size();
    	    }
            
            k-=ele.first;
            minHeap.pop();
            
    	}//while
    	
        
        return minHeap.size();
    }
};