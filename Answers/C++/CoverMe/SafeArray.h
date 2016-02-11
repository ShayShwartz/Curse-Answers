#ifndef _SAFEARRAY_H_
#define _SAFEARRAY_H_

template<class T>
class SafeArray
{
public:
	SafeArray(unsigned int size);
	~SafeArray(void);
	T* getArray()const;
	T& operator[](const unsigned int index);
	T operator++();
	T operator--();
	void SafeArray<T>::print()const;

private:
	unsigned int m_size;
	T* m_array;
	unsigned int m_index;
};



// c'tor & d'tor
template<class T>
SafeArray<T>::SafeArray(unsigned int size) : m_size(size), m_index(0)
{
	if ( size == 0 )
		throw Exception("ERROR: Array size must be bigger then 0.");

	m_array = new T[m_size];
	//Initialized the array from 0 to 4.
	for ( unsigned int i = 0 ; i < m_size ; i++ )
		m_array[i] = i;
	
}

template<class T>
SafeArray<T>::~SafeArray(void)
{
	delete[] m_array;
}


// operator [] overload
template<class T>
T& SafeArray<T>::operator[](const unsigned int index)
{
	if ( index > ( m_size - 1 ) )
		throw Exception("ERROR: array index out of range.");
	
	return m_array[index];
		
}


// operator ++ overload
template<class T>
T SafeArray<T>::operator++()
{
	if ( m_index >= (m_size - 1) )
		throw Exception("ERROR: array index out of range.");
	
	return m_array[++m_index];
}


// operator -- overload
template<class T>
T SafeArray<T>::operator--()
{
	if ( m_index == 0 )
		throw Exception("ERROR: array index out of range.");

	return m_array[--m_index];
}


//return the array.
template<class T>
T* SafeArray<T>::getArray()const { return m_array; }


//create output stream for the array.
template<class T>
std::ostream& operator<<(std::ostream &os, const SafeArray<T>& sArray) { return os << *(sArray.getArray()); }


//Print the array.
template<class T>
void SafeArray<T>::print()const
{
	for ( int i = 0 ; i < m_size ; i++ )
		cout << m_array[i] << " ";

	cout << endl;
}

#endif