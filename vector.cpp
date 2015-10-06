#ifndef _MY_VECTOR_H
#define _MY_VECTOR_H
#include <string.h>
#include <assert.h>

template<class T>
class MyVector
{
    public:
    class iterator                                  //先实现迭代器
    {
        public:
        iterator():pelem(NULL){}
        iterator(T *pt):pelem(pt){}
        iterator(const iterator &iter);
        iterator& operator = (const iterator &iter);
        iterator& operator = (T *pt);
        ~iterator(){}
        bool operator != (const iterator &iter);
        iterator& operator ++ ();
        iterator& operator ++ (int);
        iterator& operator -- ();
        iterator& operator -- (int);
        iterator  operator + (size_t size);
        iterator  operator - (size_t size);
        iterator& operator -= (size_t size);
        iterator& operator += (size_t size);
        T& operator * ();

        //functions add here
        private:
        T *pelem;
    };


    //constructor
    MyVector():pbuff(NULL),beg(NULL),last(NULL),count(0),capcity(0){}
    MyVector(const MyVector &orig);
    MyVector& operator = (const MyVector &orig);
    ~MyVector();
    //member function
    T& operator [] (size_t index);
    void pushback(const T &mt);
    iterator insert(size_t index,const T &mt);
    iterator insert(const T *phead,const T *pback, iterator p);
    iterator erase(size_t index);
    iterator erase(iterator phead, iterator pback);
    void clear();
    size_t size();
    size_t capacity();
    iterator begin();
    iterator end();

    private:
    void del_buff()
    {
        if(NULL != pbuff)
        {
            delete pbuff;
            pbuff = NULL;
        }
    }
    T *pbuff;//Memory buff for elements
    iterator beg;
    iterator last;
    size_t count;
    size_t capcity;
};
/**MyVector's member functions**/
/**here are the member functions implementations**/
template<class T>
size_t MyVector<T>::size()
{
    return count;
}
template<class T>
size_t MyVector<T>::capacity()
{
    return capcity;
}
template<class T>
MyVector<T>::MyVector(const MyVector<T> &orig)
{
    count = orig.size();
    capcity = 2*count;
    pbuff = new T [count*2];
    size_t totalbytes = count*2*sizeof(T);
    memcpy(pbuff,orig.pbuff,totalbytes);
}
template<class T>
MyVector<T>& MyVector<T>::operator = (const MyVector<T> &orig)
{
    del_buff();
    count = orig.size();
    capcity = 2*count;
    pbuff = new T [count*2];
    size_t totalbytes = count*2*sizeof(T);
    memcpy(pbuff,orig.pbuff,totalbytes);
    return *this;
}
template<class T>
MyVector<T>::~MyVector<T>()
{
    del_buff();
}
template<class T>
T& MyVector<T>::operator[](size_t index)
{
    return pbuff[index];
}
template<class T>
void MyVector<T>::pushback(const T &mt)
{
    if(NULL == pbuff && 0 == count)
    {
        pbuff = new T[(1+count)*2];
        pbuff[0] = mt;
        count++;
        capcity = 2*count;
    }
    else
    {
        if(NULL != pbuff && count == capcity)
        {
            capcity *= 2;
            T *ptem = new T[capcity];
            size_t totalbytes = capcity*sizeof(T);
            memcpy(ptem,pbuff,totalbytes);
            del_buff();
            pbuff = ptem;
            pbuff[count] = mt;
            count ++;
        }
        if(NULL != pbuff && count != capcity)
        {
            pbuff[count] = mt;
            count++;
        }
    }
}
template<class T>
typename MyVector<T>::iterator MyVector<T>::insert(size_t index,const T &mt)
{
    assert(count >= index);

    if(NULL != pbuff && count == capcity)
    {
        capcity *= 2;
        T *ptem = new T[capcity];
        memcpy(ptem,pbuff,capcity*sizeof(T));
        ptem[index] = mt;
        memcpy(&ptem[index+1],(count-index)*sizeof(T));
        del_buff();
        pbuff = ptem;
        count ++;
        typename MyVector<T>::iterator _iter(&pbuff[index]);
        return _iter;
    }
    else if(NULL != pbuff && count != capcity)
    {
        size_t _end = count-1;
        size_t _beg = index;
        for(;_end >= _beg;_end--)
            pbuff[_end+1] = pbuff[_end];
        pbuff[index] = mt;
        count++;
        typename MyVector<T>::iterator _iter(&pbuff[index]);
        return _iter;
    }
}
template<class T>
typename MyVector<T>::iterator MyVector<T>::
	insert(const T *phead,const T *pback,
			 typename MyVector<T>::iterator p)
{
	typename MyVector<T>::iterator _beg = begin(),_end = end();
	size_t insertnum = 0;
	for(;phead != pback;phead++)
		insertnum++;
	phead -= insertnum;
	size_t index = 0;
	for(;_beg != p;_beg++)
		index++;
	if(count +insertnum > capcity && NULL != pbuff)
	{
		capcity = 2*(count +insertnum);
		T *ptem = new T [capcity];
		memcpy(ptem,pbuff,(index)*sizeof(T));
		memcpy(&ptem[index],phead,insertnum*sizeof(T));
		memcpy(&ptem[index+insertnum],&pbuff[index],
				(count-index)*sizeof(T));
		del_buff();
		pbuff = ptem;
		count += insertnum;
		typename MyVector<T>::iterator _iter(&pbuff[index]);
		return _iter;
	}
	else if(count +insertnum <= capcity && NULL != pbuff)
	{
		for(size_t i = insertnum;i != 0;i--,count--)
			pbuff[count+insertnum-1] = pbuff[count-1];
		for(;phead != pback;phead++,p++)
			*p = *phead;
		count += insertnum;

		return p;
	}
	if(NULL == pbuff && 0 == count)
	{
		capcity = 2*insertnum;
		pbuff = new T[capcity];
		memcpy(pbuff,phead,insertnum*sizeof(T));
		count = insertnum;
		typename MyVector<T>::iterator _iter(&pbuff[0]);
		return _iter;
	}
}
template<class T>
typename MyVector<T>::iterator MyVector<T>::erase(size_t index)
{
	T *temp = new T[count-index-1];
	memcpy(temp,&pbuff[index+1],(count-index-1)*sizeof(T));
	memcpy(&pbuff[index],temp,(count-index-1)*sizeof(T));
	pbuff[count-1] = '\0';
	count--;
	delete [] temp;
	typename MyVector<T>::iterator _iter(&pbuff[index]);
	return _iter;
}
template<class T>
typename MyVector<T>::iterator MyVector<T>::
	erase( typename MyVector<T>::iterator phead,
		 typename MyVector<T>::iterator pback)
{
	size_t elemnum = 0;
	size_t _toend = 0;
	for(;phead != pback;phead++)
		elemnum++;
	phead -= elemnum;
	for(;pback != end();pback++)
		_toend++;
	pback -= _toend;
	T *temp = new T[_toend];
	memcpy(temp,&pbuff[count-_toend],_toend*sizeof(T));
	memcpy(&pbuff[count-elemnum-_toend],temp,_toend*sizeof(T));
	memset(&pbuff[count-elemnum],'\0',(count-elemnum)*sizeof(T));
	delete [] temp;
	count -= elemnum;
	return phead;
}
template<class T>
typename MyVector<T>::iterator MyVector<T>::begin()
{
    beg = &pbuff[0];
    return beg;
}
template<class T>
typename MyVector<T>::iterator MyVector<T>::end()
{
    last = &pbuff[count];
    return last;
}
/**nested dependent typeclass**/
/**implementation**/

template<class T>
MyVector<T>::iterator::iterator(const typename MyVector<T>::iterator &iter)
{
    pelem = iter.pelem;
}
template<class T>
typename MyVector<T>::iterator& MyVector<T>::iterator::
    operator = (const typename MyVector<T>::iterator &iter)
{
    pelem = iter.pelem;
    return *this;
}
template<class T>
typename MyVector<T>::iterator& MyVector<T>::iterator::
    operator = (T *pt)
{
    pelem = pt;
    return *this;
}
template<class T>
bool MyVector<T>::iterator::operator !=
    (const typename MyVector<T>::iterator &iter)
{
    if(pelem != iter.pelem)
        return true;
    else
        return false;
}
template<class T>
typename MyVector<T>::iterator& MyVector<T>::iterator::operator ++ ()
{
	++pelem;
    return *this;
}
template<class T>
typename MyVector<T>::iterator& MyVector<T>::iterator::operator ++ (int)
{
	pelem++;
	return *this;
}
template<class T>
typename MyVector<T>::iterator& MyVector<T>::iterator::operator -- (int)
{
    pelem--;
    return *this;
}
template<class T>
typename MyVector<T>::iterator& MyVector<T>::iterator::operator -- ()
{
    --pelem;
    return *this;
}
template<class T>
typename MyVector<T>::iterator& MyVector<T>::iterator::operator += (size_t size)
{
    pelem += size;
    return *this;
}
template<class T>
typename MyVector<T>::iterator& MyVector<T>::iterator::operator -= (size_t size)
{
    pelem -= size;
    return *this;
}
template<class T>
typename MyVector<T>::iterator MyVector<T>::iterator::operator + (size_t size)
{
    pelem += size;
    typename MyVector<T>::iterator _iter(pelem);
    return _iter;
}
template<class T>
typename MyVector<T>::iterator MyVector<T>::iterator::operator - (size_t size)
{
    pelem -= size;
    typename MyVector<T>::iterator _iter(pelem);
    return _iter;
}
template<class T>
T& MyVector<T>::iterator::operator * ()
{
    return *pelem;
}
#endif



//////////另一种实现
template<class Object>
class Vector
{
      public:
             explicit Vector(int initsize=0):theSize(initsize),theCapacity(initsize+SPACE_CAPACITY){
                datas=new Object[theCapacity];
             }
             Vector(const Vector & rhs):datas(NULL){
               operator=(rhs);
             }
             ~Vector()
             {
               delete []datas;
             }
             
             const Vector & operator=(const Vector& rhs)
             {
               if(&rhs!=this)
               {
                 delete []datas;
                 theSize=rhs.size();
                 theCapacity=rhs.capacity();
                 
                 datas=new Object[theCapacity];
                 for(int k=0;k<theSize;++k)
                   datas[k]=rhs.datas[k];
               }
               return *this;
             }
             
             void resize(int newSize)
             {
                  if(newSize>theCapacity)
                    reserve(newSize*2+1);
                  theSize=newSize;
             }
             
             void reserve(int newCapacity)
             {
                  if(newCapacity<theSize) return;
                  
                  Object* olddatas=datas;
                  datas=new Object[newCapacity];
                  
                  for(int k=0;k<theSize;++k)
                    datas[k]=olddatas[k];
                    
                  theCapacity=newCapacity;
                  delete []olddatas;
             }
             
             Object& operator[](int index)
             {
                return datas[index];
             }
             
             const Object& operator[](int index) const
             {
                return datas[index];
             }
             
             bool empty() const     
             {
                return theSize==0;
             }
             int size() const
             {
                 return theSize;
             }
             int capacity() const
             {
                 return theCapacity;
             }
             
             void push_back(const Object & x)           //第一次push_back回发生什么问题
             {
                  if(theSize==theCapacity)
                    reserve(2*theCapacity+1);
                  datas[theSize++]=x;
             }
             
             void pop_back()
             {
                  theSize--;
             }
             
             const Object& back() const
             {
                   return datas[theSize-1];
             }
             
             typedef Object* iterator;
             typedef const Object* const_iterator;
             
             iterator begin()
             {
                return &datas[0];
             }
             const_iterator begin() const
             {
                return &datas[0];
             }
             
             iterator end()
             {
                return &datas[size()];
             }
             const_iterator end() const
             {
                return &datas[size()];
             }
             
             enum {SPACE_CAPACITY=16};
             
      private:
              int theSize;
              int theCapacity;
              Object * datas;
};


template <class T>
class Iterator
{
public:
    Iterator(): m_pData(NULL),m_nSize(0), m_nLen(0)
    {
    }
    virtual ~Iterator()
    {
        if (NULL != m_pData)
        {
            delete[] m_pData;
            m_pData = NULL;
        }
    }
public:
    virtual T* begin() = 0;
    virtual T* end() = 0;
protected:
    int m_nSize;
    int m_nLen;
    T *m_pData;
};
template <class T>
class CMyVector : public Iterator<T>
{
public:
    typedef T* iterator;
public:
    CMyVector(int nSize = 10)
    {
        if (nSize <= 0)
        {
            nSize = 10;
        }
        m_nSize = nSize;
        m_pData = new T[m_nSize];
    }
    ~CMyVector()
    {
    }
public:
    int Length() const
    {
        return m_nLen;
    }
    bool push_back(T obj)
    {
        if (m_nLen >= m_nSize)
        {
            int nSize = m_nSize * 2 + 1;
            T *pTemp = new(nothrow) T[nSize];
            if (!pTemp)
            {
                return false;
            }
            memcpy(pTemp, m_pData, sizeof(T) * m_nLen);        
            delete []m_pData;
            m_pData = pTemp;
            m_nSize = nSize;
        }
        memcpy(m_pData + m_nLen, &obj, sizeof(obj));
        m_nLen++;
        return true;
    }
public:
    virtual T* end()
    {
        return m_pData + m_nLen;
    }
    virtual T* begin()
    {
        return m_pData;
    }
};


int main(int argc, char* argv[])
{
    CMyVector<int> vtData;
    CMyVector<int>::iterator it;
    for (int i = 0; i < 30; i++)
    {
        vtData.push_back(i);
    }
    cout << "vector data: " << endl;
    for (it = vtData.begin(); it != vtData.end(); it++)
    {
        cout << *it << "\t";
    }
    cout << endl;
    return 0;
}