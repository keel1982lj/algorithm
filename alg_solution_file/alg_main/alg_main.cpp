// alg_main.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "Rec_Class.h"


int main()
{
	int A[] = { 2,8,6,1, 6, 4, 16, 5, 6, 0, 85, 62,1,1};

	Rec_Class::perm(A, 13, 13);
	// Rec_Class.perm(A, 13, 13);
    return 0;
}

