#pragma once
#include <stdexcept>

template <typename T>
class Stack
{
public:
    Stack();
    ~Stack();
    void push(T element);
    T pop();
    T top();
    bool isEmpty();

    class Node
    {
    public:
        Node(T element, Node* next = nullptr);
        ~Node();
        T& getElement();
        Node* getNext();
        void setNext(Node* next);

    private:
        T element;
        Node* next;
    };

    Node* getHead();

    class Iterator
    {
    public:
        Iterator(Node* node);
        ~Iterator();
        T& operator*();
        Iterator& operator++();
        bool operator!=(const Iterator& other);

    private:
        Node* node;
    };

    Iterator begin();
    Iterator end();

private:
    Node* head;
};

template <typename T>
Stack<T>::Stack()
{
    head = nullptr;
}

template <typename T>
Stack<T>::~Stack()
{
    Node* current = head;
    while (current != nullptr)
    {
        Node* next = current->getNext();
        delete current;
        current = next;
    }
}

template <typename T>
void Stack<T>::push(T element)
{
    Node* newNode = new Node(element, head);
    head = newNode;
}

template <typename T>
T Stack<T>::pop()
{
    if (head == nullptr)
        throw std::out_of_range{ "Stack is empty" };

    Node* current = head;
    head = head->getNext();
    T element = current->getElement();
    delete current;
    return element;
}

template <typename T>
T Stack<T>::top()
{
    if (head == nullptr)
        throw std::out_of_range{ "Stack is empty" };

    return head->getElement();
}

template <typename T>
bool Stack<T>::isEmpty()
{
    return head == nullptr;
}

template <typename T>
Stack<T>::Node::Node(T element, Node* next)
{
    this->element = element;
    this->next = next;
}

template <typename T>
Stack<T>::Node::~Node()
{
}

template <typename T>
T& Stack<T>::Node::getElement()
{
    return element;
}

template <typename T>
typename Stack<T>::Node* Stack<T>::Node::getNext()
{
    return next;
}

template <typename T>
void Stack<T>::Node::setNext(Node* next)
{
    this->next = next;
}

template <typename T>
typename Stack<T>::Node* Stack<T>::getHead()
{
    return head;
}

template <typename T>
typename Stack<T>::Iterator Stack<T>::begin()
{
    return Iterator(head);
}

template <typename T>
typename Stack<T>::Iterator Stack<T>::end()
{
    return Iterator(nullptr);
}

template <typename T>
Stack<T>::Iterator::Iterator(Node* node)
{
    this->node = node;
}

template <typename T>
Stack<T>::Iterator::~Iterator()
{
}

template <typename T>
T& Stack<T>::Iterator::operator*()
{
    return node->getElement();
}

template <typename T>
typename Stack<T>::Iterator& Stack<T>::Iterator::operator++()
{
    node = node->getNext();
    return *this;
}

template <typename T>
bool Stack<T>::Iterator::operator!=(const Iterator& other)
{
    return node != other.node;
}
