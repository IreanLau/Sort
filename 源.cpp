#include<iostream>
using namespace std;
#define __DEBUG__



//������Ϊ��׼


/**************************************************************************************/

/*����������*/
struct Node
{
	int key;
	Node* next;
	Node(int nKey, Node* pNext)
		: key(nKey)
		, next(pNext)
	{}
};

Node* GetPartion(Node* pBegin, Node* pEnd)
{
	Node* _key = pBegin;
	Node* prev = pBegin;
	Node* cur = prev->next;
	while (cur != pEnd)
	{
		if (cur->key < _key->key)
		{
			prev = prev->next;
			std::swap(prev->key, cur->key);
		}
		cur = cur->next;
	}
	std::swap(prev->key, pBegin->key);
	return prev;
}

void QuickSort(Node* pBeign, Node* pEnd)
{
	if (pBeign->next == pEnd || pBeign == NULL)
		return;
	if (pBeign != pEnd)
	{
		Node* partion = GetPartion(pBeign, pEnd);
		QuickSort(pBeign, partion);
		QuickSort(partion->next, pEnd);
	}
}
/*ð��*/
void BubbleSort(Node* pBeign)
{
	if (pBeign == NULL)
		return;
	Node* tail = NULL;/*��������*/
	while (tail != pBeign)
	{
		Node* prev = pBeign;
		Node* cur = prev->next;
		bool flag = true;/*��� ������Ч�ıȽ�*/

		while (cur != tail)/*һ������*/
		{
			if (cur->key < prev->key)
			{
				swap(cur->key, prev->key);
				flag = false;
			}
			prev = cur;
			cur = cur->next;
		}
		if (flag)
			return;

		tail = prev;
	}
}

void show(Node* pBeign)
{
	Node* cur = pBeign;
	while (cur)
	{
		cout << cur->key << " ";
		cur = cur->next;
	}
}

void test1()
{
	Node *h = new Node(1, NULL);
	Node *g = new Node(0, h);
	Node *f = new Node(9, g);
	Node *e = new Node(7, f);

	Node *d = new Node(5, e);
	Node *c = new Node(3, d);
	Node *b = new Node(2, c);
	Node *a = new Node(4, b);

	show(a);

	cout << endl;
	Node* pBeign = a;


	cout << "QuickSort:> \t" << endl;
	QuickSort(pBeign, NULL);
	show(a);
	cout << endl;


	//cout << "BubbleSort for list:> \t" << endl;
	//BubbleSort(pBeign);
	//show(a);
	//cout << endl;
}

/********************************************************************/
/*��������ֱ*/
void rever(Node* pBegin)
{
}


/***************************************************************************************/

void unitPrint(int a[], int n, int i) //��ӡÿ�˽��
{
	cout << i << ":";
	for (int j = 0; j < 8; j++) {
		cout << a[j] << " ";
	}
	cout << endl;
}
/**************************************************************************************/
/*
���ţ����������һ��  ʱ�临�Ӷ�O(n* lg n)

��������
1.ѡȡ����
2.�������Ԫ�طֿ���  ��߱���С���ұ߱�����
3.�ݹ���������������

*/
int GetPart(int ar[], int head, int tail)/*�ڿӷ�*/
{
	int left = head;
	int right = tail - 1;	//�������ұ����С��
	int key = ar[left];
	while (left < right)
	{
		while (left < right && ar[right]>key)
			right--;
		if (left < right)
		{
			ar[left] = ar[right];//�ҵ�С�� ������ �ұ߳�Ϊһ�����õġ��ӡ�
			left++;		//	
		}

		while (left<right && ar[left] < key)
			left++;
		if (left < right)
		{
			ar[right] = ar[left];	//��߳�Ϊ�µĿ�
			right--;
		}
	}
	ar[left] = key;				//������������һ�����У�midλ�ã�

	return left;
}

void QSort(int ar[], int left, int right)
{
	if (ar == NULL || left + 1 == right)
		return;
	if (left < right)
	{
		int mid = GetPart(ar, left, right);
#ifdef __DEBUG__
		for (int i = 0; i < 8; ++i)
			cout << ar[i] << " ";
		cout << endl;
#endif
		QSort(ar, left, mid);
		QSort(ar, mid + 1, right);
	}
}


void  test2()
{
	int ar[8] = { 4,3,5,2,0,9,7,1 };
	for (int i = 0; i < 8; ++i)
		cout << ar[i] << " ";
	cout << endl << endl;

	QSort(ar, 0, 8);

	cout << " Qsort for arry:>\n\t";
	for (int i = 0; i < 8; ++i)
		cout << ar[i] << " ";
	cout << endl;
}
/************************************************************************************************/


/*
ѡ��
��һ������С�����һ��λ�ý���
�ڶ��δ�ʣ�µ����ҵڶ�С����ڶ���λ�ý���
*/
void SelectSort(int ar[], int n)
{
	int min = 0;
	for (int i = 0; i < n; ++i)
	{
		min = i;
		for (int j = i + 1; j < n; ++j)
			if (ar[j] < ar[min])
				min = j;

		if (min != i)
			std::swap(ar[min], ar[i]);
		/*****************************/
		unitPrint(ar, n, i);		//��ӡÿ�εĽ��
	}
}


void test3()
{
	int ar[8] = { 4,3,5,2,0,9,7,1 };
	for (int i = 0; i < 8; ++i)
		cout << ar[i] << " ";
	cout << endl << endl;

	SelectSort(ar, 8);

	cout << " Select for arry:>\n\t";
	for (int i = 0; i < 8; ++i)
		cout << ar[i] << " ";
	cout << endl;
}


/******************************************************************/
/*
�������� �� �����ڱ�λ

//	(�ڱ�λ)4,3,5,2,0,9,7,1
��������
1.�ӵڶ���ʵ�ʵ�Ԫ�س������Ӻ���ǰ�Ƚϣ�����������ʵ�λ��,�����3�嵽4��λ�ã�
��4���ƣ��γ�3��4��5��2����
3.ѭ�� ���� �ӵڶ����������ɲ���

�ܽ᣺�ӵڶ���Ԫ�ص���󣬲������ʵ�λ�ã�Ҫ�ƶ�����Ԫ�أ�
*/


void InsertSort(int ar[], int n)
{
	for (int i = 1; i < n; ++i)
	{
		if (ar[i] < ar[i - 1])
		{
			int Guard = ar[i];	//�ڱ�
			int j = i - 1;
			while (ar[j] > Guard)
			{
				ar[j + 1] = ar[j];
				j--;
			}
			ar[j + 1] = Guard;
		}
		unitPrint(ar, n, i);		//��ӡÿ�εĽ��
	}
}

void test4()
{
	int ar[8] = { 4,3,5,2,0,9,7,1 };
	for (int i = 0; i < 8; ++i)
		cout << ar[i] << " ";
	cout << endl << endl;

	InsertSort(ar, 8);

	cout << " InsertSort for arry:>\n\t";
	for (int i = 0; i < 8; ++i)
		cout << ar[i] << " ";
	cout << endl;
}
/*******************************************************************************/


/*
ϣ�� ����С����������		��������d = {n/2 ,n/4, n/8 .....1} nΪҪ�������ĸ���
*/

/*
������4,3,5,2,0,9,7,1
�������� {5��3��1}
*/

void ShellInsertSort(int ar[], int n, int dk)
{
	for (int i = dk; i < n; ++i)
	{
		if (ar[i] < ar[i - dk])
		{
			int j = i - dk;
			int Guard = ar[i];//�ڱ�
			ar[i] = ar[i - dk];

			while (ar[j] > Guard)
			{
				ar[j + dk] = ar[j];
				j -= dk;
			}
			ar[j + dk] = Guard;
		}
#ifdef __DEBUG__
		for (int i = 0; i < 8; ++i)
			cout << ar[i] << " ";
		cout << endl;
#endif
	}
}

void ShellSort(int ar[], int n)
{
	int dk = n >> 1;
	while (dk >= 1)
	{
		ShellInsertSort(ar, n, dk);
		dk >>= 1;
	}
}

void test5()
{
	int ar[8] = { 4,3,5,2,0,9,7,1 };
	for (int i = 0; i < 8; ++i)
		cout << ar[i] << " ";
	cout << endl << endl;

	ShellSort(ar, 8);

	cout << " ShellSort for arry:>\n\t";
	for (int i = 0; i < 8; ++i)
		cout << ar[i] << " ";
	cout << endl;
}
/*****************************************************************************/
/*
�鲢����
��������
1���� void Merge(int ar[], int left, int mid, int right)
һ��������mid���ֳ����������֣����������ֶ�Ϊ��������������������������

2���� void MergeSort(int ar[], int left, int right)
��Χ�Ӵ�С�ݹ�
*/


#define __SIZE__ 8
void Merge(int*ar, int left, int mid, int right)
{
	int _other[__SIZE__];
	for (int i = 0; i < __SIZE__; ++i)
		_other[i] = ar[i];

	int start1 = left;
	int start2 = mid + 1;
	int cur = left;

	while (start1 <= mid && start2 <= right)//[]������  �ǵ��ж�����һ����<=  Ҫ���Ƿ�Χ�ڵ����һ��Ԫ��
	{
		if (_other[start1] < _other[start2])
			ar[cur++] = _other[start1++];
		else
			ar[cur++] = _other[start2++];
	}
	while (start1 <= mid)
		ar[cur++] = _other[start1++];
	while (start2 <= right)
		ar[cur++] = _other[start2++];
}
void MergeSort(int*ar, int left, int right)
{
	if (left >= right)
		return;

	int mid = (left + right) / 2;		//(left+right)/2 �� ��left right���������������ʾ��Χ��1/2ʱ����ᷢ�����

	MergeSort(ar, left, mid);			//�ݹ��󲿷�����  
	MergeSort(ar, mid + 1, right);		//�ݹ��Ҳ�������  
	Merge(ar, left, mid, right);      //�ϲ�  
}

void test6()
{
	int ar[8] = { 4,3,5,2,0,9,7,1 };
	for (int i = 0; i < 8; ++i)
		cout << ar[i] << " ";
	cout << endl << endl;

	MergeSort(ar, 0, 7);

	cout << " MergeSort for arry:>\n\t";
	for (int i = 0; i < 8; ++i)
		cout << ar[i] << " ";
	cout << endl;
}
/**********************************************************************************/


/*
������
*/

/***********************************************************************/
void main()
{
	//test1();			//������ ����,ð��
	//cout << endl;

	test2();			//����
	cout << endl;

	//test3();			//ѡ��
	//cout << endl;

	//test4();		//ֱ�Ӳ���
	//cout << endl;

	//test5();			//ϣ��(����)
	//cout << endl;

	//test6();			//�鲢
	//cout << endl;
}



//void test7()/*��ӡ�ַ�����ַ*/
//{
//	char*c = "cadn\0hello";
//	char *str = "string";
//	char str2[] = "string2";
//	char str3[] = { 's','t','r','i','n','g','3','/0' };
//
//	cout << "static_cast<void *>(&c)=" << static_cast<void*>(&c) << endl;
//	cout << "static_cast<void *>(str)=" << static_cast<void*>(str) << endl;
//
//}
