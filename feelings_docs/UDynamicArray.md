# UDynamicArray动态数组

UDynamicArray是动态数组，类声明如下：

```cpp
template <typename T>
class UDynamicArray
{
public:
    using iterator = URandomIterator<T>;
    using reserve_iterator = UReserveRandomIterator<T>;
    using const_iterator = const iterator;
    using const_reserve_iterator = const reserve_iterator;
    /* 省略部分代码 */
private:
    T *m_data;
    size_t m_size;
    size_t m_capacity; 
};
```

## 成员变量

本类使用了三个成员变量，m_data是一个指针，维护一块动态开辟的内存，m_size记录数组当前元素个数，m_capacity记录着数组的容积
