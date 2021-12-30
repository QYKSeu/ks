/*1
. 设计一个程序实现快速排序
（
1 使用指针常量 创建 一个大小为 5 0 的 动态 一维数组 。生成 5 0 个 1 10000 之间的随机
整数 分别 赋值给 动态数组 的 5 0 个元素 。
（
2 定义一个 函数 实现 快速排序 可参考第 5 章 p pt 。调用该自定义函数 对动态数组
中的 5 0 个随机整数进行升序排列 。 将 排序前 、排序后的序列 输出到屏幕上 。
（
3 使用 局部 静态 变量 记录实现快速 排序的自定义函数的被调用次数 ，并 输出到屏幕上 。*/
#include<iostream>
#include<ctime>
#include<cstdlib>
using namespace std;
int fast(int* const a,int i,int j);          //函数声明
int main() {
	srand((int)time(0));
	int* const a=new int[50];
	for (int i = 0; i <= 49; i++) {
		a[i] = rand() % 10000;
	}                                            //随机赋值
	for (int i = 0; i <= 49; i++) {
		cout << a[i]<<" ";
	}                                             //输出
	cout << endl;

	cout << "函数被调用" << fast(a, 0, 49) << "次" << endl;
	for (int i = 0; i <= 49; i++) {
		cout << a[i]<<" ";
	}                                               //输出快速排序后的数组
	delete [] a;
	return 0;
}
int fast(int* const a,int i,int j) {
	static int cishu = 0;
	cishu++;       //次数
	int first = i;      //第一个元素
	int last = j;              //最后一个元素
	int key = a[i];
	while (1) {
		if (i == j)break;             //i==j时结束
		while (1) {
			if (i == j)break;
			if (a[j] < key) {
				a[i] = a[j];
				break;
			}                         //j往前
			j--;
		}
		if (i == j)break;
		while (1) {
			if (i == j)break;
			if (a[i] > key) {
				a[j] = a[i];
				break;
			}
			i++;
		}                             //i往后
	}
	a[i] = key;
	if (i != first + 1 && i != first) { fast(a, first, i - 1); }   //递归
	if (j != last && j != last - 1) { fast(a, j + 1, last); }     //递归
	return cishu;                   //返回次数
}