#include "Gre_Class.h"
#include "Rec_Class.h"



Gre_Class::Gre_Class()
{
}


Gre_Class::~Gre_Class()
{
}

//̰���еĸ����������㷨
void 

float Gre_Class::knapsack_greedy(float M, Object instance[], float X[], int n)
{
	for (int i = 0; i < n; i++) {
		instance[i].v = instance[i].p / instance[i].w;  //�����ֵ������
		X[i] = 0; //����������ֵ
	}
}
