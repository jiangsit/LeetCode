class Solution {
public:
    string convert(string s, int numRows) {
        string res;
        int len=s.size();
        if(numRows<=1)
            return s;
        vector<string> str(numRows);//不能少了numRows
        int row=0,step=1;
        for(int i=0;i<len;i++){
            str[row].push_back(s[i]);
            if(row==0)
                step=1;
            else if(row==numRows-1)
                step=-1;
            row+=step;
        }
        for(int j=0;j<numRows;j++){
            res.append(str[j]);
        }
        return res;
    }
};
