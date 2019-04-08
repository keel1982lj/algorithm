#pragma once
#include<iostream>   
#include <fstream>      // std::ifstream
#include <stdlib.h>      
#include <cmath>        
using namespace std;
/*
����������
���� https://blog.csdn.net/sinat_36219858/article/details/78164606
2019-4-08��fp&bp��д��
*/

class Matrix 
{
private:
	unsigned row, col, size;
	double *pmm;   //����ָ��
public:
	Matrix(unsigned r, unsigned c);   //�Ƿ���Ĺ���
	Matrix(unsigned r, unsigned c, double val);   //���첢����ֵ
	Matrix(unsigned n);   //���빹��
	Matrix(const Matrix &rhs);   //��������
	~Matrix();   //��������

	Matrix &operator = (const Matrix&);    //������Ա��ָ�������д��ֵ������������ǳ�Ա
	friend istream &operator>>(istream&, Matrix&);

	friend ofstream &operator <<(of)

};
