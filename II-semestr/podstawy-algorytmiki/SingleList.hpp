#pragma once

#include <stdexcept>
#include <iostream>

template<typename T>
class SingleList
{
private:
    struct Node
    {
        T m_value;
        Node* m_next;

        Node(const T& value = T{}, Node* next = nullptr)
            : m_value{ value }, m_next{ next }
        {
        }
    };

    class iterator
#if __cplusplus >= 202002L
        : public std::iterator<std::forward_iterator_tag, T>
#endif
    {
        friend class SingleList;
    public:
        using value_type = T;
        using pointer_type = T*;
        using ref_type = T&;

        iterator(Node* node)
            : m_node{ node }
        {
        }

        iterator(const iterator& other)
            : m_node{ other.m_node }
        {
        }

        iterator& operator++() {
            m_node = m_node->m_next;
            return *this;
        }

        iterator operator++(int) {
            iterator tmp{ *this };
            ++(*this);
            return tmp;
        }

        bool operator==(const iterator& other) const { return m_node == other.m_node; }
        bool operator!=(const iterator& other) const { return !(*this == other); }
        ref_type operator*() { return m_node->m_value; }
        pointer_type operator->() { return &(m_node->m_value); }

    private:
        Node* m_node;
    };

    class const_iterator
#if __cplusplus >= 202002L
        : public std::iterator<std::forward_iterator_tag, T>
#endif
    {
        friend class SingleList;
    public:
        using value_type = const T;
        using pointer_type = const T*;
        using ref_type = const T&;

        const_iterator(const Node* node)
            : m_node{ node }
        {
        }

        const_iterator(const const_iterator& other)
            : m_node{ other.m_node }
        {
        }

        const_iterator& operator++() {
            m_node = m_node->m_next;
            return *this;
        }

        const_iterator operator++(int) {
            const_iterator tmp{ *this };
            ++(*this);
            return tmp;
        }

        bool operator==(const const_iterator& other) const { return m_node == other.m_node; }
        bool operator!=(const const_iterator& other) const { return !(*this == other); }
        ref_type operator*() { return m_node->m_value; }

    private:
        const Node* m_node;
    };

public:
    SingleList()
        : m_head{ nullptr }
        , m_tail{ nullptr }
        , m_size{ 0 }
    {

    }

    bool empty() const { return m_size == 0; }
    size_t size() const { return m_size; }

    void clear() {
        while (!empty())
            pop_front();
    }

    void push_front(const T& value) {
        Node* node = new Node{ value };
        if (empty())
            m_tail = m_head = node;
        else {
            node->m_next = m_head;
            m_head = node;
        }

        ++m_size;
    }

    void push_back(const T& value) {
        Node* node = new Node{ value };
        if (empty())
            m_tail = m_head = node;
        else {
            m_tail->m_next = node;
            m_tail = node;
        }

        ++m_size;
    }

    void insert(const iterator& pos, const T& value) {
        if (pos == end())
            push_back(value);
        else {
            Node* node = new Node{ value };
            node->m_next = pos.m_node->m_next;
            pos.m_node->m_next = node;
            ++m_size;
        }
    }

    void pop_front() {
        if (empty())
            throw std::out_of_range("List is empty");

        Node* node = m_head;
        m_head = m_head->m_next;
        delete node;

        --m_size;
    }

    void pop_back() {
        if (empty())
            throw std::out_of_range("List is empty");

        Node* node = m_head;
        while (node->m_next != m_tail)
            node = node->m_next;

        delete m_tail;
        m_tail = node;
        m_tail->m_next = nullptr;

        --m_size;
    }

    void erase(const iterator& pos) {
        if (pos == end())
            throw std::out_of_range("Iterator is out of range");

        Node* node = m_head;
        while (node->m_next != pos.m_node)
            node = node->m_next;

        node->m_next = pos.m_node->m_next;
        delete pos.m_node;

        --m_size;
    }

    T& front() {
        if (empty())
            throw std::out_of_range("List is empty");

        return m_head->m_value;
    }

    const T& front() const {
        if (empty())
            throw std::out_of_range("List is empty");

        return m_head->m_value;
    }

    T& back() {
        if (empty())
            throw std::out_of_range("List is empty");

        return m_tail->m_value;
    }

    const T& back() const {
        if (empty())
            throw std::out_of_range("List is empty");

        return m_tail->m_value;
    }

    iterator begin() { return iterator{ m_head }; }
    iterator end() { return iterator{ nullptr }; }

    const_iterator begin() const { return const_iterator{ m_head }; }
    const_iterator end() const { return const_iterator{ nullptr }; }

    const_iterator cbegin() const { return const_iterator{ m_head }; }
    const_iterator cend() const { return const_iterator{ nullptr }; }

    T sum() const {
        T sum{};
        for (const_iterator it = cbegin(); it != cend(); ++it)
            sum += *it;
        return sum;
    }

    iterator max() {
        iterator max{ begin() };
        for (iterator it = begin(); it != end(); ++it)
            if (*it > *max)
                max = it;
        return max;
    }

    double average() const {
        return sum() / size();
    }

    void print() const {
        std::cout << "[ ";
        for (const_iterator it = cbegin(); it != cend(); ++it)
            std::cout << *it << " ";

        std::cout << "]\n";
    }

private:
    Node* m_head;
    Node* m_tail;
    size_t m_size;

};
