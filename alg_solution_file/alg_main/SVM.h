#pragma once
/*
��֧��������������������
���볬ƽ�棺W'��x+b=0
������ߺ�����f(x)=sign(W'��x+b)
*/
class svm_Class
{
private:
	int sampleNum;  //������
	int featureNum;  //������
	double **data;  //�������   �У������� �У�����
	double *lable;  //���yֵ
	double *alpha;  //������
	double b;
	double *gx;
public:
	svm_Class();
	~svm_Class();

}