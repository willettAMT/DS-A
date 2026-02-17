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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
      if (!head || !head->next || !n) {
        return nullptr;
      }

      int nth { count_nodes(head) - n - 1 };
      
      if (!nth) return head->next;

      ListNode *curr = head->next, *prev = head;
      int tracker { 1 };

      while (tracker < nth && curr) 
      { prev = curr; curr = curr->next; ++tracker; }

      if (tracker == nth && curr) {
        prev->next = curr->next;
      }

      return head;
    }

    int count_nodes(ListNode *head) {
      if (!head) return 0;

      int count { 1 };
      while (head) {
        ++count;
        head = head->next;
      }
      return count;
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
  ListNode five(5);
  ListNode four(4, &five);
  ListNode three(3, &four);
  ListNode two(2, &three);
  ListNode head(1, &two);

  // ListNode five(5);
  // ListNode head(0, &five);

  // ListNode head(1);
  Solution solution;
  int nth { 2 }; // 3rd node is 4

  std::println("***BEFORE REMOVAL***");
  solution.print(&head);
  ListNode * result = solution.removeNthFromEnd(&head, nth);
  std::println("\n***AFTER REMOVAL***");
  solution.print(result);
  return EXIT_SUCCESS;
}
