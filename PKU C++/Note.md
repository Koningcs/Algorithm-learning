## 从C到C++
### 引用
 * 定义引用时一定要将其**初始化**成引用某个变量。
 * 从一而终，初始化后不再改变。
 * 只能引用变量，不能引用常量和表达式
    ``` C++
    double a = 4, b = 5;
    double & r1 = a;      // r1 引用了a
    double & r2 = r1;     // r2 也引用了a
    r2 = 10;              // 相当于对a赋值
    cout << a << endl;    // a = 10;
    r1 = b;               // 相当于用b对a赋值，而不是r1引用b
    cout << a << endl;    // a = 5;
    ```
  * 引用作为函数的返回值
    ``` C++
    int n = 4;
    int & SetValue() {return n;}
    int main() {
      SetValue() = 40;
      cout << n;    //n = 40
      return 0;
    }
    ```
  * 加`const`关键字变成常引用，不能通过常引用去修改其引用的内容
    ``` C++
    int n = 100;
    const int & r = n;
    r = 200;  //错误
    n = 300;
    ```
  * `const T &` 和 `T &`是不太的类型。
    ``` C++
      int n = 100;
      int & r1 = n;
      const & r2 = r1;  //对
      int & r3 = r2     //错
    ```
### const关键字
  * 定义常量
    ``` C++ 
    const string SCHOOL_NAME = "East China Normal University";
    ```
  * 定义常量指针
    * 不可以通过常量指针修改其指向的内容
      ``` C++
      int n, m;
      const int *p = &n;
      *p = 5;       // 编译出错
      n = 4;        // OK
      p = &m;       // OK 常量指针指向发生变化
      ```
    * 不能把常量指针赋值给非常量指针，反过来可以
      ``` C++
        const int *p1; int *p2;
        p1 = p2;    // 正确
        p2 = p1;    // 错误
        p2 = (int *) p1;  // 正确，强制类型转化
      ```
    * 作为传参， 不可被改变
      ``` C++
      void MyPrintf(const char *p) {
        strcpy(p, "this");    //编译出错  
        printf("%s",p);       //ok
      }
      ```

### 动态内存分配
  * 用`new`运算符实现动态内存分配
    * 分配一个变量
      ``` C++ 
      P = new T;
      ```
      `T`是任意`类型名`，`P`是类型为`T*`的指针，动态分配出大小为`sizeif(T)`的内存空间，并将该内存的`首地址`赋值给`P`。
      ``` C++
      int *pn;
      pn = new int;
      *pn = 5;
      ```
    * 分配一个数组
      ``` C++
      P = new T[N];
      ```
      `T`是任意`类型名` <br>
      `p`是类型为`T*`的指针 <br>
      `N`是要分配的数组的`元素个数`，也可以是`表达式`
  * 用`delete`运算符动态释放内存
      * 用`new`动态分配的内存空间，一定要用`delete`释放
        ``` C++
        delete P; //P必须指向new出来的空间
        ```
      * 例
        ``` C++
        int *p = new int;
        *p = 4;
        delete p;

        int *pn = new int[20];
        p[0] = 1;
        delete []p;
        ```
  * 内联函数
    * 在编译阶段，内联函数并不像普通函数一样产生调用过程，而是直接把内联函数的函数体嵌入在调用内敛函数的地方。
      ```C++
      inline int Max(int a, int b) {
        if(a > b) return a;
        return b;
      }
      ```
  * 函数重载
    * 一个或多个函数，名字相同，然而参数个数或者参数类型不同，这叫做函数的重载
      ``` C++
      int Max(double f1, double f2) { }
      int Max(int n1, int n2) { }
      int Max(int n1, int n2, int n3) { }

      Max(3.4, 2.5);  //调用1
      Max(2, 4);      //调用2
      Max(3, 2.4);    //error，二义性
      ```
    * `C++`的编译过程中，会将函数名改写，改写的函数名和参数类型和数量有关， 以此解决同名冲突
  * 函数的缺省参数
    * `C++`中，定义函数的时候可以让`最右边的连续若干个`参数有`缺省值`，那么在调用函数的时候，若相应的位置不写参数，参数就是`缺省值`
    ``` C++
    void func(int x1, int x2 = 2, int x3 = 3) { }
    
    func(10); // 等效于func(10, 2, 3)
    ```
## 类和对象基础

### 面向对象的程序设计
  * 程序设计方法
    > 将某类客观事物共同特点(属性)归纳出来，形成一个`数据结构`(可以用多个变量描述事物的属性)。
    > <br>
    > 将这类事物所能进行的行为也归纳出来，形成一个个`函数`， 这些函数可以用来操作数据结构(这一步叫`抽象`)。
    > 通过某种语法形式，将数据结构和操作该数据结构的函数`捆绑`在一起，形成一个`类`, 从而使得数据结构和操作该数据结构的算法呈现出显而易见的紧密关系，这就是`封装`。
    > <br>
  
    *面向对象的程序具有`抽象`，`封装`,`继承`,`多态`四个基本特点*
  

### 构造函数
* 是成员函数的一种
  * 名字与类名相同，可以有参数，但无返回值
  * 作用是初始化对象， 如给成员变量赋初值
  * 如果定义类时没写构造函数， 编译器会生成一个无参数的构造函数
  * 声明某类的指针时，指针没有被初始化时，对象不会生成，不会引发构造函数调用
### 复制构造函数
* 只有一个参数，即对同类对象的引用。用于对象的复制
* 形如X::X(X&) 或X::X(const X &),二者选一
* 没有定义，则编译器自动生成
* 应用情形：
  * 用一个对象去初始化同类的另一个对象
  * 如果某函数有一个参数是类A的对象，那么该函数被调用时，类A的复制构造函数将被调用



## 输出输出模板





### 函数模板
* 用函数模板实现不同类型的sawp:
  ```  C++
  template <class T>
  void Swap(T &x, T &y) {
      T  tmp = x;
      x = y;
      y = tmp;
  }

  ```
* 函数模板是可以重载的，只要他们的形参表或类型参数表不同即可
  ``` C++  

  template<class T1, class T2>
  void print(T1 arg1, T2 arg2) {
      cout << arg1 << " " << arg2 << endl;
  }

  template<class T>
  void print(T arg1, T arg2) {
      cout << arg1 << " " << arg2 << endl;
  }

  template<class T, class T2>
  void print(T arg1, T arg21) {
      cout << arg1 << " " << arg2 << endl;
  }

  ```

* 函数模板和函数的次序
  1. 先找参数完全匹配的普通函数
  2. 再找参数完全匹配的模板函数
  3. 再找实参经过自动类型转换之后能够匹配的普通函数
  4. 报错
* 匹配模板函数时，不进类型自动转换


### 类模板
* 类模板的定义：
  ```  C++
  template<typename x1, typename x2, ···>
  class A {
    ···
  }
  ```
* 类模板里成员函数的写法:
  ``` C++
  tmplate<class x1, class x2, ···>
  void A<类型参数名列表> :: 成员函数名(参数表) {

  }
  ```
* 例子：
  ``` C++
  template <class T1, class T2>
  class MyPair {
  public: 
      T1 key;
      T2 value;
      MyPair() {};
      MyPair(T1 k, T2 v) : key(k), value(v) {};
      bool operator < (const MyPair<T1, T2> &p) const{
          return key < p.key;
      }
  }; 
  ```
* 函数模板作为类模板成员:
  ``` C++ 
  template < class T >
  class A {
  public:
      template<class T2>
      void Func(T2 t) {cout << t;}
  };
  ```
