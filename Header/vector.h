#include<iostream>
typedef int Rank;
#define DEFAULT_CAPACITY 3
using namespace std;

template <class T> class Vector { 
protected:
	Rank _size;
	int _capacity;
	T *_elem;
	void copyFrom(T const* A, Rank lo, Rank hi);   //OK
	void expand()
	{
		if (_size < _capacity) 
			return;
		if (_capacity < DEFAULT_CAPACITY)
			_capacity = DEFAULT_CAPACITY;
		T *oldElem = _elem;
		T *_elem = new T[_capacity <<= 1]; //扩大一倍
		cout << "_capacity: " << _capacity << endl;
		int i = 0;
		while (i++ < _size) {
			_elem[i] = oldElem[i];
		}
		delete [] oldElem;
	} //OK
	void shrink();  //OK
	bool bubble(Rank lo, Rank hi);
	void bubbleSort(Rank lo, Rank hi);
	Rank max(Rank lo, Rank hi);
	void selectionSort(Rank lo, Rank hi);
	void merge(Rank lo, Rank hi);
	void mergeSort(Rank lo, Rank hi);
	Rank partition(Rank lo, Rank hi);
	void quickSort(Rank lo, Rank hi);
	void heapSort(Rank lo, Rank hi);		

public:
	//构造函数
	Vector(int c = DEFAULT_CAPACITY, int s = 0, T v = 0 )
	{
		
		_elem = new T[_capacity];
		_size = s;
		_capacity = c;
	}  //OK
	Vector(T const* A, Rank n) { copyFrom(A, 0, n); }  //OK
	Vector(T const* A, Rank lo, Rank hi) { copyFrom(A, lo, hi); }  //OK
	Vector(Vector<T> const &V) { copyFrom(V.elem, 0, V._size); }   //OK
	Vector(Vector<T> const &V, Rank lo, Rank hi) { copyFrom(V.elem, lo, hi); }   //OK
	//析构函数
	~Vector() { delete [] _elem; }

	//只读访问接口
	Rank size() { return _size; } //OK
	bool empty() { return !_size; } //OK
	int disordered() const;
	Rank find(T const& e) const { return find(e, 0, _size); } //OK
	Rank find(T const& e, Rank lo, Rank hi) const;  //无序查找  //OK
	Rank search(T const& e) const { return 0 >= _size? -1 : search(e, 0, _size); }
	Rank search(T const& e, Rank lo, Rank hi) const;
	int getCapacity() { return _capacity; };

	//可写访问接口
	T& operator[] (Rank r) const;  //OK
	Vector<T> & operator= (Vector<T> const&); //OK
	T remove(Rank r); //OK
	int remove(Rank lo, Rank hi); //OK
	Rank insert(Rank r, T e)
	{
		expand();
		for(int i=_size; i > r; i--)
		{
			_elem[i] = _elem[i-1];
		}
		_elem[r] = e;
		_size++;
		return r;
	}  //OK
	Rank push(T const& e) { return insert(_size, e); } //OK
	void sort(Rank lo, Rank hi);
	void sort() { return sort(0, _size); }
	void unsort(Rank lo, Rank hi);
	void unsort() { unsort(0, _size); }
	int deduplicate(); //无序去重
	int uniquify();  //有序去重

	void traverse (void (*) (T&));
	template <typename VST> void traverse( VST&);

};
