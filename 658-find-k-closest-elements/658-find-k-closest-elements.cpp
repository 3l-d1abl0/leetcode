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
    
    int binarySearch2Pointer(vector<int>& arr, int x) {
        
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
    
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        
        
        //1. Simple sorting
        //return justSort(arr, k, x);
        
        //2. 2 Pointer
        //return twoPointer(arr, x);
        
        //3. Bianry Search
        int R = binarySearch2Pointer(arr, x);
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
};