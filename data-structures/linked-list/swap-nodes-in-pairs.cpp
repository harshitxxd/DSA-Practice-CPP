#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;

    ListNode(int x) : val(x), next(NULL) {}
};

void insert(ListNode*& head, ListNode*& tail, int value) {
    ListNode* newNode = new ListNode(value);
    if (head == NULL) {
        head = tail = newNode;
    } else {
        tail->next = newNode;
        tail = newNode;
    }
}

class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        if (head == NULL || head->next == NULL) return head;

        ListNode* first = head;
        ListNode* second = head->next;
        first->next = swapPairs(second->next);
        second->next = first;

        return second;
    }
};

int main() {
    ListNode* head = NULL;
    ListNode* tail = NULL;
    insert(head, tail, 1);
    insert(head, tail, 2);
    insert(head, tail, 3);
    insert(head, tail, 4);

    Solution solution;
    head = solution.swapPairs(head);

    while (head != NULL) {
        cout << head->val << " ";
        head = head->next;
    }

    return 0;
}
