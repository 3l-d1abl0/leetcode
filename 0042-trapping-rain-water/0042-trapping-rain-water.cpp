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
    
    int method2(vector<int> &h){

        int N = h.size();

        int lmax = -1, rmax = -1;
        int left = 0, right = N-1;

        int water = 0;

        while(left<=right){

            if(h[left] < h[right]){

                if(h[left] > lmax){
                    lmax = h[left];
                }else{
                    water += lmax - h[left];
                    left++;
                }

            }else{

                if(h[right] > rmax){
                    rmax = h[right];
                }else{
                    water += rmax- h[right];
                    right--;
                }

            }

        }//while

        return water;
    }
    
    
    int method3(vector<int> &h){
        
        int water =0;
        int N = h.size();
        
        stack<int> st;
        for(int i=0; i<N; i++){
            
            while(!st.empty() && h[st.top()] < h[i]){
                
                int top = st.top(); st.pop();
                /*
                    At this point:
                    [i] is on the right of [top] and is Greater than [top]
                    
                    [st.top()] is on left of [top] and is greater than it
                    
                    thats all we need
                
                */
                
                if(st.empty()) break;
                
                int height = min(h[st.top()], h[i]) - h[top];
                
                water += height * (i-st.top()-1);
            }
            
            st.push(i);
            
        }
        
        return water;
    }
    
    
    int trap(vector<int>& h) {
        
        //linear- max of left right- 14ms 21MB
        //return method1(h);
        
        //Two Pointer - 16ms 20MB
        //return method2(h);

        //Stack - 10ms = 20.7MB
        return method3(h);
    }
                       

                       
};