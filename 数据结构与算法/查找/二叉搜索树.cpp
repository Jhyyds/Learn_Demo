#include<iostream>
using namespace std;
typedef char KeyType;                               //设置关键字的类型
typedef char InfoType;                             //设置其他变量的类型
typedef struct
{
    KeyType key;                                   //关键字域
    InfoType otherinfo;                            //其他域
}ElemType;
typedef struct BSTNode
{
    ElemType data;
    struct BSTNode *lchild,*rchild;
}BSTNode,*BSTree;

BSTree Searcc_Bst(BSTree T,KeyType Key)            //二叉搜索树
{
    if(T==NULL) return T;
    if(T->data.key == Key) return T;
    else if(T->data.key<Key)
    return Searcc_Bst(T->rchild,Key);
    else
    return Searcc_Bst(T->lchild,Key);
}
void Insert_Bst(BSTree &T,ElemType e)              //二叉搜索树的插入(插入的是整个data域)
{

    if(T==NULL)
    {
        BSTree S = new BSTNode;
        S->data = e;
        S->lchild = NULL;
        S->rchild = NULL;
        T=S;
    }
    else if(T->data.key<e.key)
    Insert_Bst(T->rchild,e);
    else
    Insert_Bst(T->lchild,e);   
}
void InOrderTraverse(BSTree &T)
{
	if(T)
	{
	InOrderTraverse(T->lchild);
	cout<<T->data.key;
	InOrderTraverse(T->rchild);
	}
}
void Create_Bst(BSTree &T)
{
    T=NULL;                                  //不是空树，不能创建
    ElemType e;
    cin>>e.key;                                  //输入关键字
    while(e.key!='#')
    {
        Insert_Bst(T,e);
        cin>>e.key;      
    }

}
int main()
{
	BSTree T;
	cout<<"请输入若干字符，用回车区分，以#结束输入"<<endl;
	Create_Bst(T);
	cout<<"当前有序二叉树中序遍历结果为"<<endl;
	InOrderTraverse(T);
}

