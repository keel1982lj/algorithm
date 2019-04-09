#include "Gre_Class.h"
#include "Rec_Class.h"



Gre_Class::Gre_Class()
{
}


Gre_Class::~Gre_Class()
{
}

//̰���еĸ����������㷨(Pop)
void Gre_Class::sort_v(Object A[], int n) {
	for (int i = n-1; i>=0; i--) {
		for (int j = 0; j < i;j++) {
			if (A[j].v > A[j + 1].v) {
				Object temp = A[j];
				A[j] = A[j + 1];
				A[j + 1] = temp;
			}
		}
	}
}

//̰���㷨�������������
float Gre_Class::knapsack_greedy(float M, Object instance[], float X[], int n)
{
	for (int i = 0; i < n; i++) {
		instance[i].v = instance[i].p / instance[i].w;  //�����ֵ������
		X[i] = 0; //����������ֵ
	}
	sort_v(instance, n); //����v����

	float M_curr = 0;
	for (int i = 0; i < n; i++) {
		if (M_curr + instance[i].w <= M) {
			X[i] = 1;
		}
		else {
			X[i] = (M - M_curr) / instance[i].w;
			M_curr = M;
			break;
		}
	}

	return 0;   
}
 