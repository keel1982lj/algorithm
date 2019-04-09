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

	friend ofstream &operator<<(ofstream &out, Matrix &obj);    //������ļ�
	friend ostream &operator<<(ostream &, Matrix &);    //�������Ļ
	friend Matrix operator+ (const Matrix&, const Matrix&);
	friend Matrix operator- (const Matrix&, const Matrix&);
	friend Matrix operator* (const Matrix&, const Matrix&);  //����˷�
	friend Matrix operator* (double, const Matrix&);   //���˾���
	friend Matrix operator* (const Matrix&, double);
	friend Matrix operator/(const Matrix&, double);   //������Ե���

	Matrix multi(const Matrix &);  //��ӦԪ�����
	Matrix mtanh(); //��ӦԪ��tanh
	unsigned Row() const { return row; }
	unsigned Col() const { return col; }
	Matrix getrow(size_t index);   //���ص�index�У� ������0
	Matrix getcol(size_t index);   //���ص�index��

	Matrix cov(_In_opt_ bool flag = true);   //Э������� ������������
	double det();   //����ʽ
	Matrix solveAb(Matrix &obj);   //b������������������
	Matrix diag();  //���ضԽ���Ԫ��
	Matrix T()const;   //ת��
	void sort(bool);  //trueΪ��С����
	Matrix adjoint();
	Matrix inverse();
	void QR(_Out_ Matrix &, _Out_ Matrix&)const;
	Matrix eig_val(_In_opt_ unsigned _iters = 1000);
	Matrix eig_vect(_In_opt_ unsigned _iters = 1000);

	double norm1();  //1����
	double norm2();  //2����
	double mean();   //����ƽ��ֵ
	double *operator[](int i) { return pmm + i * col; }
	void zeromean(_In_opt_ bool flag = true);  //Ĭ�ϲ���Ϊtrue������
	void normalize(_In_opt_ bool flag = true);   //Ĭ�ϲ���Ϊtrue������
	Matrix exponent(double x);  //ÿ��Ԫ��x����
	Matrix eye();  //�Խ���
	void maxlimit(double max, double set = 0);  //�Խ���

};
