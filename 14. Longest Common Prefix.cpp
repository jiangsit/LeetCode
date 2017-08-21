class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string prefix="";
        int len=strs.size();
        if(len==0)
            return prefix;
        for(int k=0; k<strs[0].size(); k++){
            int i=1;
            for(; i<len && strs[i].size()>k; i++){
                if(strs[i][k]!=strs[0][k])
                    return prefix;
            }
            if(i==strs.size()) prefix+=strs[0][k];
        }
        return prefix;    
    }
};

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int n = strs.size();
        if (n == 0) {
            return "";
        }
        string res = strs[0];
        int i, j;
        int len;
        for (i = 1; i < n; ++i) {
            len = res.size();
            for (j = 0; j < len; ++j) {
                if (strs[i][j] != res[j]) {
                    res.resize(j);//重新截取字符串大小
                    break;
                }
            }
        }
        return res;
    }
};
