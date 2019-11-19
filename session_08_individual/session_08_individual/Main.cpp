#include "Matrix.h"
#include <iostream>

int main() {
	Matrix<int> m{ 3,3 };
	int jednodpole[] = { 0,1,2,3,4,5,6,7,8 };
	m.SetFrom(jednodpole);

	Matrix<int> mt = m.Transpose();
	Matrix<int> mmt = m.Multiply(mt);

	Matrix<double> mmt_d = mmt.Cast<double>();

	Matrix<double> n_d{ 3,3 }; 
	double jednodpole_d[] = { 4.5,5,0,2,-0.5,7,1.5,9,6 };
	n_d.SetFrom(jednodpole_d);

	Matrix<double> mmtn_d = mmt_d.Multiply(n_d);

	Matrix<int> r = mmtn_d.Cast<int>();

	Matrix<int> t{ 3,3 }; 
	int tpole[] = { 85,225,236,292,819,866,499,1413,1496 };
	t.SetFrom(tpole);

	std::cout << "r==t ? " << (r.Equals(t) ? "true" : "false") << std::endl;  
	return 0;
}