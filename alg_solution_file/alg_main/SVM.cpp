#include "SVM.h"
#include <math.h>
using namespace std;

#define eps 1e-2    //误差精度
const int C = 100;    //惩罚参数

SVM_Cla::~SVM_Cla() {
	if (data) delete[]data;
	if (lable) delete lable;
	if (alpha) delete alpha;
	if (gx) delete gx;
}

//d为样本数据，每个样本按行存储；l标签（1或-1）；sn样本个数；fn特征个数；
void SVM_Cla::initialize(double *d, double *l, int sn, int fn)
{
	sampleNum = sn;
	featureNum = fn;
	lable = new double[sampleNum];
	data = new double *[sampleNum];    //data是一个指针数组，存了sn个指针的数组
	for (int i = 0; i < sampleNum; i++) {
		lable[i] = l[i];		//给lable赋值
		data[i] = new double[featureNum];
		for (int j = 0; j < featureNum; j++)
			data[i][j] = d[i*featureNum + j];     //data[i]是指针
	}
	alpha = new double[sampleNum] {0};
	gx = new double[sampleNum] {0};
}