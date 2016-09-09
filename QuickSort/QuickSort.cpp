#include<iostream>
#include<fstream>
#include<string>
#include<time.h>

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::ifstream;

// adapt ordinal number

const int length = 2000000;


void exchange(int A[], int i, int j){
	int temp = A[i-1];
	A[i-1] = A[j-1];
	A[j-1] = temp;
}

int PARTITION(int A[], int p, int q){
	int x = A[p-1];
	int i = p;
	for (int j = p + 1; j <= q; ++j){
		if (A[j-1] <= x){
			++i;
			exchange(A, i, j);
		}
	}
	exchange(A, p, i);
	return i;
}

int RANDOMIZED_PARTITION(int A[], int p, int q){
	int i = p + rand() % (q - p + 1) ;
	exchange(A, i, p);
	return PARTITION(A, p, q);
}
void RANDOMIZED_QUICKSORT(int A[], int p, int r){
	if (p < r){
		int q = RANDOMIZED_PARTITION(A, p, r);
//		int q = PARTITION(A, p, r);
		RANDOMIZED_QUICKSORT(A, p, q - 1);
		RANDOMIZED_QUICKSORT(A, q + 1, r);
	}
}

void READ_DATA_FILE(int A[], string filename){
	ifstream test_txt(filename);
	if (!test_txt){
		cout << "Unable to open" << endl;
	}
	int i = 1;
	while(i <= length){
		string line;
		getline(test_txt, line);
		int buff = atof(line.c_str());
		A[i-1] = buff;
		++i;
	}
	test_txt.close();
}

bool Validation(int A[]){
	for (int i = 0; i < length - 1; i++){
		if (A[i] > A[i+1])
			return false;
	}
	return true;
}

int main(){
//	int A[10] = {1,1,2,2,4,4,3,5,5,3};
	int A[length];
	string filename = "2000000.txt";
	READ_DATA_FILE(A, filename);

	clock_t start, finish;
	double totaltime;
	srand((int)time(NULL));
	cout << "length: " << length << endl;
	start = clock();
	RANDOMIZED_QUICKSORT(A, 1, length);
	finish = clock();
	totaltime = (double)(finish-start)/CLOCKS_PER_SEC;
	std::cout<<"\n此程序的运行时间为"<<totaltime<<"秒！"<<std::endl;
       	bool result = Validation(A);
	cout << result << endl;

//	for (int i=0;i<10;i++)
//		cout <<A[i]<< " ";
//	cout << endl;
	return 0;
}
