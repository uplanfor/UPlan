#ifndef _ULINKEDLIST_HPP
#define _ULINKEDLIST_HPP
#include "UIterator.hpp"
#include "ULinkedNode.hpp"


template <typename T>
class ULinkedList
{
public:
    friend class UForwardIterator<UFrLinkedNode<T>>;
    using iterator = UForwardIterator<UFrLinkedNode<T>>;
    using const_iterator = const iterator;

    ~ULinkedList()
    {
        clear();
    }

    // defualt constructor
    ULinkedList()
    {
        m_head = new UFrLinkedNode<T>;
        m_head->next = NULL;
        m_tail = NULL;
    }

    // to construct a linked list that will be filled with vals
    // @param size the number of the vals
    // @param val the elem to fill the linked list
    ULinkedList(const size_t &size, const T &val = T()) : ULinkedList()
    {
        for (size_t i = 0; i != size; ++i)
        {
            push_front(val);
        }
    }

    // copy constructor
    ULinkedList(const ULinkedList<T> &copy) : ULinkedList()
    {
        UFrLinkedNode<T> *node = copy.m_head->next;
        iterator it = before_begin();
        while (node)
        {
            it = insert_after(it, node->data);
            node = node->next;
        }
        m_tail = it.m_ptr;
    }

    ULinkedList(const std::initializer_list<T> &list) : ULinkedList()
    {
        auto it = list.begin();
        auto end = list.end();
        iterator my_it = before_begin();
        while (it != end)
        {
            my_it = insert_after(my_it, *it);
            ++it;
        }
        m_tail = my_it.m_ptr;
    }

    // to get the reference of the first elem
    // @return the reference of the first elem
    T& front() const
    {
        return m_head->next->data;
    }

    T& back() const
    {
        return m_tail->data;
    }

    // to push a value in the front of the linked list
    // @param val the value to add in
    void push_front(const T &val)
    {
        insert_after(before_begin(), val);
    }

    // to remove a value in the front of the linked list
    void pop_front()
    {
        erase_after(before_begin());
    }

    void push_back(const T &val)
    {
        if (m_tail)
        {
            m_tail->next = new UFrLinkedNode<T>(val, NULL);
            m_tail = m_tail->next;
            return;
        }
        insert_after(before_begin(), val);
    }

    void pop_back()
    {
        if (m_tail)
        {
            if (m_tail == m_head->next)
            {
                delete m_tail;
                m_tail = NULL;
                return;
            }
            UFrLinkedNode<T> *node = m_head->next;
            while (node)
            {
                if (node->next == m_tail)
                {
                    delete m_head;
                    m_tail = node;
                    return;
                }
                node = node->next;
            }
            
        }
    }

    // to check if the linked list is empty
    // @return bool
    bool empty() const
    {
        return m_head->next;
    }

    // to remove all of the elems in the linked list
    void clear()
    {
        UFrLinkedNode<T>::DestoryLinkedList(&m_head->next);
        m_tail = NULL;
    }

    // to swap with another linkedlist
    // @param other the other linked list
    void swap(ULinkedList<T> &other)
    {
        std::move(other.m_head, m_head);
    }

    // to resize the size of the linked list
    // if the new size is greater than the current size,
    // the rest of the linked list will be filled with vals
    // @param size the new size of the linked list
    // @param val the value may fill the linked list
    void resize(const size_t &size, const T &val = T())
    {
        if (size)
        {
            size_t now = UIteratorDistance(begin(), end());
            if (now == size)
            {
                return;
            }
            UFrLinkedNode<T> *node{0};
            if (now > size)
            {
                node = UFrLinkedNode<T>::Find(m_head->next, size - 1);
                m_tail = node;
                UFrLinkedNode<T>::DestoryLinkedList(&node->next);
            }
            else // now < size
            {
                node = UFrLinkedNode<T>::Find(m_head->next, now - 1);
                iterator it = node;
                while (now != size)
                {
                    it = insert_after(it, val);
                    ++now;
                }
                m_tail = it.m_ptr;
            }
        }
        else
        {
            clear();
        }
    }

    // to reverse the linked list
    void reverse()
    {
        if (m_head->next && m_head->next->next)
        {
            UFrLinkedNode<T> *p = m_head->next;
            UFrLinkedNode<T> *q = m_head->next->next;
            m_head->next->next = NULL;
            while (q)
            {
                m_head->next = q->next;
                q->next = p;
                p = q;
                q = m_head->next;
            }
            m_head->next = p;
        }
    }

    // to insert a val after the elem that the iterator it points to
    // @param it iterator
    // @param val the val to add in
    // @return the iterator which points to the val you add in
    iterator insert_after(iterator it, const T &val)
    {
        UFrLinkedNode<T> *node = it.m_ptr;
        if (node)
        {
            if (node->next)
            {
                node->next = new UFrLinkedNode<T>(val, node->next);
            }
            else
            {
                node->next = new UFrLinkedNode<T>(val, NULL);
                if (node == m_head && m_head->next->next == NULL)
                {
                    m_tail = node->next;
                }
            }
        }
        return ++it;
    }

    // to remove a val after the elem that the iterator it points to
    // @param it iterator
    // @return the iterator which points to the elem after the one removed
    iterator erase_after(iterator it)
    {
        if (!(it.m_ptr == NULL || it.m_ptr->next == NULL))
        {
            if (it.m_ptr->next->next == NULL)
            {
                m_tail = it.m_ptr;
            }
            it.m_ptr->next = it.m_ptr->next->next;
        }
        return ++it;
    }

    // to get the iterator of the front of the first elem
    // @return the iterator of the front of the first elem
    iterator before_begin() const
    {
        return m_head;
    }

    // to get the const iterator of the front of the first elem
    // @return the const iterator of the front of the first elem
    iterator cbefore_begin() const
    {
        return before_begin();
    }

    iterator before_end() const
    {
        return m_tail;
    }

    iterator cbefore_end() const
    {
        return before_end();
    }

    iterator begin() const
    {
        return m_head->next;
    }

    iterator end() const
    {
        return NULL;
    }

    const_iterator cbegin() const
    {
        return begin();
    }

    const_iterator cend() const
    {
        return end();
    }
private:
    UFrLinkedNode<T> *m_head;
    UFrLinkedNode<T> *m_tail;
};

#endif // !_ULINKEDLIST_HPP