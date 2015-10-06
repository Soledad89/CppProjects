//TrieTreeNode.h
#include<iostream>
#include<fstream>
using namespace std;

template<class T>
class TrieTreeNode
{
public:
	TrieTreeNode()//用于构造根节点
	{
		for (int i = 0; i < MaxBranchNum; i++)
			ChildNodes[i] = NULL;
		word = NULL;
		Freq = 0;
		ID = -1;
	}
	// ~TrieTreeNode() {
	// 	for (int i = 0; i < MaxBranchNum; i++) {
	// 		delete ChildNodes[i];
	// 		ChildNodes[i] = NULL;
	// 	}
	// }
public:
	static const int MaxBranchNum = 26;//最大分支数；
	char* word;//单词字符串的指针
	TrieTreeNode<T>* ChildNodes[MaxBranchNum];
	int Freq;//词频统计
	int ID;//构建TrieTree树时的插入顺序，可用来记录字符串第一次出现的位置
};
//TrieTree.h

template<class T>
class TrieTree
{
	//Insert时为节点代表的单词word分配内存，Delete时只修改Freq而不删除word，Search时以Freq的数值作为判断依据，而不是根据word是否为NULL
public:
	TrieTree(const int size);
	~TrieTree(){ Destroy(root); };//缺省的析构函数
	void Insert(const T* str);//插入单词str
	void Insert(const T* str, const int num);//插入单词str，带有编号信息
	int Search(const T* str);//查找单词str，返回出现次数
	bool Delete(const T* str);//删除单词str
	void PrintALL();//打印trie树中所有节点对应的单词
	void PrintPre(const T* str);//打印以str为前缀的单词
private:
	void Print(const TrieTreeNode<T>* p);
	void Destroy(TrieTreeNode<T>* p);//由析构函数调用，释放以p为根节点的树的空间
private:
	TrieTreeNode<T>* root;
	int MaxBranchNum;//最大分支数
};

template<class T>
void TrieTree<T>::Destroy(TrieTreeNode<T>* p)
{
	if (!p)
		return;
	for (int i = 0; i < MaxBranchNum; i++)
		Destroy(p->ChildNodes[i]);
	if (!p->word)
	{
		delete[] p->word;//只是释放了char数组word的空间，指针word本身的空间未释放，由后续的delete p释放
		p->word = NULL;
	}
	delete p;//释放节点空间
	p = NULL;//节点指针置为空
	//以上的置NULL的两句无太大意义，但是：编程习惯
}

template<class T>
bool TrieTree<T>::Delete(const T* str)
{
	TrieTreeNode<T>* p = root;
	if (!str)
		return false;
	for (int i = 0; str[i]; i++)
	{
		int index = str[i] - 'a';
		if (p->ChildNodes[index])
			p = p->ChildNodes[index];
		else return false;
	}
	p->Freq = 0;
	p->ID = -1;
	return true;
}

template<class T>
void TrieTree<T>::PrintPre(const T* str)
{
	TrieTreeNode<T>* p = root;
	if (!str)
		return;
	for (int i = 0; str[i]; i++)
	{
		int index = str[i] - 'a';
		if (p->ChildNodes[index])
			p = p->ChildNodes[index];
		else return;
	}
	cout << "以" << str << "为前缀的单词有:" << endl;
	Print(p);
}

template<class T>
int TrieTree<T>::Search(const T* str)
{
	TrieTreeNode<T>* p = root;
	if (!str)
		return -1;
	for (int i = 0; str[i]; i++)
	{
		int index = str[i] - 'a';
		if (p->ChildNodes[index])
			p = p->ChildNodes[index];
		else return 0;
	}
	return p->Freq;
}

template<class T>
TrieTree<T>::TrieTree(const int size)
{
	MaxBranchNum = size;
	root = new TrieTreeNode<T>();//根节点不储存字符
}

template<class T>
void TrieTree<T>::Insert(const T* str)
{
	TrieTreeNode<T>* p = root;
	for (int i = 0; str[i]; i++)
	{
		if (str[i]<'a' || str[i]>'z')
		{
			cout << "格式错误！" << endl;
			return;
		}
		int index = str[i] - 'a';//下溯的分支编号
		if (!p->ChildNodes[index])
			p->ChildNodes[index] = new TrieTreeNode<T>();
		p = p->ChildNodes[index];
	}
	if (!p->word)//该词以前没有出现过
	{
		p->word = new char[strlen(str) + 1];
		strcpy_s(p->word, strlen(str) + 1, str);
	}
	p->Freq++;
}

template<class T>
void TrieTree<T>::Insert(const T* str, const int num)
{
	TrieTreeNode<T>* p = root;
	for (int i = 0; str[i]; i++)
	{
		if (str[i]<'a' || str[i]>'z')
		{
			cout << "格式错误！" << endl;
			return;
		}
		int index = str[i] - 'a';//下溯的分支编号
		if (!p->ChildNodes[index])
			p->ChildNodes[index] = new TrieTreeNode<T>();
		p = p->ChildNodes[index];
	}
	if (!p->word)//该词以前没有出现过
	{
		p->word = new char[strlen(str) + 1];
		strcpy_s(p->word, strlen(str) + 1, str);
	}
	p->Freq++;
	if (num < p->ID || p->ID == -1)
		p->ID = num;
}

template<class T>
void TrieTree<T>::PrintALL()
{
	Print(root);
}

template<class T>
void TrieTree<T>::Print(const TrieTreeNode<T>* p)
{
	if (p == NULL)
		return;
	if (p->Freq > 0)
	{
		cout << "单词:" << p->word << "	频数:" << p->Freq;
		if (p->ID >= 0)
			cout << "		ID:" << p->ID;
		cout << endl;
	}
	for (int i = 0; i < MaxBranchNum; i++)
	{
		if (p->ChildNodes[i])
		{
			Print(p->ChildNodes[i]);
		}
	}

}
//main.cpp

void test(TrieTree<char>* t)
{
	char* charbuffer = new char[50];
	char* cb = charbuffer;

	fstream fin("words.txt");
	if (!fin){
		cout << "File open error!\n";
		return;
	}
	char c;
	int num = 0;
	while ((c = fin.get()) != EOF)
	{
		if (c >= '0'&&c <= '9')
			num = num * 10 + c - '0';
		if (c >= 'a'&&c <= 'z')
			*cb++ = c;
		if (c == '\n')
		{
			*cb = NULL;
			t->Insert(charbuffer, num);
			cb = charbuffer;
			num = 0;
		}
	}
	fin.close();
}


void main()
{
	TrieTree<char>* t = new TrieTree<char>(26);
	char* pre = "fu";
	/*char* c1 = "fuck";
	char* c2 = "class";
	char* c3 = "name";
	char* c4 = NULL;
	char* c5 = "fucka";
	char* c6 = "fuckaa";
	char* c7 = "fuckaabc";
	t->Insert(c1);
	t->Delete(c1);
	t->Insert(c1);
	t->Insert(c2);
	t->Insert(c5);
	t->Insert(c6);
	t->Insert(c7);*/
	test(t);
	t->PrintALL();
	cout << endl;
	t->PrintPre(pre);
	//cout << t->Search(c1) << endl;
	system("pause");
}