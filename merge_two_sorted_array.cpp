/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* temp, *dummy; //tạo 2 con trỏ Node mới
        temp = new ListNode();    // khai báo vùng nhớ cho temp
        dummy = temp;    // gán địa chỉ của temp cho dummy (bù nhìn)

        // loop while khi 2 mảng không trống
        while (list1 && list2){    
            // nếu giá trị ở mảng trước < giá trị ở mảng sau hoặc ngược lại -> gán temp->next=list1/list2
            if (list1->val < list2->val){
                temp->next=list1;
                list1=list1->next;
            }
            else{
                temp->next=list2;
                list2=list2->next;
            }
            //??
            temp = temp->next;
        }

        // nếu chỉ còn 1 trong 2 mảng k trống thì gán temp->next=list1/list2
        if (list1) temp->next=list1;
        if (list2) temp->next=list2;

        //trả về dummy->next (vì giá trị đầu = 0(hoặc giá trị bất kì chưa khai báo))
        return dummy->next;
    }
};

// again nào quỡn sẽ cmt, qá bùn ngủ
