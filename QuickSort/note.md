# QuickSort VS. HeapSort
## QuickSort
- QuickSort_Vector.cpp中的数组使用vector<int>，但是发现vector虽然方便但是速度很慢。当数据量为100w，会让速度降低万倍数量级，**所以当追求速度或者数据量很大时，最好用最底层的操作，而不是封装好的容器**。当用ordinal number访问数组，自然要减一。**使用vector时的end()时，它是尾后指针，当用ordinal number访问数组，要减一变为最后一位ordinal number**。在QUICKSORT(A,p,r)函数中，递归调用QUICKSORT(A,p,q-1),QUICKSORT(A,q+1,r),即此时的r=end()-1。

- QuickSort.cpp使用c语言基本数组，速度很快。

## Compare（200w）
- HeapSort:**0.75s**
- 非随机QuickSort:**0.42s**
- 随机QuickSort:**0.45s**  
可以看到对于大数据量，虽然HeapSort与QuickSort复杂度都是O(nlgn),但是QuickSort的常数项更小，因此速度更快

# C++ NEW
## int转为std::string
    std::stringstream ss;
    string str_name;
    ss << A_length;
    ss >> str_name
其中,A_length是int，str_name是string;目的是为了根据输入的长度，生成相应的A_length.txt

# 重构的函数
## Creat_Data
通过输入一个数字，生成随机数，并存为length.txt

## Read_Data_File
将Creat_Data生成的txt读入一个数组中。

## Validation
返回布尔值，最终验证排序是否正确
