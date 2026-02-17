#include <cstdlib>
#include <print>

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
      if (!list1) return list2;
      if (!list2) return list1;

      ListNode dummy(0);
      ListNode *ptr = &dummy;

      while (list1 && list2) {
        if (list1->val <= list2->val) {
          ptr->next = list1;
          list1 = list1->next;
        }
        else {
          ptr->next = list2;
          list2 = list2->next;
        }
        ptr = ptr->next;
      }

      if (list1) {
        ptr->next = list1;
      } else ptr->next = list2;
      
      return dummy.next;
    }

    void print(ListNode *head) {
      if (!head) {
        std::println("List Empty\n");
        return;
      }

      ListNode *curr = head;

      std::print("( ");
      while (curr) {
        if (curr->next)
          std::print("{}, ", curr->val);
        else 
          std::print("{} ", curr->val);
        curr = curr->next;
      }
      std::print(") ");
    }

};

int main(){
  ListNode five(15);
  ListNode four(11, &five);
  ListNode three(7, &four);
  ListNode two(4, &three);
  ListNode head(1, &two);

  ListNode five_(22);
  ListNode four_(16, &five_);
  ListNode three_(12, &four_);
  ListNode two_(11, &three_);
  ListNode head_(8, &two_);

  Solution solution;

  std::println("***BEFORE MERGE***");
  std::println("\nList1\n");
  solution.print(&head);
  std::println("\nList2\n");
  solution.print(&head_);
  ListNode * result = solution.mergeTwoLists(&head, &head_);
  std::println("\n***AFTER MERGE***");
  solution.print(result);
  return EXIT_SUCCESS;
}

