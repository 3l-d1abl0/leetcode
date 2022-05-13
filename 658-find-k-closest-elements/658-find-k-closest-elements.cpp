class Solution {
public:
    
    struct node{
        int diff, num;
        
        node(int d, int n){
            diff = d;
            num = n;
        }
    };
    
    
    bool static cmp(node a, node b){
        
        if(a.diff < b.diff) return true;
        
        if(a.diff == b.diff)
            if(a.num < b.num)   return true;
        
        
        return false;
    }
    
    
    vector<int> justSort(vector<int> &arr, int k, int x){
        
        vector<node> vec;
        
        for(int i=0; i<arr.size(); i++){
            
            vec.push_back({abs(arr[i]-x), arr[i]});
            
            //cout<<vec[i].diff<<" "<<vec[i].num<<endl;
        }
        
        sort(vec.begin(), vec.end(), cmp);
        
        
        /*for(auto ele: vec){
            cout<<ele.diff<<" "<<ele.num<<endl;
        }*/
        
        
        vector<int> ans;
        for(int i=0; i<k; i++){
            ans.push_back(vec[i].num);
        }
        
        
        sort(ans.begin(), ans.end());
        
        return ans;
        
    }
    
    
    vector<int> twoPointer(vector<int>& arr, int k, int x) {
     
        int l = 0, r= arr.size()-1;
        
        while(r-l>=k){
            
            if(abs(arr[l]-x) <= abs(arr[r]-x) )
                r--;
            else
                l++;
        }
        
        return vector<int> (arr.begin()+l, arr.begin()+r+1);
        
    }
    
    
    int lowerBound(vector<int> &arr, int x){
                int N = arr.size();
        
        int l=-1, r=N;
        
        while(r-l>1){
            
            int mid = l +(r-l)/2;
            
            if(arr[mid]>=x)
                r=mid;
            else
                l =mid;
            
        }
        
        
        return r;
    }
    
    vector<int> binarySearch2Pointer(vector<int>& arr, int k, int x) {
        
        int R = lowerBound(arr, x);
        int L = R-1;
        int N = arr.size();
        
        while(k--){
            
            if(R>=N ||( L>=0 && abs(arr[L]-x) <= (arr[R]-x)))
                L--;
            else
                R++;
            
        }
        cout<<L<<" "<<R<<endl;
        return vector<int> (arr.begin()+L+1, arr.begin()+R);
    }
    
    
    vector<int> binarySearch(vector<int> arr, int k, int x){
        
        int n = arr.size();
        int l = 0, r = n-k;
        
        while(l<r){
         
            int mid = l+(r-l)/2;
            
            if(arr[mid]== arr[mid+k]){
                
                if(x>arr[mid+k]){
                    l=mid+1;
                }else{
                    r=mid;
                }
                
            }else if(abs(arr[mid]-x) < abs(arr[mid+k]-x)){
                r=mid;
            }else{
                l=mid+1;
            }
        }
        
        
        return vector<int> (arr.begin() + l, arr.begin()+l+k);
    }
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        
        
        //1. Simple sorting
        //return justSort(arr, k, x);
        
        //2. 2 Pointer
        //return twoPointer(arr, x);
        
        //3. Binary Search+2 Pointer
        return binarySearch2Pointer(arr, k, x);
        
        //4. Just Binary Search
        return binarySearch(arr, k, x);
        
    }
};