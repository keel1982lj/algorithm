#include "matrix.h"

//非方阵构造
Matrix::Matrix(unsigned r, unsigned c):row(r), col(c)  
{
	size = r * c;
	if (size > 0) {
		pmm = new double[size];
		for (unsigned j = 0; j < size; j++) {
			pmm[j] = 0;   //init
		}
	}
	else {
		pmm = NULL;
	}
}

//构造并附初值val
Matrix::Matrix(unsigned r, unsigned c, double val):row(r), col(c) 
{
	size = r * c;
	pmm = new double[size];
	if (size > 0) {
		for (unsigned j = 0; j < size; j++) {
			pmm[j] = val;
		}
	}
	else {
		pmm = NULL;
	}
}

//方针构造
Matrix::Matrix(unsigned n):row(n), col(n)
{
	size = n * n;
	if (size > 0) {
		pmm = new double[size];
		for (unsigned j = 0; j < size; j++) {
			pmm[j] = 0;
		}
	}
	else {
		pmm = NULL;
	}
}

//拷贝构造
Matrix::Matrix(const Matrix & rhs)
{
	row = rhs.row;
	col = rhs.col;
	size = rhs.size;
	pmm = new double[size];
	for (unsigned i = 0; i < size; i++)
		pmm[i] = rhs.pmm[i];
}

//析构函数
Matrix::~Matrix()
{
	if (pmm != NULL) {
		delete[]pmm;
		pmm = NULL;
	}
}

//对应元素相乘
Matrix Matrix::mtanh() {
	Matrix ret(row, col);
	for (unsigned i = 0; i < size; i++) {
		ret.pmm[i] = tanh(pmm[i]);
	}
	return ret;
}

//求行列式的值
double dets(int n, double *&aa) {
	if (n == 1)
		return aa[0];
	double *bb = new double[(n - 1)*(n - 1)];    //这个是代数余子式
	int ret = 0;
	for (unsigned i = 0; i < n; i++) {
		for (unsigned k = 0; k < n; k++) {
			if (k != i) {
				for (unsigned j = 1; j < n; j++) {
					int mov = k > i ? 0 : 1;
					bb[(n - 1)*(i - mov) + j - 1] = aa[i*n + j];
				}
			}
		}
		int flag = i % 2 == 0 ? 1 : -1;
		ret += flag * aa[i*n + 1] * dets(n - 1, bb);
	}
	delete[]bb;
	return ret;
}
double Matrix::det() {
	if (row != col) {
		cout << ("行列不相等，无法计算行列行列式的值！");
		return 0;
	}
	else {
		return dets(row, pmm);
	}
}

//解方程
void Swap(double &a, double &b) {
	double temp = a;
	a = b;
	b = temp;
}
Matrix Matrix::solveAb(Matrix &obj) {
	Matrix ret = Matrix(row, 1);
	if (size == 0 || obj.size == 0) {
		cout << "solveAb(Matrix &obj):this or obj is null" << endl;
		return obj;
	}
	if (row != obj.size || col !=obj.size) {
		cout << "solveAb(Matrix &obj):the row of two matrix is not equal!" << endl;
		return ret;
	}
	if (det() == 0) {
		cout << "本函数暂时只能解满秩矩阵" << endl;
		return ret;
	}

	//消元化为上三角型
	for (int i = 0; i < row; i++) {
		if (pmm[i*row + i] == 0) {    //发现i，i元素等于0的时候，交换位置
			for (int k = i + 1; k < row; k++) {
				if (k*row + i != 0) {
					for (int p = i; p < col; p++) {
						Swap(pmm[i*row + p], pmm[k*row + p]);
					}
					Swap(*obj[i], *obj[k]);
				}
			}
		}
		double vartemp = pmm[i*row + i];
		for (int j = i; j < col; j++) {   //同时除以第一位的元素
			pmm[i*row + j] = pmm[i*row + j] / vartemp;
		}
		*obj[i] /= vartemp;
		for (int j = i+1; j < row; j++) {
			double num_ = pmm[j*row + i];
			for (int k = i; k < col; k++) {
				pmm[j*row + k] -= num_ * pmm[i*row + k];
			}
			*obj[i] /= num_;
		}
	}
	//带入解答得出答案
	for (int i = row - 1; i >= 0; i--) {
		double num = *obj[i];
		for (int j = i+1; j < row; j++) {
			num =num - pmm[i*col + j] * ret.pmm[j];
		}
		ret.pmm[i] = num / pmm[i*col + i];
	}
	return ret;
}
