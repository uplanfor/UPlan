# UArray数组

UArray是仿造std::array编写的类，类原型如下：

```cpp
template <typename T, size_t N>
class UArray
{
public:
    using iterator = URandomIterator<T>;
    using reserve_iterator = UReserveRandomIterator<T>;
    using const_iterator = const iterator;
    using const_reserve_iterator = const reserve_iterator;;
    /* 省略代码 */
private:
    T m_data[N];
}
```

## 成员变量

其中m_data是存储数据的数组

## 成员函数

默认构造函数使用默认方式 UArray\() = default;

拷贝构造函数，直接进行内存拷贝即可

```cpp
    UArray(const UArray<T, N>& copy)
    {
        memcpy(m_data, copy.m_data, sizeof(T) * N);
    }
```

size()函数获得大小，数组的大小即为数组的容量，非常好理解

max_size()函数获得数组最大容量，也是数组的容量，很好理解

```cpp
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
```

这个数组还有一个empty()函数判断数组是否为空，实际上数组肯定不为空的，直接return false

我们还需要重载[]运算符使得这个UArray用起来和平常的数组一样，at函数就不检测是否越界了

```cpp
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
```

front()函数返回数组第一个元素的引用，back()返回数组最后一个元素的引用，这些都很好实现，还有一个data函数返回m_data的地址，都非常好实现

```cpp
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
```

数组的迭代器是随机访问迭代器，于是获取迭代器的方法也非常简单，直接就是常量表达式函数

```cpp
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
```
