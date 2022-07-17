#ifndef _UVECTOR_HPP
#define _UVECTOR_HPP
#include "UIterator.hpp"

template <typename T>
class UVector
{
public:
    using iterator = URandomIterator<T>;
    using reserve_iterator = UReserveRandomIterator<T>;
    using const_iterator = const iterator;
    using const_reserve_iterator = const reserve_iterator;

    ~UVector()
    {
        if (m_first)
        {
            delete []m_first;
            m_first = NULL;
        }
        m_last = NULL;
        m_end = NULL;
    }

    // default constructor
    UVector()
    {
        m_first = NULL;
        m_last = NULL;
        m_end = NULL;
    }

    UVector(const size_t &size)
    {
        m_first = new T[size];
        m_last = m_first;
        m_end = &m_first[size];
    }

    // to construct a dynamic vector that will be filled with vals
    // @param size the number of the vals
    // @param val the elem to fill the vector
    UVector(const size_t &size, const T &val) : UVector(size)
    {
        size_t my_size = size;
        while (my_size--)
        {
            *m_last++ = val;
        }
    }

    // copy constructor
    UVector(const UVector<T> &copy) : UVector(copy.size())
    {
        memcpy(m_first, copy.m_first, sizeof(T) * copy.size());
        m_last = m_end;
    }

    UVector(const std::initializer_list<T> &list) : UVector(list.size())
    {
        for (auto it = list.begin(); it != list.end(); ++it)
        {
            push_back(*it);
        }
    }

    UVector<T>& operator=(const UVector<T> &other)
    {
        if (m_first == other.m_first)
        {
            return other;
        }
        size_t my_capacity = capacity();
        size_t other_size = other.size();
        if (my_capacity >= other_size)
        {
            m_last = m_first;
            m_last += other_size;
            memcpy(m_first, other.m_first, sizeof(T) * other_size);
        }
        else
        {
            swap(UVector<T>(other));
        }
        return other;
    }

    UVector<T>& operator=(UVector<T> &&other)
    {
        m_first = other.m_first;
        m_end = other.m_end;
        m_last = other.m_last;
        other.m_data = NULL;
        return *this;
    }

    // to get the elem of the array
    // @param pos the position of the array
    // @return the reference of the elem
    T& operator[](const size_t &pos)
    {
        return m_first[pos];
    }

    // to get the elem of the vector
    // @param pos the position of the vector
    // @return the reference of the elem
    T& at(const size_t &pos)
    {
        return m_first[pos];
    }

    T& front() const
    {
        return *m_first;
    }

    T& back() const
    {
        return m_last[-1];
    }

    // to get the size of the vector
    // @return the size of the vector
    size_t size() const
    {
        return static_cast<size_t>(m_last - m_first);
    }

    // to get the capacity of the vector
    // @return the capacity of the vector
    size_t capacity() const
    {
        return static_cast<size_t>(m_end - m_first);
    }

    // to check if the vector is empty
    // @return bool
    bool empty() const
    {
        return m_first == m_last;
    }

    // to clear all of the elems in the vector
    void clear()
    {
        m_first = m_last;
    }

    // to resize the size of the vector
    // if the new size is greater than the current size,
    // the rest of the vector will be filled with vals
    // @param size the new size of the vector
    // @param val the value may fill the vector
    void resize(const size_t &size, const T &val = T())
    {
        if (size > capacity())
        {
            reserve(size);
            for (size_t i = 0; i != size; ++i)
            {
                push_back(val);
            }
            return;
        }
        if (size < this->size())
        {
            m_last -= size;
        }
    }

    // to reserve the capacity of the vector
    // @param size the size you wanna reserve
    void reserve(const size_t &size)
    {
        if (size > capacity())
        {
            T *temp = new T[size];
            size_t old_size = this->size();
            if (m_first)
            {
                memcpy(temp, m_first, sizeof(T) * this->size());
                delete[] m_first;
            }
            m_first = temp;
            m_last = &m_first[old_size];
            m_end = &m_first[size];
        }
    }


    // to push a value in the back of the vector
    // @param val the value to add in
    void push_back(const T &val)
    {
        if (m_last == m_end)
        {
            reserve(m_first ? (capacity() * 1.5) : 4);
        }
        *m_last++ = val;
    }

    // to remove the last elem of the vector
    void pop_back()
    {
        if (!empty())
        {
            --m_last;
        }
    }

    // to insert a value in the position that the iterator points to
    // @param where the iterator
    // @param val the value to insert
    void insert(iterator where, const T& val)
    {
        if (m_first)
        {
            if (m_last == m_end)
            {
                size_t steps = static_cast<size_t>(&*where - &*begin()) * sizeof(T);
                reserve(capacity() * 1.5);
                where = (T*)((char*)(&front()) + steps);
            }
            iterator old_end = end();
            ++m_last;
            UIteratorBackCopy(where, old_end, end());
            *where = val;
        }
    }

    // to insert a value for count times in the position that the iterator points to
    // @param where the iterator
    // @param count the number of the value
    // @param val the value to insert
    void insert(iterator where, const size_t &count, const T& val)
    {
        if (count && m_first)
        {
            size_t target = size() + count + 3;
            if (target > capacity())
            {
                size_t steps = static_cast<size_t>(&*where - &*begin()) * sizeof(T);
                reserve(target);
                where = (T*)((char*)(&front()) + steps);
            }
            iterator old_end = end();
            m_last += count;
            UIteratorBackCopy(where, old_end, end());
            UIteratorFill(where, count, val);
        }
    }

    // to insert the elems between the range of the two iterators
    void insert(iterator where, iterator beg, iterator end)
    {
        size_t count = &*end - &*beg;
        if (count && m_first)
        {
            size_t target = size() + count + 3;
            if (target > capacity())
            {
                size_t steps = static_cast<size_t>(&*where - &*begin()) * sizeof(T);
                reserve(target);
                where = (T*)((char*)(&front()) + steps);
            }
            iterator old_end = this->end();
            m_last += count;
            UIteratorBackCopy(where, old_end, this->end());
            UIteratorCopy(beg, end, where);
        }
    }

    // to remove the elem which the iterator points to
    // @param where the iterator
    // @return the next of the elem removed
    iterator erase(iterator where)
    {
        if (where != --end())
        {
            iterator next = where;
            ++next;
            UIteratorCopy(next, end(), where);
        }
        --m_last;
        return where;
    }

    // to remove elems in the range between two iterators
    // @param beg the beginning of the range
    // @param end the end of the range
    // @return the next of the elem removed
    iterator erase(iterator beg, iterator end)
    {
        size_t length = static_cast<size_t>(&*end - &*beg);
        UIteratorCopy(end, this->end(), beg);
        m_last -= length;
        return beg;
    }

    // to swap with the other
    // @param other the vector that swap with
    void swap(UVector<T> &other)
    {
        std::swap(other.m_first, m_first);
        std::swap(other.m_last, m_last);
        std::swap(other.m_end, m_end);
    }

    iterator begin() const
    {
        return m_first;
    }

    iterator end() const
    {
        return m_last;
    }

    reserve_iterator rbegin() const
    {
        return &(m_last[-1]);
    }

    reserve_iterator rend() const
    {
        return &m_first[-1];
    }

    const_iterator cbegin() const
    {
        return begin();
    }

    const_iterator cend() const
    {
        return end();
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
    T *m_first;
    T *m_last;
    T *m_end;
};


#endif // !_UVECTOR_HPP