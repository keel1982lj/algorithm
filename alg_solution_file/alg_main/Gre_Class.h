#pragma once
class Gre_Class
{
public:
	Gre_Class();
	~Gre_Class();
	//��������ݽṹ
	typedef struct{
		float p;//����ļ�ֵ
		float w;//���������
		float v;//����ļ�ֵ������
	}Object;
	static float knapsack_greedy(float M, Object instance[], float X[], int n); //̰������ⱳ������
};

