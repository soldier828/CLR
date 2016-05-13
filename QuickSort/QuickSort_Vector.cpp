#include<iostream>
#include<vector>
#include<fstream>
#include<string>
#include<stdlib.h>
#include<time.h>
using std::cin;
using std::cout;
using std::endl;
using std::vector;
using std::ifstream;
using std::string;

vector<int>::iterator PARTITION(vector<int> A, vector<int>::iterator p, vector<int>::iterator q){
	
	int size = q - p;
	auto random = p + rand() % size;
	// change *random with *p
	auto temp1 = *random;
	*random = *p;
	*p = temp1;

	int  x = *p;
	auto i = p;
	for(auto j = p + 1; j != q; j++){
		if (*j <= x){
			i = i + 1;
			auto temp = *j;
			*j = *i;
			*i = temp;
		}
	}
	auto temp = *i;
	*i = *p;
	*p = temp;
	return i;
}

void QUICKSORT(vector<int> A, vector<int>::iterator p, vector<int>::iterator r){
//注意：伪代码中的r是数组尾元素的位置，而vector的end是尾后指针，r - 1 才指向最后一个元素
//因此 所有用到r的地方都要注意
//PATITION传入的本来就定义的是尾后指针，所以QUICKSORT(A, p, q - 1 + 1)快排A[p,q-1] q-1应该变为q
	if (p < r - 1){
		auto q = PARTITION(A, p, r);
		QUICKSORT(A, p, q - 1 + 1);
		QUICKSORT(A, q + 1, r);
	}
}

int main(){
	//vector<int> A = {10,9,8,7,6,5,4,3,2,1};
	vector<int> A;
	string filename = "10.txt";
        ifstream test_txt(filename);
	if (!test_txt){
		cout << "Unable to open" << endl;
		return 0;
	}
	while(!test_txt.eof()){
		string line;
		getline(test_txt, line);
		int buff = atof(line.c_str());
		A.push_back(buff);
	}
	test_txt.close();

	cout << A.size() << endl;
	clock_t start, finish;
	double totaltime;
	auto beg = A.begin();
	auto end = A.end();

	srand((int)time(NULL));
	cout << "start" << endl;
	start = clock();
	QUICKSORT(A, beg, end);
	finish = clock();
	totaltime = (double)(finish-start)/CLOCKS_PER_SEC;
	std::cout<<"\n此程序的运行时间为"<<totaltime<<"秒！"<<std::endl;  
//	for (auto i : A)
//		cout << i << " ";
//	cout << endl;
	return 0;
}

