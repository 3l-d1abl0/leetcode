class Solution {
    
public:
    
    //TC: O(n * len)    
    vector<int> findSubstring(string s, vector<string>& words) {
        
        //Get Frequency count of the Words
        unordered_map<string, int> counts;
        for (string word : words) counts[word]++;

        int N = s.length();
        int wordsCount = counts.size();
        int wordLen = words[0].length();

        vector<int> indexes;
        // Traverse through each possible starting point within the first 'len' characters
        /*because i=len .. N would already be covered by the nested for loop
        */
        for (int i = 0; i < wordLen; i++) {
            unordered_map<string, int> seen;
            int lf = i, count = 0;

            /*
            Keep increasing the window if the next word matches,
            other wise skip the word and start a new Window 
            */
            for (int rt = i; rt <= N - wordLen; rt += wordLen) {
                
                //Get the Word
                string word = s.substr(rt, wordLen);
                // Check if the word is valid (exists in counts)
                if (counts.find(word) != counts.end()) {
                    seen[word]++;

                    if(seen[word] == counts[word])
                        count++;

                    // If seen word exceeds the count, shift the window, Shrink from the Left
                    while (seen[word] > counts[word]) {
                        string leftWord = s.substr(lf, wordLen);

                        if(seen[leftWord] == counts[leftWord])
                            count--;

                        seen[leftWord]--;
                        lf += wordLen;
                        //cout<<"lf= "<<lf<<" count="<<count<<endl;
                    }

                    //cout<<"C= "<<count<<" w="<<word<<" "<<seen[word]<<endl;

                    // If all words matched, add the starting index
                    if (count == wordsCount) {
                        indexes.push_back(lf);
                    }
                    
                } else {
                    // Reset the window if an invalid word is encountered
                    seen.clear();
                    count = 0;
                    lf = rt + wordLen;  //rt will be rt+len in the next hop
                }
            }
        }
        return indexes;
    }
};