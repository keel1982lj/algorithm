// alg_main.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "Rec_Class.h"


int main()
{
	int A[] = {1,2,3,4,5};

	Rec_Class::perm(A, 5, 5);
	// Rec_Class.perm(A, 13, 13);
	return 0;
}

