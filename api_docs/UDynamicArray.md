# UDynamicArray动态数组

UDynamicArray是封装好的动态数组，定义于头文件`UDynamicArray.hpp`用起来和UVector相似，但是内部实现不同

类声明如下：

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

## 关于迭代器

UDynamicArray的迭代器是随机访问迭代器

## 构造函数

### UDynamicArray\<T>::UDynamicArray()

默认构造函数

### UDynamicArray\<T>::UDynamicArray(const size_t &size)

构造一个动态数组，预先分配size个容量

### UDynamicArray\<T>::UDynamicArray(const size_t &size, const T &val)

构造一个动态数组，预先分配size个容量，并用val填充

### UDynamicArray\<T>::UDynamicArray(const UDynamicArray\<T> &copy)

拷贝构造函数

### UDynamicArray\<T>::UDynamicArray(const std::initializer_list\<T> &list)

使用初始化列表的构造函数

### UDynamicArray\<T>::UDynamicArray(UDynamicArray\<T> &&other)

移动构造函数

## 成员函数

### UDynamicArray\<T>& operator=(const UDynamicArray\<T> &other)

- 作用：等号赋值运算符重载，用于给数组赋值

- 返回值：other

- 参数：
  
  - other 赋值的对象

### UDynamicArray\<T>& operator=(UDynamicArray\<T> &&other)

- 作用：移动赋值函数

- 返回值：自身引用

- 参数：
  
  - other 右值引用

### inline T& at(const size_t &pos)

- 作用：根据索引返回数组对应下标的元素，不检查下标是否越界

- 返回值：对应下标元素的引用

- 参数：
  
  - pos 该元素的下标

### T& front() const

- 作用：返回数组的第一个元素的引用

- 返回值：引用

### T& back() const

- 作用：返回数组最后一个元素的引用

- 返回值：引用

### size_t size() const

- 作用：返回数组的元素个数

- 返回值：元素的个数

### size_t capacity() cosnt

- 作用：返回数组的容量

- 返回值：数组的容量

### bool empty() const

- 作用：判断数组是否为空

- 返回值：bool

### void clear()

- 作用：清空数组所有元素

- 返回值：无

### void resize(const size_t &size, const T &val = T())

- 作用：重设数组元素个数，如果变小会删掉多余元素，变大会扩大数组容量，并用val填充空位

- 参数：
  
  - size 重设数组元素个数
  - val 填充的值

### void reserve(const size_t &size)

- 作用：给数组预留空间

- 参数：
  
  - size 预留空间的大小

### void push_back(const T &val)

- 作用：在数组尾部插入元素

- 参数：
  
  - val 插入的值

### void pop_back()

- 作用：删去数组最后一个元素

- 返回值：无

### void insert(iterator where, const T& val)

- 作用：向迭代器where位置插入val的值

- 返回值：无

- 参数：
  
  - where 迭代器位置
  
  - val 插入的值

### void insert(iterator where, const size_t &count, const T& val)

- 作用：向迭代器where位置插入count个val的值

- 返回值：无

- 参数：
  
  - where 迭代器位置
  
  - count 插入的值的数量
  
  - val 插入的值

### void insert(iterator where, iterator beg, iterator end)

- 作用：向迭代器where位置插入[beg, end)区间的所有元素的值

- 返回值：无

- 参数：
  
  - where 迭代器位置
  
  - beg 迭代器开始位置
  
  - end 迭代器结束位置

### iterator erase(iterator where)

- 作用：删去迭代器where指向位置元素

- 返回值：删去元素的下一个元素的迭代器

- 参数：
  
  - where 迭代器位置

### iterator erase(iterator beg, iterator end)

- 作用：删去[beg, end)区间的所有元素

- 返回值：删去元素的下一个元素的迭代器

- 参数：
  
  - beg迭代器位置
  
  - end 迭代器位置

### void swap(UDynamicArray\<T> &other)

- 作用：与另一数组互换元素

- 参数：
  
  - other 另一个数组
