
struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution
{
public:
    ListNode *swapPairs(ListNode *head)
    {
        ListNode *tempNode = head;
        while (tempNode != nullptr && tempNode->next != nullptr)
        {
            int tempVal = tempNode->val;
            int tempNextVal = tempNode->next->val;

            // swap values
            tempVal += tempNextVal;
            tempNextVal = tempVal - tempNextVal;
            tempVal = tempVal - tempNextVal;

            tempNode->val = tempVal;
            tempNode->next->val = tempNextVal;

            tempNode = tempNode->next->next;
        }
        return head;
    }
};

int main()
{
    ListNode *head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);

    Solution *s = new Solution();
    s->swapPairs(head);
    return 0;
}