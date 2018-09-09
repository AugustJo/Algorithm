/*
  题目描述:

  输入一个整形数组，数组里有正数也有负数。数组中的一个或者连续的多个整数组成一个子数组。
  求所有子数组的和的最大值。要求时间复杂度为O(n).

  思路：
    解法一：举例分析数组规律，{1,-2,3,10,-4,7,2,-5}
    解法二：动态规划，
*/

// 解法一：（3ms 472k）
class Solution {
public:
    int FindGreatestSumOfSubArray(vector<int> array) {
        if(array.empty())
            return 0;
        
        int nCurSum = 0;
        int nGreatesSum = 0x80000000;   //最小负数
        for(int i = 0; i < array.size(); ++i){
            if(nCurSum <= 0)        // 抛弃前面的负数和
                nCurSum = array[i];
            else
                nCurSum += array[i];
            
            if(nCurSum > nGreatesSum)
                nGreatesSum = nCurSum;
        }
        return nGreatesSum;
    }
};

// 解法二：动态规划 (3ms 480k)
class Solution {
public:
    int FindGreatestSumOfSubArray(vector<int> array) {
        if(array.empty())
            return 0;
        
        int nCurSum = 0;
        int nGreatesSum = 0x80000000;   //最小负数
        for(int i = 0; i < array.size(); ++i){
            nCurSum = fIndex(array, i);
            if(nCurSum > nGreatesSum)
                nGreatesSum = nCurSum;
        }
        
        return nGreatesSum;
    }
    
    int fIndex(vector<int> array, int index){
        if(index == 0 || fIndex(array, index - 1) <= 0)
            return array[index];
        else
            return (fIndex(array, index - 1) + 
                    array[index]);
    }
};
