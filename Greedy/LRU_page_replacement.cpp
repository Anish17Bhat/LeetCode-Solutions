#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class LRUCache{
    private:
        int time = 0;
        int size = 0;
        int cap = 0;
        struct ListNode{
            int key;
            int val;
            ListNode* next;
            ListNode* prev;
            ListNode() : next(nullptr), prev(nullptr) {}
            ListNode(int k,int v) : key(k), val(v) {} 
        };
        ListNode* head = new ListNode();
        unordered_map<int,ListNode*>mp;

        void insertFront(ListNode* node){
            if(head->next == nullptr) {
                head->next = node;
                head->prev = node; 
                node->prev = head;
                node->next = head;
                return;
            }
            head->next->prev = node;
            node->next = head->next;
            node->prev = head;
            head->next = node;
        }
    public:
        LRUCache(int capacity){
            cap = capacity;
        }
        void put(int key , int value){
            if(mp.find(key) != mp.end()){
                ListNode* node = mp[key];
                node->prev->next = node->next;
                node->next->prev = node->prev;
                insertFront(node);
                mp[key] = node;
            }
            else{
                if(size < cap){
                    ListNode* node = new ListNode(key,value);
                    insertFront(node);
                    mp[key] = node;
                    size++;
                }
                else{
                    ListNode* lastNode = head->prev;
                    head->prev = lastNode->prev;
                    lastNode->prev->next = head;
                    mp.erase(lastNode->key);
                    delete lastNode;
                    ListNode* node = new ListNode(key,value);
                    insertFront(node);
                    mp[key] = node;
                }
            }
        }
        int get(int key){
            if(mp.find(key) == mp.end()) return -1;
            ListNode* node = mp[key];
            node->prev->next = node->next;
            node->next->prev = node->prev;
            insertFront(node);
            return node->val;
        }
};

int main(){
    LRUCache *l = new LRUCache(2);
    l->put(1,1);
    l->put(2,2);
    cout<<l->get(1)<<endl;
    l->put(3,3);
    cout<<l->get(2)<<endl;
    return 0;
}
