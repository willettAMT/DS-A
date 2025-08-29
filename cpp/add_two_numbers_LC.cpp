#include <iostream>

/*
 * You are given two non-empty linked lists representing two non-negative integers. 
 * The digits are stored in reverse order, and each of their nodes contains a single digit.
 * Add the two numbers and return the sum as a linked list.
 * You may assume the two numbers do not contain any leading zero, except the number 0 itself.
 */

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class LinkedList {
    public:
        ListNode * add_two_numbers(ListNode *l1, ListNode *l2) {
            ListNode *head = new ListNode();
            ListNode *curr = head; 
            int carry {0};

            while(l1 || l2 || carry != 0){
                int digit1 = (l1) ? l1->val : 0;
                int digit2 = (l2) ? l2->val : 0;
                int sum = digit1 + digit2 + carry;

                ListNode *new_node = new ListNode(sum % 10);
                carry = sum/10;
                curr->next = new_node;
                curr = curr->next;

                l1 = (l1) ? l1->next : nullptr;
                l2 = (l2) ? l2->next : nullptr;
            }
            return head->next;
        }

        void print_list(ListNode *list) {
            if (!list) return;

            ListNode * iter = list;
                std::cout << "{";
            while (iter) {
                if (iter->next)
                    std::cout << iter->val << ", ";
                else std::cout << iter->val;
                iter = iter->next;
            }

            std::cout << "}";
        }
};

int main (void) {
    ListNode one(1), two(2), three(3), four(4); //five(5);
    ListNode first_list(3, &one); // 3, 1
    ListNode node1(4, &four);
    ListNode node2(0, &node1);
    ListNode node3(7, &node2);
    ListNode second_list(9, &node3); // 9, 7, 0, 4, 4
    LinkedList run;

    ListNode * result = run.add_two_numbers(&first_list, &second_list); 
    run.print_list(result);
};


/******************* DEAD CODE ****************************************
            int first_int = get_int(l1);
            std::cout << "first int: " << first_int <<std::endl;
            int second_int = get_int(l2);
            std::cout << "second int: " << second_int <<std::endl;
            int sum = _sum(first_int, second_int);
            std::cout << "sum: " << sum <<std::endl;

            if (sum == 0) {
                head = new ListNode(sum);
                return head;
            }

            while (sum > 0) {
                if (!head) {
                    head = curr = new ListNode(sum % 10);
                }
                else {
                    ListNode * new_node = new ListNode(sum % 10);
                    curr->next = new_node;
                    curr = curr->next;
                }
                sum /= 10;
            }
            return head;
        }

        void print_list(ListNode *list) {
            if (!list) return;

            ListNode * iter = list;
                std::cout << "{";
            while (iter) {
                if (iter->next)
                    std::cout << iter->val << ", ";
                else std::cout << iter->val;
                iter = iter->next;
            }

            std::cout << "}";
        }
    private:
        int get_int(ListNode *list) { 
            string ordered_int = ""; 
            ListNode *iter = list;

            while (iter) {
                char digitChar = iter->val + CONVERSION;
                ordered_int = digitChar + ordered_int;
                iter = iter->next;
            }

            int num = std::stoi(ordered_int); 
            return num;
        }

        int _sum(int first_int, int second_int) { return first_int + second_int; }
        */
