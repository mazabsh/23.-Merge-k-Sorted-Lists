#include<iostream> 
#include<queue> 

using namespace std; 

struct ListNode{
    int val; 
    ListNode* next; 
    ListNode(): val(0), next(nullptr){}
    ListNode(int _val): val(_val), next(nullptr){}
    ListNode(int _val, ListNode* _next): val(_val), next(_next){}
};
class Solution{
public: 
      struct Compare{
      bool operator()(ListNode* a, ListNode* b){
        return a->val > b->val ; 
      }
      };
      ListNode* mergeKLists(vector<ListNode*> lists){
        priority_queue<ListNode*, vector<ListNode*> , Compare> pq; 
        for(auto list:lists){
          if(list) pq.push(list); 
        }
        ListNode dummy(0); 
        ListNode* tail = &dummy; 
        while(!pq.empty()){
          ListNode* minNode = pq.top(); 
          pq.pop(); 
          tail->next = minNode; 
          tail = tail->next; 
          if(minNode->next) pq.push(minNode->next); 
        }
        return dummy.next; 
      }
};
ListNode* buildList(const vector<int>& vals) {
    ListNode dummy(0);
    ListNode* tail = &dummy;
    for (int val : vals) {
        tail->next = new ListNode(val);
        tail = tail->next;
    }
    return dummy.next;
}

// Helper function to print a list
void printList(ListNode* head) {
    while (head) {
        cout << head->val << " -> ";
        head = head->next;
    }
    cout << "NULL" << endl;
}

int main() {
    vector<ListNode*> lists = {
        buildList({1, 4, 5}),
        buildList({1, 3, 4}),
        buildList({2, 6})
    };

    Solution sol;
    ListNode* merged = sol.mergeKLists(lists);
    printList(merged);
    return 0;
}
