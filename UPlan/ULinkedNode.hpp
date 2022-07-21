#ifndef _ULINKEDNODE_HPP
#define _ULINKEDNODE_HPP
#include "UIterator.hpp"

template <typename T>
class UFrLinkedNode
{
public:
    typedef UFrLinkedNode<T>* Node;
    UFrLinkedNode() = default;
    UFrLinkedNode(const T &data, Node next) 
        : next(next), data(data)
    {
    }
    UFrLinkedNode(const UFrLinkedNode<T> &copy) = delete;

    static void DestoryLinkedList(Node *head)
    {
        while (*head)
        {
            Node near = (*head)->next;
            delete *head;
            *head = near;
        }
        *head = NULL;
    }

    static Node Find(Node pos, size_t size)
    {
        Node node = pos;
        while (size)
        {
            node = node->next;
            size--;
        }
        return node;
    }
    Node next;
    T data;
};


template <typename T>
class UBiLinkedNode
{
public:
    typedef UBiLinkedNode<T>* Node;
    UBiLinkedNode() = default;
    UBiLinkedNode(const T &data, Node prev, Node next) 
        : prev(prev), next(next), data(data)
    {
    }
    UBiLinkedNode(const UBiLinkedNode<T> &copy) = delete;
    
    static void DestoryLinkedList(Node *head)
    {
        while (*head)
        {
            Node near = (*head)->next;
            delete *head;
            *head = near;
        }
        *head = NULL;
    }

    Node prev;
    Node next;
    T data;
};


template <typename T>
class UIterator<UFrLinkedNode<T>>
{
public:
    typedef UFrLinkedNode<T>* pointer;
    typedef T& reference;

    UIterator(pointer ptr = nullptr) : m_ptr(ptr)
    {
    }

    reference operator*()
    {
        return m_ptr->data;
    }

    T* operator->()
    {
        return &(m_ptr->data);
    }

    bool operator!=(const UIterator &it)
    {
        return it.m_ptr != this->m_ptr;
    }

    bool operator==(const UIterator &it)
    {
        return it.m_ptr == this->m_ptr;
    }
protected:
    pointer m_ptr;
};


template <typename T>
class UForwardIterator<UFrLinkedNode<T>> : public UIterator<UFrLinkedNode<T>>
{
public:
    using UIterator<UFrLinkedNode<T>>::UIterator;
    using UIterator<UFrLinkedNode<T>>::m_ptr;

    UForwardIterator operator++()
    {
        decltype(*this) temp = *this;
        m_ptr = m_ptr->next;
        return temp;
    }
    
    UForwardIterator& operator++(int)
    {
        m_ptr = m_ptr->next;
        return *this;
    }
};


template <typename T>
class UIterator<UBiLinkedNode<T>>
{
public:
    typedef UBiLinkedNode<T>* pointer;
    typedef T& reference;

    UIterator(pointer ptr = nullptr) : m_ptr(ptr)
    {
    }

    reference operator*()
    {
        return m_ptr->data;
    }

    T* operator->()
    {
        return &(m_ptr->data);
    }

    bool operator!=(const UIterator &it)
    {
        return it.m_ptr != this->m_ptr;
    }

    bool operator==(const UIterator &it)
    {
        return it.m_ptr == this->m_ptr;
    }
protected:
    pointer m_ptr;
};


template <typename T>
class UBidirctionalIterator<UBiLinkedNode<T>> : public UIterator<UBiLinkedNode<T>>
{
public:
    using UIterator<UBiLinkedNode<T>>::UIterator;
    using UIterator<UBiLinkedNode<T>>::m_ptr;

    UBidirctionalIterator operator++()
    {
        decltype(*this) temp = *this;
        m_ptr = m_ptr->next;
        return temp;
    }
    
    UBidirctionalIterator& operator++(int)
    {
        m_ptr = m_ptr->next;
        return *this;
    }
    UBidirctionalIterator operator--()
    {
        decltype(*this) temp = *this;
        m_ptr = m_ptr->prev;
        return temp;
    }

    UBidirctionalIterator operator--(int)
    {
        m_ptr = m_ptr->prev;
        return *this;
    }
};

template <typename T>
class UReserveBidirctionalIterator<UBiLinkedNode<T>> : public UIterator<UBiLinkedNode<T>>
{
public:
    using UIterator<UBiLinkedNode<T>>::UIterator;
    using UIterator<UBiLinkedNode<T>>::m_ptr;

    UReserveBidirctionalIterator operator++()
    {
        decltype(*this) temp = *this;
        m_ptr = m_ptr->prev;
        return temp;
    }
    
    UReserveBidirctionalIterator& operator++(int)
    {
        m_ptr = m_ptr->prev;
        return *this;
    }
    UReserveBidirctionalIterator operator--()
    {
        decltype(*this) temp = *this;
        m_ptr = m_ptr->next;
        return temp;
    }

    UReserveBidirctionalIterator operator--(int)
    {
        m_ptr = m_ptr->next;
        return *this;
    }
};
#endif // !_ULINKEDNODE_HPP