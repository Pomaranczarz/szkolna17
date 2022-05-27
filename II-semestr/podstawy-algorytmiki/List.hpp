#pragma once

#if __cplusplus < 201402L
#error "This file requires C++11 support."
#else

#include <utility>
#include <stdexcept>
#include <limits>
#include <iterator>
#include <sstream>
#include <iostream>

template<typename T>
class List
{
private:
    struct Node
    {
        T data;
        Node* next;
        Node* prev;

        constexpr Node(T data, Node* next, Node* prev)
            : data(data), next(next), prev(prev) {}
    };

public:
    class iterator
#if __cplusplus < 201703L
        : public std::iterator<std::bidirectional_iterator_tag, T>
#endif
    {
        friend class List<T>;
    public:
        using value_type = T;
        using pointer_type = T*;
        using reference_type = T&;

        constexpr iterator() noexcept = default;
        constexpr iterator(Node* node) noexcept : node{ node } {}
        constexpr iterator(const iterator& other) noexcept : node{ other.node } {}

        constexpr iterator& operator++() noexcept {
            node = node->next;
            return *this;
        }

        constexpr iterator operator++(int) noexcept {
            auto temp{ *this };
            node = node->next;
            return temp;
        }

        constexpr iterator& operator--() noexcept {
            node = node->prev;
            return *this;
        }

        constexpr iterator operator--(int) noexcept {
            auto temp{ *this };
            node = node->prev;
            return temp;
        }

        constexpr bool operator==(const iterator& other) const noexcept { return node == other.node; }
        constexpr bool operator!=(const iterator& other) const noexcept { return node != other.node; }
        constexpr reference_type operator*() const noexcept { return node->data; }
        constexpr pointer_type operator->() const noexcept { return &node->data; }

    private:
        Node* node{ nullptr };
    };

    class const_iterator
#if __cplusplus < 201703L
        : public std::iterator<std::bidirectional_iterator_tag, T>
#endif
    {
        friend class List<T>;
    public:
        using value_type = T;
        using pointer_type = const T*;
        using reference_type = const T&;

        constexpr const_iterator() noexcept = default;
        constexpr const_iterator(Node* node) noexcept : node{ node } {}
        constexpr const_iterator(const iterator& other) noexcept : node{ other.node } {}

        constexpr const_iterator& operator++() noexcept {
            node = node->next;
            return *this;
        }

        constexpr const_iterator operator++(int) noexcept {
            auto temp{ *this };
            node = node->next;
            return temp;
        }

        constexpr const_iterator& operator--() noexcept {
            node = node->prev;
            return *this;
        }

        constexpr const_iterator operator--(int) noexcept {
            auto temp{ *this };
            node = node->prev;
            return temp;
        }

        constexpr bool operator==(const const_iterator& other) const noexcept { return node == other.node; }
        constexpr bool operator!=(const const_iterator& other) const noexcept { return node != other.node; }
        constexpr reference_type operator*() const noexcept { return node->data; }
        constexpr pointer_type operator->() const noexcept { return &node->data; }

    private:
        Node* node{ nullptr };
    };

    class reverse_iterator
#if __cplusplus < 201703L
        : public std::iterator<std::bidirectional_iterator_tag, T>
#endif
    {
        friend class List<T>;
    public:
        using value_type = T;
        using pointer_type = T*;
        using reference_type = T&;

        constexpr reverse_iterator() noexcept = default;
        constexpr reverse_iterator(Node* node) noexcept : node{ node } {}
        constexpr reverse_iterator(const reverse_iterator& other) noexcept : node{ other.node } {}

        constexpr reverse_iterator& operator++() noexcept {
            node = node->prev;
            return *this;
        }

        constexpr reverse_iterator operator++(int) noexcept {
            auto temp{ *this };
            node = node->prev;
            return temp;
        }

        constexpr reverse_iterator& operator--() noexcept {
            node = node->next;
            return *this;
        }

        constexpr reverse_iterator operator--(int) noexcept {
            auto temp{ *this };
            node = node->next;
            return temp;
        }

        constexpr bool operator==(const reverse_iterator& other) const noexcept { return node == other.node; }
        constexpr bool operator!=(const reverse_iterator& other) const noexcept { return node != other.node; }
        constexpr reference_type operator*() const noexcept { return node->data; }
        constexpr pointer_type operator->() const noexcept { return &node->data; }

    private:
        Node* node{ nullptr };
    };

    class const_reverse_iterator
#if __cplusplus < 201703L
        : public std::iterator<std::bidirectional_iterator_tag, T>
#endif
    {
        friend class List<T>;
    public:
        using value_type = T;
        using pointer_type = const T*;
        using reference_type = const T&;

        constexpr const_reverse_iterator() noexcept = default;
        constexpr const_reverse_iterator(Node* node) noexcept : node{ node } {}
        constexpr const_reverse_iterator(const reverse_iterator& other) noexcept : node{ other.node } {}

        constexpr const_reverse_iterator& operator++() noexcept {
            node = node->prev;
            return *this;
        }

        constexpr const_reverse_iterator operator++(int) noexcept {
            auto temp{ *this };
            node = node->prev;
            return temp;
        }

        constexpr const_reverse_iterator& operator--() noexcept {
            node = node->next;
            return *this;
        }

        constexpr const_reverse_iterator operator--(int) noexcept {
            auto temp{ *this };
            node = node->next;
            return temp;
        }

        constexpr bool operator==(const const_reverse_iterator& other) const noexcept { return node == other.node; }
        constexpr bool operator!=(const const_reverse_iterator& other) const noexcept { return node != other.node; }
        constexpr reference_type operator*() const noexcept { return node->data; }
        constexpr pointer_type operator->() const noexcept { return &node->data; }

    private:
        Node* node{ nullptr };
    };

    using value_type = T;
    using ref_type = T&;
    using const_ref_type = const T&;
    using pointer = T*;

    constexpr explicit List() noexcept
        : head{ nullptr }
        , tail{ nullptr }
        , m_size{ 0 }
    {

    }

    constexpr explicit List(size_t count, const T& value = T{}) noexcept
        : head{ nullptr }
        , tail{ nullptr }
        , m_size{ 0 }
    {
        for (size_t i = 0; i < count; ++i)
            push_back(value);
    }

    constexpr List(const List& other) noexcept
        : head{ nullptr }
        , tail{ nullptr }
        , m_size{ 0 }
    {
        for (auto& elem : other)
            push_back(elem);
    }

    constexpr List(List&& other) noexcept
        : head{ other.head }
        , tail{ other.tail }
        , m_size{ other.size }
    {
        other.head = nullptr;
        other.tail = nullptr;
        other.size = 0;
    }

    ~List() noexcept {
        clear();
    }

    constexpr List& operator=(const List& other) noexcept {
        if (this == &other)
            return *this;

        return List(other);
    }

    constexpr List& operator=(List&& other) noexcept {
        if (this == &other)
            return *this;

        return List(std::forward<List&&>(other));
    }

    template<typename InputIt>
    constexpr List(InputIt first, InputIt last) noexcept
        : head{ nullptr }
        , tail{ nullptr }
        , m_size{ 0 }
    {
        for (auto it = first; it != last; ++it)
            push_back(*it);
    }

    constexpr List(std::initializer_list<T> list) noexcept
        : head{ nullptr }
        , tail{ nullptr }
        , m_size{ 0 }
    {
        for (auto& elem : list)
            push_back(elem);
    }

    constexpr void assign(size_t count, const T& value = T{}) noexcept {
        clear();
        for (size_t i = 0; i < count; ++i)
            push_back(value);
    }

    template<typename InputIt>
    constexpr void assign(InputIt first, InputIt last) noexcept {
        clear();
        for (auto it = first; it != last; ++it)
            push_back(*it);
    }

    constexpr void assign(std::initializer_list<T> list) noexcept {
        clear();
        for (auto& elem : list)
            push_back(elem);
    }

    constexpr ref_type front() {
        if (empty())
            throw std::out_of_range("List is empty");

        return head->data;
    }

    constexpr const_ref_type front() const {
        if (empty())
            throw std::out_of_range("List is empty");

        return head->data;
    }

    constexpr ref_type back() {
        if (empty())
            throw std::out_of_range("List is empty");

        return tail->data;
    }

    constexpr const_ref_type back() const {
        if (empty())
            throw std::out_of_range("List is empty");

        return tail->data;
    }

    constexpr void clear() noexcept {
        while (!empty())
            pop_front();
    }

    constexpr void push_back(const T& value) noexcept {
        Node* new_node = new Node{ value, nullptr, nullptr };

        if (empty()) {
            head = new_node;
            tail = new_node;
        }
        else {
            tail->next = new_node;
            new_node->prev = tail;
            tail = new_node;
        }

        ++m_size;
    }

    constexpr void push_back(T&& value) noexcept {
        Node* new_node = new Node{ std::move(value), nullptr, nullptr };

        if (empty()) {
            head = new_node;
            tail = new_node;
        }
        else {
            tail->next = new_node;
            new_node->prev = tail;
            tail = new_node;
        }

        ++m_size;
    }

    template<typename... Args>
    constexpr void emplace_back(Args&&... args) noexcept {
        push_back(T{ std::forward<Args>(args)... });
    }

    constexpr void push_front(const T& value) noexcept {
        Node* new_node = new Node{ value, head, nullptr };

        if (empty()) {
            head = new_node;
            tail = new_node;
        }
        else {
            head->prev = new_node;
            head = new_node;
        }

        ++m_size;
    }

    constexpr void push_front(T&& value) noexcept {
        Node* new_node = new Node{ std::move(value), head, nullptr };

        if (empty()) {
            head = new_node;
            tail = new_node;
        }
        else {
            head->prev = new_node;
            head = new_node;
        }

        ++m_size;
    }

    template<typename... Args>
    constexpr void emplace_front(Args&&... args) noexcept {
        push_front(T{ std::forward<Args>(args)... });
    }

    constexpr void insert(const_iterator pos, const T& value) {
        if (pos == cbegin())
            push_front(value);
        else if (pos == cend())
            push_back(value);
        else if (!pos.node)
            throw std::out_of_range("List iterator out of range");
        else {
            Node* new_node = new Node{ std::move(value), pos.node, pos.node->prev };

            pos.node->prev = new_node;
            new_node->prev->next = new_node;

            ++m_size;
        }
    }

    constexpr void insert(const_iterator pos, T&& value) {
        if (pos == cbegin())
            push_front(value);
        else if (pos == cend())
            push_back(value);
        else if (!pos.node)
            throw std::out_of_range("List iterator out of range");
        else {
            Node* new_node = new Node{ std::move(value), pos.node, pos.node->prev };

            pos.node->prev = new_node;
            new_node->prev->next = new_node;

            ++m_size;
        }
    }

    constexpr void insert(const_iterator pos, size_t count, const T& value) {
        for (size_t i = 0; i < count; ++i)
            insert(pos, value);
    }

    template<typename InputIt>
    constexpr void insert(const_iterator pos, InputIt first, InputIt last) {
        for (auto it = first; it != last; ++it)
            insert(pos, *it);
    }

    constexpr void insert(const_iterator pos, std::initializer_list<T> list) {
        insert(pos, list.begin(), list.end());
    }

    template<typename... Args>
    constexpr void emplace(const_iterator pos, Args&&... args) {
        insert(pos, T{ std::forward<Args>(args)... });
    }

    constexpr void pop_back() {
        if (empty())
            throw std::out_of_range("List is empty");

        Node* current = tail;

        if (m_size == 1) {
            head = nullptr;
            tail = nullptr;
        }
        else {
            tail = current->prev;
            tail->next = nullptr;
        }

        delete current;
        --m_size;
    }

    constexpr void pop_front() {
        if (empty())
            throw std::out_of_range("List is empty");

        Node* current = head;

        if (m_size == 1) {
            head = nullptr;
            tail = nullptr;
        }
        else {
            head = current->next;
            head->prev = nullptr;
        }

        delete current;
        --m_size;
    }

    constexpr void erase(const_iterator pos) {
        if (!pos.node)
            throw std::out_of_range("List iterator out of range");

        if (pos.node == head)
            pop_front();
        else if (pos.node == tail)
            pop_back();
        else {
            pos.node->prev->next = pos.node->next;
            pos.node->next->prev = pos.node->prev;

            delete pos.node;
            --m_size;
        }
    }

    constexpr void erase(const_iterator first, const_iterator last) {
        while (first != last)
            erase(first++);
    }

    constexpr void erase(const_iterator pos, size_t count) {
        for (size_t i = 0; i < count; ++i)
            erase(pos);
    }

    constexpr const_iterator find(const T& value) const {
        for (auto it = cbegin(); it != cend(); ++it) {
            if (*it == value)
                return it;
        }

        return cend();
    }

    constexpr const_iterator find(const_iterator start, const T& value) const {
        for (auto it = start; it != cend(); ++it) {
            if (*it == value)
                return it;
        }

        return cend();
    }

    constexpr void reverse() noexcept {
        if (empty())
            return;

        Node* current = head;

        while (current) {
            std::swap(current->prev, current->next);
            current = current->prev;
        }

        std::swap(head, tail);
    }

    constexpr void swap(List& other) noexcept {
        std::swap(head, other.head);
        std::swap(tail, other.tail);
        std::swap(m_size, other.m_size);
    }

    constexpr bool empty() const noexcept { return m_size == 0; }
    constexpr size_t size() const noexcept { return m_size; }
    constexpr size_t max_size() const noexcept { return std::numeric_limits<size_t>::max(); }

    constexpr iterator begin() noexcept { return iterator{ head }; }
    constexpr iterator end() noexcept { return iterator{ nullptr }; }

    constexpr const_iterator begin() const noexcept { return const_iterator{ head }; }
    constexpr const_iterator end() const noexcept { return const_iterator{ nullptr }; }

    constexpr const_iterator cbegin() const noexcept { return const_iterator{ head }; }
    constexpr const_iterator cend() const noexcept { return const_iterator{ nullptr }; }

    constexpr reverse_iterator rbegin() noexcept { return reverse_iterator{ tail }; }
    constexpr reverse_iterator rend() noexcept { return reverse_iterator{ nullptr }; }

    constexpr const_reverse_iterator rbegin() const noexcept { return const_reverse_iterator{ tail }; }
    constexpr const_reverse_iterator rend() const noexcept { return const_reverse_iterator{ nullptr }; }

    constexpr const_reverse_iterator crbegin() const noexcept { return const_reverse_iterator{ tail }; }
    constexpr const_reverse_iterator crend() const noexcept { return const_reverse_iterator{ nullptr }; }

    [[nodiscard]] constexpr  std::string pretty_string() const noexcept {
        std::stringstream ss;
        ss << "List: ";

        if (empty())
            ss << "empty";
        else {
            ss << "[";

            for (auto it = begin(); it != end(); ++it) {
                if (it != begin())
                    ss << ", ";

                ss << *it;
            }

            ss << "]";
        }

        return ss.str();
    }

private:
    Node* head;
    Node* tail;
    size_t m_size;
};

#endif // __cplusplus < 201703L
