#pragma once 

#include <utility>
#include <stdexcept>
#include <limits>
#include <sstream>

template<typename T>
class List
{
private:
    struct Node
    {
        T data;
        Node* next;
        Node* prev;

        Node(T data, Node* next, Node* prev)
            : data(data), next(next), prev(prev)
        {
        }
    };

public:
    class iterator
    {
        friend class List<T>;
    public:
        using value_type = T;
        using pointer_type = T*;
        using reference_type = T&;

        iterator() noexcept = default;
        iterator(Node* node) noexcept : node{ node } {}
        iterator(const iterator& other) noexcept : node{ other.node } {}

        iterator& operator++() noexcept {
            node = node->next;
            return *this;
        }

        iterator operator++(int) noexcept {
            iterator temp{ node };
            node = node->next;
            return temp;
        }

        iterator operator+(int step) noexcept {
            iterator temp{ node };
            for (int i = 0; i < step; ++i)
                temp.node = temp.node->next;

            return temp;
        }

        iterator operator-(int step) noexcept {
            iterator temp{ node };
            for (int i = 0; i < step; ++i)
                temp.node = temp.node->prev;

            return temp;
        }

        bool operator==(const iterator& other) const noexcept { return node == other.node; }
        bool operator!=(const iterator& other) const noexcept { return node != other.node; }
        reference_type operator*() const noexcept { return node->data; }
        pointer_type operator->() const noexcept { return &node->data; }

    private:
        Node* node{ nullptr };
    };

    class const_iterator
    {
        friend class List<T>;
    public:
        using value_type = T;
        using pointer_type = const T*;
        using reference_type = const T&;

        const_iterator() noexcept = default;
        const_iterator(Node* node) noexcept : node{ node } {}
        const_iterator(const iterator& other) noexcept : node{ other.node } {}

        const_iterator& operator++() noexcept {
            node = node->next;
            return *this;
        }

        const_iterator operator++(int) noexcept {
            const_iterator temp{ node };
            node = node->next;
            return temp;
        }

        const_iterator operator+(int step) noexcept {
            const_iterator temp{ node };
            for (int i = 0; i < step; ++i)
                temp.node = temp.node->next;

            return temp;
        }

        const_iterator operator-(int step) noexcept {
            const_iterator temp{ node };
            for (int i = 0; i < step; ++i)
                temp.node = temp.node->prev;

            return temp;
        }

        bool operator==(const const_iterator& other) const noexcept { return node == other.node; }
        bool operator!=(const const_iterator& other) const noexcept { return node != other.node; }
        reference_type operator*() const noexcept { return node->data; }
        pointer_type operator->() const noexcept { return &node->data; }

    private:
        Node* node{ nullptr };
    };

    class reverse_iterator
    {
        friend class List<T>;
    public:
        using value_type = T;
        using pointer_type = T*;
        using reference_type = T&;

        reverse_iterator() noexcept = default;
        reverse_iterator(Node* node) noexcept : node{ node } {}
        reverse_iterator(const reverse_iterator& other) noexcept : node{ other.node } {}

        reverse_iterator& operator++() noexcept {
            node = node->prev;
            return *this;
        }

        reverse_iterator operator++(int) noexcept {
            reverse_iterator temp{ node };
            node = node->prev;
            return temp;
        }

        reverse_iterator operator+(int step) noexcept {
            reverse_iterator temp{ node };
            for (int i = 0; i < step; ++i)
                temp.node = temp.node->prev;

            return temp;
        }

        reverse_iterator operator-(int step) noexcept {
            reverse_iterator temp{ node };
            for (int i = 0; i < step; ++i)
                temp.node = temp.node->next;

            return temp;
        }

        bool operator==(const reverse_iterator& other) const noexcept { return node == other.node; }
        bool operator!=(const reverse_iterator& other) const noexcept { return node != other.node; }
        reference_type operator*() const noexcept { return node->data; }
        pointer_type operator->() const noexcept { return &node->data; }

    private:
        Node* node{ nullptr };
    };

    class const_reverse_iterator
    {
        friend class List<T>;
    public:
        using value_type = T;
        using pointer_type = const T*;
        using reference_type = const T&;

        const_reverse_iterator() noexcept = default;
        const_reverse_iterator(Node* node) noexcept : node{ node } {}
        const_reverse_iterator(const reverse_iterator& other) noexcept : node{ other.node } {}

        const_reverse_iterator& operator++() noexcept {
            node = node->prev;
            return *this;
        }

        const_reverse_iterator operator++(int) noexcept {
            const_reverse_iterator temp{ node };
            node = node->prev;
            return temp;
        }

        const_reverse_iterator operator+(int step) noexcept {
            const_reverse_iterator temp{ node };
            for (int i = 0; i < step; ++i)
                temp.node = temp.node->prev;

            return temp;
        }

        const_reverse_iterator operator-(int step) noexcept {
            const_reverse_iterator temp{ node };
            for (int i = 0; i < step; ++i)
                temp.node = temp.node->next;

            return temp;
        }

        bool operator==(const const_reverse_iterator& other) const noexcept { return node == other.node; }
        bool operator!=(const const_reverse_iterator& other) const noexcept { return node != other.node; }
        reference_type operator*() const noexcept { return node->data; }
        pointer_type operator->() const noexcept { return &node->data; }

    private:
        Node* node{ nullptr };
    };

    using value_type = T;
    using ref_type = T&;
    using const_ref_type = const T&;
    using pointer = T*;

    explicit List() noexcept
        : head{ nullptr }
        , tail{ nullptr }
        , m_size{ 0 }
    {

    }

    explicit List(size_t count, const T& value = T{}) noexcept
        : head{ nullptr }
        , tail{ nullptr }
        , m_size{ 0 }
    {
        for (size_t i = 0; i < count; ++i)
            push_back(value);
    }

    List(const List& other) noexcept
        : head{ nullptr }
        , tail{ nullptr }
        , m_size{ 0 }
    {
        for (auto& elem : other)
            push_back(elem);
    }

    List(List&& other) noexcept
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

    List& operator=(const List& other) noexcept {
        if (this == &other)
            return *this;

        return List(other);
    }

    List& operator=(List&& other) noexcept {
        if (this == &other)
            return *this;

        return List(std::forward<List&&>(other));
    }

    template<typename InputIt>
    List(InputIt first, InputIt last) noexcept
        : head{ nullptr }
        , tail{ nullptr }
        , m_size{ 0 }
    {
        for (auto it = first; it != last; ++it)
            push_back(*it);
    }

    List(std::initializer_list<T> list) noexcept
        : head{ nullptr }
        , tail{ nullptr }
        , m_size{ 0 }
    {
        for (auto& elem : list)
            push_back(elem);
    }

    void assign(size_t count, const T& value = T{}) noexcept {
        clear();
        for (size_t i = 0; i < count; ++i)
            push_back(value);
    }

    template<typename InputIt>
    void assign(InputIt first, InputIt last) noexcept {
        clear();
        for (auto it = first; it != last; ++it)
            push_back(*it);
    }

    void assign(std::initializer_list<T> list) noexcept {
        clear();
        for (auto& elem : list)
            push_back(elem);
    }

    ref_type front() {
        if (empty())
            throw std::out_of_range("List is empty");

        return head->data;
    }

    const_ref_type front() const {
        if (empty())
            throw std::out_of_range("List is empty");

        return head->data;
    }

    ref_type back() {
        if (empty())
            throw std::out_of_range("List is empty");

        return tail->data;
    }

    const_ref_type back() const {
        if (empty())
            throw std::out_of_range("List is empty");

        return tail->data;
    }

    void clear() noexcept {
        while (!empty())
            pop_front();
    }

    void push_back(const T& value) noexcept {
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

    void push_back(T&& value) noexcept {
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
    void emplace_back(Args&&... args) noexcept {
        push_back(T{ std::forward<Args>(args)... });
    }

    void push_front(const T& value) noexcept {
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

    void push_front(T&& value) noexcept {
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
    void emplace_front(Args&&... args) noexcept {
        push_front(T{ std::forward<Args>(args)... });
    }

    void insert(const_iterator pos, const T& value) {
        Node* new_node = new Node{ value, pos.node->prev, pos.node };

        if (pos.node->prev)
            pos.node->prev->next = new_node;
        else
            head = new_node;

        pos.node->prev = new_node;
        ++m_size;
    }

    void insert(const_iterator pos, T&& value) {
        Node* new_node = new Node{ std::move(value), pos.node->prev, pos.node };

        if (pos.node->prev)
            pos.node->prev->next = new_node;
        else
            head = new_node;

        pos.node->prev = new_node;
        ++m_size;
    }

    void insert(iterator pos, const T& value) {
        Node* new_node = new Node{ value, pos.node->prev, pos.node };

        if (pos.node->prev)
            pos.node->prev->next = new_node;
        else
            head = new_node;

        pos.node->prev = new_node;
        ++m_size;
    }

    void insert(const_iterator pos, size_t count, const T& value) {
        for (size_t i = 0; i < count; ++i)
            insert(pos, value);
    }

    template<typename InputIt>
    void insert(const_iterator pos, InputIt first, InputIt last) {
        for (auto it = first; it != last; ++it)
            insert(pos, *it);
    }

    void insert(const_iterator pos, std::initializer_list<T> list) {
        for (auto& elem : list)
            insert(pos, elem);
    }

    template<typename... Args>
    void emplace(const_iterator pos, Args&&... args) {
        insert(pos, T{ std::forward<Args>(args)... });
    }

    void pop_back() {
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

    void pop_front() {
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

    void swap(List& other) noexcept {
        std::swap(head, other.head);
        std::swap(tail, other.tail);
        std::swap(m_size, other.m_size);
    }

    bool empty() const noexcept { return m_size == 0; }
    size_t size() const noexcept { return m_size; }
    size_t max_size() const noexcept { return std::numeric_limits<size_t>::max(); }

    iterator begin() noexcept { return iterator{ head }; }
    iterator end() noexcept { return iterator{ nullptr }; }

    const_iterator begin() const noexcept { return const_iterator{ head }; }
    const_iterator end() const noexcept { return const_iterator{ nullptr }; }

    const_iterator cbegin() const noexcept { return const_iterator{ head }; }
    const_iterator cend() const noexcept { return const_iterator{ nullptr }; }

    reverse_iterator rbegin() noexcept { return reverse_iterator{ tail }; }
    reverse_iterator rend() noexcept { return reverse_iterator{ nullptr }; }

    const_reverse_iterator rbegin() const noexcept { return const_reverse_iterator{ tail }; }
    const_reverse_iterator rend() const noexcept { return const_reverse_iterator{ nullptr }; }

    const_reverse_iterator crbegin() const noexcept { return const_reverse_iterator{ tail }; }
    const_reverse_iterator crend() const noexcept { return const_reverse_iterator{ nullptr }; }

    [[nodiscard]] std::string pretty_string() const noexcept {
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
