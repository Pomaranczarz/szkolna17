#pragma once

#include <stdexcept>
#include <iostream>

template<typename T>
class BTree
{
private:
    struct Node
    {
        T m_data;
        Node* m_left;
        Node* m_right;
        constexpr Node(const T& data = T{}, Node* left = nullptr, Node* right = nullptr)
            : m_data{ data }
            , m_left{ left }
            , m_right{ right }
        {

        }

        constexpr void insert(const T& data) {
            if (data < m_data) {
                if (m_left)
                    m_left->insert(data);
                else
                    m_left = new Node{ data };
            }
            else if (data > m_data) {
                if (m_right)
                    m_right->insert(data);
                else
                    m_right = new Node{ data };
            }
            else
                throw std::runtime_error("Duplicate value");
        }

        constexpr void remove(const T& data) {
            if (data < m_data)
                m_left ? m_left->remove(data) : throw std::runtime_error("Value not found");
            else if (data > m_data)
                m_right ? m_right->remove(data) : throw std::runtime_error("Value not found");
            else {
                if (m_left && m_right) {
                    Node* temp = m_right;
                    while (temp->m_left)
                        temp = temp->m_left;
                    m_data = temp->m_data;
                    temp->remove(temp->m_data);
                }
                else if (m_left) {
                    Node* temp = m_left;
                    m_data = temp->m_data;
                    m_left = temp->m_left;
                    delete temp;
                }
                else if (m_right) {
                    Node* temp = m_right;
                    m_data = temp->m_data;
                    m_right = temp->m_right;
                    delete temp;
                }
                else {
                    delete this;
                }
            }
        }

        constexpr bool find(const T& data) noexcept {
            if (data == m_data)
                return true;
            else if (data < m_data)
                return m_left ? m_left->find(data) : false;
            else
                return m_right ? m_right->find(data) : false;
        }

        constexpr bool has_children() const noexcept {
            return m_left || m_right;
        }

        constexpr void print_inorder() noexcept {
            if (m_left) m_left->print_inorder();

            std::cout << m_data << " ";

            if (m_right) m_right->print_inorder();
        }

        constexpr void print_preorder() noexcept {
            std::cout << m_data << " ";

            if (m_left) m_left->print_preorder();
            if (m_right) m_right->print_preorder();
        }

        constexpr void print_postorder() noexcept {
            if (m_left) m_left->print_postorder();
            if (m_right) m_right->print_postorder();

            std::cout << m_data << " ";
        }

        constexpr void clear() noexcept {
            if (m_left && m_left->has_children()) m_left->clear();
            if (m_right && m_right->has_children()) m_right->clear();
            delete m_left;
            delete m_right;
        }
    };

public:
    constexpr BTree() noexcept
        : m_root{ nullptr }
        , m_size{ 0 }
    {

    }

    ~BTree() {
        clear();
    }

    constexpr void insert(const T& data) {
        if (!m_root)
            m_root = new Node{ data };
        else
            m_root->insert(data);
        ++m_size;
    }

    constexpr void remove(const T& data) {
        if (!m_root)
            throw std::runtime_error("Tree is empty");
        else
            m_root->remove(data);
        --m_size;
    }

    constexpr bool find(const T& data) noexcept {
        if (m_root)
            return m_root->find(data);
    }

    constexpr void print_inorder() noexcept {
        if (m_root)
            m_root->print_inorder();
    }

    constexpr void print_preorder() noexcept {
        if (m_root)
            m_root->print_preorder();
    }

    constexpr void print_postorder() noexcept {
        if (m_root)
            m_root->print_postorder();
    }

    constexpr void clear() noexcept {
        if (m_root) {
            m_root->clear();
            delete m_root;
            m_root = nullptr;
        }
        m_size = 0;
    }

    constexpr bool empty() const { return m_size == 0; }
    constexpr size_t size() const { return m_size; }

private:
    Node* m_root;
    size_t m_size;
};