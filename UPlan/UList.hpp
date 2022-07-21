#ifndef _ULIST_HPP
#define _ULIST_HPP

#include "UIterator.hpp"
#include "ULinkedNode.hpp"

template <typename T>
class UList
{
public:
    friend class UBidirctionalIterator<UBiLinkedNode<T>>;
    using iterator = UBidirctionalIterator<UBiLinkedNode<T>>;
    using reserve_iterator = UReserveBidirctionalIterator<UBiLinkedNode<T>>;
    using const_iterator = const iterator;
    using const_reserve_iterator = const reserve_iterator;

    ~UList()
    {
        clear();
    }

    UList() : m_head(NULL), m_tail(NULL)
    {
    }

    UList(const size_t &size, const T &val = T()) : UList()
    {
        for (size_t i = 0; i != size; ++i)
        {
            push_back(val);
        }
    }

    UList(const UList<T> &copy) : UList()
    {
        iterator it = copy.begin();
        iterator end = copy.end();
        while (it != end)
        {
            push_back(*it);
            ++it;
        }
    }

    UList(const std::initializer_list<T> &list) : UList()
    {
        auto it = list.begin();
        auto end = list.end();
        while (it != end)
        {
            push_back(*it);
            ++it;
        }
    }

    bool empty() const
    {
        return m_head;
    }

    void clear()
    {
        UBiLinkedNode<T>::DestoryLinkedList(&m_head);
        m_tail = NULL;
    }

    void push_back(const T &val)
    {
        if (m_tail)
        {
            m_tail->next = new UBiLinkedNode<T>(val, m_tail, NULL);
            m_tail = m_tail->next;
            return;
        }
        m_head = new UBiLinkedNode<T>(val, NULL, NULL);
        m_tail = m_head;
    }

    void pop_back()
    {
        if (m_tail)
        {
            UBiLinkedNode<T> *prev = m_tail->prev;
            delete m_tail;
            m_tail = prev;
            if (!prev)
            {
                m_head = NULL;
            }
        }
    }

    void push_front(const T &val)
    {
        if (m_head)
        {
            m_head->prev = new UBiLinkedNode<T>(val, NULL, m_head);
            m_head = m_head->prev;
            return;
        }
        m_head = new UBiLinkedNode<T>(val, NULL, NULL);
        m_tail = m_head;
    }

    void pop_front()
    {
        if (m_head)
        {
            UBiLinkedNode<T> *next = m_head->next;
            delete m_head;
            m_head = next;
            if (!next)
            {
                m_tail = NULL;
            }
        }
    }

    void swap(UList<T> &other)
    {
        std::swap(this->m_head, other.m_head);
        std::swap(this->m_tail, other.m_tail);
    }

    void reverse()
    {
        if (!m_head || !m_head->next)
        {
            return;
        }
        m_tail = m_head;
        UBiLinkedNode<T> *temp = m_head->next;
        while (temp)
        {
            temp->prev->next = temp->prev->prev;
            temp->prev->prev = temp;
            
            if (temp->next)
            {
                m_tail = temp;
                return;
            }

        }
    }

    iterator begin() const
    {
        return m_head;
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

    reserve_iterator rbegin() const
    {
        return m_tail;
    }

    reserve_iterator rend() const
    {
        return NULL;
    }

    const_reserve_iterator crbegin() const
    {
        return rbegin();
    }

    const_reserve_iterator crend() const
    {
        return rend();
    }

private:
    UBiLinkedNode<T> *m_head;
    UBiLinkedNode<T> *m_tail;
};



#endif // !_ULIST_HPP