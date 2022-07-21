#ifndef _UITERATOR_HPP
#define _UITERATOR_HPP
#include <initializer_list>

template <typename T>
class UIterator
{
public:
    typedef T* pointer;
    typedef T& reference;

    UIterator(pointer ptr = nullptr) : m_ptr(ptr)
    {
    }

    reference operator*()
    {
        return *m_ptr;
    }

    pointer operator->()
    {
        return m_ptr;
    }

    // void operator=(pointer ptr)
    // {
    //     m_ptr = ptr;
    // }

    bool operator!=(const UIterator &it)
    {
        return it.m_ptr != this->m_ptr;
    }

    bool operator==(const UIterator &it)
    {
        return it.m_ptr == this->m_ptr;
    }
protected:
    pointer m_ptr;
};


template <typename T>
class UForwardIterator : public UIterator<T>
{
public:
    using UIterator<T>::UIterator;
    using UIterator<T>::m_ptr;

    UForwardIterator operator++()
    {
        decltype(*this) temp = *this;
        ++m_ptr;
        return temp;
    }
    
    UForwardIterator& operator++(int)
    {
        ++m_ptr;
        return *this;
    }
};


template <typename T>
class UReserveForwardIterator : public UIterator<T>
{
public:
    using UIterator<T>::UIterator;
    using UIterator<T>::m_ptr;

    UReserveForwardIterator operator++()
    {
        decltype(*this) temp = *this;
        --m_ptr;
        return temp;
    }
    
    UReserveForwardIterator& operator++(int)
    {
        --m_ptr;
        return *this;
    }
};


template <typename T>
class UBidirctionalIterator : public UIterator<T>
{
public:
    using UIterator<T>::UForwardIterator;
    using UIterator<T>::m_ptr;

    UBidirctionalIterator operator++()
    {
        decltype(*this) temp = *this;
        ++m_ptr;
        return temp;
    }
    
    UBidirctionalIterator& operator++(int)
    {
        ++m_ptr;
        return *this;
    }
    UBidirctionalIterator operator--()
    {
        decltype(*this) temp = *this;
        --m_ptr;
        return temp;
    }

    UBidirctionalIterator operator--(int)
    {
        --m_ptr;
        return *this;
    }
};


template <typename T>
class UReserveBidirctionalIterator : public UIterator<T>
{
public:
    using UIterator<T>::UIterator;
    using UIterator<T>::m_ptr;

    UReserveBidirctionalIterator operator++()
    {
        decltype(*this) temp = *this;
        --m_ptr;
        return temp;
    }
    
    UReserveBidirctionalIterator& operator++(int)
    {
        --m_ptr;
        return *this;
    }
    UReserveBidirctionalIterator operator--()
    {
        decltype(*this) temp = *this;
        ++m_ptr;
        return temp;
    }

    UReserveBidirctionalIterator operator--(int)
    {
        ++m_ptr;
        return *this;
    }
};


template <typename T>
class URandomIterator : public UIterator<T>
{
public:
    typedef T& reference;
    using UIterator<T>::UIterator;
    using UIterator<T>::m_ptr;

#ifndef NO_USE_CPLUSPLUS_STYLE
    URandomIterator operator++()
    {
        decltype(*this) temp = *this;
        ++m_ptr;
        return temp;
    }
    
    URandomIterator& operator++(int)
    {
        ++m_ptr;
        return *this;
    }
    URandomIterator operator--()
    {
        decltype(*this) temp = *this;
        --m_ptr;
        return temp;
    }

    URandomIterator operator--(int)
    {
        --m_ptr;
        return *this;
    }
    URandomIterator& operator+=(const int &size)
    {
        for (int i = 0; i != size; ++i)
        {
            ++m_ptr;
        }
        return *this;
    }

    URandomIterator& operator-=(const int &size)
    {
        for (int i = 0; i != size; ++i)
        {
            --m_ptr;
        }
        return *this;
    }

    reference operator[](const size_t &size)
    {
        return m_ptr[size];
    }
#endif
};


template <typename T>
class UReserveRandomIterator : public UIterator<T>
{
public:
    typedef T& reference;
    using UIterator<T>::UIterator;
    using UIterator<T>::m_ptr;

    UReserveRandomIterator operator++()
    {
        decltype(*this) temp = *this;
        --m_ptr;
        return temp;
    }
    
    UReserveRandomIterator& operator++(int)
    {
        --m_ptr;
        return *this;
    }
    UReserveRandomIterator operator--()
    {
        decltype(*this) temp = *this;
        ++m_ptr;
        return temp;
    }

    UReserveRandomIterator operator--(int)
    {
        ++m_ptr;
        return *this;
    }
    UReserveRandomIterator& operator+=(const int &size)
    {
        for (int i = 0; i != size; ++i)
        {
            --m_ptr;
        }
        return *this;
    }

    UReserveRandomIterator& operator-=(const int &size)
    {
        for (int i = 0; i != size; ++i)
        {
            ++m_ptr;
        }
        return *this;
    }

    reference operator[](const size_t &size)
    {
        return m_ptr[-size];
    }
};


template <class UIterator>
UIterator&& UIteratorCopy(UIterator beg, UIterator end, UIterator pos)
{
    while (beg != end)
    {
        *pos = *beg;
        ++pos;
        ++beg;
    }
    return std::move(beg);
}

template <class UIterator>
UIterator&& UIteratorCopy(UIterator beg, size_t steps, UIterator pos)
{
    while (steps)
    {
        *pos = *beg;
        ++pos;
        ++beg;
    }
    return std::move(pos);
}

template <class UIterator, typename T>
UIterator&& UIteratorFill(UIterator beg, UIterator end, const T &val)
{
    while (beg != end)
    {
        *beg = val;
        ++beg;
    }
    return std::move(beg);
}

template <class UIterator, typename T>
UIterator&& UIteratorFill(UIterator beg, size_t size, const T &val)
{
    while (size)
    {
        *beg = val;
        ++beg;
        --size;
    }
    return std::move(beg);
}


template <class UIterator>
void UIteratorBackCopy(UIterator beg, UIterator end, UIterator pos)
{
    do{
        --end;
        --pos;
        *pos = *end;
    }while (pos != beg);
}


template <class UIterator>
size_t UIteratorDistance(UIterator beg, UIterator end)
{
    size_t ret = 0;
    while (beg != end)
    {
        ++ret;
        ++beg;
    }
    return ret;
}
#endif // !_UITERATOR_HPP