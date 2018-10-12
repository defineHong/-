#include<iostream>
#include<climits>
#include<vector>
using namespace std;
//寻找候选主要元素子函数
/*
	寻找候选主要元素
	返回候选主要元素
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
//寻找多数元素
/*
	若有主要元素，返回主要元素
	若无主要元素，返回int的最大值
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

//寻找多数元素2
/*
	简单搜索算法，时间复杂度较高
	若有主要元素，返回主要元素
	若无主要元素，返回int的最大值
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

//寻找多数元素3
/*
	简单搜索算法，时间复杂度略微下降
	若有主要元素，返回主要元素
	若无主要元素，返回int的最大值
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

	//输入
	vector<int> buff;
	cout << "请输入数组，以任意非数字字符结束" << endl;
	int i;
	while (cin >> i) {
		buff.push_back(i);
	}
	cin.clear();
	while (cin.get() != '\n');
	//转换为普通数组 & 打印数组
	auto length = buff.size();
	auto A = new int[length];
	cout << "初始数组：";
	for (int i = 0; i < length;i++) {
		cout << buff[i] << "\t";
		A[i] = buff[i];
	}
	cout << endl;
	//寻找主要元素
	auto m=findMajority(A, length);
	//打印结果
	if (m == INT_MAX) {
		cout << "无主要元素" << endl;
	}
	else {
		cout << "主要元素为：" << m << endl;
	}
	system("pause");
	return 0;
}
