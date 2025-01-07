/*
 * @lc app=leetcode id=1408 lang=cpp
 *
 * [1408] String Matching in an Array
 */

// @lc code=start
class Solution {
public:
    vector<string> stringMatching(vector<string>& words) {
         sort(words.begin(),words.end(),[](string &a,string &b){
            return a.size()<b.size();
        });
        vector<string>result;
        for(int i=0;i<words.size();i++){
            for(int j=i+1;j<words.size();j++){
                if(i!=j && words[j].find(words[i])!=string::npos){
                    result.push_back(words[i]);
                    break;
                }
            }
        }
        return result;
    }
};
// @lc code=end

