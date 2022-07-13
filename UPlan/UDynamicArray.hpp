#ifndef _UDYNAMICARRAY_HPP
#define _UDYNSMICARRAY_HPP


template <class T>
class UDynamicArray
{
public:
    class u_random_iterator;
    class u_reserve_random_iterator;
    using iterator = u_random_iterator;
    using reserve_iterator = u_reserve_random_iterator;
    using const_iterator = const iterator;
    using const_reserve_iterator = const reserve_iterator;

    ~UDynamicArray()
    {
        if (m_data)
        {
            delete []m_data;
            m_data = NULL;
        }
    }

    UDynamicArray()
    {
        m_data = NULL;
        m_size = 0;
        m_capacity = 0;
    }

    UDynamicArray(size_t size = 0, const T &val = T())
    {        
        m_size = copy.m_size;
        m_capacity = m_size;
        m_data = new T[m_size];
        for (size_t i = 0; i != size; ++i)
        {
            m_data[i] = val;
        }
    }

    UDynamicArray(const UDynamicArray<T> &copy)
    {
        m_size = copy.m_size;
        m_capacity = m_size;
        m_data = new T[m_size];
        for (size_t i = 0; i != m_size; ++i)
        {
            m_data[i] = copy.m_data[i];
        }
    }

    UDynamicArray(const std::initializer_list<T> &list) : UDynamicArray()
    {
        for (auto val : list)
        {
            push_back(val);
        }
    }

    T& operator[](const size_t &pos)
    {
        return m_data[pos];
    }

    T& at(const size_t &pos)
    {
        return m_data[pos];
    }

    size_t size()
    {
        return m_size;
    }

    size_t capacity()
    {
        return m_capacity;
    }

    bool empry()
    {
        return m_size;
    }

    void clear()
    {
        m_size = 0;
    }

    void resize(size_t size)
    {
        if (size > m_capacity)
        {
            reserve(size);
            return;
        }
        if (size < m_size)
        {
            m_size = size;
        }
    }

    void reserve(size_t size)
    {
        if (size > m_size)
        {
            T *temp = new T[size];
            memcpy(temp, m_data, m_size);
            delete[] m_data;
            m_data = temp;
            m_capacity = size;
        }
    }

    void push_back(const T &val)
    {
        if (m_size == m_capacity)
        {
            if (!m_capacity)
            {
                reserve(10);
            }
            else
            {
                reserve(m_capacity * 1.5);
            }
        }
        m_data[m_size] = val;
        ++m_size;
    }

    void pop_back(const T &val)
    {
        if (m_size)
        {
            --m_size;
        }
    }

    void erase(const iterator &where)
    {
        // todo
    }

    void erase(const iterator &beg, const iterator &end)
    {
        // todo
    }

    void swap(UDynamicArray<T> &other)
    {
        std::swap(other.m_data, m_data);
        std::swap(other.m_size, m_size);
        std::swap(other.m_capacity, m_capacity);
    }

    inline iterator begin()
    {
        return &m_data[0];
    }

    inline iterator end()
    {
        return &m_data[m_size];
    }

    inline reserve_iterator rbegin()
    {
        return &data[m_size - 1];
    }

    inline reserve_iterator rend()
    {
        return &data[-1];
    }

    inline const_iterator cbegin()
    {
        return begin();
    }

    inline const_iterator cend()
    {
        return end();
    }

    inline const_reserve_iterator crbegin()
    {
        return rbegin();
    }

    inline const_reserve_iterator crend()
    {
        return rend();
    }

    class u_random_iterator
    {
    public:
        u_random_iterator(T* ptr): m_ptr(ptr){}

        T& operator*()
        {
            return *m_ptr;
        }

        T* operator->()
        {
            return m_ptr;
        }

        u_random_iterator operator++()
        {
            u_random_iterator temp = *this;
            ++m_ptr;
            return temp;
        }

        u_random_iterator operator--()
        {
            u_random_iterator temp = *this;
            --m_ptr;
            return temp;
        }

        u_random_iterator& operator++(int)
        {
            ++m_ptr;
            return *this;
        }

        u_random_iterator& operator--(int)
        {
            --m_ptr;
            return *this;
        }

        bool operator!=(const u_reserve_random_iterator &it)
        {
            return it.m_ptr != this->m_ptr;
        }
        
        bool operator==(const u_reserve_random_iterator &it)
        {
            return it.m_ptr == this->m_ptr;
        }

    private:
        T *m_ptr;
    };

    class u_reserve_random_iterator
    {
    public:
        u_reserve_random_iterator(T* ptr): m_ptr(ptr){}

        T& operator*()
        {
            return *m_ptr;
        }

        T* operator->()
        {
            return m_ptr;
        }

        u_reserve_random_iterator operator++()
        {
            u_reserve_random_iterator temp = *this;
            --m_ptr;
            return temp;
        }

        u_reserve_random_iterator operator--()
        {
            u_reserve_random_iterator temp = *this;
            ++m_ptr;
            return temp;
        }

        u_reserve_random_iterator& operator++(int)
        {
            --m_ptr;
            return *this;
        }

        u_reserve_random_iterator& operator--(int)
        {
            ++m_ptr;
            return *this;
        }

        bool operator!=(const u_reserve_random_iterator &it)
        {
            return it.m_ptr != this->m_ptr;
        }
        
        bool operator==(const u_reserve_random_iterator &it)
        {
            return it.m_ptr == this->m_ptr;
        }

    private:
        T *m_ptr;
    };
private:
    T *m_data;
    size_t m_size;
    size_t m_capacity; 
};


#endif