#include <iostream>


struct Node
{
    int value  = 0;
    Node* next = nullptr;

    Node(int v)
      : value(v)
    {
    }

    ~Node()
    {
        delete next;
    }
};


void PrintList(Node* list)
{
    std::cout << "[";
    for (Node* current = list; current != nullptr; current = current->next)
    {
        std::cout << current->value << ", ";
    }
    std::cout << "]\n";
}


Node* GenerateTestList(unsigned n)
{
    Node* list = new Node(0);
    Node* current = list;
    for (unsigned i = 1; i < n; i++)
    {
        current->next = new Node(i);
        current = current->next;
    }

    return list;
}


Node* RevertList(Node* list)
{
    if (list == nullptr)
        return nullptr;

    Node* prev = list;
    Node* current = list->next;
    list->next = nullptr;
    while (current != nullptr)
    {
        Node* next = current->next;
        current->next = prev;
        
        prev = current;
        current = next;
    }

    return prev;
}


int main()
{
    Node* list = GenerateTestList(20);
    std::cout << "Initial list: ";
    PrintList(list);

    std::cout << "Reverted list: ";
    list = RevertList(list);
    PrintList(list);
    delete list;

    return 0;
}
