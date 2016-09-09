#include<iostream>
#include<vector>
#include <sstream>
#include <string>
#include<time.h>
using namespace std;
int partition(vector<int>& nums, int p, int r){
    // random choose pivot
    int random_n = p + rand() % (r-p);
    swap(nums[p-1], nums[random_n-1]);

    int pivot = nums[p-1];
    int i = p;
    for (int j = i+1; j <= r; ++j)
        if (nums[j-1] < pivot){
            ++i;
            swap(nums[i-1], nums[j-1]);
        }
    swap(nums[i-1], nums[p-1]);
    return i;
}

void quicksort(vector<int>& nums, int p, int r){
    if (p < r){
        int q = partition(nums, p, r);
        quicksort(nums, p, q-1);
        quicksort(nums, q+1, r);
    }
}
int main(int argc, char ** argv){
    stringstream ss;
    ss << argv[1];
    int len;
    ss >> len;
    cout << "Len: " << len << endl;
    if (ss.fail()){
        cout << "Wrong argv" << endl;
        return -1;
    }
    srand((int)time(NULL));
    vector<int> seq(len);
    for (auto it = seq.begin(); it != seq.end(); ++it)
        *it = rand() % len;

    clock_t start, finish;
    double totaltime;
    cout << "start" << endl;
    start = clock();
    quicksort(seq, 1, seq.size());
    finish = clock();
    totaltime = (double)(finish-start)/CLOCKS_PER_SEC;
    std::cout<<"\n此程序的运行时间为"<<totaltime<<"秒！"<<std::endl;
/*
    for (int s : seq)
        cout << s << " ";
    cout << endl;
*/
    bool flag = 1;
    for (auto it = seq.begin(); it != seq.end()-1; ++it)
        if(*it > *(it+1))
            flag = 0;
    cout << "SORT " << flag << endl;
    return 0;
}

