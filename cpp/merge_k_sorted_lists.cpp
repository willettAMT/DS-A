/*
You are given an array of k linked-lists lists, each linked-list is sorted in ascending order.

Merge all the linked-lists into one sorted linked-list and return it.

 

Example 1:

Input: lists = [[1,4,5],[1,3,4],[2,6]]
Output: [1,1,2,3,4,4,5,6]
Explanation: The linked-lists are:
[
  1->4->5,
  1->3->4,
  2->6
]
merging them into one sorted linked list:
1->1->2->3->4->4->5->6

Example 2:

Input: lists = []
Output: []

Example 3:

Input: lists = [[]]
Output: []

 

Constraints:

    k == lists.length
    0 <= k <= 104
    0 <= lists[i].length <= 500
    -104 <= lists[i][j] <= 104
    lists[i] is sorted in ascending order.
    The sum of lists[i].length will not exceed 104.

*/

#include <print>
#include <memory>
#include <queue>
#include <vector>

/*
// LC version
struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {};
      ListNode(int x) : val(x), next(nullptr) {};
      ListNode(int x, ListNode *next) : val(x), next(next) {};
}; 

using std::vector;
using v_t = std::vector<ListNode*>;
using std::priority_queue;

class Solution {
    public:
        // Class-level typedef
        typedef ListNode* node_p;

        // Custom comparator for min-heap
        struct Compare {
            bool operator()(node_p a, node_p b) {
                return a->val > b->val;  // Min-heap behavior
            }
        };

        node_p mergeKLists(v_t& lists) {
            // Create min-heap using our typedef and aliases
            priority_queue<node_p, vector<node_p>, Compare> minHeap;

            // Step 1: Add all non-null list heads to the heap
            for (node_p list : lists) {
                if (list != nullptr) {
                    minHeap.push(list);
                }
            }

            // Step 2: Create dummy head for easier list construction
            node_p dummy = new ListNode(0);
            node_p current = dummy;

            // Step 3: Build result list by always taking the minimum element
            while (!minHeap.empty()) {
                // Extract the node with minimum value
                node_p minNode = minHeap.top();
                minHeap.pop();

                // Append to result list
                current->next = minNode;
                current = current->next;

                // If this node has a next node, add it to heap
                if (minNode->next != nullptr) {
                    minHeap.push(minNode->next);
                }
            }

            // Step 4: Return the merged list (skip dummy head)
            node_p result = dummy->next;
            delete dummy;  // Clean up dummy node
            return result;
        }
};

// Helper function to create a linked list from vector (for testing)
ListNode* createList(vector<int>& vals) {
    if (vals.empty()) return nullptr;

    ListNode* head = new ListNode(vals[0]);
    ListNode* current = head;

    for (int i = 1; i < vals.size(); i++) {
        current->next = new ListNode(vals[i]);
        current = current->next;
    }

    return head;
}

// Helper function to print linked list (for testing)
void printList(ListNode* head) {
    while (head != nullptr) {
        cout << head->val;
        if (head->next != nullptr) cout << "->";
        head = head->next;
    }
    cout << endl;
}
*/
/******************************************************************************
--------------------------- Smart Pointer Version -----------------------------  
*******************************************************************************/

/**
 * ListNode designed for shared ownership - perfect for heap algorithms
 */
struct ListNode {
    int val;
    std::shared_ptr<ListNode> next;
    
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, std::shared_ptr<ListNode> next) : val(x), next(next) {}
};

// Smart pointer typedefs and aliases - fully committed approach
using std::vector;
using std::priority_queue;

class Solution {
    public:
        // Clean typedefs for smart pointer approach
        typedef std::shared_ptr<ListNode> node_p;
        typedef vector<node_p> v_t;

        // Custom comparator that works directly with smart pointers
        struct Compare {
            bool operator()(const node_p& a, const node_p& b) const {
                return a->val > b->val;  // Min-heap behavior
            }
        };

        typedef priority_queue<node_p, v_t, Compare> heap_t;

        node_p mergeKLists(v_t& lists) {
            // Step 1: Create min-heap that stores smart pointers directly
            heap_t minHeap;

            // Step 2: Add all non-null list heads to heap
            for (const node_p& list : lists) {
                if (list != nullptr) {
                    minHeap.push(list);
                }
            }

            // Step 3: Create dummy head using smart pointer
            node_p dummy = std::make_shared<ListNode>(0);
            node_p current = dummy;

            // Step 4: Build result list using only smart pointers
            while (!minHeap.empty()) {
                // Extract minimum node (shared ownership)
                node_p minNode = minHeap.top();
                minHeap.pop();

                // Add the next node to heap if it exists
                if (minNode->next != nullptr) {
                    minHeap.push(minNode->next);
                }

                // Create new node for result list to avoid shared ownership issues
                current->next = std::make_shared<ListNode>(minNode->val);
                current = current->next;
            }

            // Step 5: Return the merged list (skip dummy head)
            return dummy->next;
        }
};

// Alternative approach that reuses existing nodes (more memory efficient)
class SolutionReuse {
    public:
        typedef std::shared_ptr<ListNode> node_p;
        typedef vector<node_p> v_t;

        node_p mergeKLists(v_t& lists) {
            auto compare = [](const node_p& a, const node_p& b) {
                return a->val > b->val;
            };

            priority_queue<node_p, v_t, decltype(compare)> minHeap(compare);

            // Add all non-null heads to heap
            for (const node_p& list : lists) {
                if (list != nullptr) {
                    minHeap.push(list);
                }
            }

            node_p dummy = std::make_shared<ListNode>(0);
            node_p current = dummy;

            while (!minHeap.empty()) {
                node_p minNode = minHeap.top();
                minHeap.pop();

                // Store next before we modify the node
                node_p nextNode = minNode->next;

                // Break the connection to avoid cycles
                minNode->next = nullptr;

                // Add to result list
                current->next = minNode;
                current = current->next;

                // Add the next node to heap if it exists
                if (nextNode != nullptr) {
                    minHeap.push(nextNode);
                }
            }

            return dummy->next;
        }
};

// Helper functions that work with smart pointers and typedefs
Solution::node_p createList(const vector<int>& vals) {
    if (vals.empty()) return nullptr;

    Solution::node_p head = std::make_shared<ListNode>(vals[0]);
    Solution::node_p current = head;
    const size_t n {vals.size()};

    for (size_t i = 1; i < n; ++i) {
        current->next = std::make_shared<ListNode>(vals[i]);
        current = current->next;
    }

    return head;
}

void printList(const Solution::node_p& head) {
    Solution::node_p current = head;
    while (current != nullptr) {
        std::print("{}",current->val);
        if (current->next != nullptr) 
            std::print("->");

        current = current->next;
    }

    std::println();
}

// Clean example showing consistent typedef usage
void demonstrateUsage() {
    Solution solution;

    // Clean vector creation using typedef
    Solution::v_t lists = {
        createList({1, 4, 5}),
        createList({1, 3, 4}),
        createList({2, 6})
    };

    // Clean function call and result
    Solution::node_p merged = solution.mergeKLists(lists);
    printList(merged);  // Output: 1->1->2->3->4->4->5->6
}
