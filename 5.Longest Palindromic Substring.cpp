/*class Solution {
public:
    string longestPalindrome(string s) {
        int length=s.size();
        int maxlength=0;//最长回文字符串长度
        int start;//回文开始位置
        for(int i=0;i<length;i++)
            for(int j=i+1;j<length;j++){
                int temp1,temp2;
                for(temp1=i,temp2=j;temp1<temp2;temp1++,temp2--){//判断是不是回文
                    if(s.at(temp1)!=s.at(temp2))
                        break;
                }
                if(temp1>=temp2&&j-i>maxlength){
                    maxlength=j-i+1;
                    start=i;
                }
            }  
        if(maxlength>0)
            return s.substr(start,maxlength);//求子串
        return NULL;
    }
};
*/
class Solution {
public:
    string longestPalindrome(string s)
    {
        const int length=s.size();
        int maxlength=0;
        int start;
        bool P[50][50]={false};
        for(int i=0;i<length;i++)//初始化准备
        {
            P[i][i]=true;
            if(i<length-1&&s.at(i)==s.at(i+1))
            {
                P[i][i+1]=true;
                start=i;
                maxlength=2;
            }
        }
        for(int len=3;len<length;len++)//子串长度
            for(int i=0;i<=length-len;i++)//子串起始地址
            {
                int j=i+len-1;//子串结束地址
                if(P[i+1][j-1]&&s.at(i)==s.at(j))
                {
                    P[i][j]=true;
                    maxlength=len;
                    start=i;
                }
            }
        if(maxlength>=2)
            return s.substr(start,maxlength);
        string res="";
        return res;
    }
};
