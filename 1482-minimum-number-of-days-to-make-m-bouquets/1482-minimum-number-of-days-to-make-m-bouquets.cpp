class Solution {
public:
    int calBou(vector<int> &bloomDay, int k, int mid){
        /*
        
            This function finds the total number of bouquets one can make on 'mid'th day
            with k adjacent flowers
        */
        int bo =0, idx =0;
        while(idx<bloomDay.size()){
            
            /*if(bloomDay[idx]>mid){
                idx++;
                continue;
            }*/
            
            int kk=0;
            while(kk<k && idx<bloomDay.size()){
                
                if(bloomDay[idx]>mid){
                    idx++;
                    break;
                }
                
                kk++; idx++;
                
            }
            
            if(kk==k)
                bo++;
        }
        
        //cout<<"bo= "<<bo<<endl;
        return bo;
    }
    
    int minDays(vector<int>& bloomDay, int m, int k) {
        
        
        int llim = *min_element(bloomDay.begin(), bloomDay.end())-1;
        int rlim = *max_element(bloomDay.begin(), bloomDay.end())+1;
        
        int l = llim;
        int r = rlim;
        
        while(r-l>1){
            
            int mid = l+(r-l)/2;
            
            //cout<<l<<" "<<mid<<" "<<r<<endl;
            if(calBou(bloomDay, k, mid) >= m)
                r=mid;
            else
                l=mid;
        }
        
        //cout<<l<<" , "<<r<<endl;
        if(r==rlim)
            return -1;
        
        return r;
    }
};