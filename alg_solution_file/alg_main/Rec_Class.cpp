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

//�ݹ����׳�
int Rec_Class::factorial(int n) {
	if (n == 0)return 1;
	else return n * factorial(n - 1);
}

//���ڵݹ�Ĳ��������㷨
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

//�ݹ����������
int Rec_Class::power(int x, int n) {
	if (n == 1)
		return x;
	else
		return power(x, n / 2)*power(x, n - n / 2);
}

//����ʽ��ֵ�ĵݹ��㷨
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
//���е����ɵĵݹ��㷨
void Rec_Class::perm(int A[], int k, int n)
{
	if (k == 1) {
		for (int i = 0; i < n; i++) {
			cout << A[i] << "  ";
		}
	}
	else {
		for (int i = n - k; i < n; i++) {
			
		}
	}
}
