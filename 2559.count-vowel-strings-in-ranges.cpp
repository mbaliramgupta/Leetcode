/*
 * @lc app=leetcode id=2559 lang=cpp
 *
 * [2559] Count Vowel Strings in Ranges
 */

// @lc code=start
class Solution {
public:
bool isvow(char &ch){
        if(ch=='a' || ch=='e' || ch=='i' || ch=='u'|| ch=='o'){
            return true;
        }
            return false;
        
    }
    vector<int> vowelStrings(vector<string>& words, vector<vector<int>>& queries) {
        int q=queries.size();
     int n=words.size();

     vector<int>result(q);
     vector<int>cumsum(n);
      int sum=0;
      for(int i=0;i<n;i++){
            if(isvow(words[i][0]) && isvow(words[i].back())){
                sum++;
            }
            cumsum[i]=sum;
      }
      for(int i=0;i<q;i++){
        int l=queries[i][0];
        int r=queries[i][1];

        result[i]=cumsum[r]-((l>0)?cumsum[l-1]:0);
      }
         return result;
    }
};
// @lc code=end

