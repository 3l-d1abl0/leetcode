class Solution {
public:
    
    int method1(vector<int> &citations){
        
        int N = citations.size();
        int h;
        for(int i=N-1; i>=0; i--){
            
            h = N- i;//number of Papers
            
            if(citations[i] >= h)
                continue; //move left

            /*
                This is the first instance where #papers > citations
                just an Index before
                #paper-1 <= citations
            
            */

            cout<<h<<" -1"<<endl;
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
        

        // citations< #paper ________ citations==#Papers  _______________ citations > #papers
        
        return N==1 ? (citations[0]>0?1:0): ans;

        int l =-1, r= N;

        while(r-l>1){
            
            int mid = l+(r-l)/2;
            int h = N=mid;

            if(citations[mid]>=h){
                r=mid;//go left
            }else{
                l=mid;
            }
        }//while


        return r;
    }
    
    int hIndex(vector<int>& citations) {
        
        //Maximize the Papers, with greater citations
        sort(citations.begin(), citations.end());
        
        //Linear - O(n)
        //return method1(citations);
        
        
        // Binary Sarch - O(logn)
        return method2(citations);
        
    }
};