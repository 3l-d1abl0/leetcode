class Solution {
    
public:
    
    //TC: O(n * len)    
    vector<int> findSubstring(string s, vector<string>& words) {
        
        //Get Frequency count of the Words
        unordered_map<string, int> counts;
        for (string word : words) counts[word]++;

        int N = s.length();
        int wordsCount = words.size();
        int len = words[0].length();

        vector<int> indexes;
        // Traverse through each possible starting point within the first 'len' characters
        /*because i=len .. N has already been covered y i=0 loop
        */
        for (int i = 0; i < len; i++) {
            unordered_map<string, int> seen;
            int lf = i, count = 0;

            for (int rt = i; rt <= N - len; rt += len) {
                
                //Get the Word
                string word = s.substr(rt, len);
                // Check if the word is valid (exists in counts)
                if (counts.find(word) != counts.end()) {
                    seen[word]++;
                    count++;

                    // If seen word exceeds the count, shift the window, Shrink from the Left
                    while (seen[word] > counts[word]) {
                        string leftWord = s.substr(lf, len);
                        seen[leftWord]--;
                        lf += len;
                        count--;
                    }

                    // If all words matched, add the starting index
                    if (count == wordsCount) {
                        indexes.push_back(lf);
                    }
                    
                } else {
                    // Reset the window if an invalid word is encountered
                    seen.clear();
                    count = 0;
                    lf = rt + len;  //rt will be rt+len in the next hop
                }
            }
        }
        return indexes;
    }
};