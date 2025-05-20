/*
Given a pattern and a string s, find if s follows the same pattern.

Here follow means a full match, such that there is a bijection between a letter in pattern and a non-empty word in s. Specifically:

Each letter in pattern maps to exactly one unique word in s.
Each unique word in s maps to exactly one letter in pattern.
No two letters map to the same word, and no two words map to the same letter.
 

Example 1:

Input: pattern = "abba", s = "dog cat cat dog"

Output: true

Explanation:

The bijection can be established as:

'a' maps to "dog".
'b' maps to "cat".
Example 2:

Input: pattern = "abba", s = "dog cat cat fish"

Output: false

Example 3:

Input: pattern = "aaaa", s = "dog cat cat dog"

Output: false

 

Constraints:

1 <= pattern.length <= 300
pattern contains only lower-case English letters.
1 <= s.length <= 3000
s contains only lowercase English letters and spaces ' '.
s does not contain any leading or trailing spaces.
All the words in s are separated by a single space.
*/

//solution
class Solution {
public:
    bool wordPattern(string pattern, string s) {
        unordered_map<char,string>char_word;
        unordered_map<string,char>word_char;
        vector<string>words;
        string word = "";
        for(int i=0;i<s.size();i++){
            if(s[i]!=' ') word+=s[i];
            else{
                if(!word.empty()){
                    words.push_back(word);
                    word.clear();
                }
            }
        }
        if(!word.empty())words.push_back(word);
        if(words.size()!=pattern.size()) return false;
        for(int i=0;i<words.size();i++){
            char c = pattern[i];
            string w = words[i];
            if(char_word.count(c)){
                if(char_word[c]!=w) return false;
            }
            else{
                if(word_char.count(w)){
                    return false;
                }
                char_word[c] = w;
                word_char[w] = c;
            }
        }
        return true;
    }
};
