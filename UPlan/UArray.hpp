#ifndef _UARRAY_HPP
#define _UARRAY_HPP
#include "UIterator.hpp"


template <class T, size_t N>
class UArray
{
public:
    using iterator = URandomIterator<T>;
    using reserve_iterator = UReserveRandomIterator<T>;
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
    inline T& operator[](const size_t &pos)
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

    constexpr iterator begin()
    {
        return &m_data[0];
    }

    constexpr iterator end()
    {
        return &m_data[N];
    }

    constexpr reserve_iterator rbegin()
    {
        return &m_data[N - 1];
    }

    constexpr reserve_iterator rend()
    {
        return &m_data[-1];
    }

    constexpr const_iterator cbegin()
    {
        return begin();
    }

    constexpr const_iterator cend()
    {
        return end();
    }

    constexpr const_reserve_iterator crbegin()
    {
        return rbegin();
    }

    constexpr const_reserve_iterator crend()
    {
        return rend();
    }
private:
    T m_data[N];
};


#endif // !_UARRAY_HPP