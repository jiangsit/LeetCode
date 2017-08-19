//用一个数组实时统计每个字母的出现次数，边走边数就行了。
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        static const int DICT_SIZE = 256;
        
        int length = s.size();
        if (length < 2) {
            return length;
        }
        
        vector<int> count(DICT_SIZE, 0);
        int i, j;
        int res = 0;
        j = 0;
        for (i = 0; i < length; ++i) {
            ++count[s[i]];
            if (count[s[i]] > 1) {
                while (count[s[i]] > 1) {
                    --count[s[j++]];
                }
            }
            res = max(res, i - j + 1);
        }
        count.clear();
        return res;
        
    }
};
