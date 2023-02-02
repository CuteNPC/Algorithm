#include <algorithm>
#include <iostream>
#include <stdlib.h>
#define MOD (100000000 - 3)
using namespace std;

int cnt;
template <class Record>
void Merge(Record Array[], Record TempArray[], int left, int right, int middle)
{										// �鲢����
	for (int j = left; j <= right; j++) // �������ݴ�����ʱ����
		TempArray[j] = Array[j];
	int index1 = left;		 // ��������е���ʼλ��
	int index2 = middle + 1; // �ұ������е���ʼλ��
	int i = left;			 // ����ʼ�鲢
	while (index1 <= middle && index2 <= right)
	{
		// ȡ��С�߲���ϲ�������
		if (TempArray[index1] <= TempArray[index2]) // Ϊ��֤�ȶ��ԣ����ʱ�������
			Array[i++] = TempArray[index1++];
		else
		{
			Array[i++] = TempArray[index2++];
			cnt = (cnt + middle - index1 + 1) % MOD;
		}
	}
	while (index1 <= middle) // ֻʣ�����У�����ֱ�Ӹ���
		Array[i++] = TempArray[index1++];
	while (index2 <= right) // ���ϸ�ѭ�����⣬ֱ�Ӹ���ʣ���������
		Array[i++] = TempArray[index2++];
}

template <class Record>
void MergeSort(Record Array[], Record TempArray[], int left, int right)
{
	// ��·�鲢����Array[]Ϊ���������飬left��right�ֱ�Ϊ��������
	if (left < right)
	{													// ���������ֻ��0��1����¼���Ͳ�������
		int middle = (left + right) / 2;				// ���м仮��Ϊ����������
		MergeSort(Array, TempArray, left, middle);		// �����һ����еݹ�
		MergeSort(Array, TempArray, middle + 1, right); // ���ұ�һ����еݹ�
		Merge(Array, TempArray, left, right, middle);	// ���й鲢
	}
}

template <class Record>
void sort(Record *array, int n)
{
	static Record *temp = NULL;
	if (temp == NULL)
		temp = new Record[n]; // ���븨������
	MergeSort(array, temp, 0, n - 1);
}

int A[100005];
int B[100005];

class Node
{
public:
	int from;
	int to;
};
bool cmp(Node a, Node b)
{
	return a.to < b.to;
}
Node a1[100005], a2[100005];

int main()
{
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		a1[i].from = i;
		cin >> a1[i].to;
	}
	for (int i = 0; i < n; i++)
	{
		a2[i].from = i;
		cin >> a2[i].to;
	}
	sort(a1, a1 + n, cmp);
	sort(a2, a2 + n, cmp);
	for (int i = 0; i < n; i++)
	{
		a1[i].to = a2[i].from;
	}
	sort(a1, a1 + n, cmp);

	for (int i = 0; i < n; i++)
	{
		A[i] = a1[i].from;
	}

	MergeSort<int>(A, B, 0, n - 1);
	cout << cnt << endl;

	return 0;
}