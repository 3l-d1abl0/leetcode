class Solution {
public:
    
    int lookLeft(long long int ele, vector<int> &B, long long int k){
        
        int l =-1, r = B.size();
        
        while(r-l>1){
            
            int mid = l+(r-l)/2;
            
            if(ele*B[mid]<=k){
                l=mid;
            }else{
                r=mid;
            }
        }
       // cout<<ele<<", l+1 ="<<l+1<<endl;
        return l+1;
        
    }
    
    int lookRight(long long int ele, vector<int> &B, long long int k){
        
        int l = -1, r= B.size();
        while(r-l>1){
            
            int mid = l+(r-l)/2;
            //cout<<l<<" "<<ele*B[mid]<<" "<<r<<endl;
            if(ele*B[mid]<=k){
                r=mid;
            }else{
                l=mid;
            }
            
        }
        
        //cout<<ele<<", sz-r ="<<B.size()-r<<" "<<l<<","<<r<<endl;
        return B.size()-r;
    }
    
    long long int lessThan(vector<int> &A, vector<int> &B, long long int mid){
        //cout<<"mid : "<<mid<<endl;
        long long int ctr =0;
        for(int ele: A){
            
            if(ele<0){
                ctr+=lookRight(ele, B, mid);
            }else{
                ctr+=lookLeft(ele, B, mid);
            }
            
        }
        //cout<<"ctr = "<<ctr<<endl;
        return ctr;
        
    }
    
    long long kthSmallestProduct(vector<int>& A, vector<int>& B, long long k) {
        
        
        long long int l= -1e10-1, r = 1e10+1;
        //cout<<l<<" "<<r<<" "<<k<<endl;
        while(r-l>1){
            
            long long int mid = l+(r-l)/2;
            //no of pairs whose product is less than =mid
            if(lessThan(A, B, mid) <k){
                l = mid;
            }else{
                r=mid;
            }
            
        }
        
        return r;
    }
};