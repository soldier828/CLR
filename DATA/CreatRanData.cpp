#include<iostream>
#include<string>
#include<sstream>
#include<fstream>

using std::cout;
using std::cin;
using std::endl;
using std::string;

int main(){
	int A_length = 0;
	cout << "How mant data you want? " << endl;
	cin >> A_length;
	
	int A[A_length];

	std::stringstream ss;
	string str_name;
	ss << A_length;
	ss >> str_name;
	
	string filename = str_name + ".txt";
	std::ofstream fout(filename);

	srand((int)time(NULL));

	for(int i = 0; i < A_length; i++){
		A[i] =  rand() % A_length;
		if (i != A_length - 1)
			fout << A[i] << "\n";					
		else
			fout << A[i];
	}
	cout << filename << " Creat" << endl;
}
