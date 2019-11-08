#include<iostream>
typedef int Rank;
#define DEFAULT_CAPACITY 3
using namespace std;

template <class T> class Vector { 
protected:
	Rank _size;
	int _capacity;
	T *_elem;
	void copyFrom(T const* A, Rank lo, Rank hi)
	{
		_elem = new T[_capacity = 2*(hi-lo)];
		_size = 0;
		while( lo++ < hi )
			_elem[_size++] = A[lo];
	}

	void expand()
	{
		if (_size < _capacity) 
			return;
		if (_capacity < DEFAULT_CAPACITY)
			_capacity = DEFAULT_CAPACITY;
		T *oldElem = _elem;
		_elem = new T[_capacity <<= 1]; //扩大一倍
		int i = 0;
		while (i< _size) {
			_elem[i] = oldElem[i];
			i++;
		}
		delete [] oldElem;
	} //OK

	void shrink()
	{
		if (_size << 2 > _capacity << 1) 
			return;
		T *oldElem = _elem;
		_elem = new T[_capacity >>= 1]; //缩小一倍
		int i = 0;
		while (i < _size) {
			_elem[i] = oldElem[i];
			i++;
		}
		delete [] oldElem; 
	}

	bool bubble(Rank lo, Rank hi)
    {
	    bool sorted = true;
	    for(int i = lo+1; i < hi; i++)
        {
	        if( _elem[i-1] > _elem[i]){
                sorted = false;
                swap(_elem[i-1], _elem[i]);
	        }
        }
	    return sorted;
    }

	void bubbleSort(Rank lo, Rank hi){
	    while(!bubble(lo, hi--));
	}

	Rank max(Rank lo, Rank hi);
	void selectionSort(Rank lo, Rank hi);
	void merge(Rank lo, Rank mi, Rank hi) {
	    T *start = _elem + lo;
	    int preLen = mi - lo;
	    int behindLen = hi - mi;
        T *pre = new T[preLen];
        T *behind = _elem + mi;
        for(int i = 0; i < preLen; i++)
            pre[i] = start[i];

	    int i = 0, j = 0;
	    int k = 0;
	    while (i < preLen && j < behindLen) {
	        if(pre[i] < behind[j]) {
                start[k++] = pre[i++];
            }
	        else
                start[k++] = behind[j++];
	    }
	    if (i == preLen) {
	        while(j < behindLen)
	            start[k++] = behind[j++];
	    }
	    else {
            while(i < preLen)
                start[k++] = pre[i++];
	    }
	    delete[] pre;
	}

	void mergeSort(Rank lo, Rank hi) { //对区间[lo, hi)进行排序
	    if (hi - lo < 2)
	        return;
	    int mid = (lo + hi) / 2;
	    mergeSort(lo, mid);
	    mergeSort(mid, hi);
	    merge(lo, mid, hi);
	}
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

	Rank find(T const& e) const
	{ 
		return find(e, 0, _size);
	}

	Rank find(T const& e, Rank lo, Rank hi) const
	{ 
		while( lo < hi && e != _elem[--hi]);
		return hi;
	}
	Rank search(T const& e) const { return 0 >= _size? -1 : search(e, 0, _size); }
	Rank search(T const& e, Rank lo, Rank hi) const;
	int getCapacity() { return _capacity; };

	//可写访问接口
	T& operator[](Rank r) const
	{
		return _elem[r]; //需要满足 0 =< r < _size
	}

	Vector<T>& operator=(Vector<T> const& V)
	{
		if (_elem) 
			delete [] _elem;
		copyFrom(V._elem, 0, V._size);
		return *this;
	}

	T remove(Rank r)  //删除指定位置的元素
	{
		T e = _elem[r];
		remove(r, r+1);
		return e;
	}

	int remove(Rank lo, Rank hi)  //删除区间[lo,hi)内的元素，返回删除元素的个数
	{
		if (lo == hi) 
			return 0;
		while(hi < _size)
			_elem[lo++] = _elem[hi++];
		_size = lo;
		shrink();
		return hi-lo;
	}

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

	Rank insert(T e)
	{
		return insert(_size, e);
	}  //OK
	
	Rank push(T const& e) { return insert(_size, e); } //OK
	void sort(Rank lo, Rank hi)
    {
        mergeSort(lo, hi);
//	    int key = rand() % 5;
//	    key = 1;
//	    switch( key ) {
//	        case 1: bubbleSort(lo, hi); break;
//	        case 2: selectionSort(lo, hi); break;
//	        case 3: mergeSort(lo, hi); break;
//	        case 4: heapSort(lo, hi); break;
//	        default: quickSort(lo, hi); break;
//	    }
    }

	void sort() { return sort(0, _size); }
	void unsort(Rank lo, Rank hi);
	void unsort() { unsort(0, _size); }

	int deduplicate()  //去掉无序向量中的重复元素
	{
		int oldSize = _size; //计数器，计算去掉重复元素的个数
		for(int i = 1; i < _size; i++)
		{
			find(_elem[i]) >= 0 ? remove(i) : i--;
		}
		return oldSize - _size;
	}

	int uniquify()  //有序去重
    {
	    int i = 0, j = 0; //定义一个快一个慢的“指针”
	    int count = 0; //去重元素的个数
	    while (j < _size) {
	        if (_elem[i] == _elem[j]) {
                j++;
	        }
	        else {
	            remove(i+1, j);
                count += j - i - 1;
	            i = j;
	        }
	    }
	    return count;
    }

    //查找算法
    Rank binSearchVa(T const&e, Rank lo, Rank hi)
    {
        while (lo < hi) {
            int mid = (lo + hi) / 2;
            if (_elem[mid] > e)
                hi = mid;
            else if (_elem[mid] < e)
                lo = mid + 1;
            else
                return mid;
        }
        return -1;
    }

    //这是对二分查找的改进，将三支变成两支,缺点，当命中mid时不能提前结束
    Rank binSearchVb(T const&e, Rank lo, Rank hi)
    {
        while (1 < hi - lo) {
            int mid = (lo + hi) / 2;
            e < _elem[mid] ? hi = mid : lo = mid;
        }
        return (e == _elem[lo]) ? lo : -1;
    }

    //这也是对二分查找的升级版，返回的总是不大于目标元素e的最大元素的秩
    Rank binSearchVc(T const&e, Rank lo, Rank hi)
    {
        while (lo < hi) {
            int mid = (lo + hi) / 2;
            e < _elem[mid] ? hi = mid : lo = mid + 1;
        }
        return --lo;
    }

    Rank binSearchVa(T const&e)
    {
        return _size <= 0 ? -1 : binSearchVa(e, 0, _size);
    }

    Rank binSearchVb(T const&e)
    {
        return _size <= 0 ? -1 : binSearchVb(e, 0, _size);
    }

    Rank binSearchVc(T const&e)
    {
        return _size <= 0 ? -1 : binSearchVc(e, 0, _size);
    }

	void traverse (void (*) (T&));
	template <typename VST> void traverse( VST&);

};
