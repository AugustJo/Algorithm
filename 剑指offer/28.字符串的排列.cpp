/*
  题目描述:

  输入一个字符串,按字典序打印出该字符串中字符的所有排列。例如输入字符串abc,
  则打印出由字符a,b,c所能排列出来的所有字符串abc,acb,bac,bca,cab和cba。

  输入描述:

  输入一个字符串,长度不超过9(可能有字符重复),字符只包括大小写字母。

  思路：递归问题（a）把字符串分为两部分，一部分是字符串的第一个字符，另一部分是
  第一个字符以后的所有字符，接下来求第一个字符以后的所有字符的排列。（b）拿到第一个
  字符后和它后面的字符逐个交换。
*/

class Solution {
public:
    vector<string> Permutation(string str) {
        vector<string> result;   //创建字符串数组
        int len = str.length();  //求出字符串长度，作为参数传递控制循环次数
        if(!len) return result;  //当输入为空时，直接返回

        Permutations(result, str, 0, len);
        return result;
    }
    //递归函数
    void Permutations(vector<string>&result, string str,int index, int len){
     //当索引指向字符串尾部时，将str压入数组
        if (index == len){
            result.push_back(str);
        }
        else{
            for (int i = index; i < len; ++i) {  
                if (i!=index && str[i]== str[index]) 
                    continue;// 保证当输入多个重复字符时，不会重复计算
                
                swap(str[i],str[index]);//每一次，交换从第index位以后的一个元素
                Permutations(result, str, index+1, len);
            }
        }
    }
};
