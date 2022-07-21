# UIterator

UIterator是迭代器类，定义于头文件`UIterator.hpp`，如果可以，均重载了 * ++ -- [] -> == != 这些运算符

UIterator定义的迭代器种类

| 迭代器种类     | 定义标识符                        | 支持运算符                  |
| --------- | ---------------------------- | ---------------------- |
| 基类迭代器     | UIterator                    | * -> != ==             |
| 前进迭代器     | UForwardIterator             | * -> != == ++          |
| 双向迭代器     | UBidirctionalIterator        | * -> != == ++ --       |
| 反向双向迭代器   | UReserveBidirctionalIterator | * -> != == ++ --       |
| 随机访问迭代器   | URandomIterator              | * -> != == ++ -- += -= |
| 反向随机访问迭代器 | UReserveRandomIterator       | * -> != == ++ -- += -= |

## 函数模板

### UIterator&& UIteratorCopy(UIterator beg, UIterator end, UIterator pos)

- 作用：将[beg, end)区间的元素，从pos位置一直向后拷贝

- 返回值 ：拷贝的最后一个元素的迭代器

- 参数：
  
  - beg 开始位置的双向迭代器
  - end 结束位置的双向迭代器
  - pos 要拷贝位置的双向迭代器

### UIterator&& UIteratorCopy(UIterator beg, size_t steps, UIterator pos)

- 作用：从beg开始拷贝steps长度的数据，从pos位置一直向后拷贝

- 返回值：拷贝的最后一个元素的迭代器

- 参数：
  
  - beg 开始位置的双向迭代器
  
  - steps 拷贝的长度
  
  - pos 要拷贝位置的双向迭代器

### UIterator&& UIteratorFill(UIterator beg, UIterator end, const T &val)

- 作用：将[beg, end)区间的元素，用val填充

- 返回值：拷贝的最后一个元素的迭代器

- 参数：
  
  - beg 开始位置的双向迭代器
  
  - end 结束位置的双向迭代器
  
  - val 要填充的值

### void UIteratorBackCopy(UIterator beg, UIterator end, UIterator pos)

- 作用： 将[beg, end)区间的元素，从pos位置开始向前拷贝数据

- 返回值：无

- 参数：
  
  - beg 开始位置的双向迭代器
  
  - end 结束位置的双向迭代器
  
  - pos 要拷贝位置的双向迭代器
