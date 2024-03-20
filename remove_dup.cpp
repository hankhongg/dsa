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
    ListNode* deleteDuplicates(ListNode* head) {
        if (head == nullptr || head->next == nullptr) return head;

        ListNode *dummy;
        dummy = new ListNode();
        dummy->val=-1000;

        dummy->next=head;
        ListNode* cur = head;
        ListNode* prev = dummy;

        while(cur!=nullptr){
            if (cur->val > prev->val){
                prev=prev->next;
            }
            else {
                prev->next=cur->next;
            }
            cur=cur->next;
        }


        return dummy->next;
    }
};

// nào rảnh cmt chớ bùn ngủ qá :Đ
