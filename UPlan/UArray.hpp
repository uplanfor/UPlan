#ifndef _UARRAY_HPP
#define _UARRAY_HPP
#include <initializer_list>


template <class T, size_t N>
class UArray
{
public:
    class u_random_iterator;
    class u_reserve_random_iterator;
    using iterator = u_random_iterator;
    using reserve_iterator = u_reserve_random_iterator;
    using const_iterator = const iterator;
    using const_reserve_iterator = const reserve_iterator;

    // default constructor
    UArray() = default;

    // to copy an array
    // @param copy the copy
    UArray(const UArray<T, N>& copy)
    {
        memcpy(m_data, copy.m_data, sizeof(T) * N);
    }

    Uarray(const std::initializer_list<int> &list)
    {
        size_t count = 1;
        for (const auto &elem : list)
        {
            m_data[count] = elem; 
            ++count;
            if (count > N)
            {
                break;
            }
        }
    }

    // to return the size of the array
    // @return the size of array
    constexpr size_t size()
    {
        return N;
    }

    // to return the maxinum size of the array
    // @return the maxinum size of the array
    constexpr size_t max_size()
    {
        return N;
    }

    // to check if the array is empty
    // @return iweather the array is empty
    constexpr bool empty()
    {
        return false;
    }

    // to get the element of the array by its positon
    // @param pos the position of the element
    // @return the reference of the element
    inline T& operator[](size_t pos)
    {
        return m_data[pos];
    }

    // to get the element of the array by its positon
    // @param pos the position of the element
    // @return the reference of the element
    inline T& at(const size_t &pos)
    {
        // if (pos >= N || pos < 0)
        // {
        //      throw("pos out of range");
        // }
        return m_data[pos];
    }

    // to return the first element of the array
    // @return the reference of the first element
    constexpr T& front()
    {
        return m_data[0];
    }

    // to return the last element of the array
    // @return the reference of the last element
    constexpr T& back()
    {
        return m_data[N - 1];
    }

    // to get the pointer which points to the data of the array
    // @return the pointer which points to the data of the array
    T* data()
    {
        return m_data;
    }

    // to fill the whole array with a value
    // @param val the value that will be filled
    void fill(const T& val)
    {
        for (auto &elem : m_data)
        {
            elem = val;
        }
    }
    
    // to swap with an array
    void swap(UArray<T, N> &arr)
    {
        for(int i = 0; i < N; ++i)
        {
            std::swap(arr[i], this->operator[](i));
        }
    }

    inline iterator begin()
    {
        return &m_data[0];
    }

    inline iterator end()
    {
        return &m_data[N];
    }

    inline reserve_iterator rbegin()
    {
        return &data[N - 1];
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
    T m_data[N];
};


#endif // !_UARRAY_HPP