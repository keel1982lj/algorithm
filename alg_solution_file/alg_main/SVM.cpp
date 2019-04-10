#include "SVM.h"
#include <math.h>
using namespace std;

#define eps 1e-2    //����
const int C = 100;    //�ͷ�����

SVM_Cla::~SVM_Cla() {
	if (data) delete[]data;
	if (lable) delete lable;
	if (alpha) delete alpha;
	if (gx) delete gx;
}

//dΪ�������ݣ�ÿ���������д洢��l��ǩ��1��-1����sn����������fn����������
void SVM_Cla::initialize(double *d, double *l, int sn, int fn)
{
	sampleNum = sn;
	featureNum = fn;
	lable = new double[sampleNum];
	data = new double *[sampleNum];    //data��һ��ָ�����飬����sn��ָ�������
	for (int i = 0; i < sampleNum; i++) {
		lable[i] = l[i];		//��lable��ֵ
		data[i] = new double[featureNum];
		for (int j = 0; j < featureNum; j++)
			data[i][j] = d[i*featureNum + j];     //data[i]��ָ��
	}
	alpha = new double[sampleNum] {0};
	gx = new double[sampleNum] {0};
}

double SVM_Cla::s_max(double a, double b) {
	return a > b ? a : b;
}
double SVM_Cla::s_min(double a, double b) {
	return a > b ? b : a;
}

double SVM_Cla::objFun(int x) {
	int j = 0;
	//ѡ��һ��0<alpha[j]<C
	for (int i = 0; i < sampleNum; i++) {
		if (alpha[i] > 0 && alpha[i] < a) {
			j = i;
			break;
		}
	}
	//����b
	double b = lable[j];
	for (int i = 0; i < sampleNum; i++)
		b -= alpha[i] * lable[i] * kernel(i, j);
	//������ߺ���
	double objf = b;
	for (int i = 0; i < sampleNum; i++)
		objf += alpha[i] * lable[i] * kernel(x, i);
	return objf;
}