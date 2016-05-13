## 实验结论
- MATLAB & C++
通过c++程序随机产生100w数据，导入到MATLAB中，实验结果如下：
  - MATLAB 80s
  - C++ 0.4s
差距如此巨大，已确认无误
***
## C++语法回顾
- **写一个新变量要定义**
- if判断的条件要加（），同时c++中逻辑与是and；MATLAB中是&&。**非常重要的一点**，c++与python不一样，if要执行的语句如果超过一行，即使缩进，也不会被认为在函数体内，因此if要执行的语句也要{}。
- c++中声明数组要 **指定大小，同时赋值用{}**，即 int A[10]={1};
***
## C++ new
- 计算数组的长度
      //数组A在这里定义，而不是传进来的参数，可以这样求出
      int A_length = sizeof(A) / sizeof(A[0]);
      //因为如果A是参数传进来，相当于首地址，即数组的指针
      //此时计算的是指针的size除以第一个元素的size，完全不对
      //解决方法就是在main函数中定义长度，传进函数

- c++下标反人类的问题  
      void HEAPSORT(int A[], int A_length)
      void BUILD_MAX_HEAP()
      void MAX_HEAPIFY(int A[], int i, int heapsize, int A_length)
  这里可以这样理解：A_length就是数组的长度，heapsize就是剩余需要heapsort考虑的长度，**i是数组中的位置，第一个位置就是i=1**。因为i是 **位置**，因此在使用i的时候，自动A[i-1]。  
  在for循环中使用A_length的时候，如果i=1：A_length，则for(int **i=0;i<A_length**;i++)

- C++ 数组写入txt
      #include<fstream>
      std::ofstream fout("100w.txt");//新建打开文件
      for(int i = 0; i<A_length; i++){
		      A[i] = rand() % A_length;
		        fout << A[i] << "\n";//往flush中写数据newline
	    }
      fout << std::flush;  //把flush写入文件
      fout.close();   //关闭文件，成功

- 产生随机数
      A[i] = rand() % A_length;
  rand()产生0-RAND_MAX的任意值，在stdlib.h定义。模A_length即产生0-A_length的随机数。
      #include<time.h>
      srand((int)time(NULL));
      A[i] = rand() % A_length;
  这样可以 **改变种子，以时间为参量**，使得每次重新开始产生的随机数组不同。

- C++计时
      #include<time.h>
      clock_t start,finish;
      double totaltime;
      start=clock();
      HEAPSORT(A, A_length);
      finish=clock(); totaltime=(double)(finish-start)/CLOCKS_PER_SEC;
  totaltime是总时间，即可。

- MATLAB读取txt
  意外的简单，对于A[i]+'\n'形式的txt数据，直接
      A=importdata('100w.txt');
  就会产生A数组
