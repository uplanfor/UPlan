#ifndef _UDYNAMICARRAY_HPP
#define _UDYNSMICARRAY_HPP
#include "UIterator.hpp"

template <class T>
class UDynamicArray
{
public:
    using iterator = URandomIterator<T>;
    using reserve_iterator = UReserveRandomIterator<T>;
    using const_iterator = const iterator;
    using const_reserve_iterator = const reserve_iterator;

    ~UDynamicArray()
    {
        if (m_data)
        {
            delete []m_data;
            m_data = NULL;
        }
        m_size = 0;
        m_capacity = 0;
    }

    // default constructor
    UDynamicArray()
    {
        m_data = NULL;
        m_size = 0;
        m_capacity = 0;
    }

    UDynamicArray(const size_t &size)
    {
        m_size = 0;
        m_capacity = m_size;
        m_data = new T[m_size];
    }

    // to construct a dynamic array that will be filled with vals
    // @param size the number of the vals
    // @param val the elem to fill the array
    UDynamicArray(const size_t &size, const T &val) : UDynamicArray(size)
    {        
        for (size_t i = 0; i != size; ++i)
        {
            m_data[i] = val;
        }
    }

    // copy constructor
    UDynamicArray(const UDynamicArray<T> &copy)
    {
        m_size = copy.m_size;
        m_capacity = m_size;
        m_data = new T[m_size];
        memcpy(m_data, copy.m_data, sizeof(T) * m_size);
    }

    UDynamicArray(const std::initializer_list<T> &list) : UDynamicArray(list.size())
    {
        for (auto it = list.begin(); it != list.end(); ++it)
        {
            push_back(*it);
        }
    }

    UDynamicArray(UDynamicArray<T> &&other)
    {
        this->operator=(other);
    }

    UDynamicArray<T>& operator=(const UDynamicArray<T> &other)
    {
        if (m_data == other.m_data)
        {
            return other;
        }
        if (m_capacity >= other.m_size)
        {
            m_size = other.m_size;
            memcpy(m_data, other.m_data, sizeof(T) * m_size);
        }
        else
        {
            T *temp = new T[other.m_size];
            m_size = other.m_size;
            m_capacity = m_size;
            if (m_data)
            {
                memcpy(temp, other.m_data, sizeof(T) * m_size);
                delete[] m_data;
            }
            m_data = temp;
        }
        return other;
    }

    UDynamicArray<T>& operator=(UDynamicArray<T> &&other)
    {
        m_data = other.m_data;
        m_size = other.m_size;
        m_capacity = other.m_capacity;
        other.m_data = NULL;
        return *this;
    }


    // to get the elem of the array
    // @param pos the position of the array
    // @return the reference of the elem
    T& operator[](const size_t &pos)
    {
        return m_data[pos];
    }

    // to get the elem of the array
    // @param pos the position of the array
    // @return the reference of the elem
    T& at(const size_t &pos)
    {
        return m_data[pos];
    }

    T& front() const
    {
        return m_data[0];
    }

    T& back() const
    {
        return m_data[m_size - 1];
    }

    // to get the size of the array
    // @return the size of the array
    size_t size() const
    {
        return m_size;
    }

    // to get the capacity of the array
    // @return the capacity of the array
    size_t capacity() const
    {
        return m_capacity;
    }

    // to check if the array is empty
    // @return bool
    bool empty() const
    {
        return m_size;
    }

    // to clear all of the elems in the array
    void clear()
    {
        m_size = 0;
    }

    // to resize the size of the array
    // if the new size is greater than the current size,
    // the rest of the array will be filled with vals
    // @param size the new size of the array
    // @param val the value may fill the array
    void resize(const size_t &size, const T &val = T())
    {
        if (size > m_capacity)
        {
            reserve(size);
            for (size_t i = m_size; i != size; ++i)
            {
                push_back(val);
            }
            return;
        }
        if (size < m_size)
        {
            m_size = size;
        }
    }

    // to reserve the capacity of the array
    // @param size the size you wanna reserve
    void reserve(const size_t &size)
    {
        if (size > m_capacity)
        {
            T *temp = new T[size];
            if (m_data)
            {
                memcpy(temp, m_data, sizeof(T) * m_size);
                delete[] m_data;
            }
            m_data = temp;
            m_capacity = size;
        }
    }


    // to push a value in the back of the array
    // @param val the value to add in
    void push_back(const T &val)
    {
        if (m_size == m_capacity)
        {
            reserve(m_capacity ? (m_capacity * 1.5) : 4);
        }
        m_data[m_size] = val;
        ++m_size;
    }

    // to remove the last elem of the array
    void pop_back()
    {
        if (m_size)
        {
            --m_size;
        }
    }

    // to insert a value in the position that the iterator points to
    // @param where the iterator
    // @param val the value to insert
    void insert(iterator where, const T& val)
    {
        if (m_data)
        {
            if (m_size == m_capacity)
            {
                size_t steps = static_cast<size_t>(&*where - &*begin()) * sizeof(T);
                reserve(m_capacity * 1.5);
                where = (T*)((char*)(&front()) + steps);
            }
            iterator old_end = end();
            ++m_size;
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
        if (count && m_data)
        {
            size_t target = m_size + count + 3;
            if (target > m_capacity)
            {
                size_t steps = static_cast<size_t>(&*where - &*begin()) * sizeof(T);
                reserve(target);
                where = (T*)((char*)(&front()) + steps);
            }
            iterator old_end = end();
            m_size += count;
            UIteratorBackCopy(where, old_end, end());
            UIteratorFill(where, count, val);
        }
    }

    // to insert the elems between the range of the two iterators
    void insert(iterator where, iterator beg, iterator end)
    {
        size_t count = &*end - &*beg;
        if (count && m_data)
        {
            size_t target = m_size + count + 3;
            if (target > m_capacity)
            {
                size_t steps = static_cast<size_t>(&*where - &*begin()) * sizeof(T);
                reserve(target);
                where = (T*)((char*)(&front()) + steps);
            }
            iterator old_end = this->end();
            m_size += count;
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
        --m_size;
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
        m_size -= length;
        return beg;
    }

    // to swap with the other
    // @param other the array that swap with
    void swap(UDynamicArray<T> &other)
    {
        std::swap(other.m_data, m_data);
        std::swap(other.m_size, m_size);
        std::swap(other.m_capacity, m_capacity);
    }


    iterator begin() const
    {
        return &m_data[0];
    }

    iterator end() const
    {
        return &m_data[m_size];
    }

    reserve_iterator rbegin() const
    {
        return &m_data[m_size - 1];
    }

    reserve_iterator rend() const
    {
        return &m_data[-1];
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
    T *m_data;
    size_t m_size;
    size_t m_capacity; 
};


#endif