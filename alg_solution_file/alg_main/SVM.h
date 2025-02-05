#pragma once
/*
用支撑向量机求解二分类问题
分离超平面：W'·x+b=0
分类决策函数：f(x)=sign(W'·x+b)
*/
class SVM_Cla
{
private:
	int sampleNum;  //样本数
	int featureNum;  //特征数
	double **data;  //存放样本   行：样本， 列：特征
	double *lable;  //存放y值
	double *alpha;  //超参数
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
	//初始化数据
	void initialize(double *, double *, int, int);
	void SMO();
	double objFun(int);
	void show();
};

