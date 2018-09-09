/**
  题目描述:

  统计一个数字在排序数组中出现的次数。

  思路：在排序数组中进行二分查找，算法复杂度O(logn)，找到头尾指针位置计算差值得到次数。

*/

class Solution {
public:
    int GetNumberOfK(vector<int> data ,int k) {
        int num = 0;
        
        if(!data.empty()){
            int first = GetFirstK(data, k, 0, data.size() - 1);
            int last = GetLastK(data, k, 0, data.size() - 1);
            
            if(first > -1 && last > -1)
                num = last - first + 1;
        }
        
        return num;
    }
    
    int GetFirstK(vector<int> data, int k, int start, int end) {
        if(start > end)
            return -1;
        int midIndex = (start + end) / 2;
        int midData = data[midIndex];
        
        if(midData == k){
            if((midIndex > 0 && data[midIndex - 1] != k) || midIndex == 0)
                return midIndex;
            else
                end = midIndex - 1;
        }
        else if(midData > k)
            end = midIndex - 1;
        else
            start = midIndex + 1;
        
        return GetFirstK(data, k, start, end);
    }
    
    int GetLastK(vector<int> data, int k, int start, int end) {
        if(start > end)
            return -1;
        int midIndex = (start + end) / 2;
        int midData = data[midIndex];
        
        if(midData == k){
            if((midIndex < data.size() - 1 && data[midIndex+1] != k) || midIndex == data.size() - 1)
                return midIndex;
            else
                start = midIndex + 1;
        }
        else if(midData < k)
            start = midIndex + 1;
        else
            end = midIndex - 1;
        
        return GetLastK(data, k, start, end);
    }
};