class Solution {
public:
    
    bool findSubstring(string &s,int idx, vector<string> words, int ctr, unordered_map<string, int> mp){

	//cout<<"Starting: "<<idx<<endl;
	int wordLength = words[0].size();

	for(int i = idx; i<s.size(); i+=wordLength){

		//Matched all words
		if(ctr == words.size())
			return true;

		string sub = s.substr(i, wordLength);
		//cout<<"Matching ... "<<sub<<endl;

		if ( mp.find(sub) == mp.end() ){
			return false;
		}else{

			//exists

			//already matched
			if(mp[sub]==0)
				return false;

			//cout<<"matched ... "<<sub<<endl;
			mp[sub]--;
			ctr++;

		}

	}//for


	if(ctr == words.size())
		return true;

    return false;
}
    
    vector<int> findWordConcatenation(const string &str, const vector<string> &words) {
    unordered_map<string, int> wordFrequencyMap;
    for (auto word : words) {
      wordFrequencyMap[word]++;
    }

    vector<int> resultIndices;
    int wordsCount = words.size(), wordLength = words[0].length();

    for (int i = 0; i <= int(str.length()) - wordsCount * wordLength; i++) {
      unordered_map<string, int> wordsSeen;
      for (int j = 0; j < wordsCount; j++) {
        int nextWordIndex = i + j * wordLength;
        // get the next word from the string
        string word = str.substr(nextWordIndex, wordLength);
        if (wordFrequencyMap.find(word) ==
            wordFrequencyMap.end()) {  // break if we don't need this word
          break;
        }

        wordsSeen[word]++;  // add the word to the 'wordsSeen' map

        // no need to process further if the word has higher frequency than required
        if (wordsSeen[word] > wordFrequencyMap[word]) {
          break;
        }

        if (j + 1 == wordsCount) {  // store index if we have found all the words
          resultIndices.push_back(i);
        }
      }
    }

    return resultIndices;
  }
    
    
        bool helper(string s,int word,unordered_map<string,int> mp){
        for(int i = 0; i < s.size(); i += word){
            string a = s.substr(i,word);
            if(mp.find(a) != mp.end()){
                if(--mp[a] < 0)return false;
            }else return false;
        }
        return true;
    }
    
    //driver
    vector<int> findSubstring(string s, vector<string>& words) {
        
                vector<int>v; 
        int word = words[0].size();
        int len = words.size()*word;
        unordered_map<string,int>mp;
        for(auto it : words){
            mp[it]++;
        }
        int a = 0;
        while(a + len <= s.size()){
            if(helper(s.substr(a,len),word,mp))v.push_back(a);
            a++;
        } 
        return v;
        
    
    return findWordConcatenation(s, words);
        
    /*int listLength = words.size();
	int wordLength = words[0].size();

	int totalSubstringlength = listLength*wordLength;

	if(s.size() < totalSubstringlength)
		return {};

	//Generate freq-map for each word
	unordered_map<string, int> mp;
	for(string wd: words){
		mp[wd]++;
	}


    //unordered_set<int> pos;
    vector<int> pos;
	for(int i=0; i<s.size()-(totalSubstringlength)+1; i++){

		//for(string wd: words){
        for(auto p: mp){
            
            string wd = p.first;
            
			if ( wd.compare( s.substr(i, wordLength) ) == 0 ){

				mp[wd]--;
				bool ans = findSubstring(s, i+wordLength, words, 1, mp);
				mp[wd]++;


				if(ans==true){

					//cout<<"Found: "<<i<<endl;
					//pos.insert(i);
                    pos.push_back(i);
				}


			}

		}
	} //for


	return pos;//vector<int> (pos.begin(), pos.end());
        
      */  
    }
};