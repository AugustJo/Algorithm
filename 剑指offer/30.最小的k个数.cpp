/*
  题目描述:

  输入n个整数，找出其中最小的K个数。
  例如输入4,5,1,6,2,7,3,8这8个数字，则最小的4个数字是1,2,3,4,。

  思路：
  解法一：O(n)的算法，只有当我们可以修改输入的数组时可用，基于快排的Partition函数，
  基于数组的第k个数来调整，使得比第k个数小的所有数字都位于数组左边，比第k个数字大的
  都位于数组右边。
  解法二：O(nlogK)的算法，特别适合处理海量数据
  创建一个容量为k的大根堆，第一步将输入数组的前k个数插入此大根堆，
  第二步将输入数组后面的数依此与大根堆堆顶元素比较，并将较小者替换掉大根堆堆顶元素。
  考虑到可以用c++中的STL，我们可以考虑用基于红黑树实现的set和multiset

*/

// 解法一： (2ms 476k)
class Solution {
public:
    vector<int> GetLeastNumbers_Solution(vector<int> input, int k) {
        vector<int> output;
        if(input.empty() || k > input.size() || k <=0)
            return output;
        
        int n = input.size();
        int start = 0;
        int end = n - 1;
        int index = Partition(input, n, start, end);
        while(index != k - 1){
            if(index > k - 1){
                end = index - 1;
                index = Partition(input, n, start, end);
            }
            else{
                start = index + 1;
                index = Partition(input, n, start, end);
            }
        }

        for(int i = 0; i < k; i++)
            output.push_back(input[i]);
        
        return output;
    }

    int Partition(vector<int> &data, int length, int start, int end){
        if(data.empty() || length < 0 || start < 0 || end >= length)
            return -1;

        int index = start; // RandomInRange(start, end);
        swap(data[index], data[end]);

        int small = start - 1;
        for(index = start; index < end; ++index){
            if(data[index] < data[end]){
                ++small;
                if(small != index)
                    swap(data[index], data[small]);
            }
        }

        ++small;
        swap(data[small], data[end]);

        return small;
    }

};

// 解法二：利用STL中的multiset(基于RB树)不修改原始数组 (3ms 480k)
class Solution {
public:
    typedef multiset<int, greater<int> >     intSet;
    typedef multiset<int, greater<int> >::iterator setIterator;

    vector<int> GetLeastNumbers_Solution(vector<int> input, int k) {
        vector<int> output;
        if(input.empty() || k > input.size() || k <=0)
            return output;
        
        intSet leastNumbers;
        vector<int>::iterator iter = input.begin();
        for(;iter != data.end(); ++iter){
            if(leastNumbers.size() < k)
                leastNumbers.insert(*iter);

            else{
                setIterator iterGreatest = leastNumbers.begin();
                if(*iter < *(leastNumbers.begin())){
                    leastNumbers.erase(iterGreatest);
                    leastNumbers.insert(*iter);
                }
            }
        }

        for(int i=0; i<k; i++)
            output.push_back(leastNumbers[i]);
        
        return output;
    }
};
