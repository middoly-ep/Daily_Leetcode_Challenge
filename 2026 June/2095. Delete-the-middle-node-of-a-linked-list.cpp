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
using namespace std;
class Solution {
public:
    ListNode* deleteMiddle(ListNode* head) {
        if (head == nullptr || head->next == nullptr) return nullptr;
        ListNode* prev = head;
        ListNode* curr = head;
        ListNode* fast = head;
        while (fast != nullptr && fast->next != nullptr){
            fast = fast->next->next;
            curr = curr->next;
            if (prev->next != curr) prev = prev->next;
        }
        prev->next = curr->next;
        delete(curr);
        return head;
    }
};
