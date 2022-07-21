# UForwardList单链表

UForwardList是封装好的单链表，定义于头文件`UForwardList.hpp`添加了一些成员函数便于使用，类原型声明如下：

```cpp
template <typename T, size_t N>
class UForwardList
{
public
    using iterator = UForwardIterator<T>;
    using const_iterator = const iterator;
    using const_reserve_iterator = const reserve_iterator;
    /* 省略代码 */
private:
    UFrLinkedNode<T> *head;
};
```

## 关于迭代器

UForwardList的迭代器是前进迭代器

## 构造函数

### UForwardList\<T, N>::UForwardList() = default

默认构造函数

### UForwardList\<T, N>::UForwardList(size_t size, const T &val = T())

用size个val填充一个单链表

### UForwardList\<T, N>::UForwardList(const UForwardList\<T, N> &copy)

拷贝构造函数

### UForwardList\<T, N>::UForwardList(const std::initializer_list\<int> &list)

使用初始化列表的构造函数

## 成员函数

### constexpr T& front()

- 作用：返回单链表的第一个元素的引用

- 返回值：引用

### void push_front(const T &val)

- 作用：向单链表头部插入值

- 参数：
  
  - other 另一个单链表

### void pop_front()

- 作用：移去单链表头部元素

- 返回值: 无

### constexpr bool empty()

- 作用：判断单链表是否为空

- 返回值：bool

### void clear()

- 作用：清除单链表所有元素

- 返回值：无

### void swap(UForwardList\<T, N> &other)

- 作用：与另一单链表互换元素

- 参数：
  
  - other 另一个单链表

### void resize(const size_t &size, const T &val = T())

- 作用：重设单链表大小，如size比现在单链表大小还大，则扩大单链表并用val填充，如size小于现在的单链表大小，则缩小单链表

- 参数：
  
  - size 重设的大小
  - val 如果可以，将要填充的值

### void reverse()

- 作用：反转单链表顺序

- 返回值：无 

### void insert_after(iterator it, const T &val = T())

- 作用：添加val到迭代器it指向的元素后方元素

- 返回值：指向添加后元素的迭代器

- 参数：
  
  - it 迭代器位置
  - val 添加的值

### void erase_after(iterator it)

- 作用：移除迭代器it指向的元素后方元素

- 返回值：指向被移除元素的下一个元素的迭代器

- 参数：
  
  - it 迭代器位置

### void before_begin() const

- 作用：返回单链表第一个元素的前一个元素的迭代器

- 返回值：单链表第一个元素的前一个元素的迭代器

### void cbefore_begin() const

- 作用：返回单链表第一个元素的前一个元素的只读迭代器

- 返回值：单链表第一个元素的前一个元素的只读迭代器
