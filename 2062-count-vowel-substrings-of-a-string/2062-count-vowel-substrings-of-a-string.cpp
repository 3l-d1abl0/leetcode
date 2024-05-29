class Solution {
public:
    int countVowelSubstrings(string word) {
        
        int result = 0;
        int lf=0, mid=0;
        unordered_map<char, int> count;
        
        unordered_set<char> vowels{'a', 'e', 'i', 'o', 'u'};
        
        
        for(int rt=0; rt<word.size(); rt++){
            
            
            if(vowels.find(word[rt]) == vowels.end()){
                mid = rt+1;
                lf = mid;
                
                count.clear();
            }else{
                
                count[word[rt]]++;
            }
            
            
            
            if( count.size()==5){
                
                
                
                while(count[word[mid]]>1){
                    
                    count[word[mid]]--;
                    
                    if(count[word[mid]]==0)
                        count.erase(word[mid]);
                    
                    mid++;
                    
                }
                
                
                result += (mid-lf+1);
            }
            
            
            //cout<<result<<" "<<lf<<" "<<mid<<" "<<rt<<endl;
            
            
        }
        
        
        return result;
    }
};