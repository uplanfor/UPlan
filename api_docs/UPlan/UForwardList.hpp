#ifndef _UFORWARDLIST_HPP
#define _UFORWARDLIST_HPP
#include "UIterator.hpp"
#include "ULinkedNode.hpp"


template <typename T>
class UForwardList
{
public:
    friend class UForwardIterator<UFrLinkedNode<T>>;
    using iterator = UForwardIterator<UFrLinkedNode<T>>;
    using const_iterator = const iterator;

    ~UForwardList()
    {
        clear();
    }

    // defualt constructor
    UForwardList()
    {
        m_head = new UFrLinkedNode<T>;
        m_head->next = NULL;
    }

    // to construct a linked list that will be filled with vals
    // @param size the number of the vals
    // @param val the elem to fill the linked list
    UForwardList(const size_t &size, const T &val = T()) : UForwardList()
    {
        for (size_t i = 0; i != size; ++i)
        {
            push_front(val);
        }
    }

    // copy constructor
    UForwardList(const UForwardList<T> &copy) : UForwardList()
    {
        UFrLinkedNode<T> *node = copy.m_head->next;
        iterator it = before_begin();
        while (node)
        {
            it = insert_after(it, node->data);
            node = node->next;
        }
    }

    UForwardList(const std::initializer_list<T> &list) : UForwardList()
    {
        auto it = list.begin();
        auto end = list.end();
        iterator my_it = before_begin();
        while (it != end)
        {
            my_it = insert_after(my_it, *it);
            ++it;
        }
    }

    // to get the reference of the first elem
    // @return the reference of the first elem
    T& front() const
    {
        return m_head->next->data;
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
    }

    // to swap with another linkedlist
    // @param other the other linked list
    void swap(UForwardList<T> &other)
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
};

#endif // !_UFORWARDLIST_HPP