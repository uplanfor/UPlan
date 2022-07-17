#ifndef _ULINKEDNODE_HPP
#define _ULINKEDNODE_HPP

template <typename T>
class UForwardLinkedNode
{
public:
    UForwardLinkedNode(const T &data = T(), const T *next = NULL) 
        : next(next), data(data)
    {
    }
private:
    T *next;
    T data;
};


template <typename T>
class UBiLinkedNode
{
public:
    UBiLinkedNode(const T &data = T(), const T *prev = NULL, const T *next = NULL) 
        : prev(prev), next(next), data(data)
    {
    }
private:
    T *prev;
    T *next;
    T data;
};

#endif // !_ULINKEDNODE_HPP