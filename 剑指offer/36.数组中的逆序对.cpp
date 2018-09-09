/**
  题目描述:

  在数组中的两个数字，如果前面一个数字大于后面的数字，则这两个数字组成一个逆序对。
  输入一个数组,求出这个数组中的逆序对的总数P。并将P对1000000007取模的结果输出。 
  即输出P%1000000007

  输入描述:

  题目保证输入的数组中没有的相同的数字
  数据范围：
  对于%50的数据,size<=10^4
  对于%75的数据,size<=10^5
  对于%100的数据,size<=2*10^5

  示例1
  输入:
  1,2,3,4,5,6,7,0
  输出:
  7

  思路：先把数组分割成子数组，先统计出子数组内部的逆序对的数目，然后再统计出两个相邻子数组
  之间的逆序对的数目。在统计逆序对的过程中，还需要对数组进行排序，归并排序。
    
*/

class Solution {
public:
    int InversePairs(vector<int> data) {
        int length = data.size();  
        if(length < 1)  
            return 0;  
        vector<int> copy(data);  
        return InversePairsCore(copy,data,0,length - 1); 
    }
     int InversePairsCore(vector<int> &copy,vector<int> &data,int start, int end){  
        if(start == end)  
            return 0;  
        int center = (end - start) / 2;  
          
        int left = InversePairsCore(copy,data,start,start + center)%1000000007;  
        int right = InversePairsCore(copy,data,start + center + 1,end)%1000000007;  
          
        int i = start + center;  
        int j = end;  
        int copyIndex = end;  
        int count = 0;  
          
        while(i >= start && j >= start + center + 1){  
            if(data[i] > data[j]){  
                copy[copyIndex--] = data[i--];  
                count += j - start -center;  
                if(count > 1000000007)  
                    count %= 1000000007;  
            }  
            else{  
                copy[copyIndex--] = data[j--];  
            }  
        }  
          
        while(i >= start)  
            copy[copyIndex--] = data[i--];  
        while(j >= start + center + 1)  
            copy[copyIndex--] = data[j--];  
          
        for(int k = start; k <= end; k++)  
            data[k] = copy[k];  
          
        return (left + right + count)%1000000007;  
    }
};
