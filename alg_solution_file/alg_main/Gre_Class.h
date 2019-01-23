#pragma once
class Gre_Class
{
public:
	Gre_Class();
	~Gre_Class();
	//物体的数据结构
	typedef struct{
		float p;//物体的价值
		float w;//物体的重量
		float v;//物体的价值重量比
	}Object;
	static float knapsack_greedy(float M, Object instance[], float X[], int n); //贪婪法求解背包问题
};

