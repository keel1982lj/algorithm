#pragma once
#include<iostream>   
#include <fstream>      // std::ifstream
#include <stdlib.h>      
#include <cmath>        
using namespace std;
/*
矩阵运算类
来自 https://blog.csdn.net/sinat_36219858/article/details/78164606
2019-4-08，fp&bp抄写。
*/

class Matrix 
{
private:
	unsigned row, col, size;
	double *pmm;   //数组指针
public:
	Matrix(unsigned r, unsigned c);   //非方针的构造
	Matrix(unsigned r, unsigned c, double val);   //构造并赋初值
	Matrix(unsigned n);   //方针构造
	Matrix(const Matrix &rhs);   //拷贝构造
	~Matrix();   //析构函数

	Matrix &operator = (const Matrix&);    //如果类成员有指针必须重写赋值运算符，必须是成员
	friend istream &operator>>(istream&, Matrix&);

	friend ofstream &operator<<(ofstream &out, Matrix &obj);    //输出到文件
	friend ostream &operator<<(ostream &, Matrix &);    //输出到屏幕
	friend Matrix operator+ (const Matrix&, const Matrix&);
	friend Matrix operator- (const Matrix&, const Matrix&);
	friend Matrix operator* (const Matrix&, const Matrix&);  //矩阵乘法
	friend Matrix operator* (double, const Matrix&);   //数乘矩阵
	friend Matrix operator* (const Matrix&, double);
	friend Matrix operator/(const Matrix&, double);   //矩阵除以单数

	Matrix multi(const Matrix &);  //对应元素相乘
	Matrix mtanh(); //对应元素tanh
	unsigned Row() const { return row; }
	unsigned Col() const { return col; }
	Matrix getrow(size_t index);   //返回第index行， 索引从0
	Matrix getcol(size_t index);   //返回第index列

	Matrix cov(_In_opt_ bool flag = true);   //协方差矩阵， 或者样本方差
	double det();   //行列式
	Matrix solveAb(Matrix &obj);   //b是行向量或者列向量
	Matrix diag();  //返回对角线元素
	Matrix T()const;   //转置
	void sort(bool);  //true为从小到大
	Matrix adjoint();
	Matrix inverse();
	void QR(_Out_ Matrix &, _Out_ Matrix&)const;
	Matrix eig_val(_In_opt_ unsigned _iters = 1000);
	Matrix eig_vect(_In_opt_ unsigned _iters = 1000);

	double norm1();  //1范数
	double norm2();  //2范数
	double mean();   //矩阵平均值
	double *operator[](int i) { return pmm + i * col; }
	void zeromean(_In_opt_ bool flag = true);  //默认参数为true计算列
	void normalize(_In_opt_ bool flag = true);   //默认参数为true计算列
	Matrix exponent(double x);  //每个元素x次幂
	Matrix eye();  //对角阵
	void maxlimit(double max, double set = 0);  //对角阵

};
