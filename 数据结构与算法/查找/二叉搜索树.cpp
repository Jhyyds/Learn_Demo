#include<iostream>
using namespace std;
typedef char KeyType;                               //���ùؼ��ֵ�����
typedef char InfoType;                             //������������������
typedef struct
{
    KeyType key;                                   //�ؼ�����
    InfoType otherinfo;                            //������
}ElemType;
typedef struct BSTNode
{
    ElemType data;
    struct BSTNode *lchild,*rchild;
}BSTNode,*BSTree;

BSTree Searcc_Bst(BSTree T,KeyType Key)            //����������
{
    if(T==NULL) return T;
    if(T->data.key == Key) return T;
    else if(T->data.key<Key)
    return Searcc_Bst(T->rchild,Key);
    else
    return Searcc_Bst(T->lchild,Key);
}
void Insert_Bst(BSTree &T,ElemType e)              //�����������Ĳ���(�����������data��)
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
    T=NULL;                                  //���ǿ��������ܴ���
    ElemType e;
    cin>>e.key;                                  //����ؼ���
    while(e.key!='#')
    {
        Insert_Bst(T,e);
        cin>>e.key;      
    }

}
int main()
{
	BSTree T;
	cout<<"�����������ַ����ûس����֣���#��������"<<endl;
	Create_Bst(T);
	cout<<"��ǰ�������������������Ϊ"<<endl;
	InOrderTraverse(T);
}

