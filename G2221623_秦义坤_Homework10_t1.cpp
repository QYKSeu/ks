/*1
. ���һ������ʵ�ֿ�������
��
1 ʹ��ָ�볣�� ���� һ����СΪ 5 0 �� ��̬ һά���� ������ 5 0 �� 1 10000 ֮������
���� �ֱ� ��ֵ�� ��̬���� �� 5 0 ��Ԫ�� ��
��
2 ����һ�� ���� ʵ�� �������� �ɲο��� 5 �� p pt �����ø��Զ��庯�� �Զ�̬����
�е� 5 0 ��������������������� �� �� ����ǰ ������������ �������Ļ�� ��
��
3 ʹ�� �ֲ� ��̬ ���� ��¼ʵ�ֿ��� ������Զ��庯���ı����ô��� ���� �������Ļ�� ��*/
#include<iostream>
#include<ctime>
#include<cstdlib>
using namespace std;
int fast(int* const a,int i,int j);          //��������
int main() {
	srand((int)time(0));
	int* const a=new int[50];
	for (int i = 0; i <= 49; i++) {
		a[i] = rand() % 10000;
	}                                            //�����ֵ
	for (int i = 0; i <= 49; i++) {
		cout << a[i]<<" ";
	}                                             //���
	cout << endl;

	cout << "����������" << fast(a, 0, 49) << "��" << endl;
	for (int i = 0; i <= 49; i++) {
		cout << a[i]<<" ";
	}                                               //�����������������
	delete [] a;
	return 0;
}
int fast(int* const a,int i,int j) {
	static int cishu = 0;
	cishu++;       //����
	int first = i;      //��һ��Ԫ��
	int last = j;              //���һ��Ԫ��
	int key = a[i];
	while (1) {
		if (i == j)break;             //i==jʱ����
		while (1) {
			if (i == j)break;
			if (a[j] < key) {
				a[i] = a[j];
				break;
			}                         //j��ǰ
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
		}                             //i����
	}
	a[i] = key;
	if (i != first + 1 && i != first) { fast(a, first, i - 1); }   //�ݹ�
	if (j != last && j != last - 1) { fast(a, j + 1, last); }     //�ݹ�
	return cishu;                   //���ش���
}