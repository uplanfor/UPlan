# UVector向量

UVector是向量，可当做动态数组使用，类声明如下：

```cpp
template <typename T>
class UVector
{
public:
    using iterator = URandomIterator<T>;
    using reserve_iterator = UReserveRandomIterator<T>;
    using const_iterator = const iterator;
    using const_reserve_iterator = const reserve_iterator;
    /* 省略部分代码 */
private:
    T *m_first;
    T *m_last;
    T *m_end;
};
```

## 成员变量

本类有本类使用了三个成员变量，m_first是一个指针，维护一块动态开辟的内存，m_last是一个指针，指向着数组最后一个元素的下一个位置，m_end也是一个指针，指向着动态开辟的内存的尽头的下一个位置，实际上的确是野指针了
