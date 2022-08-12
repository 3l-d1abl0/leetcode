class Solution {
public:
    
    int method1(vector<int> &h){
        int N = h.size();
        
        vector<int> l(N);
        vector<int> r(N);
        
        l[0] = h[0];
        r[N-1] = h[N-1];
        
        for(int i=1; i<N; i++){
            
            l[i] = max(l[i-1], h[i]);    
            r[N-i-1] = max(r[N-i], h[N-i-1]);
        }
        
        
        int cnt =0;
        for(int i=0; i<N; i++)
            cnt+= min(l[i], r[i]) - h[i];
        
        return cnt;
    }
    
    int method2(vector<int> &arr){
        
        int lf =0, rt=arr.size()-1;
        int left_max = -1; int rt_max = -1;
        int water =0;
        while(lf<=rt){

            if(arr[lf]<arr[rt]){
                    if(arr[lf]>left_max)
                        left_max = arr[lf];
                    else
                        water += left_max -arr[lf];
                        lf++;
            }else{

                if(arr[rt]>rt_max)
                    rt_max = arr[rt];
                else
                    water += rt_max - arr[rt];
                    rt--;
            }

        }

        return water;
    }
    
    int trap(vector<int>& h) {
        
        //return method1(h);
        
        return method2(h);
    }
};