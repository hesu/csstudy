/*
 	abstract classes - polymorphism
*/
	
#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <algorithm>
#include <set>
#include <cassert>
using namespace std;

struct Node{
   Node* prev;
   Node* next;
   int key;
   int value;
   Node(Node* p, Node* n, int k, int val):prev(p),next(n),key(k),value(val){};
   Node(int k, int val):prev(NULL),next(NULL),key(k),value(val){};
};

class Cache{
   protected: 
   map<int,Node*> mp; //map the key to the node in the linked list
   int cp;  //capacity
   Node* tail; // double linked list tail pointer
   Node* head; // double linked list head pointer
   virtual void set(int, int) = 0; //set function
   virtual int get(int) = 0; //get function
};


class LRUCache : public Cache {
  public:
  LRUCache(int cp):Cache() {
    this->cp = cp;
    head = nullptr;
    tail = nullptr;
  }

  virtual ~LRUCache() {;}

  virtual void set(int key, int value)
  {
    std::map<int, Node*>::iterator it;

    if( mp.size() == 0) {
      Node *node = new Node(key, value);
      insert_into_head(node);
      mp.insert(make_pair(key, node));
    }
    else if( mp.find(key) != mp.end()) {
      Node *node = new Node(key, value);
      insert_into_head(node);
      mp.insert(make_pair(key, node));
    }
    else if( mp.size() < (unsigned int)cp) {
      Node *node = new Node(key, value);
      insert_into_head( node);
      mp.insert(make_pair(key, node));
    } else {
      auto it = tail;
      mp.erase(it->key);
      linked_list_delete(it);
      delete it;
    }
  }

  virtual int get(int key)
  {
    std::map<int, Node*>::iterator it;
    it = mp.find(key);

    if( it == mp.end()) {
       return -1;
    } else {
      insert_into_head(mp[key]);
      return it->second->value;
    }
  }

  private :
  void linked_list_delete(Node* node)
  {
    if (!node) return;
    if (node->prev) node->prev->next = node->next;
    if (node->next) node->next->prev = node->prev;
    if (node == head) head = node->next;
    if (node == tail) tail = node->prev;
  }

  void insert_into_head(Node* node)
  {
    if (!node) return;
    linked_list_delete(node);
    if (head) head->prev = node;
    node->next = head;
    node->prev = nullptr;
    if (!tail) tail = node;
    head = node;
  }

};

int main() {
   int n, capacity,i;
   cin >> n >> capacity;
   LRUCache l(capacity);
   for(i=0;i<n;i++) {
      string command;
      cin >> command;
      if(command == "get") {
         int key;
         cin >> key;
         cout << l.get(key) << endl;
      } 
      else if(command == "set") {
         int key, value;
         cin >> key >> value;
         l.set(key,value);
      }
   }
   return 0;
}
