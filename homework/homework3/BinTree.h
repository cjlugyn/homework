#pragma once

#include"BinNode.h"

template <typename T > class BinTree { //二叉树模板类
protected:
	int _size;
	BinNodePosi(T) _root;
	virtual int updataHeight(BinNodePosi(T) x);
	void updataHeightAbove(BinNodePosi(T) x);

public:
	//构造,析构函数 
	BinTree() : _size(0), _root(NULL) {
	}
	~BinTree() {
		if (0 < _size) {
			remove(_root);
		}
	}

	//接口 
	int size() const {
		return _size; //规模 
	}
	bool empty() {
		return !_root; //判空 
	}

	BinNodePosi(T) root() const {
		return _root;
	}
	BinNodePosi(T) insertAsRoot(T const& e); //插入根节点
	BinNodePosi(T) insertAsLC(BinNodePosi(T) x, T const& e); //插入e作为左孩子 
	BinNodePosi(T) insertAsRC(BinNodePosi(T) x, T const& e); //插入e作为右孩子 
	BinNodePosi(T) attachAsLC(BinNodePosi(T) x, BinTree<T>*& T); //插入T作为左子树 
	BinNodePosi(T) attachAsRC(BinNodePosi(T) x, BinTree<T>*& T); //插入T作为右子树 

	int remove(BinNodePosi(T) x); //删除x位置的子树，返回该子树原先规模
	BinTree<T>* secede(BinNodePosi(T) x); //将子树从当前树摘除，并转化为一个独立树

	//操作器 
	template <typename VST>
	void travLevel(VST& visit) { //层次遍历 
		if (_root) {
			_root->traveLevel(visit);
		}
	}

	template <typename VST>
	void travPre(VST& visit) { //先序遍历 
		if (_root) {
			_root->travePre(visit);
		}
	}

	template <typename VST>
	void travIn(VST& visit) { //中序遍历 
		if (_root) {
			_root->traveIn(visit);
		}
	}

	template <typename VST>
	void travPost(VST& visit) { //后序遍历 
		if (_root) {
			_root->travePost(visit);
		}
	}

	//比较器
	bool operator< (BinTree<T> const& t) {
		return _root && t.root && lt(_root, t.root);
	}
	bool operator> (BinTree<T> const& t) {
		return _root && t._root && lt(t._root, _root);
	}

	//判等器	
	bool operator== (BinTree<T> const& t) {
		return _root && t._root && (_root == t._root);
	}


};