class Solution {
public:
    int minAddToMakeValid(string s) {
        int extraLeft=0, extraRight =0;
        for(char ch: s){
            if(ch=='('){
                extraLeft++;
            }else if(ch==')'){
                
                if(extraLeft>0){
                    extraLeft--;
                }else{
                    extraRight++;
                }
            }
        }//for
        
        cout<<extraLeft<<" "<<extraRight<<endl;
        return extraLeft+extraRight;
    }
};