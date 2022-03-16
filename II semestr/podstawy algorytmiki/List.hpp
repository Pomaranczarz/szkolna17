#pragma once

template<typename T>
class List
{
private:
    class Node
    {
    public:
        Node(T value, Node* next = nullptr) : value{ value }, next{ next } {}

        T value;
        Node* next;
    };

    class iterator
    {
    public:
        iterator(Node* node) : current{ node } {}

        bool operator==(const iterator& other) const { return current == other.current; }
        bool operator!=(const iterator& other) const { return current != other.current; }
        T& operator*() { return current->value; }

        iterator& operator++() {
            current = current->next;
            return *this;
        }

    private:
        Node* current;
    };

public:
    List() = default;
    List(const List&) = delete;
    List& operator=(const List&) = delete;
    List(List&&) = delete;
    List& operator=(List&&) = delete;
    ~List();

public:
    void push(const T& value);
    void pop();

    iterator begin();
    iterator end();

private:
    Node* head;
    size_t size{ 0 };
};

template<typename T>
List<T>::~List() {
    while (head) {
        Node* tmp = head;
        head = head->next;
        delete tmp;
    }
}

template<typename T>
void List<T>::push(const T& value) {
    Node* new_node = new Node{ value };
    if (!head)
        head = new_node;
    else {
        new_node->next = head;
        head = new_node;
    }
}

template<typename T>
void List<T>::pop() {
    if (!head)
        return;

    Node* tmp = head;
    head = head->next;
    delete tmp;
}

template<typename T>
typename List<T>::iterator List<T>::begin() {
    return iterator{ head };
}

template<typename T>
typename List<T>::iterator List<T>::end() {
    return iterator{ nullptr };
}