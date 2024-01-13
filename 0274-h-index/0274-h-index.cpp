class Solution {
public:
    
    int method1(vector<int> &citations){
        
        int N = citations.size();
        int h;
        for(int i=N-1; i>=0; i--){
            
            h = N- i;
            
            if(citations[i] >= h)
                continue; //move left
            
            return h-1;
        }
        
        return h;
    }
    
    
    int method2(vector<int> &citations){
        
        int N = citations.size();
        int st =0, end = N-1;
        
        int h, ans =0;
        while(st <= end){
            int mid = st + (end-st)/2;
            
            h = N-mid;
            //cout<<h<<" "<<endl;
            if(citations[mid] >= h){
                end = mid-1;
                ans = max(ans, h);
            }else{
                st=mid+1;
            }
                
        }
        
        
        return N==1 ? (citations[0]>0?1:0): ans;
    }
    
    int hIndex(vector<int>& citations) {
        
        sort(citations.begin(), citations.end());
        
        //Linear - O(n)
        //return method1(citations);
        
        
        // Binary Sarch - O(logn)
        return method2(citations);
        
    }
};