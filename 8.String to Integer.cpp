class Solution {
public:
    int myAtoi(string str) {
        long result = 0;
        int indicator = 1;
        for(int i = 0; i<str.size();)
        {
            i = str.find_first_not_of(' ');//消除空格问题
            if(str[i] == '-' || str[i] == '+')
                indicator = (str[i++] == '-')? -1 : 1;//判断符号
            while('0'<= str[i] && str[i] <= '9') //有效性，是否为数字
            {
                result = result*10 + (str[i++]-'0');
                if(result*indicator >= INT_MAX) return INT_MAX;//判断是否越界
                if(result*indicator <= INT_MIN) return INT_MIN;                
            }
        }
        return result*indicator;
    }
};
