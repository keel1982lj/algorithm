// alg_main.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "Rec_Class.h"
#include <iostream>
#include "Gre_Class.h"
#include<Windows.h>

using namespace std;

int main()
{
	//快排
	/*int A[] = { 1,2,3,1,2,3,4,5,4,5,1,2,3,1,2,3,4,5,4,5,6};

	int min = 0, max = 0;
	Rec_Class::quick_sort(A, 0, 20);
	
	for (int i = 0; i < 21; i++) {
		cout << A[i];
	}*/   //快排

	//多项式分治相乘
	/*int p[]= { 0,1,1,1};
	int q[] = {0,2,2,2};
	int r[] = { 0,0,0,0,0,0,0};
	Rec_Class::poly_product(p, q, r, 4);
	Rec_Class::print(r, 7);*/  //多项式分治相乘

	//平面点集最近点对
	/*Rec_Class::Point *X = new Rec_Class::Point[7];
	int X_x[7] = { 1,2,3,4,5,6,7 };
	int X_y[7] = { 16,9,4,1,0,1,4 };
	for (int i = 0; i < 7; i++) {
		X[i].x = X_x[i];
		X[i].y = X_y[i];
	}
	Rec_Class::Point a, b;
	float d;
	Rec_Class::closest_pair(X, 7, a, b, d);
	cout <<"a:"<< a.x << "," << a.y << ";" <<"b:"<< b.x << "," << b.y << endl;
	cout << "distance:" << d << endl;*/  //平面点集最近点对 （没有好好测试）

	//分治选择第k小O（n）
	/*int A[100];
	int B[100];
	for (int i = 0; i < 100; i++) {
		A[i] = rand();
		B[i] = A[i];
	}
	cout << Rec_Class::select(A, 100, 33) << endl;
	Rec_Class::insert_sort_rec(B, 100);
	cout << B[33 - 1] << endl;;
	for (int i = 0; i < 100; i++) {
		cout << B[i] << "   ";
	}*/  //分治选择k小，O（n）
	return 0;
}


