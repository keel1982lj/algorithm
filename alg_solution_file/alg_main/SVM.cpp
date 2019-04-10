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