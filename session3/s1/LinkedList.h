class Node{
public:
    int data;
    Node* previous;
    Node* Next;
    Node();
    ~Node();
};

class LinkedList
{
private:
Node* head = new Node();
Node* tail = new Node();
public:
    LinkedList();
    LinkedList(int value, int size);
    LinkedList(const LinkedList& Cloned);
    ~LinkedList();
    void push_back(int num);
    void push_front(int num);
    int pop_back();
    int pop_front();
    bool is_empty();
    int at(int index);
};