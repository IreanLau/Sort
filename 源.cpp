#include<iostream>
using namespace std;
#define __DEBUG__



//以升序为基准


/**************************************************************************************/

/*单链表排序*/
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
/*冒泡*/
void BubbleSort(Node* pBeign)
{
	if (pBeign == NULL)
		return;
	Node* tail = NULL;/*控制趟数*/
	while (tail != pBeign)
	{
		Node* prev = pBeign;
		Node* cur = prev->next;
		bool flag = true;/*标记 减少无效的比较*/

		while (cur != tail)/*一趟排序*/
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
/*单链表逆直*/
void rever(Node* pBegin)
{
}


/***************************************************************************************/

void unitPrint(int a[], int n, int i) //打印每趟结果
{
	cout << i << ":";
	for (int j = 0; j < 8; j++) {
		cout << a[j] << " ";
	}
	cout << endl;
}
/**************************************************************************************/
/*
快排，交换排序的一种  时间复杂度O(n* lg n)

分三步：
1.选取枢轴
2.用枢轴把元素分开，  左边比他小，右边比他大
3.递归排序，左，右两部分

*/
int GetPart(int ar[], int head, int tail)/*挖坑法*/
{
	int left = head;
	int right = tail - 1;	//以升序，右标记找小的
	int key = ar[left];
	while (left < right)
	{
		while (left < right && ar[right]>key)
			right--;
		if (left < right)
		{
			ar[left] = ar[right];//找到小的 交换， 右边成为一个无用的“坑”
			left++;		//	
		}

		while (left<right && ar[left] < key)
			left++;
		if (left < right)
		{
			ar[right] = ar[left];	//左边成为新的坑
			right--;
		}
	}
	ar[left] = key;				//将枢轴放入最后一个坑中（mid位置）

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
选择：
第一次找最小，与第一个位置交换
第二次从剩下的中找第二小，与第二个位置交换
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
		unitPrint(ar, n, i);		//打印每次的结果
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
插入排序 ， 带有哨兵位

//	(哨兵位)4,3,5,2,0,9,7,1
分两步：
1.从第二个实际的元素出发，从后向前比较，把它插入合适的位置,例如把3插到4的位置，
把4后移，形成3，4，5，2……
3.循环 趟数 从第二个到最后完成插入

总结：从第二个元素到最后，插入其适当位置（要移动大量元素）
*/


void InsertSort(int ar[], int n)
{
	for (int i = 1; i < n; ++i)
	{
		if (ar[i] < ar[i - 1])
		{
			int Guard = ar[i];	//哨兵
			int j = i - 1;
			while (ar[j] > Guard)
			{
				ar[j + 1] = ar[j];
				j--;
			}
			ar[j + 1] = Guard;
		}
		unitPrint(ar, n, i);		//打印每次的结果
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
希尔 （缩小增量）插入		增量序列d = {n/2 ,n/4, n/8 .....1} n为要排序数的个数
*/

/*
待排序：4,3,5,2,0,9,7,1
增量序列 {5，3，1}
*/

void ShellInsertSort(int ar[], int n, int dk)
{
	for (int i = dk; i < n; ++i)
	{
		if (ar[i] < ar[i - dk])
		{
			int j = i - dk;
			int Guard = ar[i];//哨兵
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
归并排序
分两步：
1：》 void Merge(int ar[], int left, int mid, int right)
一个数组由mid划分成左右两部分，并且两部分都为有序，怎样才能让整个数组有序。

2：》 void MergeSort(int ar[], int left, int right)
范围从大到小递归
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

	while (start1 <= mid && start2 <= right)//[]形区间  记得判断条件一定是<=  要考虑范围内的最后一个元素
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

	int mid = (left + right) / 2;		//(left+right)/2 ： 当left right都大于最大整数表示范围的1/2时，则会发生溢出

	MergeSort(ar, left, mid);			//递归左部分排序  
	MergeSort(ar, mid + 1, right);		//递归右部分排序  
	Merge(ar, left, mid, right);      //合并  
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
堆排序
*/

/***********************************************************************/
void main()
{
	//test1();			//单链表 快排,冒泡
	//cout << endl;

	test2();			//快排
	cout << endl;

	//test3();			//选择
	//cout << endl;

	//test4();		//直接插入
	//cout << endl;

	//test5();			//希尔(插入)
	//cout << endl;

	//test6();			//归并
	//cout << endl;
}



//void test7()/*打印字符串地址*/
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
