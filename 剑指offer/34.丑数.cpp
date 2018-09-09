/*
  题目描述:

  把只包含质因子2、3和5的数称作丑数（Ugly Number）。例如6、8都是丑数，但14不是，
  因为它包含质因子7。 习惯上我们把1当做是第一个丑数。求按从小到大的顺序的第N个丑数。

  思路：创建数组保存已找到的丑数，用空间换时间，根据丑数定义，丑数应该是另一个丑数乘以
  2、3或者5的结果(1除外)。
    
*/
class Solution {
public:
    int GetUglyNumber_Solution(int index) {
        if (index <= 0)
            return 0;
        int *puglynumber = new int[index];  
        puglynumber[0] = 1;
        int *puglymulty2 = puglynumber;
        int *puglymulty3 = puglynumber;
        int *puglymulty5 = puglynumber;//三个指标
        int uglynumberindex = 1;//记录丑数的个数
        while (uglynumberindex < index)
        {  
            int m = min(*puglymulty2 * 2, *puglymulty3 * 3, *puglymulty5 * 5);  
            puglynumber[uglynumberindex] = m;
            //下边就是更新2,3,5的指标  
            while (*puglymulty2 * 2 <= m)//小于等于当前最大的丑数，则要更新  
                puglymulty2++;     //因为在这个指标之前的数乘以2都比当前,的最大丑数小，
            while (*puglymulty3 * 3 <= m)  
                puglymulty3++;  
            while (*puglymulty5 * 5 <= m)  
                puglymulty5++;  
            
            uglynumberindex++;  
        }  
        int ugly = puglynumber[uglynumberindex - 1];  
        delete[] puglynumber;
        return ugly;
    }
    int min(int number1, int number2, int number3)  
    {  
        int min = (number1 < number2) ? number1:number2;  
        min = (min < number3) ? min:number3;  
        return min;  
    } 
};

