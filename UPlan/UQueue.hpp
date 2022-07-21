#ifndef _UQUEUE_HPP
#define _UQUEUE_HPP
#include "ULinkedList.hpp"
#include <queue>

template <typename T, typename UContainer = ULinkedList<T>>
class UQueue
{
public:
    ~UQueue()
    {
        if (m_con)
        {
            delete m_con;
            m_con = NULL;
            std::queue<int> q;
        }
    }
    UQueue()
    {
        m_con = new UContainer;
    }

    UQueue(const size_t &size, const T &val = T())
    {
        m_con = new UContainer(size, val);
    }

    UQueue(const UContainer &con)
    {
        m_con = new UContainer(con);
    }

    UQueue(const UQueue<T> &copy)
    {
        m_con = new UContainer(copy.m_con);
    }

    UQueue(const std::initializer_list<T> &list)
    {
        m_con = new UContainer(list);
    }

    UQueue(UQueue<T> &&other)
    {
        m_con = other.m_con;
        other.m_con = NULL;
    }

    bool empty() const
    {
        return m_con->empty();
    }

    size_t size() const
    {
        return m_con->size();
    }

    T& front() const
    {
        return m_con->back();
    }

    T& back() const
    {
        return m_con->back();
    }

    void clear()
    {
        m_con->clear();
    }

    void push(const T &val)
    {        
        m_con->push_back(val);
    }

    void pop()
    {
        m_con->pop_front();
    }

    void swap(UQueue<T> &other)
    {
        std::swap(other.m_con, m_con);
    }
private:
    UContainer *m_con;
};

#endif //!_UQUEUE_HPP