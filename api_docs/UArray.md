# UArray静态数组

UArray是封装好的静态数组，添加了一些成员函数便于使用，类原型声明如下：

```cpp
template <class T, size_t N>
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

## 关于迭代器

UArray的迭代器是随机访问迭代器

## 构造函数

### UArray\<T, N>::UArray() = default

默认构造函数

### UArray\<T, N>::UArray(const UArray\<T, N> &copy)

拷贝构造函数

### UArray\<T, N>::Uarray(const std::initializer_list\<int> &list)

使用初始化列表的构造函数

## 成员函数

### constexpr size_t size()

- 作用：获取数组的大小

- 返回值：数组的大小

### constexpr size_t max_size()

- 作用：获取数组最大大小

- 返回值：数组的大小

### constexpr bool empty()

- 作用：判断数组是否为空

- 返回值：false

### inline T& operator\[](const size_t &pos)

- 作用：重载[]运算符，根据索引返回数组对应下标的元素，不检查下标是否越界

- 返回值：对应下标元素的引用

- 参数：
  
  - pos 该元素的下标

### inline T& at(const size_t &pos)

- 作用：根据索引返回数组对应下标的元素，不检查下标是否越界

- 返回值：对应下标元素的引用

- 参数：
  
  - pos 该元素的下标

### constexpr T& front()

- 作用：返回数组的第一个元素的引用

- 返回值：引用

### constexpr T& back()

- 作用：返回数组最后一个元素的引用

- 返回值：引用

### T* data()

- 作用：返回数组指针

- 返回值：指针

### void fill(const T& val)

- 作用：将整个数组用val填充

- 参数：
  
  - val 填充的值

### void swap(UArray\<T, N> &arr)

- 作用：与另一数组互换元素

- 参数：
  
  - arr 另一个数组
