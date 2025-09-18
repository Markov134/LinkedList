#ifndef LINKEDLIST_H
#define LINKEDLIST_H

template <typename T>
class LinkedList {
  private:
    //---------------- nested Node class ----------------
    class Node {
      public:
        T elem;                                   // stored element
        Node* next;                               // pointer to next node

        Node(const T& element, Node* nxt = nullptr) : elem{element}, next{nxt} {}
    };  //------------ end of nested Node class ------------

    // LinkedList instance variables
    int sz{0};                                    // number of entries in the list
    Node* head{nullptr};                          // raw pointer to first node of list
    Node* tail{nullptr};                          // raw pointer to last node of list

  public:
    LinkedList() {}                         // Constructs an empty list

    // ---------- Accessor functions ----------
    int size() const { return sz; }               // Returns the number of elements stored
    bool empty() const { return sz == 0; }        // Tests whether the list is empty
    T& front() { return head->elem; }             // Live reference to first element
    const T& front() const { return head->elem; } // Const reference to first element
    T& back() { return tail->elem; }              // Live reference to last element
    const T& back() const { return tail->elem; }  // Const reference to last element

    // ---------- Update functions ----------

    // Inserts element at the beginning of the list
    void push_front(const T& elem) {
        head = new Node(elem, head);              // new head uses old head (possibly null) as next
        if (sz == 0)
            tail = head;                          // special case: newest node is also the tail
        sz++;
    }

    // Inserts element at the end of the list
    void push_back(const T& elem) {
        Node* newest{new Node(elem)};
        if (sz == 0)
            head = newest;                        // newest node becomes head
        else
            tail->next = newest;                  // new node follows old tail
        tail = newest;                            // in either case, newest node becomes the tail
        sz++;
    }

    // Removes the first element of the list; behavior is undefined if list is empty
    void pop_front() {
        Node* old{head};
        head = head->next;
        delete old;
        sz--;
        if (sz == 0)
            tail = nullptr;                       // special case as list is now empty
    }

    void print() {
        Node* current = head;


        while (current != nullptr) {
            std::cout << current->elem << std::endl;

            if (current->next != nullptr) {
                current = current->next;
            }
            else {
                current = nullptr;
            }
        }
    }
};

#endif //LINKEDLIST_H
