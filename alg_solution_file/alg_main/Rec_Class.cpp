#include "stdafx.h"
#include "Rec_Class.h"
#include <iostream>
#include <math.h>

using namespace std;
int Rec_Class::count = 0;

Rec_Class::Rec_Class()
{
}


Rec_Class::~Rec_Class()
{
}

//��������
void Rec_Class::print(int A[], int n) {
	for (int i = 0; i < n; i++)
		cout << A[i] << " ";
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

//���η��������С
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

//��������
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
		}				//����
		A[low] = temp;     
		//�ݹ�����
		quick_sort(A, low_r, low-1);
		quick_sort(A, low + 1, high_r);
	}
}

///����ʽ�˻��ķ����㷨  ���㷨ֻ�ܼ���n��ϵ������������ʽ��ˣ�n=2^k���������n�����ʽ��������0ϵ���
//ϵ��ֻ������ʱ��ֱ�ӳˣ�
void product(int p[], int q[], int r[]) {
	r[2] = p[1] * q[1];
	r[0] = p[0] * q[0];
	r[1] = (p[0] + p[1])*(q[0] + q[1]) - r[2] - r[0];
}

//�ӷ���n��ϵ��
void Plus(int p[], int q[], int r[],int n) {
	for (int i = 0; i < n; i++) 
		r[i] = p[i] + q[i];
}

//������n��ϵ��,"p-q"
void mins(int p[], int q[], int n) {
	for (int i = 0; i < n; i++)
		p[i] = p[i] - q[i]; 
}

//ͨ����λ��ʵ�ֳ���x^k,   �����
void multi(int p[], int k, int n) {
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
	}//��ʼ������

	if (n == 2)
		product(p, q, r0);
	else {
		int k = n / 2;
		poly_product(p, q, r1 + 2 * k, k);    //����r1 = p0 * q0   ���λΪ2*k-1  ��p0��q0ָ���ǽ�����ʽ�������е�ǰһ��ϵ����
		poly_product(p + k, q + k, r0 + 2 * k, k);   //����r0 = p1 * q1   ���λΪ2*k-1  ��p1��q1ָ���Ǻ�һ��ϵ����
		Plus(p, p + k, r2 + 3 * k - 1, k);    //����r2 = p0+p1   ���λΪ k-1
		Plus(q, q + k, r3 + 3 * k - 1, k);    //����r3 = q0+q1   ���λΪ k-1
		poly_product(r2 + 3 * k - 1, r3 + 3 * k - 1, r4 + 2 * k, k);    //����r4 = r2 * r3    ���λΪ2*k-1

		//���=r0 + (r4-r0-r1)*x^k + r1 * x^n
		mins(r4, r0, 4 * k - 1);
		mins(r4, r1, 4 * k - 1);     //r4 = r4 - r0 - r1    ���λΪ2*k-1
		multi(r4, k, 2 * n - 1);   //r4 = r4 * x^k   ���λΪ3*k-1
		multi(r1, 2 * k, 2 * n - 1);   //r1 = r1 * x^n    ���λΪ2*n-1
		Plus(r0, r4, r0, 4 * k - 1);     //r0 + r4 
		Plus(r0, r1, r0, 4 * k - 1);     //     
	}

}


//��������֮��ľ���
float Rec_Class::dist(Point &a, Point &b) {
	return sqrt(pow(a.x - b.x, 2) + pow(a.y - b.y,2));
}
//���η���ƽ��㼯����������⣻XΪ�㼯��nΪ������a��bΪ��������ĵ㣻dΪ����
void Rec_Class::closest_pair(Point X[], int n, Point & a, Point & b, float & d)
{ 
	if (n == 2) {
		a = X[0]; b = X[1];
		d = dist(a, b);
	}
	else if (n == 3) {
		if (dist(X[0], X[1]) > dist(X[1], X[2])) {
			a = X[0]; b = X[1]; d = dist(X[0], X[1]);
		}
		else {
			a = X[1]; b = X[0]; d = dist(X[1], X[2]);
		}
	}
	else if (n > 3) {
		Point *X_select = new Point[n];
		Point a1, a2,a3, b1, b2,b3;
		float d1, d2,d3, dmin,xmid;//dmin�����������ȡһ����Сֵ��xmidָ�������߻��ֵ�λ��
		int count = 0;

		closest_pair(X, n / 2, a1, b1, d1);
		closest_pair(X + n / 2, n - n / 2, a2, b2, d2);
		if (d1 > d2) {
			a = a2; b = b2; dmin = d2;
		}
		else {
			a = a1; b = b1; dmin = d1;
		}
		xmid = (X[n / 2].x + X[n / 2 + 1].x) / 2;

		for (int i = 0; i < n; i++) {
			if (abs(X[i].x - xmid) <= dmin) 
				X_select[count++] = X[i];
		}  //��������С��dmin��ѡ����
		closest_pair(X_select, count + 1, a3, b3, d3);
		if (d3 < dmin) {
			a = a3; b = b3; d = d3;
		}
		else {
			d = dmin;
		}
	}
}


//��������������5��������λ��  
int mid(int *A) {
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 4-i; j++) {
			if (A[j] > A[j + 1])swap(A, j, j + 1);
		}
	}
	return A[2];
}
//n��Ԫ�ص�����A��ѡ���KСԪ��
int Rec_Class::select(int A[], int n, int k)
{
	if (n >= 6) {
		int *M = new int[n / 5];
		int *P = new int[3 * n / 4];
		int *Q = new int[3 * n / 4];
		int *R = new int[3 * n / 4];
		int countM = 0, countP = 0, countQ = 0, countR = 0, m = 0;
		for (int i = 0; i+5 < n; i += 5) {
			M[countM++] = mid(A+i);
		}
		m = select(M, countM, countM / 2+ countM%2);//ȡ����λ��
		for (int i = 0; i < n; i++) {
			if (A[i] < m) P[countP++] = A[i];
			else if (A[i] == m) Q[countQ++] = A[i];
			else R[countR++] = A[i];
		}
		if (k < countP)return select(P, countP, k);
		else if (k > countP && k < countP + countQ) return m;
		else return select(R, countR, k - countP - countQ);
	}
	else {
		//ֱ������ ����ǰ��д��
		insert_sort_rec(A, n);
		return A[k - 1];
	}

}


