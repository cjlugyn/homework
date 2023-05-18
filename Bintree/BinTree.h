#pragma once

#include"BinNode.h"

template <typename T > class BinTree { //������ģ����
protected:
	int _size;
	BinNodePosi(T) _root;
	virtual int updataHeight(BinNodePosi(T) x);
	void updataHeightAbove(BinNodePosi(T) x);

public:
	//����,�������� 
	BinTree() : _size(0), _root(NULL) {
	}
	~BinTree() {
		if (0 < _size) {
			remove(_root);
		}
	}

	//�ӿ� 
	int size() const {
		return _size; //��ģ 
	}
	bool empty() {
		return !_root; //�п� 
	}

	BinNodePosi(T) root() const {
		return _root;
	}
	BinNodePosi(T) insertAsRoot(T const& e); //������ڵ�
	BinNodePosi(T) insertAsLC(BinNodePosi(T) x, T const& e); //����e��Ϊ���� 
	BinNodePosi(T) insertAsRC(BinNodePosi(T) x, T const& e); //����e��Ϊ�Һ��� 
	BinNodePosi(T) attachAsLC(BinNodePosi(T) x, BinTree<T>*& T); //����T��Ϊ������ 
	BinNodePosi(T) attachAsRC(BinNodePosi(T) x, BinTree<T>*& T); //����T��Ϊ������ 

	int remove(BinNodePosi(T) x); //ɾ��xλ�õ����������ظ�����ԭ�ȹ�ģ
	BinTree<T>* secede(BinNodePosi(T) x); //�������ӵ�ǰ��ժ������ת��Ϊһ��������

	//������ 
	template <typename VST>
	void travLevel(VST& visit) { //��α��� 
		if (_root) {
			_root->traveLevel(visit);
		}
	}

	template <typename VST>
	void travPre(VST& visit) { //������� 
		if (_root) {
			_root->travePre(visit);
		}
	}

	template <typename VST>
	void travIn(VST& visit) { //������� 
		if (_root) {
			_root->traveIn(visit);
		}
	}

	template <typename VST>
	void travPost(VST& visit) { //������� 
		if (_root) {
			_root->travePost(visit);
		}
	}

	//�Ƚ���
	bool operator< (BinTree<T> const& t) {
		return _root && t.root && lt(_root, t.root);
	}
	bool operator> (BinTree<T> const& t) {
		return _root && t._root && lt(t._root, _root);
	}

	//�е���	
	bool operator== (BinTree<T> const& t) {
		return _root && t._root && (_root == t._root);
	}


};