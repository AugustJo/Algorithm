/*
  题目描述:

  输入一个整数n，求从1到n这n个整数的十进制表示中1出现的次数。例如输入12，从1到12这些整数中
  包含有1的数字有1，10，11，和12，一共出现了5次。

  思路：
    
*/
// 方案一：分段法 （3ms 488k）复杂度O(logn)
class Solution {
public:
    int NumberOf1Between1AndN_Solution(int n)
    {
        if(n <= 0)
            return 0;
        
        char strN[50];
        sprintf(strN, "%d", n);
        
        return NumberOf1(strN);
    }
    
    int NumberOf1(const char *strN){
        if(!strN || *strN < '0' || *strN > '9' || *strN == '\0')
            return 0;
        
        int first = *strN - '0';
        unsigned int length = static_cast<unsigned int>(strlen(strN));
        
        if(length == 1 && first == 0)
            return 0;
        
        if(length == 1 && first >0)
            return 1;
        
        //假设strN是“21345”
        //numFirstDigit是数字10000~19999的第一个位中的数目
        int numFirstDigit = 0;
        if(first > 1)
            numFirstDigit = PowerBase10(length - 1);
        else if(first == 1)
            numFirstDigit = atoi(strN + 1) + 1;
        
        //numOtherDigit是1346~21345除了第一位之外的数位中的数目
        int numOtherDigit = first * (length - 1) * PowerBase10(length - 2);
        //numRecursive是1~1345中的数目
        int numRecursive = NumberOf1(strN + 1);
        
        return numFirstDigit + numOtherDigit + numRecursive;
    }
    
    int PowerBase10(unsigned int n){
        int result = 1;
        for(int i=0; i<n; ++i)
            result *=10;
        
        return result;
    }
};

// 方案二：（3ms 480k）
class Solution {
public:
    int NumberOf1Between1AndN_Solution(int rnum){
        if(n <= 0)
            return 0;

        int scale=10;
        int count=0;

        int len=lenOfnum(rnum);
        for(int i=1;i<=len;i++){
            int nn=rnum/scale;
            int mm=rnum-nn*scale;
            count=count+nn*scale/10;
            if(mm*10/scale>1) count+=scale/10;
            else if(mm*10/scale==1) {
                //if(i!=1)
                    count+=mm%(scale/10)+1;
                //else count+=1;
            }
            scale*=10;
        }
        return count;
    }
    
    int lenOfnum(int rw){
        if(rw>=0&&rw<=9) return 1;
        else if(rw>=10) return 1+lenOfnum(rw/10);
        return 0;
    }
}
