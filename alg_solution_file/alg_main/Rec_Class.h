#pragma once
class Rec_Class   //递归算法的类
{
public:
	Rec_Class();
	~Rec_Class();
	int factorial(int n);
	static void insert_sort_rec(int A[], int n);//递归插入排序 （n^2） （n）
	static int power(int x, int n);//递归阶乘（log n）（log n）
	static float horner_pol(float x, float A[], int n);//多项式求值的递归算法 (n) (n)
	static void perm(int A[], int k, int n);//排列问题的递归算法，k为当前递归层次需完成排列的元素个数
	static int count;//排列问题中用的计数器
};

