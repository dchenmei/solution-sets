#include <bits/stdc++.h>

using namespace std;

struct ListNode
{
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(nullptr) {}
};

/* Notes 
 * - very obvious a linked list topic
 * - both are non-empty (one less corner case)
 * - non-negative (one less corner case)
 * - *** stored in reverse order *** (this makes it easier)
 *   >>>> would be nice if someone wrote a version where numbers are not in reverse <<<<
 * - no leading zero padding
 * - be careful of carries and overflows
 *
 * e.g. 
 * (2->4->3) + (5->6->4) same as 342 + 465
 */
ListNode* add_two_numbers(ListNode *l1, ListNode *l2)
{
	/* Q: Why should we use a dummy?
     *
     */
	ListNode *dummy = new ListNode(-1);
	ListNode *curr = dummy;

	/* Other possible solutions */


	/* >>>> Double check solution and add others */

	/* as like anything, these pointers are passed by value */
	int carry = 0;
	while (l1 || l2 || carry)
	{
		int val1 = l1 ? l1->val : 0;
		int val2 = l2 ? l2->val : 0;
		int sum = val1 + val2 + carry;
		int carry = sum / 10;
		curr->next = new ListNode(sum % 10);
		curr = curr->next;
		l1 = l1 ? l1->next : l1;
		l2 = l2 ? l2->next : l2;
	}

	return dummy->next;
}

int main()
{

}
