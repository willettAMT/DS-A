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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
      if (!head) return nullptr;

      int place {};
      ListNode *left_ptr = head, *right_ptr = nullptr;

      while (place < left && left_ptr) {
        left_ptr = left_ptr->next;
        ++place;
      }

      right_ptr = left_ptr->next;
      while (place < right && right_ptr) {
        right_ptr = right_ptr->next;
        ++place;
      }

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

int main(void){

  ListNode five(15);
  ListNode four(11, &five);
  ListNode three(7, &four);
  ListNode two(4, &three);
  ListNode head(1, &two);

  int left {}, right {};
  Solution solution;

  std::println("***List before reversal***\n");
  solution.print(&head);

  ListNode * res ( solution.reverseBetween(&head, left, right));
  
  std::println("***List after reversal***\n");
  solution.print(&res);

  return EXIT_SUCCESS;
}
