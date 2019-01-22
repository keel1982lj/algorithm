#pragma once
class Rec_Class   //�ݹ��㷨����
{
public:
	Rec_Class();
	~Rec_Class();

	//��������
	static void print(int A[], int n);//��ӡ������

	//����������Ҫ�� �������ݽṹ��ƽ��㣩
	typedef struct {
		float x;
		float y;
	}Point;
	typedef struct {
		float x;
		float y;
		int index;   //��Ԫ����X�����ֵ��±�
	}A_Point;

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

	static float dist(Point & a, Point & b);//��������֮��ľ���
	//����֮����̾��룬û�кܺõĲ��ԣ�Ҳû����ȫ�������ϵ��㷨�������ϵ��㷨���Ż���һ��),��������б����ǰ���x��˳���źõ�
	static void closest_pair(Point X[], int n, Point &a, Point &b, float &d);//���η���ƽ��㼯��ӽ�������⣻X��ŵ㼯��a��bΪ�����ԣ�����Ϊd
	static int select(int A[], int n, int k);//n��Ԫ�ص�����A��ѡ���KСԪ��

	

	
};

