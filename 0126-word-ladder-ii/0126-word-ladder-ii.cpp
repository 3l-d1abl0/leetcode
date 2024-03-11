class Solution {
public:
    
    void dfs(string &currentWord, string &beginWord, vector<vector<string>> &ans, unordered_map<string, int> &levelOf, vector<string> &path){
        
        //currentWord always exist in levelOf
        
        if(currentWord == beginWord){
            
            vector<string> begToEnd(path.rbegin(), path.rend());
            ans.push_back(begToEnd);
            return;
        }
        
        //current level
        int currentLevel = levelOf[currentWord];

        //Loop for each character of the word
        for(int i=0; i<currentWord.size(); i++){

            char originalChar = currentWord[i];
            //loop for each possible character for the current character at[i]
            for(char ch = 'a'; ch<='z'; ch++){
         
                if(ch==currentWord[i])
                    continue;
                
                currentWord[i] = ch;
                
                if(levelOf.find(currentWord) != levelOf.end() && currentLevel-1 == levelOf[currentWord] ){
                    path.push_back(currentWord);
                    dfs(currentWord, beginWord, ans, levelOf, path);
                    path.pop_back();
                }
                
            }//for ch
            currentWord[i] = originalChar;
            
        }//for i
        
        
    }
    
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        
        /*
            Approach 1:
            Do a bfs , track every path in each level
            the level which finds the endWorld, is the shortest path
            save all the path in that level which finds reaches the endword.
            
            The causes memeory limit Exceeded since we are storing path in each state,
            so the total number of possible path could be 26^5.
            
            
            
            Another approach is to do a bfs to reach the end word.
            This will give us the shortest path.
            Also, while travelling we keep a mapping of word -> to
            So, once we have reached the end word, each word will map to 
            a level, the shortest level it could be.
            
            
            Now from endWorld we will try dfs to generate each possbile path till beign word
            
            endWord - word1 - word2 - word3 - word4 - beginWord
            the catch is while hopping from 1 word to another
            we check if it is in a level lesser than the current word
            
            eg:
            
            endWord [6] - word1 [5] - word2 [4] - word3 [3] - word4 [2] - beginWord [1]
        
        */
        
        unordered_set<string> wordBank(wordList.begin(), wordList.end());
        unordered_map<string, int> levelOf;
        queue<string> q;
        
        q.push(beginWord);
        levelOf[beginWord] = 1; //beginWorld is at level 1
        wordBank.erase(beginWord);
        
        while(!q.empty()){
            
            string currentWord = q.front();
            q.pop();
            
            if(currentWord == endWord){
                
                break;
                /* At this point all the words in the previous level have been assigned their level number
                and the endWord also has its level number, which the min len path
                */
                
            }
            
            //current level
            int currentLevel = levelOf[currentWord];
            
            //Loop for each character of the word
            for(int i=0; i<currentWord.size(); i++){
                
                char originalChar = currentWord[i];
                //loop for each possible character for the current character at[i]
                for(char ch = 'a'; ch<='z'; ch++){
                    
                    if(ch==currentWord[i])
                        continue;
                    
                    currentWord[i] = ch;
                    
                    //if a valid word
                    if(wordBank.find(currentWord) == wordBank.end())
                        continue;
                    
                    levelOf[currentWord] = currentLevel+1;
                    q.push(currentWord);
                    
                    wordBank.erase(currentWord);
                    
                }//for ch
                
                currentWord[i] = originalChar;
                
            }//for i
            
        }//while q
        
        
        vector<vector<string>> ans;
        
        //check if reached the endWord;
        if(levelOf.find(endWord) != levelOf.end()){
            
            //cout<<levelOf[endWord]<<endl;
            
            vector<string> path;
            path.push_back(endWord);
            dfs(endWord, beginWord, ans, levelOf, path);
            
        }
        
        return ans;
    }
};