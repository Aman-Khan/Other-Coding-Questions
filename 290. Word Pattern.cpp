    void convert(string s, vector<string> &words){
        string temp = "";
        for(int i=0; i<s.length(); i++){
            temp.push_back(s[i]);
            if(s[i]==' '){
                temp.pop_back();
                words.push_back(temp);
                temp="";
            }
        }
        words.push_back(temp);
    }
    bool wordPattern(string pattern, string s) {
        map<char, string> charToWord;
        map<string, char> wordToChar;
        vector<string> words;
        convert(s, words);

        int n = pattern.length();
        if(n!=words.size()) return false;

        for(int i=0; i<n; i++){
            if(charToWord.find(pattern[i])==charToWord.end() && wordToChar.find(words[i])==wordToChar.end()){
                charToWord[pattern[i]]=words[i];
                wordToChar[words[i]]=pattern[i];
            }
            if(pattern[i]!=wordToChar[words[i]]) return false;
            if(words[i]!=charToWord[pattern[i]]) return false;
        }

        return true;
    }
