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
