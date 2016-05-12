#include<iostream>
#include<vector>
using std::cin;
using std::cout;
using std::endl;
using std::vector;

vector<int>::iterator PARTITION(vector<int> A, vector<int>::iterator p, vector<int>::iterator q){
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
	if (p < r - 1){
		auto q = PARTITION(A, p, r);
		QUICKSORT(A, p, q - 1 + 1);
		QUICKSORT(A, q + 1, r);
	}
}

int main(){
	vector<int> A = {2,4,3,5,1,9,10,8,6,7};
	auto beg = A.begin();
	auto end = A.end();
	QUICKSORT(A, beg, end);
	for (auto i : A)
		cout << i << " ";
	cout << endl;
	return 0;
}

