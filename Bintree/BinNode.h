#pragma once

#define BinNodePosi(T) BinNode<T>* //节点位置
#define stature(p) ( (p) ? (p) -> height : -1 ) // 节点高度（空树高度为-1）

//BinNode状态与性质判断

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
}  RBColor; // 节点颜色 

template <typename T > struct BinNode { //二叉树节点模板类
	//成员 
	T data;
	BinNodePosi(T) parent; BinNodePosi(T) lc; BinNodePosi(T) rc;
	int height;
	int npl;
	RBColor color;

	//构造函数 
	BinNode() :
		parent(NULL), lc(NULL), rc(NULL), height(0), npl(1), color(RB_RED) {

	}

	BinNode(T e, BinNodePosi(T) p = NULL, BinNodePosi(T) lc = NULL, BinNodePosi(T) rc = NULL, int h = 0, int l = 1, RBColor = RB_RED) :
		data(e), parent(p), lc(lc), rc(rc), height(h), npl(l), color(c) {

	}

	//操作接口	

	int size(); //统计当前节点后代数
	BinNodePosi(T) insertAsLC(T const&); //作为当前节点的左孩子插入节点
	BinNodePosi(T) insertAsRC(T const&); //作为当前节点的右孩子插入节点
	BinNodePosi(T) succ(); //取当前节点的直接后继
	template < typename VST > void travLevel(VST&); //子树层次遍历
	template < typename VST > void travPre(VST&); //子树先序遍历
	template < typename VST > void travIn(VST&); //子树中序遍历
	template < typename VST > void travPost(VST&); //子树后序遍历

	// 比较器 
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