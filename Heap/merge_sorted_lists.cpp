#include<iostream>
#include<bits/stdc++.h>
using namespace std;

 struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
  };

class Compare{
    public:
        bool operator()(ListNode* a , ListNode* b){
            return a->val > b->val;  //greater elements should have lower priority
        }
};

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<ListNode*,vector<ListNode*>,Compare>minHeap;
        for(auto list : lists){
            if(list){
                minHeap.push(list);
            }
        }   
        ListNode* dummy = new ListNode();
        ListNode* temp = dummy;
        while(!minHeap.empty()){
            temp->next = minHeap.top();
            minHeap.pop();
            temp = temp->next;
            if(temp->next != nullptr) minHeap.push(temp->next);
        }
        return dummy->next;
    }
};

int main(){
    vector<ListNode*>lists;
    ListNode* list1 = new ListNode(1);
    list1->next = new ListNode(4);
    list1->next->next = new ListNode(5);
    lists.push_back(list1);

    ListNode* list2 = new ListNode(1);
    list2->next = new ListNode(3);
    list2->next->next = new ListNode(4);
    lists.push_back(list2);

    ListNode* list3 = new ListNode(2);
    list3->next = new ListNode(6);
    lists.push_back(list3);

    Solution s;
    ListNode* head = s.mergeKLists(lists);
    ListNode* temp = head;
    while(temp != nullptr){
        cout<<temp->val<<" ";
        temp = temp->next;
    }
    cout<<endl;
    return 0;
}
