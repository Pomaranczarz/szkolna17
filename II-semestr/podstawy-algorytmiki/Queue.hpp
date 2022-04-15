#pragma once
#include <stdexcept>

template<typename T>
class Queue
{
private:
    struct Node
    {
        T m_data;
        Node* m_next;

        Node(const T& data = T{}, Node* next = nullptr)
            : m_data{ data }
            , m_next{ next }
        {
        }
    };
public:
    explicit Queue() : m_head{ nullptr }, m_tail{ nullptr }, m_size{ 0 } {}

    bool empty() const noexcept { return m_size == 0; }
    size_t size() const noexcept { return m_size; }

    void push(const T& value) {
        Node* node = new Node{ value };
        if (empty()) {
            m_head = node;
            m_tail = node;
        }
        else {
            m_tail->m_next = node;
            m_tail = node;
        }

        ++m_size;
    }

    T pop() {
        if (empty())
            throw std::out_of_range("Queue is empty");

        Node* to_delete = m_head;
        T value = m_head->m_data;

        if (m_head == m_tail) {
            m_head = nullptr;
            m_tail = nullptr;
        }
        else {
            m_head = m_head->m_next;
        }

        delete to_delete;
        --m_size;

        return value;
    }

    T front() {
        if (empty())
            throw std::out_of_range("Queue is empty");

        return m_head->m_data;
    }

    T back() {
        if (empty())
            throw std::out_of_range("Queue is empty");

        return m_tail->m_data;
    }

    void clear() {
        while (!empty())
            pop();
    }

private:
    Node* m_head;
    Node* m_tail;
    size_t m_size;
};