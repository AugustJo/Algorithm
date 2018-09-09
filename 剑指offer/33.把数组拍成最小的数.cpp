/*
  题目描述:

  输入一个正整数数组，把数组里所有数字拼接起来排成一个数，打印能拼接出的所有数字中
  最小的一个。例如输入数组{3，32，321}，则打印出这三个数字能排成的最小数字为321323。

  思路：参照字符数组的排列组合，隐形大数问题，将数字转换为字符串。
    
*/
class Solution {
public:
    string PrintMinNumber(vector<int> numbers) {
        string str;
        vector<string> nums;
        int len=numbers.size();
        if(len<=0)return str;
       
        for(int i=0;i<len;i++)
            nums.push_back(to_string(numbers[i]));
        
        sort(nums.begin(),nums.end(),camp);
        for(int i=0;i<len;i++)
            str+=nums[i];
        
        return str;
    }
    static  bool camp(const string &s1,const string &s2)
    {
        return s1+s2<s2+s1;
    }
};
