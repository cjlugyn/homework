#pragma once

#define BinNodePosi(T) BinNode<T>* //�ڵ�λ��
#define stature(p) ( (p) ? (p) -> height : -1 ) // �ڵ�߶ȣ������߶�Ϊ-1��

//BinNode״̬�������ж�

#define IsRoot(x) ( ! ( (x).parent ) )
#define IsLChild(x) ( ! IsRoot(x) && ( & (x) == (x).parent->lc ) )
#define IsRChild(x) ( ! IsRoot(x) && ( & (x) == (x).parent->rc ) )
#define HasParent(x) (! IsRoot(x) )
#define HasLChild(x) ( (x).lc )
#define HasRChild(x) ( (x).rc )
#define HasChild(x) ( HasLChild(x) || HasRChild(x) )
#define HasBothChild(x) ( HasLChild(x) && HasRChild(x) )
#define IsLeaf(x) ( ! HasChild(x) )




typedef enum {
	RB_RED, RB_BLACK,
}  RBColor; // �ڵ���ɫ 

template <typename T > struct BinNode { //�������ڵ�ģ����
	//��Ա 
	T data;
	BinNodePosi(T) parent; BinNodePosi(T) lc; BinNodePosi(T) rc;
	int height;
	int npl;
	RBColor color;

	//���캯�� 
	BinNode() :
		parent(NULL), lc(NULL), rc(NULL), height(0), npl(1), color(RB_RED) {

	}

	BinNode(T e, BinNodePosi(T) p = NULL, BinNodePosi(T) lc = NULL, BinNodePosi(T) rc = NULL, int h = 0, int l = 1, RBColor = RB_RED) :
		data(e), parent(p), lc(lc), rc(rc), height(h), npl(l), color(c) {

	}

	//�����ӿ�	

	int size(); //ͳ�Ƶ�ǰ�ڵ�����
	BinNodePosi(T) insertAsLC(T const&); //��Ϊ��ǰ�ڵ�����Ӳ���ڵ�
	BinNodePosi(T) insertAsRC(T const&); //��Ϊ��ǰ�ڵ���Һ��Ӳ���ڵ�
	BinNodePosi(T) succ(); //ȡ��ǰ�ڵ��ֱ�Ӻ��
	template < typename VST > void travLevel(VST&); //������α���
	template < typename VST > void travPre(VST&); //�����������
	template < typename VST > void travIn(VST&); //�����������
	template < typename VST > void travPost(VST&); //�����������

	// �Ƚ��� 
	bool operator< (BinNode const& bn) {
		return data < bn.data;
	}
	bool operator == (BinNode const& bn) {
		return data == bn.data;
	}
	bool operator> (BinNode const& bn) {
		return data > bn.data;
	}
};