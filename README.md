# UPlan

> UPlan是鄙人练习写的模版类 **简易实现,效果当然比不上STL**,UPlan的每一个类,除了特殊声明外,均有他自己的迭代器
> 
> 为了方便使用,**所有模板类的公开成员函数都就尽量用C++ STL的方式命名**

UPlan的每个类如无特殊声明，均支持迭代器，如果可以均可通过begin(), end(), rbegin(), rend(), cbegin(), cend(), crbegin(), crend()获得迭代器。UPlan的迭代器参考：[点击查看](./api_docs/UIterator.md)

## 奋斗目标

- [x] UArray [数组](./api_docs/UArray.md)
- [x] UDynamicArray [动态数组](./api_docs/UDynamicArray.md)
- [x] UVector [向量](./api_docs/UVector.md)
- [x] UForwardList  [单链表](./api_docs/UForwardList.md)
- [x] ULinkedList [单链表，但是可以尾插](./api_docs/UForwardList.md)
- [ ] UBiList [双向链表](./api_docs/UBiList.md)
- [ ] UList [双向循环链表](./api_docs/UList.md)
- [x] UStack [栈](./api_docs/UStack.md)
- [x] UQueue [队列](./api_docs/UQueue.md)
- [ ] UString [字符串](./api_docs/UString.md)
- [ ] UTree [树](./api_docs/UTree.md)
- [ ] UBiTree [二叉树](./api_docs/UBiTree.md)
- [ ] UBiSearchTree [二叉查找树](./api_docs/UBiSearchTree.md)
- [ ] UAVLTree [AVL树](./api_docs/UAVLTree.md)
- [ ] URedBlackTree [红黑树](./api_docs/URedBlackTree.md)
- [ ] USplayTree [伸展树](./api_docs/USplayTree.md)
- [ ] UScapegoatTree [替罪羊树](./api_docs/UScapegoatTree.md)
- [ ] UBTree [B树](./api_docs/UBTree.md)
- [ ] UHeap [堆](./api_docs/UHeap.md)
- [ ] USet [集合](./api_docs/uset.md)
- [ ] UMultiset [多重集合](./api_docs/UMultiset.md)
- [ ] UMap [集合](./api_docs/UMap.md)
- [ ] UMultimap[多重集合](./api_docs/UMultimap.md)
- [ ] UUnorderedSet[无序集合](./api_docs/UUnorderdSet.md)
- [ ] UUnorderedMultiset[无序多重集合](./api_docs/UUnorderedMultiset.md)
- [ ] UUnorderedMap[无序集合](./api_docs/UUnorderdSet.md)
- [ ] UUnorderedMultimap[无序多重集合](./api_docs/UUnorderedMultimap.md)

## 杂项

- [x] UIterator [迭代器](./api_docs/UIterator.md)
- [ ] ULinkedNode [链表节点](./api_docs/ULinkedNode.md)

## 关于迭代器

> 迭代器的实质: **用于提供一种方法顺序访问一个聚合对象中各个元素, 而又不需暴露该对象的内部表示**,这就是迭代器

所有迭代器总类

| 迭代器总类   | 内部类定义标识符                |
| ------- | ----------------------- |
| 前进迭代器   | u_forward_iterator      |
| 双向迭代器   | u_bidirctional_iterator |
| 随机访问迭代器 | u_random_iterator       |

前向迭代器仅仅支持++, * , ->操作

双向迭代器支持++, --, * , ->操作

随机访问迭代器支持++, -- , [], *, ->, +=, -= 操作

## 汲取经验

此外，该目录下有一个feelings_docs文件夹，该文件夹储存了鄙人写这些简易数据结构的心得

[点我查看](FEELINGS_MAIN.md)
