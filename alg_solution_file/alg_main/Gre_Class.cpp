#include "Gre_Class.h"
#include "Rec_Class.h"



Gre_Class::Gre_Class()
{
}


Gre_Class::~Gre_Class()
{
}

//贪心中的辅助，排序算法
void 

float Gre_Class::knapsack_greedy(float M, Object instance[], float X[], int n)
{
	for (int i = 0; i < n; i++) {
		instance[i].v = instance[i].p / instance[i].w;  //计算价值重量比
		X[i] = 0; //解向量赋初值
	}
}
