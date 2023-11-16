class Solution {
    private:
        multiset<long long int> h1, h2;
    public:
    
    
    void erase(long long int ele){
        
        
        //1. size equal
        if(h1.size() == h2.size()){
        
            //element is present in h1
            auto itr = h1.find(ele);
            if ( itr != h1.end()){
                h1.erase(itr);
                
                h1.insert( *(h2.begin()) );
                h2.erase( h2.begin() );
            }else{//present in h2
                
                auto itr = h2.find(ele);
                if( itr != h2.end())
                    h2.erase(itr);
                
            }
            
        }else if(h1.size() == h2.size()+1){
            
            auto itr = h1.find(ele);
            if (itr != h1.end()){
                h1.erase(itr);
                
            }else{
                
                auto itr = h2.find(ele);
                if( itr != h2.end()){
                    h2.erase(itr);
                
                    //at this point sz(h1) == sz(h2)+2
                    h2.insert( *prev(h1.end()) );
                    h1.erase(prev(h1.end()));
                }
            }
            
        }
        
        //2. sz(h1) = sz(h2)+1
        
    }
    
    
    void insert(long long int ele){
        
        //cout<<h1.size()<<" ... "<<h2.size()<<endl;
        
        if(h1.size() == 0){
            h1.insert(ele);
        }else if (h1.size() == h2.size()+1){
            
            long long int lastH1 = *prev(h1.end());
            //cout<<"lastH1:: "<<lastH1<<endl;
            if(ele <=lastH1){
                h1.insert(ele);
                
                //at this point sz(h1) = sz(h2)+2
                h2.insert( *prev(h1.end()) );
                h1.erase(prev(h1.end()));
                
                //cout<<h1.size()<<" ... "<<h2.size()<<endl;
            }else{
                
                h2.insert(ele);
            }
        }else if(h1.size() == h2.size()){
            
            long long int lastH1 = *prev(h1.end());
            
            if(ele <=lastH1){
                h1.insert(ele);
            }else{
            
                h2.insert(ele);
                
                //at this point // sz(h1)  = sz(h2) -1
                h1.insert( *(h2.begin()) );
                h2.erase( (h2.begin()) );
            }
            
        }
    }
    vector<double> medianSlidingWindow(vector<int>& nums, int k) {
        
        
        vector<double> median;
        /*
          Window:  [ -----h1---- | ----h2----]
          
          k = 3
                i         
          0 1 2 3 4 5 6 7 8
        */
        
        
        
        for(int i=0; i<nums.size(); i++){
            
            //1. Take out out of range elements
            if(i>=k){   //[i-k] is the out of range element
                erase(nums[i-k]);
            }
            
            
            //2. Insert
            insert(nums[i]);
            
            
            //3.Get median
            if(i>= (k-1)){
                if(k&1){    //total even elements (0-index)

                    //cout<<"ODD: "<<*prev(h1.end())<<endl;
                    median.push_back(*prev(h1.end()));
                    
                }else{
                    
                    /*cout<<i<<" :: "<<k<<endl;
                    cout<<h1.size()<<" "<<h2.size()<<endl;
                    
                    auto it = h1.end();
                    it--;
                    double a1 = (double)(*it);
                    cout<<"a1:: "<<a1<<endl;
                    
                    double a2 = (double)*(h2.begin())/2.0;
                    cout<<"a2:: "<<a2<<endl;
                    
                    cout<<"even:: "<<( (double)(*prev(h1.end()))/2.0 + (double)*(h2.begin())/2.0 )<<endl;
                    */
                    //cout<<"EVEN: "<<(*prev(h1.end())+ *(h2.begin()))/2.0<<endl;
                    median.push_back( (*prev(h1.end())+ *(h2.begin()) ) /2.0 );
                    
                }
            }
        }//for
        
        
        
        return median;
    }
};