
#ifndef PROJECT_SIMPLYLINKEDLIST_H
#define PROJECT_SIMPLYLINKEDLIST_H
#include <iostream>
#include <vector>

template <class T>
class SimplyLinkedList
{
    struct Node
    {
        T data;
        Node * next;
        Node(T val): data(val), next(nullptr){}
    };
    Node *head;

public:
    SimplyLinkedList() : head(nullptr){}
//    SimplyLinkedList(const SimplyLinkedList<T> & ll) = default;
//    SimplyLinkedList& operator=(SimplyLinkedList const&){};
    ~SimplyLinkedList();
    std::vector<T> iterator();
    void insert(T);
    void display(std::ostream& out = std::cout) const
    {
        Node *node = head;
        while(node != nullptr)
        {
            out << node->data << ",";
            node = node->next;
        }
    }

    void deleteNode(T);
    template <class U>
    friend std::ostream & operator<<(std::ostream & os, const SimplyLinkedList<U> & ll);

public:
    struct Node *search(T n)
    {                            //returns node of the given value
        Node *node = head;
        while(node != nullptr)
        {
            if(node->data == n)
                return node;
            node = node->next;
        }

        std::cerr << "No such element in the list \n";
        return nullptr;
    }

};

template <class U>
std::ostream & operator<<(std::ostream & os, const SimplyLinkedList<U>& ll)
{
    ll.display(os);
    return os;
}

template <class T>
void SimplyLinkedList<T>::insert(T data)
{
    Node *t = new Node(data);
    Node *tmp = head;
    if (tmp == nullptr)
    {
        head = t;
    }
    else
    {
        while (tmp->next != nullptr)
        {
            tmp = tmp->next;
        }
        tmp->next = t;
    }
}

template <class T>
void SimplyLinkedList<T>::deleteNode(T data)
{
    Node *node=search(data);
    Node *tmp = head;

    if(tmp == node)
    {
        head=tmp->next;
    }
    else if (node != nullptr)
    {
        while(node != nullptr)
        {
            if(tmp->next==node)
            {
                tmp->next=node->next;
                return ;
            }
            tmp=tmp->next;
        }
        delete tmp;
    }
}

template <class T>
SimplyLinkedList<T>::~SimplyLinkedList()
{
    Node *tmp = nullptr;
    while (head)
    {
        tmp = head;
        head = head->next;
        delete tmp;
    }
    head =nullptr;
}
template <class T>
std::vector<T> SimplyLinkedList<T>::iterator() {
    std::vector<T> v;
    Node *node = head;
    while(node != nullptr)
    {

            v.push_back(node->data);
        node = node->next;
    }
    return v;
}

#endif //PROJECT_SIMPLYLINKEDLIST_H
