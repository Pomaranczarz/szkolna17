#pragma once
#include <stdexcept>

template<typename T>
class Stack
{
private:
    struct Node
    {
        T m_data;
        Node* m_next;

        Node(const T& data = T{}, Node* next = nullptr)
            : m_data(data)
            , m_next(next)
        {
        }
    };

public:
    explicit Stack() = default;

    bool empty() const noexcept {
        return m_size == 0;
    }

    void push(const T& value) {
        Node* node = new Node(value, m_top);
        m_top = node;
        ++m_size;
    }

    T pop() {
        if (empty())
            throw std::out_of_range("Stack is empty");

        Node* to_delete = m_top;
        T value = m_top->m_data;
        m_top = m_top->m_next;

        delete to_delete;
        --m_size;

        return value;
    }

    T& top() {
        if (empty())
            throw std::out_of_range("Stack is empty");

        return m_top->m_data;
    }

    void clear() {
        while (!empty())
            pop();
    }

    ~Stack() {
        clear();
    }

private:
    Node* m_top = nullptr;
    size_t m_size = 0;
};