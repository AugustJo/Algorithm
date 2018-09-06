/*
  题目描述:

  数组中有一个数字出现的次数超过数组长度的一半，请找出这个数字。
  例如输入一个长度为9的数组{1,2,3,2,2,2,5,4,2}。由于数字2在数组中出现了5次，
  超过数组长度的一半，因此输出2。如果不存在则输出0。

  思路：遍历数组时保存两个值：一个是数组中的一个数字，一个是次数。
  当我们遍历到下一个数字时，如果下一个数字和我们保存的数字相同，则次数加1；
  如果不同，则次数减一。如果次数为零，我们需要保存下一个数字，并把次数设为1.

*/

class Solution {
public:
    int MoreThanHalfNum_Solution(vector<int> numbers) {
      if(numbers.empty())
            return 0;
        
        int result = numbers[0];
        int times = 1;
        for(int i = 1; i < numbers.size(); ++i){
            if(times == 0){
                result = numbers[i];
                times = 1;
            }
            else if(numbers[i] == result)
                ++times;
            else
                --times;
        }
        
        if(!CheckMoreThanHalf(numbers, result))
            result = 0;
        
        return result;
    }
    
    bool CheckMoreThanHalf(vector<int> numbers, int result){
        int times = 0;
        for(int i=0; i<numbers.size(); ++i){
            if(numbers[i] == result)
                ++times;
        }
        
        bool isMoreThanHalf = true;
        if(times * 2 <= numbers.size())
            isMoreThanHalf = false;
        
        return isMoreThanHalf;
    }
};
