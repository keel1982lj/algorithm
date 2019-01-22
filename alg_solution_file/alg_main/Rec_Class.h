#pragma once
class Rec_Class   //递归算法的类
{
public:
	Rec_Class();
	~Rec_Class();

	//辅助方法
	static void print(int A[], int n);//打印个数组

	//最近点对中需要的 辅助数据结构（平面点）
	typedef struct {
		float x;
		float y;
	}Point;
	typedef struct {
		float x;
		float y;
		int index;   //该元素在X数组种的下标
	}A_Point;

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

	static float dist(Point & a, Point & b);//计算两点之间的距离
	//两点之间最短距离，没有很好的测试，也没有完全按照书上的算法（比书上的算法少优化了一步),输入的序列必须是按照x的顺序排好的
	static void closest_pair(Point X[], int n, Point &a, Point &b, float &d);//分治法求平面点集最接近点对问题；X存放点集，a，b为最近点对，距离为d
	static int select(int A[], int n, int k);//n个元素的数组A，选择第K小元素

	

	
};

