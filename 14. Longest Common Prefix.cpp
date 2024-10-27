/*
Write a function to find the longest common prefix string amongst an array of strings.

If there is no common prefix, return an empty string "".

Example 1:

Input: strs = ["flower","flow","flight"]
Output: "fl"
Example 2:

Input: strs = ["dog","racecar","car"]
Output: ""
Explanation: There is no common prefix among the input strings.
 

Constraints:

1 <= strs.length <= 200
0 <= strs[i].length <= 200
strs[i] consists of only lowercase English letters.*/


//Solution
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int sz = strs[0].size();
        string s = "";
        string fs = strs[0];
        int flag = 1;
        for(int i=0;i<sz;i++){
            for(int j=1;j<strs.size();j++){
                string temp = strs[j];
                if(fs[i] == temp[i]){
                    continue;
                }
                else flag = 0;
            }
            if(flag) s+=fs[i];
            else break;
        }
        return s;
    }
};
