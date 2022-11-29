class Solution {
public:
    int minSwaps(string s) {
        
        /*int count = 0;
        int stackSize = 0;
        for (int i = 0; i < s.length(); i++) {
            if (s.charAt(i) == '[') {
                stackSize++;
            } else if (stackSize == 0) {
                count++;
            } else {
                stackSize--;
            }
        }
        
        return (count + 1) / 2;
        */
        
        int extraLeft=0, extraRight =0;
        for(char ch: s){
            if(ch=='['){
                extraLeft++;
            }else if(ch==']'){
                
                if(extraLeft>0){
                    extraLeft--;
                }else{
                    extraRight++;
                }
            }
        }//for
        
        //cout<<extraLeft<<" "<<extraRight<<endl;
        return (extraRight+1)/2;
    }
};