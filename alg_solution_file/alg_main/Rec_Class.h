#pragma once
class Rec_Class   //�ݹ��㷨����
{
public:
	Rec_Class();
	~Rec_Class();
	int factorial(int n);
	static void insert_sort_rec(int A[], int n);//�ݹ�������� ��n^2�� ��n��
	static int power(int x, int n);//�ݹ�׳ˣ�log n����log n��
	static float horner_pol(float x, float A[], int n);//����ʽ��ֵ�ĵݹ��㷨 (n) (n)
	static void perm(int A[], int k, int n);//��������ĵݹ��㷨��kΪ��ǰ�ݹ�����������е�Ԫ�ظ���
	static int count;//�����������õļ�����
};

