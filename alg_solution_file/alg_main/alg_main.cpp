// alg_main.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "Rec_Class.h"
#include <iostream>

using namespace std;

int main()
{
	/*int A[] = { 1,2,3,1,2,3,4,5,4,5,1,2,3,1,2,3,4,5,4,5,6};

	int min = 0, max = 0;
	Rec_Class::quick_sort(A, 0, 20);
	
	for (int i = 0; i < 21; i++) {
		cout << A[i];
	}*/

	int p[]= { 1,2,3,4};
	int q[] = { 4,5,6,4};
	int r[] = { 0,0,0,0,0,0};
	Rec_Class::poly_product(p, q, r, 4);
	Rec_Class::print(r, 6);

	return 0;
}

