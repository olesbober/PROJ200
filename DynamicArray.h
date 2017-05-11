// DeichlerRodericLab4aDynamicArray.h
// on 09/11/2016
// Editor(s) used: XCode
// Compiler(s) used: Xcode
// Lab 4 Dynamic Array ADT

#ifndef DeichlerRodericLab4aDynamicArray_h
#define DeichlerRodericLab4aDynamicArray_h

#include <vector>

using namespace std;

template <class T>	//Template Declaration
class DynamicArray	//Class Declaration
{
	T* data;	//Store all of the data
	bool* inUse;	//Check if array component is being used
	int size, capacity;	//hold the size of the array
	void Copy(DynamicArray<T> const&);
	void Delete();
	void SetCapacity(int newCap = 20);
	void GrowArray(int);
	
public:
	static T dummy;	//dummy array
	DynamicArray();	//sets all defaults and eveyrthing else to not in use
	DynamicArray(const DynamicArray<T>&);
	DynamicArray<T>& operator=(const DynamicArray<T> &);
	T operator[](int) const;	//operator[] read access to data that is in use
	T& operator[](int);	//operator[] read & write access to data that is in use
	int Size() const {return size;}	//returns size of array (amount in use)
	int Capacity() const {return capacity;}	//returns capacity (max amount)
	bool ContainsKey(int) const;	//checks if key is in use
	void DeleteKey(int);	//deletes the key (sets to not in use)
	vector<unsigned int> Keys() const;	//returns vector of keys that are in use
	void Clear();	//sets all keys to not in use
	~DynamicArray();
};

template <class T>
T DynamicArray<T>::dummy = T();

//setting defaults for dynamic memeory
template <class T>
DynamicArray<T>::DynamicArray()
{
	size = 0;
	capacity = 5;
	data = new T[capacity];
	inUse = new bool[capacity];
	
}

//Need copy for dynamic memory
template <class T>
DynamicArray<T>::DynamicArray(const DynamicArray<T>& arrayOne)
{
	data = NULL;
	inUse = NULL;
	Copy(arrayOne);
}

//Need delete (destructor) for dynamic memory
template <class T>
DynamicArray<T>::~DynamicArray()
{
	Delete();
}

//need operator = for dynamic memory
template <class T>
DynamicArray<T> & DynamicArray<T>::operator =(const DynamicArray<T> & arrayOne)
{
	if (this != &arrayOne)
	{
		Delete();
		Copy(arrayOne);
	}
	return *this;
}

//read access to data in use or returns dummy
template <class T>
T DynamicArray<T>::operator[](int keyOne) const
{
  if (keyOne < capacity && keyOne >= 0 && inUse[keyOne])
		return data[keyOne];
  else
		return dummy;
}

//read and write access to data in use extends size if not in use
template <class T>
T& DynamicArray<T>::operator[](int keyOne)
{

	if (keyOne + 1 > capacity)
		GrowArray(keyOne);
	else if (keyOne < 0)
	{
		return dummy;
	}
	if (!inUse[keyOne])
		size++;
	inUse[keyOne] = true;
	return data[keyOne];
}

//checks if key is in use
template <class T>
bool DynamicArray<T>::ContainsKey(int keyOne) const
{
	if (keyOne < capacity)
		return inUse[keyOne];
	return false;
}

//deletes the key (sets to not in use)
template <class T>
void DynamicArray<T>::DeleteKey(int keyOne)
{
	if (keyOne < capacity)
	{
		if (inUse[keyOne])
		{
			size--;
			inUse[keyOne] = false;
		}
	}
}

//returns vector of keys that are in use
template <class T>
vector<unsigned int> DynamicArray<T>::Keys() const
{
	vector<unsigned int> one;
	for (unsigned int i = 0; i < capacity; ++i)
		if (inUse[i])
			one.push_back(i);
	return one;
}

//sets all keys to not in use
template <class T>
void DynamicArray<T>::Clear()
{
	for (unsigned int i = 0; i < capacity; ++i)
		inUse[i] = false;
	size = 0;
}

//deep copy
template <class T>
void DynamicArray<T>::Copy(const DynamicArray<T> & arrayOne)
{
	size = arrayOne.size;
	capacity = arrayOne.capacity;
	data = new T[capacity];
	inUse = new bool[capacity];
	for (unsigned int i = 0; i < capacity; ++i)
	{
		inUse[i] = false;
		if (arrayOne.inUse[i])
		{
			inUse[i] = true;
			data[i] = arrayOne.data[i];
		}
	}
}

//deep destruction
template <class T>
void DynamicArray<T>::Delete()
{
	if (data)
	{
		delete[] data;
		data = NULL;
	}
	if (inUse)
	{
		delete inUse;
		inUse = NULL;
	}
	size = capacity = 0;
}

//reset the array to capacity desired
// copies the elements that are still in range
template<class T>
void DynamicArray<T>::SetCapacity(int newCap)
{
	if (newCap == 0)
	{
		Delete();
		return;
	}
	
	T* newData = new T[newCap];
	bool* newInUse = new bool[newCap];
	size = 0;
	
	//if capacity < newCap, newLimit is capacity. Else, newLimit is newCap
	unsigned int newLimit = capacity < newCap ? capacity : newCap;
	for(unsigned int i = 0; i < newLimit; ++i)
	{
		newInUse[i] = inUse[i];
		if( inUse[i] )
		{
			size++;
			newData[i] = data[i];
		}
	}
	if(newLimit < newCap)
	{
		for(unsigned int i = newLimit; i < newCap; ++i)
		{
			newInUse[i] = false;
		}
	}
	
	capacity = newCap;
	if (data)
		delete[] data;
	if (inUse)
		delete[] inUse;
	data = newData;
	inUse = newInUse;
}

template <class T>
void DynamicArray<T>::GrowArray(int indexToGrow)
{
	int newCap = indexToGrow + 1;
	
	T* tempData = new T[newCap];
	bool* tempInUse = new bool[newCap];
	
	for (int i = 0; i < capacity; i++)
	{
		tempData[i] = data[i];
		tempInUse[i] = inUse[i];
	}
	
	delete[] data;
	delete[] inUse;
	
	capacity = newCap;
	data = tempData;
	inUse = tempInUse;
	
	inUse[indexToGrow] = false;	
}

#endif /* DeichlerRodericLab4aDynamicArray_h */
