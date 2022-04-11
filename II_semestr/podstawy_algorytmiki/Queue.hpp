#pragma once

#include <stdexcept>

template<typename T>
class Queue
{
private:
    struct Node
    {
        T value;
        Node* next;
    };
public:
    Queue();
    ~Queue();
    void push(const T& value);
    template<typename... Args>
    void emplace(Args&&... args);
    T pop();
    bool empty();

    T& front();
    const T& front() const;

    T& back();
    const T& back() const;

    size_t size();

    void swap(Queue& other);

private:
    Node* head;
    Node* tail;
    size_t size_{ 0 };
};

template<typename T>
Queue<T>::Queue()
    : head{ nullptr }
    , tail{ nullptr }
{
    head = nullptr;
    tail = nullptr;
}

template<typename T>
Queue<T>::~Queue() {
    while (head != nullptr) {
        Node* temp = head;
        head = head->next;
        delete temp;
    }
}

template<typename T>
T Queue<T>::pop() {
    if (empty())
        throw std::out_of_range{ "Queue is empty" };

    int value = head->value;
    Node* temp = head;
    head = head->next;
    delete temp;

    --size_;

    return value;
}

template<typename T>
bool Queue<T>::empty() {
    return size_ == 0;
}

template<typename T>
void Queue<T>::push(const T& value) {
    Node* temp = new Node;
    temp->value = value;
    temp->next = nullptr;
    if (empty()) {
        head = temp;
        tail = temp;
    }
    else {
        tail->next = temp;
        tail = temp;
    }

    ++size_;
}

template<typename T>
template<typename... Args>
void Queue<T>::emplace(Args&&... args) {
    push(T{ std::forward<Args>(args)... });
}

template<typename T>
T& Queue<T>::front() {
    if (empty())
        throw std::out_of_range{ "Queue is empty" };

    return head->value;
}

template<typename T>
const T& Queue<T>::front() const {
    if (empty())
        throw std::out_of_range{ "Queue is empty" };

    return head->value;
}

template<typename T>
T& Queue<T>::back() {
    if (empty())
        throw std::out_of_range{ "Queue is empty" };

    return tail->value;
}

template<typename T>
const T& Queue<T>::back() const {
    if (empty())
        throw std::out_of_range{ "Queue is empty" };

    return tail->value;
}

template<typename T>
size_t Queue<T>::size() {
    return size_;
}

template<typename T>
void Queue<T>::swap(Queue& other) {
    std::swap(head, other.head);
    std::swap(tail, other.tail);
    std::swap(size_, other.size_);
}

namespace std
{
    template<typename T>
    void swap(Queue<T>& lhs, Queue<T>& rhs) {
        lhs.swap(rhs);
    }
}