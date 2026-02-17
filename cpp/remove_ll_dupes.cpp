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
    ListNode* deleteDuplicates(ListNode* head) {
      if (!head) return nullptr;
      if (!head->next) return head;

      ListNode *prev = head, *curr = head->next;

      while (curr) {
        if (prev->val == curr->val) {
          prev->next = curr->next;
          curr = curr->next;
        } else {
          prev = curr;
          curr = curr->next;
        }
      }
      return head;
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

int main () {
  ListNode five(15);
  ListNode four(7, &five);
  ListNode three(7, &four);
  ListNode two(7, &three);
  ListNode head(1, &two);

  Solution solution;

  std::println("***BEFORE REMOVAL***");
  std::println("\nList1\n");
  solution.print(&head);
  ListNode * result = solution.deleteDuplicates(&head);
  std::println("\n***AFTER REMOVAL***");
  solution.print(result);
  return EXIT_SUCCESS;
}
