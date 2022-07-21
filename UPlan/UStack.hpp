#ifndef _USTACK_HPP
#define _USTACK_HPP
#include "UVector.hpp"

template <typename T, typename UContainer = UVector<T>>
class UStack
{
public:
    ~UStack()
    {
        if (m_con)
        {
            delete m_con;
            m_con = NULL;
        }
    }

    UStack()
    {
        m_con = new UContainer;
    }

    UStack(const size_t &size, const T &val = T())
    {
        m_con = new UContainer(size, val);
    }

    UStack(const UContainer &con)
    {
        m_con = new UContainer(con);
    }

    UStack(const UStack<T> &copy)
    {
        m_con = new UContainer(copy.m_con);
    }

    UStack(const std::initializer_list<T> &list)
    {
        m_con = new UContainer(list);
    }

    UStack(UStack<T> &&other)
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

    T& top() const
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
        m_con->pop_back();
    }

    void swap(UStack<T> &other)
    {
        std::swap(other.m_con, m_con);
    }
private:
    UContainer *m_con;

};

#endif // !_USTACK_HPP