#include "Gre_Class.h"
#include "Rec_Class.h"



Gre_Class::Gre_Class()
{
}


Gre_Class::~Gre_Class()
{
}

//贪心中的辅助，排序算法(Pop)
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

//贪心算法，解决背包问题
float Gre_Class::knapsack_greedy(float M, Object instance[], float X[], int n)
{
	for (int i = 0; i < n; i++) {
		instance[i].v = instance[i].p / instance[i].w;  //计算价值重量比
		X[i] = 0; //解向量赋初值
	}
	sort_v(instance, n); //按照v排序

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
 