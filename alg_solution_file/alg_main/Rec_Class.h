#pragma once
class Rec_Class   //�ݹ��㷨����
{
public:
	Rec_Class();
	~Rec_Class();

	//�ݹ�
	int factorial(int n);//�ݹ�׳�
	static void insert_sort_rec(int A[], int n);//�ݹ�������� ��n^2�� ��n��
	static int power(int x, int n);//�ݹ�׳ˣ�log n����log n��
	static float horner_pol(float x, float A[], int n);//����ʽ��ֵ�ĵݹ��㷨 (n) (n)
	static void perm(int A[], int k, int n);//��������ĵݹ��㷨��kΪ��ǰ�ݹ�����������е�Ԫ�ظ���
	static int count;//�����������õļ�����

	//����
	static void max_min(int A[], int &e_max, int &e_min, int low, int high);//���η��������С
	static void quick_sort(int A[], int low, int high);//��������    ������n^2�� ƽ������£�nlogn�����ռ临�Ӷȣ�logn��
	static void poly_product(int p[], int q[], int r[], int n);//����ʽ�˻��ķ����㷨


	//��������
	static void print(int A[], int n);//��ӡ������
};

