# UPlan

> UPlan是鄙人练习写的模版类 **简易实现,效果当然比不上STL**,UPlan的每一个类,除了特殊声明外,均有他自己的迭代器
>
> 为了方便使用,**所有模板类的公开成员函数都就尽量用C++ STL的方式命名**

## 目前的类&将来要实现的类

- [ ] UArray [数组](./docs/UArray.md)
- [ ] UDynamicArray [动态数组](./docs/UDynamicArray.md)
- [ ] UVector [向量](./docs/UVector.md)
- [ ] UFowardList  [单链表](./docs/ULinkedList.md)
- [ ] UCircularList [单向循环链表](./docs/UCircularLinkedList.md)
- [ ] UBidirctionalList [双向链表](./docs/UBidirctionalLinkedList.md)
- [ ] UList [双向循环链表](./docs/UList.md)
- [ ] UStack [栈](./docs/UStack.md)
- [ ] UQueue [队列](./docs/UQueue.md)
- [ ] UString [字符串](./docs/UString.md)
- [ ] UTree [树](./docs/UTree.md)
- [ ] UBiTree [二叉树](./docs/UBiTree.md)
- [ ] UBiSearchTree [二叉查找树](./docs/UBiSearchTree.md)
- [ ] UAVLTree [AVL树](./docs/UAVLTree.md)
- [ ] URedBlackTree [红黑树](./docs/URedBlackTree.md)
- [ ] USplayTree [伸展树](./docs/USplayTree.md)
- [ ] UScapegoatTree [替罪羊树](./docs/UScapegoatTree.md)
- [ ] UBTree [B树](./docs/UBTree.md)
- [ ] UHeap [堆](./docs/UHeap.md)

## 关于迭代器
> 迭代器的实质: **用于提供一种方法顺序访问一个聚合对象中各个元素, 而又不需暴露该对象的内部表示**,这就是迭代器

迭代器通常也是一个类,类里面的成员变量是指针,

UPlan为了使她自己的迭代器调用方式看起来和STL一样,使得每个类都有其专属的迭代器

例如:对于UPlan的每个对象,如果可能都可以通过begin(), end(), rbegin(), rend(), cbegin(), cend(), crbegin(), crend()获得迭代器

```cpp
template <typename T>
class UDynamicArray {
public:
    class u_random_iterator;
    typedef u_random_iterator iterator;
    /* 省略非关键代码 */
    class u_random_iterator {
    public: 
        /*  省略非关键代码 */
        /* 省略大量代码 */
    }
    /* 省略大量代码 */
}
```

所有迭代器总类

| 迭代器总类     | 内部类定义标识符        |
| -------------- | ----------------------- |
| 前进迭代器     | u_forward_iterator      |
| 双向迭代器     | u_bidirctional_iterator |
| 随机访问迭代器 | u_random_iterator       |

前向迭代器仅仅支持++, * , ->操作

双向迭代器支持++, --, * , ->操作

随机访问迭代器支持++, -- , [], *, ->, +=, -= 操作
