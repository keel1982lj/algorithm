#include "stdafx.h"
#include "Rec_Class.h"
#include <iostream>

using namespace std;
int Rec_Class::count = 0;

Rec_Class::Rec_Class()
{
}


Rec_Class::~Rec_Class()
{
}

//辅助方法
void Rec_Class::print(int A[], int n) {
	for (int i = 0; i < n; i++)
		cout << A[i] << " ";
}

//递归计算阶乘
int Rec_Class::factorial(int n) {
	if (n == 0)return 1;
	else return n * factorial(n - 1);
}

//基于递归的插入排序算法
void Rec_Class::insert_sort_rec(int A[], int n) {
	if (n > 1) {
		insert_sort_rec(A, n - 1);
		int temp = A[n - 1];
		for (int i = n - 2; i >= 0; i--) {
			if (A[i] > temp) {
				A[i + 1] = A[i];
				if (i == 0) A[i] = temp;
			}
			else {
				A[i + 1] = temp;
				break;
			}
		}
	}
}

//递归计算整数幂
int Rec_Class::power(int x, int n) {
	if (n == 1)
		return x;
	else
		return power(x, n / 2)*power(x, n - n / 2);
}

//多项式求值的递归算法
float Rec_Class::horner_pol(float x, float A[], int n)
{
	if (n != 1) {
		return horner_pol(x, A, n - 1)*x + A[n-1];
	}
	else {
		return A[0];
	}
}

void swap(int *A,int n, int m) {
	int temp = A[n];
	A[n] = A[m];
	A[m] = temp;
}                                                                                                                                                                                                                                                                                                                                                                                                                                 
//排列的生成的递归算法
void Rec_Class::perm(int A[], int k, int n)
{
	if (k == 1) {
		/*for (int i = 0; i < n; i++) {
			cout << A[i] << "  ";
		}*/
		cout << endl;
	}
	else {
		for (int i = n - k; i < n; i++) {
			swap(A[i], A[n - k]);
			perm(A, k - 1, n);
			swap(A[i], A[n - k]);
			for (int i = 0; i < n; i++) {
			cout << A[i] << "  ";
			}
		}
	}
}

//分治法求最大最小
void Rec_Class::max_min(int A[], int & e_max, int & e_min, int low, int high)
{
	if ((high - low )<= 1) {
		if (A[high] > A[low]) {
			e_max = A[high];
			e_min = A[low];
		}
		else {
			e_max = A[low];
			e_min = A[high];
		}
	}
	else {
		int min1, min2, max1, max2;
		max_min(A, max1, min1, low, (low + high) / 2);
		max_min(A, max2, min2, (low + high) / 2 + 1, high);
		if (min1 < min2)
			e_min = min1;
		else
			e_min = min2;

		if (max2 > max1)
			e_max = max2;
		else
			e_max = max1;
	}
}

//快速排序
void Rec_Class::quick_sort(int A[], int low, int high)
{
	if ((high - low) >= 1) {
		int low_r = low, high_r = high;
		int temp = A[low];
		while (low < high) {
			while (A[high] >= temp && low < high)
				high--;
			if (low >= high) break;
			A[low] = A[high];

			while (A[low] < temp&&low < high)
				low++;
			if (low >= high) break;
			A[high] = A[low];
		}				//划分
		A[low] = temp;     
		//递归排序
		quick_sort(A, low_r, low-1);
		quick_sort(A, low + 1, high_r);
	}
}

///多项式乘积的分治算法
//系数只有两项时，直接乘：
void product(int p[], int q[], int r[]) {
	r[2] = p[1] * q[1];
	r[0] = p[0] * q[0];
	r[1] = (p[0] + p[1])*(q[0] + q[1]) - r[2] - r[0];
}

//加法，n个系数
void Plus(int p[], int q[], int r[],int n) {
	for (int i = 0; i < n; i++) 
		r[i] = p[i] + q[i];
}

//减法，n个系数,"p-q"
void mins(int p[], int q[], int r[], int n) {
	for (int i = 0; i < n; i++)
		r[i] = p[i] - q[i]; 
}

//通过移位，实现乘以x^k
void multi(int p[], int n, int k) {
	for (int i = 0; i < n - k; i++)
		p[i] = p[i + k];
	for (int i = n - k; i < n; i++) 
		p[i] = 0;
}

void Rec_Class::poly_product(int p[], int q[], int r0[], int n)
{
	int *r1, *r2, *r3, *r4;
	r1 = new int[2 * n - 1];
	r2 = new int[2 * n - 1];
	r3 = new int[2 * n - 1];
	r4 = new int[2 * n - 1];
	for (int i = 0; i < 2 * n - 1; i++) {
		r0[i] = 0;
		r1[i] = 0;
		r2[i] = 0;
		r3[i] = 0;
		r4[i] = 0;
	}//初始化数组

	if (n == 2)
		product(p, q, r0);
	else {
		int k = n / 2;
		poly_product(p, q, r0 + 2 * k, k);    //计算r0 = p0 * q0   最高位为2*k-1
		poly_product(p + k, q + k, r1+2*k, k);   //计算r1 = p1 * q1   最高位为2*k-1
		Plus(p, p + k, r2 + 3 * k - 1, k);    //计算r2 = p0+p1   最高位为 k-1
		Plus(q, q + k, r3 + 3 * k - 1, k);    //计算r3 = q0+q1   最高位为 k-1
		poly_product(r2 + 3 * k - 1, r3 + 3 * k - 1, r4 + 2*k, k);    //计算r4 = r2 * r3    最高位为2*k-1
		mins(r4, r0, r4, 4 * k - 1);     
		mins(r4, r1, r4, 4 * k - 1);     //r4 = r4 - r0 - r1
		multi(r4, 2 * n - 1, k);   //r4 = r4 * x^k
		multi(r1, 2 * n - 1, 2 * k);   //r1 = r1 * x^n
		Plus(r0, r4, r0, 4 * k - 1);     //r0 + r4 
		Plus(r0, r1, r0, 4 * k - 1);
	}

}

//分治法求平面点集中最近点问题；X为点集；n为个数；a，b为两个最近的点；d为距离
void Rec_Class::closest_pair(Point X[], int n, Point & a, Point & b, float & d)
{
	if (n == 2) {

	}
}

