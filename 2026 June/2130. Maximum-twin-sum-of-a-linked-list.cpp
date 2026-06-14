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
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int pairSum(ListNode* head) {
        vector<int> sums;
        ListNode* curr = head;
        ListNode* after = head;
        int cnt = 0;
        while (curr != nullptr){
            curr = curr->next->next;
            after = after->next;
            cnt++;
        }
        sums.resize(cnt);
        curr = head;
        for (int i = 0; i < cnt; i++){
            sums[i] += curr->val;
            sums[cnt - 1 - i] += after->val;
            curr = curr->next;
            after = after->next;
        }

        int res = 0;
        for (int x : sums){
            res = max(res, x);
        }
        return res;

    }
};
