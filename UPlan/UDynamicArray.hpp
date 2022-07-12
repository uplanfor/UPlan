#ifndef _UDYNAMICARRAY_HPP
#define _UDYNSMICARRAY_HPP


template <class T>
class UDynamicArray
{
public:
    ~UDynamicArray()
    {
        if (m_data)
        {
            delete m_data;
            m_data = NULL;
        }
    }
    UDynamicArray()
    {
    }
    UDynamicArray(size_t size, const T &elem = T())
    {
        // todo
    }
private:
    T *m_data;
    size_t m_size;
    size_t m_capacity; 
};


#endif