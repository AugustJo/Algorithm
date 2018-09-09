/**
  题目描述:

  输入两个链表，找出它们的第一个公共结点。

  思路：

*/

/*
struct ListNode {
    int val;
    struct ListNode *next;
    ListNode(int x) :
      val(x), next(NULL) {
    }
};*/

class Solution {
public:
    ListNode* FindFirstCommonNode( ListNode* pHead1, ListNode* pHead2) {
        // ListNode* vec = NULL;
        if(pHead1==NULL || pHead2==NULL)
            return NULL;

        int length1 = getListLength(pHead1);
        int length2 = getListLength(pHead2);
        ListNode* pListLong = pHead1;
        ListNode* pListShort = pHead2;
        int LengthDif = length1 - length2;
        if(length2 > length1){
            pListLong = pHead2;
            pListShort = pHead1;
            LengthDif = length2 - length1;
        }
        for(int i=LengthDif; i>0; --i){
            pListLong = pListLong->next;
        }

        while(pListLong && pListShort)
        {
            if(pListLong == pListShort)
                return pListLong;

            pListLong = pListLong->next;
            pListShort = pListShort->next;
        }
        
        return NULL;
    }
    int getListLength(ListNode * ptr){
        int length = 0;
        while(ptr != NULL){
            ++length;
            ptr = ptr->next;
        }
        return length;
    }
};
