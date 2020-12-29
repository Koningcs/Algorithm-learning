# C++ 标准库 -- 体系结构与内核分析
> * 目标
> 
>   Level 0: 使用C++标准库
> 
>   Level 1: 认识C++标准库
> 
>   Level 2: 良好使用C++标准库
> 
>   Level 3: 扩充C++标准库

## 认识Headers.版本.重要资源

### C++ Standard Library vs. Standard Template Library
* 标准库包含STL，STL是标准库的一部分，包含六大部分。


**标准库以`header files`形式呈现**
  * C++ 标准库头文件不带.h
  * 新C标准库也不带.h，例如`#include<cstdio>`
  * 旧C标准库可以继续用，例如`#include<stdio.h`
  * 新`headers`分装在`std`中
    * `using namespace std;`
    * `std::cout`

* cplusplus.com
* cppreference.com
* gcc.gnu.org

## STL体系结构基础介绍

### `STL`六大部件Components

* 容器`Containers`

* 分配器`Allocators`
* 算法`Algorithms`
* 迭代器`Iterators`
* 适配器`Adapters`
* 仿函数`Functors`


标准库中, 区间是前闭合后开原则, a.begin() 指向第一个元素, a.end() 指向最后一个元素的下一个。
``` C++
  Container<T> c;
  ···
  Container<T>:: iterator ite = c.begin();
  for(; ite != c,end(); ite++) {
    ···
  }
```

* C++11 特性 `range-based for statement`
``` C++
  for(decl : coll) }{
    statement
  }
```

## 容器分类和各种测试

### 容器的结构和分类

* Sequence Containers
  * Array
  * Vector
  * Deque
  * List
  * Forward-List

* Associative Containers
  * Set/Multiset
  * Map/MultiMap
  * HashTable 
  
* Array 不可以扩充

* Vector 扩展方式

vector的动态扩展方式是, 当vector满时, 找到一块连续的内存空间, 是当时vector空间的2倍以上，将内容拷贝过去

**不支持随机访问迭代器的容器, 不能使用标准库中的算法, 内部会提供相应的算法, 比如`sort`**

* Deque 扩展方式
每次扩充一个`buffer`

* List 每次扩充一个内存单元



## 泛型(Generic Programming) vs. 面向对象(Object-Oriented programming)

### GP

*  泛型编程是把`datas`和`methods`分开
* `Containers`和`Algorithms`都可以自己闭门造车, 通过`Iterator`连接
* `Algorithms` 通过`Iterators`确定操作范围, 并通过`Iterators`取用`Container`元素

### OOP
* 面向对象是尽量让类独立, 把`datas`和`methods`放在一个类中


## 基础技术
### 重载
#### 不能重载的
### 模板
### 函数模板


