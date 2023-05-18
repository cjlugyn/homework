#include"BinTree.h"

#include"BinTree.h"

template <typename T> int BinTree<T>::updataHeight(BinNodePosi(T) x) {
	return x->height = 1 + max(stature(x->lc), stature(x->rc));
}

template <typename T> void BinTree<T>::updataHeightAbove(BinNodePosi(T) x) {
	while (x) {
		updataHeight(x);
		x = x->parent;
	}
}

//插入节点 
template <typename T> BinNodePosi(T) BinTree<T>::insertAsRoot(T const& e) {
	_size = 1;
	return _root = new BinNode<T>(e);
}

template <typename T> BinNodePosi(T) BinTree<T>::insertAsLC(BinNodePosi(T) x, T const& e) {
	_size++;
	x->insertAsLC(e);
	updataHeightAbove(x);
	return x->lc;
}

template <typename T> BinNodePosi(T) BinTree<T>::insertAsRC(BinNodePosi(T) x, T const& e) {
	_size++;
	x->insertAsRC(e);
	updataHeightAbove(x);
	return x->rc;
}

//接入子树
template <typename T> BinNodePosi(T) BinTree<T>::attachAsLC(BinNodePosi(T) x, BinTree<T>*& S) {
	if (x->lc = S->_root) x->lc->parent = x; //接入
	_size += S->_size; updataHeightAbove(x);
	S->_root = NULL; S->_size = 0; release(S; S = NULL; return x;)
}

template <typename T> BinNodePosi(T) BinTree<T>::attachAsRC(BinNodePosi(T) x, BinTree<T>*& S) {
	if (x->rc = S->_root) x->rc->parent = x; //接入
	_size += S->_size; updataHeightAbove(x);
	S->_root = NULL; S->_size = 0; release(S; S = NULL; return x;)
}

//删除子树
template <typename T> int BinTree<T>::remove(BinNodePosi(T) x) {
	FromParentTo(*x) = NULL;
	updataHeightAbove(x->parent);
	int n = removeAt(x); _size -= n; return n;
}

template <typename T> static int removeAt(BinNodePosi(T) x) {
	if (!x) return 0;
	int n = 1 + removeAt(x->lc) + removeAt(x->rc);
	release(x->data; relseae(x); return n;)
}



//分离子树 
template  <typename T> BinTree<T>* BinTree<T>::secede(BinNodePosi(T) x) {
	FromeParentTo(*x) = NULL;
	updataHeightAbove(x->parent);
	BinTree* S = new BinTree<T>; S->_root = x; x->parent = NULL;
	S->_size = x->size(); _size -= S->_size; return S;
}

//遍历
template <typename T, typename VST>
void travPre_R(BinNodePosi(T) x, VST& visit) {
	if (!x) return;
	visit(x->data);
	travPre_R(x->lc, visit);
	travPre_R(x->rc, visit);
}

template <typename T, typename VST>
void travIn_R(BinNodePosi(T) x, VST& visit) {
	if (!x) return;
	travIn_R(x->lc, visit);
	visit(x->data);
	travIn_R(x->rc, visit);
}

template <typename T, typename VST>
void travPost_R(BinNodePosi(T) x, VST& visit) {
	if (!x) return;
	travPost_R(x->lc, visit);
	travPoet_R(x->rc, visit);
	visit(x->data);
}

template <typename T> BinNodePosi(T) BinNode<T>::succ() {
	BinNodePosi s = this;
	if (rc) {
		s = rc;
		while (HasChild(*s) s = s->lc; )
	}
	else {
		while (IsChild(*s)) s = s->parent; -
			s = s->parent;
	}
	return s;
}

