class Solution {
public:

    struct VectorHash {
        size_t operator()(const std::vector<int>& vec) const {
            size_t seed = vec.size();
            for (int x : vec) {
                seed ^= x + 0x9e3779b9 + (seed << 6) + (seed >> 2);
            }
            return seed;
        }
    };
    
    vector<vector<int>> method2(vector<int> &arr){
        
        int N = arr.size();
        //set< vector<int> > triplets;
        unordered_set<std::vector<int>, VectorHash> triplets; //TLE because of creating hash for vector
        
        for(int i=0; i<N; i++){
            
            
            unordered_set<int> hashMap;
            
            for(int j=i+1; j<N; j++){
                /* sum of two numbers -> [i]+[j]
                    therefore, sum of 3rd number must be - ([i]+[j])
                
                */
                int thirdNumber = - (arr[i]+arr[j]);
                if( hashMap.find(thirdNumber) != hashMap.end() ){
                    
                    vector<int> triplet = {arr[i], arr[j], thirdNumber};
                    //cout<<triplet[0]<<" "<<triplet[1]<<" "<<triplet[2]<<endl;
                    sort(triplet.begin(), triplet.end());
                    
                    triplets.insert(triplet);
                }
                
                hashMap.insert(arr[j]);//push the number to the heap
                
            }
            
            
        }//for i

            
        vector<vector<int>> ans (triplets.begin(), triplets.end());
        
        return ans;
        
    }
    
        
    vector<vector<int>> method3(vector<int> &arr){
    
        int N = arr.size();
        sort(arr.begin(), arr.end());
        
        
        vector<vector<int> > ans;
        
        for(int i=0; i<N-2; i++){
            
            
            if (i == 0 || (i > 0 && arr[i] != arr[i-1])) {  //
            
                int l= i+1; //Second element
                int r= N-1; //Last element 


                while(l<r){

                    if(arr[i]+arr[l]+arr[r]==0){
                        ans.push_back({arr[i], arr[l], arr[r]});

                        while(l<r && arr[l]==arr[l+1]) l++; //skip if the next element is also same
                        while(l<r && arr[r]==arr[r-1]) r--; 
                            
                        l++; r--;

                    }else if(arr[i]+arr[l]+arr[r]<0){
                        l++;//increase the smaller element
                    }else{
                        r--;    //decrease teh largest eleemnt
                    }

                }//while
                
            }
        }//for
        
        
        return ans;
        
        
    }
        

    
    
    vector<vector<int>> threeSum(vector<int>& arr) {
        
        //1. Three nested loop with a set to store unique triplet
        //return method1(arr); O(N^3)
        
        /*2. Nested Loop
            TC: O(N^2 )×O(1)+O(N^2*M*logN) = O(N^2 *M*logN) (SET)
            TC: O(n^2) + O(N^2)* M*(hashMapO(1)) =  (UNORDERED)
            SC: O(N)+ O(no of unique triplets)*2
        
        */
        //return method2(arr);
        
        
        /*3. Two Pointer
        //O(NlogN)+O(N^2)
        */
        return method3(arr);
        
    }
};