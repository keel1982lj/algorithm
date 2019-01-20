#pragma once
class Rec_Class   //递归算法的类
{
public:
	Rec_Class();
	~Rec_Class();

	//递归
	int factorial(int n);//递归阶乘
	static void insert_sort_rec(int A[], int n);//递归插入排序 （n^2） （n）
	static int power(int x, int n);//递归阶乘（log n）（log n）
	static float horner_pol(float x, float A[], int n);//多项式求值的递归算法 (n) (n)
	static void perm(int A[], int k, int n);//排列问题的递归算法，k为当前递归层次需完成排列的元素个数
	static int count;//排列问题中用的计数器

	//分治
	static void max_min(int A[], int &e_max, int &e_min, int low, int high);//分治法求最大最小
	static void quick_sort(int A[], int low, int high);//快速排序    最坏情况（n^2） 平均情况下（nlogn），空间复杂度（logn）
	static void poly_product(int p[], int q[], int r[], int n);//多项式乘积的分治算法


	//辅助方法
	static void print(int A[], int n);//打印个数组
};

