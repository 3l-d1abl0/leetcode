class Solution {
public:
    
    int *constructBITree(int n){
        
        int *BITree = new int[n+1];
        for (int i=1; i<=n; i++)
            BITree[i] = 0;

        return BITree;
    }
    
    void updateBIT(int BITree[], int n, int index, int val){
        
        
        index = index + 1;

        
        while (index <= n)
        {
            
            BITree[index] += val;

            
            index += index & (-index);
        }
    }
    
    
    void updateRange(int BITTree1[], int N, int val, int l, int r)
    {

        updateBIT(BITTree1,N,l,val);
        updateBIT(BITTree1,N,r+1,-val);
    }
    
    
    int getSum(int BITree[], int index)
    {
        int sum = 0; // Initialize result

        // index in BITree[] is 1 more than the index in arr[]
        index = index + 1;

        // Traverse ancestors of BITree[index]
        while (index>0)
        {
            // Add current element of BITree to sum
            sum += BITree[index];

            // Move index to parent node in getSum View
            index -= index & (-index);
        }
        return sum;
    }
    
    string shiftingLetters(string s, vector<vector<int>>& shifts) {
        
        
        int N = s.size();

        int *BITTree1;

        
        BITTree1 = constructBITree(N);
        
        
        //loop
        for(auto row: shifts){
                
            if(row[2]==0){ //backward
                
                updateRange(BITTree1, N, -1, row[0],row[1]);
                
            }else{ //forward
                updateRange(BITTree1, N, 1, row[0],row[1]);
            }
        }
        
        
        string str="";
        for(int i=0; i<N; i++){
            
            int num = s[i]-'a';
            //cout<<num<<"->";
            if(i==0){
                
                
                num = num+getSum(BITTree1, i);
            }else{
                //cout<<(char)(s[i]+getSum(BITTree1, i))%26;
                num = num +getSum(BITTree1, i);//<<" ";//- getSum(BITTree1, i-1)<<" ";
            }
            
            if(num <0) num+=26;
            
            str+=(char)('a' + ((num%26)+26)%26);
            //cout<<(num+26)%26<<" "<<endl;
        }//cout<<endl;
        
        return str;
    }
};