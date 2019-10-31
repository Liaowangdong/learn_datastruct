#include "../Header/vector.h"

template <class T>
void Vector<T>::copyFrom(T const* A, Rank lo, Rank hi)
{
    _elem = new T[_capacity = 2*(hi-lo)];
    _size = 0;
    while( lo++ < hi )
        _elem[_size++] = A[lo];
}

//重载赋值运算符
template <class T>
Vector<T>& Vector<T>::operator=(Vector<T> const& V)
{
    if (_elem) 
        delete [] _elem;
    copyFrom(V._elem, 0, V._size);
    return *this;
}

//重载[]运算符
template <class T>
T& Vector<T>::operator[](Rank r) const
{
    return _elem[r]; //需要满足 0 =< r < _size
}

template <class T>
void Vector<T>::shrink()
{
    if (_size << 2 > _capacity << 1) 
        return;
    T *oldElem = _elem;
    T *_elem = new T[_capacity >>= 1]; //缩小一倍
    int i = 0;
    while (i++ < _size) {
        _elem[i] = oldElem[i]
    }
    delete [] oldElem; 
}

 //无序向量的查找
template <class T>
Rank Vector<T>::find(T const& e, Rank lo, Rank hi) const
{ 
    while( lo < hi && e != _elem[--hi]);
    return hi;
}

 //无序向量的查找
template <class T>
Rank Vector<T>::find(T const& e) const
{ 
    find(e, 0, _size);
}

template <class T>
int Vector<T>::remove(Rank lo, Rank hi)  //删除区间内的元素，返回删除元素的个数
{
    if (lo == hi) 
        return;
    while(hi < _size)
        _elem[lo++] = _elem[hi++];
    _size = lo;
    shrink();
    return hi-lo;
}

template <class T>
T Vector<T>::remove(Rank r)  //删除指定位置的元素
{
    T e = _elem[r];
    remove(r, r+1);
    return e;
}

template <class T>
int Vector<T>::deduplicate()  //去掉无序向量中的重复元素
{
    int oldSize = _size; //计数器，计算去掉重复元素的个数
    for(int i = 1; i < _size; i++)
    {
        find(_elem[i]) >= 0 ? remove(i) : i--;
    }
    return oldSize - _size;
}
