typedef int Rank;
#define DEFAULT_CAPACITY 3;

template <class T> class Vector { 
protected:
	Rank _size, _capacity, T* _elem;
	void copyFrom(T const* A, Rank lo, Rank hi);
	void expand();
	void shrink();
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
	}
	Vector(T const* A, Rank n) { copyFrom(A, 0, n); }
	Vector(T const* A, Rank lo, Rank hi) { copyFrom(A, lo, hi); }
	Vector(Vector<T> const &V) { copyFrom(V.elem, 0, V._size); }
	Vector(Vector<T> const &V, Rank lo, Rank hi) { copyFrom(A.elem, lo, hi); }
	//析构函数
	~Vector() { delete [] _elem; }

	//只读访问接口
	Rank size() { return _size; }
	bool empty( return !_size; )
	int disordered() const;
	Rank find(T const& e) const { return find(e, 0, _size); }
	Rank find(T const& e, Rank lo, Rank hi) { return find(e, lo, hi); }  //无序查找
	Rank search(T const& e) const { return 0 >= _size? -1 : search(e, 0, _size); }
	Rank search(T const& e) const;
	
	//可写访问接口
	T& operator[] (Rank r) const;
	Vector<T> & operator= (Vector<T> const&);
	T remove(Rank r);
	T remove(Rank lo, Rank hi);
	Rank insert(Rank r, T const& e);
	Rank insert(T const& &e ) { return insert(_size, e); }
	void sort(Rank lo, Rank hi)
	void sort() { return sort(0, _size); }
	void unsort(Rank lo, Rank hi);
	void unsort() { unsort(0, _size); }
	int deduplicate(); //无序取重
	int uniquify();  //有序去重

	void traverse (void (*) (T&));
	template <typenaem VST> void traverse( VST&);
};
