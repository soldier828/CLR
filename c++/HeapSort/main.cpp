#include<iostream>
#include<time.h> 
#include<fstream>

void MAX_HEAPIFY(int A[], int i, int heapsize, int A_length){
	int left = 2*i;
	int right = 2*i+1;
	int largest = 0;
	if (left <= heapsize and A[left-1] > A[i-1])
		largest = left;
	else
		largest = i;
	if (right <= heapsize and A[right-1] > A[largest-1])
		largest = right;
	if (largest != i){
		int temp = A[i-1];
		A[i-1] = A[largest-1];
		A[largest-1] = temp;
		MAX_HEAPIFY(A, largest, heapsize, A_length);
	} 
}


void BUILD_MAX_HEAP(int A[], int A_length){
	//int A_length = sizeof(A) / sizeof(A[0]);	
	int heapsize = A_length;
	for(int i = int(A_length/2); i > 0; i--){
		MAX_HEAPIFY(A, i, heapsize, A_length);
	}
}


void HEAPSORT(int A[], int A_length){
	BUILD_MAX_HEAP(A, A_length);
	//int A_length = sizeof(A) / sizeof(A[0]);
	int heapsize = A_length;
	for(int i = A_length; i > 1; i--){
		int temp = A[i-1];
		A[i-1] = A[0];
		A[0] = temp;
		heapsize -= 1;
		MAX_HEAPIFY(A, 1, heapsize, A_length );
	}
}

int main(){
	//int A[10] = {4,1,3,2,16,9,10,14,8,7};
	//int A_length = sizeof(A) / sizeof(A[0]);
	int A_length = 1000000;
	int A[A_length];
	//srand((int)time(NULL));
	std::ofstream fout("100w.txt");
	for(int i = 0; i<A_length; i++){
		A[i] = rand() % A_length;
		fout << A[i] << "\n";
	}
	fout << std::flush; 
	fout.close(); 
	
	std::cout << "length" << A_length <<std::endl;
	clock_t start,finish;
	double totaltime;

	start=clock(); 
	HEAPSORT(A, A_length);
	finish=clock(); 
	totaltime=(double)(finish-start)/CLOCKS_PER_SEC; //finsh & start are clock numbers(eg,integer); CLOCKS_PER_SEC also interger  
	std::cout<<"\n此程序的运行时间为"<<totaltime<<"秒！"<<std::endl;  
  
	//for(int i = 0; i < A_length; i++)
	//	std::cout << A[i] << std::endl;
	//return 0;
}
