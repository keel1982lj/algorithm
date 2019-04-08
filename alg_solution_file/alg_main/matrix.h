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

	friend ofstream &operator <<(of)

};
