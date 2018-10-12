#include<iostream>
#include<climits>
#include<vector>
using namespace std;
//Ѱ�Һ�ѡ��ҪԪ���Ӻ���
/*
	Ѱ�Һ�ѡ��ҪԪ��
	���غ�ѡ��ҪԪ��
 */
int candidate(int* A, int n, int m) {
	int i = m;
	int c = A[m];
	int count = 1;
	while (i<n-1&&count>0) {
		i++;
		if (A[i] == c) {
			count++;
		}
		else {
			count--;
		}
	}
	if (i == n-1) {
		return c;
	}
	else {
		return candidate(A, n, i + 1);
	}
}
//Ѱ�Ҷ���Ԫ��
/*
	������ҪԪ�أ�������ҪԪ��
	������ҪԪ�أ�����int�����ֵ
 */
int findMajority(int* A, int n) {
	int c = candidate(A, n, 1);
	int count = 0;
	for (int i = 0; i < n; i++) {
		if (A[i] == c) {
			count++;
		}
	}
	if (count > n / 2) {
		return c;
	}
	return INT_MAX;
}

//Ѱ�Ҷ���Ԫ��2
/*
	�������㷨��ʱ�临�ӶȽϸ�
	������ҪԪ�أ�������ҪԪ��
	������ҪԪ�أ�����int�����ֵ
 */
int simple_fMajority(int* A,int n){
	int c;
	for(int i=0;i<n;i++){
		c=A[i];
		int count=0;
		for(int j=0;count>n/2&&j<n;j++){
			if(A[j]==c){
				count++;
			}
		}
		if(count>n/2){
			return c;
		}
	}
	return INT_MAX;
}

//Ѱ�Ҷ���Ԫ��3
/*
	�������㷨��ʱ�临�Ӷ���΢�½�
	������ҪԪ�أ�������ҪԪ��
	������ҪԪ�أ�����int�����ֵ
 */
int simple_fMajority(int* A,int n){
	int c;
	for(int i=0;i<(n+1)/2;i++){
		c=A[i];
		int count=0;
		for(int j=0;count>n/2&&j<n;j++){
			if(A[j]==c){
				count++;
			}
		}
		if(count>n/2){
			return c;
		}
	}
	return INT_MAX;
}

int main() {

	//����
	vector<int> buff;
	cout << "���������飬������������ַ�����" << endl;
	int i;
	while (cin >> i) {
		buff.push_back(i);
	}
	cin.clear();
	while (cin.get() != '\n');
	//ת��Ϊ��ͨ���� & ��ӡ����
	auto length = buff.size();
	auto A = new int[length];
	cout << "��ʼ���飺";
	for (int i = 0; i < length;i++) {
		cout << buff[i] << "\t";
		A[i] = buff[i];
	}
	cout << endl;
	//Ѱ����ҪԪ��
	auto m=findMajority(A, length);
	//��ӡ���
	if (m == INT_MAX) {
		cout << "����ҪԪ��" << endl;
	}
	else {
		cout << "��ҪԪ��Ϊ��" << m << endl;
	}
	system("pause");
	return 0;
}
