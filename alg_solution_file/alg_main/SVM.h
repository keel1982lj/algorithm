#pragma once
/*
��֧��������������������
���볬ƽ�棺W'��x+b=0
������ߺ�����f(x)=sign(W'��x+b)
*/
class SVM_Cla
{
private:
	int sampleNum;  //������
	int featureNum;  //������
	double **data;  //�������   �У������� �У�����
	double *lable;  //���yֵ
	double *alpha;  //������
	double b;
	double *gx;

	double s_max(double, double);
	double s_min(double, double);
	int secondAlpha(int);
	void computeGx();
	double kernel(int, int);
	void update(int, int, double, double);
	bool isConvergence();
	bool takeStep(int, int);
public:
	~SVM_Cla();
	//��ʼ������
	void initialize(double *, double *, int, int);
	void SMO();
	double objFun(int);
	void show();
};

