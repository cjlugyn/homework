#include"List.h"

template <typename T> void List<T>::init() { //�б���ʼ�����ڴ����б�����ʱͳһ����
    header = new ListNode<T>; trailer = new ListNode<T>; //����ͷ��β�ڱ��ڵ�
    header->succ = trailer; header->pred = NULL; //��ǰ����
    trailer->pred = header; trailer->succ = NULL; //�������
    _size = 0; //��¼��ģ
}

template <typename T> //�����±����������ͨ����ֱ�ӷ����б��ڵ㣨O(r)Ч�ʣ��䷽�㣬����ã�
T& List<T> ::operator[] (Rank r) const { // 0 <= r < size
    ListNodePosi(T) p = first(); //���׽ڵ����
    while (0 < r--) p = p->succ; //˳����r���ڵ㼴��
    return p; //Ŀ��ڵ�
}

template <typename T> //�������б��ڽڵ�p��������trailer����n�����棩ǰ���У��ҵ�����e�������
ListNodePosi(T) List<T>::find(T const& e, Rank n, ListNodePosi(T) p) const {
    while (0 < n--) //��0 <= n <= Rank(p) < _size������p�������n��ǰ������������
        if (e == (p = p->pred)->data) return p; //����ȶԣ�ֱ�����л�ΧԽ��
    return NULL; //pԽ����߽���ζ�������ڲ���e������ʧ��
} //ʧ��ʱ������NULL

template <typename T> ListNodePosi(T) List<T>::insertAsFirst(T const& e)
{
    _size++; return header->insertAsSucc(e);
} // e�����׽ڵ����

template <typename T> ListNodePosi(T) List<T>::insertAsLast(T const& e)
{
    _size++; return trailer->insertAsPred(e);
} // e����ĩ�ڵ����

template <typename T> ListNodePosi(T) List<T>::insert(ListNodePosi(T) p, T const& e)
{
    _size++; return p->insertAsSucc(e);
} // e����p�ĺ�̲���

template <typename T> ListNodePosi(T) List<T>::insert(T const& e, ListNodePosi(T) p)
{
    _size++; return p->insertAsPred(e);
} // e����p��ǰ������

template <typename T> //��e������ǰ�ڵ�֮ǰ�����ڵ�ǰ�ڵ������б��������ڱ�ͷ�ڵ�header��
ListNodePosi(T) ListNode<T>::insertAsPred(T const& e) {
    ListNodePosi(T) x = new ListNode(e, pred, this); //�����½ڵ�
    pred->succ = x; pred = x; //������������
    return x; //�����½ڵ��λ��
}

template <typename T> //��e���浱ǰ�ڵ�֮������ڵ�ǰ�ڵ������б��������ڱ�β�ڵ�trailer��
ListNodePosi(T) ListNode<T>::insertAsSucc(T const& e) {
    ListNodePosi(T) x = new ListNode(e, this, succ); //�����½ڵ�
    succ->pred = x; succ = x; //������������
    return x; //�����½ڵ��λ��
}

template <typename T> //�б��ڲ������������б�����λ��p���n��
void List<T>::copyNodes(ListNodePosi(T) p, Rank n) { // p�Ϸ�����������n-1������
    init(); //����ͷ��β�ڱ��ڵ㲢����ʼ��
    while (n--) { insertAsLast(p->data); p = p->succ; } //������p��n��������Ϊĩ�ڵ����
}

template <typename T> //�����б�����λ��p���n�assert: pΪ�Ϸ�λ�ã���������n-1����̽ڵ㣩
List<T>::List(ListNodePosi(T) p, Rank n) { copyNodes(p, n); }

template <typename T> //���帴���б�L
List<T>::List(List<T> const& L) { copyNodes(L.first(), L._size); }

template <typename T> //����L���Ե�r�����n�assert: r+n <= L._size��
List<T>::List(List<T> const& L, Rank r, Rank n) {
    ListNodePosi(T) p = L.first();
    while (0 < r--) p = p->succ;
    copyNodes(p, n);
}

template <typename T> T List<T>::remove(ListNodePosi(T) p) { //ɾ���Ϸ��ڵ�p����������ֵ
    T e = p->data; //���ݴ�ɾ���ڵ����ֵ���ٶ�T���Ϳ�ֱ�Ӹ�ֵ��
    p->pred->succ = p->succ; p->succ->pred = p->pred; //��̡�ǰ��
    delete p; _size--; //�ͷŽڵ㣬���¹�ģ
    return e; //���ر��ݵ���ֵ
}

template <typename T> List<T>::~List() //�б�������
{
    clear(); delete header; delete trailer;
} //����б����ͷ�ͷ��β�ڱ��ڵ�

template <typename T> int List<T>::clear() { //����б�
    int oldSize = _size;
    while (0 < _size) remove(header->succ); //����ɾ���׽ڵ㣬ֱ���б����
    return oldSize;
}

template <typename T> int List<T>::deduplicate() {
    if (_size < 2) return 0;
    int oldSize = _size; 
    ListNodePosi(T) p = first();
    for (Rank r = 0; p != trailer; p = p->succ) //O(n)
        if (ListNodePosi(T) q = find(p->data, r, p))
            remove(q); //��ʱq��p��ͬ����ɾ��ǰ�߸�Ϊ����
        else r++; //rΪ����ǰ׺�ĳ���
    return oldSize - _size; //ɾ��Ԫ������
}

template <typename T> void List<T>::traverse(void (*visit)(T&)) //��������ָ����Ʊ���
{
    for (ListNodePosi(T) p = header->succ; p != trailer; p = p->succ) visit(p->data);
}

template <typename T> template <typename VST> //Ԫ�����͡�������
void List<T>::traverse(VST& visit) //��������������Ʊ���
{
    for (ListNodePosi(T) p = header->succ; p != trailer; p = p->succ) visit(p->data);
}

template <typename T> Rank List<T>::uniquify() { //�����޳��ظ�Ԫ�أ�Ч�ʸ���
    if (_size < 2) return 0; //ƽ���б���Ȼ���ظ�
    Rank oldSize = _size; //��¼ԭ��ģ
    ListNodePosi(T) p = first(); ListNodePosi(T) q; //pΪ��������㣬qΪ����
    while (trailer != (q = p->succ)) //����������ڵĽڵ��(p, q)
        if (p->data != q->data) p = q; //�����죬��ת����һ����
        else remove(q); //������ͬ��ֱ��ɾ�����ߣ�����������������ӵ����ɾ��
    return oldSize - _size; //�б���ģ�仯��������ɾ��Ԫ������
}

template <typename T> //�������б��ڽڵ�p��������trailer����n�����棩ǰ���У��ҵ�������e�������
ListNodePosi(T) List<T>::search(T const& e, Rank n, ListNodePosi(T) p) const {
    do { // 0 <= n <= Rank(p) < _size
        p = p->pred; n--;  //��������
    } while ((-1 != n) && (e < p->data)); //����Ƚϣ�ֱ�����л�Խ��
    return p; //���ز�����ֹ��λ��
} //ʧ��ʱ������������߽��ǰ����������header�����������߿�ͨ��valid()�жϳɹ����

template <typename T> void List<T>::sort(ListNodePosi(T) p, int n) { //�б���������
    switch (rand() % 4) { //���ѡȡ�����㷨���ɸ��ݾ���������ص����ѡȡ������
    case 1: insertionSort(p, n); break; //��������
    case 2: selectionSort(p, n); break; //ѡ������
    case 3:     mergeSort(p, n); break; //�鲢����
    default:     radixSort(p, n); break; //��������
    }
}

template <typename T> //���б�����ʼ��λ��p������Ϊn����������������
void List<T>::insertionSort(ListNodePosi(T) p, int n) { // valid(p) && Rank(p) + n <= size
    for (Rank r = 0; r < n; r++) { //��һΪ���ڵ�
        insert(search(p->data, r, p), p->data); //�����ʵ���λ�ò�����
        p = p->succ; remove(p->pred); //ת����һ�ڵ�
    }
}

template <typename T> //���б�����ʼ��λ��p������Ϊn��������ѡ������
void List<T>::selectionSort(ListNodePosi(T) p, int n) { // valid(p) && Rank(p) + n <= size
    ListNodePosi(T) head = p->pred, tail = p;
    for (int i = 0; i < n; i++) tail = tail->succ; //����������Ϊ(head, tail)
    while (1 < n) { //�����ٻ�ʣ�����ڵ�֮ǰ���ڴ�����������
        ListNodePosi(T) max = selectMax(head->succ, n); //�ҳ�����ߣ�����ʱ�������ȣ�
        insert(remove(max), tail); //����������������ĩβ����Ϊ���������µ���Ԫ�أ�
        tail = tail->pred; n--;
    }
}

template<typename T> //����ʼ��λ��p��n��Ԫ����ѡ�������
ListNodePosi(T) List<T>::selectMax(ListNodePosi(T) p, int n) {
    ListNodePosi(T) max = p; //������ݶ�Ϊ�׽ڵ�p
    for (ListNodePos(T) cur = p;1 < n; n--) //���׽ڵ�p�������������ڵ���һ��max�Ƚ�
        if (!lt((cur = cur ->succ) ->data, max -> data)) //����ǰԪ�ز�С��max����
            max = cur; //�������Ԫ��λ�ü�¼
    return max; //�������ڵ�λ��
}


template <typename T> //�����б��Ĺ鲢����ǰ�б�����p���n��Ԫ�أ����б�L����q���m��Ԫ�ع鲢
void List<T> ::merge(ListNodePosi(T)& p, int n, List<T>& L, ListNodePosi(T) q, int m) {
    // this.valid(p) && Rank(p) + n <= size && this.sorted(p, n)
    // L.valid(q) && Rank(q) + m <= L._size && L.sorted(q, m)
    // ע�⣺�ڱ�mergeSort()����ʱ��this == &L && Rank(p) + n = Rank(q)
    ListNodePosi(T) pp = p->pred; //�鲢֮��p���ܲ���ָ���׽ڵ㣬�����ȼ��䣬�Ա��ڷ���ǰ����
    while (0 < m) //q��δ���磨����mergeSort()�У�p����δ���磩֮ǰ
        if ((0 < n) && (p->data <= q->data)) //��p��δ������v(p) <= v(q)����
        {
            if (q == (p = p->succ)) break; n--;
        } //pֱ�Ӻ��ƣ�����ɹ���
        else //���򣬽�qת����p֮ǰ������ɹ���
        {
            insert(L.remove((q = q->succ)->pred), p); m--;
        }
    p = pp->succ; //���µ��׽ڵ�
}

template <typename T> //�б��Ĺ鲢�����㷨������ʼ��λ��p��n��Ԫ������
void List<T> ::mergeSort(ListNodePosi(T)& p, int n) { // valid(p) && Rank(p) + n <= size
    if (n < 2) return; //��������Χ���㹻С����ֱ�ӷ��أ�����...
    int m = n >> 1; //���е�Ϊ��
    ListNodePosi(T) q = p; for (int i = 0; i < m; i++) q = q->succ; //�ҵ������б����
    mergeSort(p, m); mergeSort(q, n - m); //ǰ�������б����ֱ�����
    p = merge(p, m, *this, q, n - m); //�鲢
} //ע�⣺�����p��Ȼָ��鲢������ģ��£����