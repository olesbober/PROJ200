// PriorityQueue.h
// by Oles Bober and Roderic Deichler
// on 04/13/2016
// Editor(s) used: Code::Blocks
// Compiler(s) used: GNU GCC Compiler
// The header file for the PriorityQueue template class

#ifndef BOBEROLESLAB11APRIORITYQUEUE_H_INCLUDED
#define BOBEROLESLAB11APRIORITYQUEUE_H_INCLUDED

#include <cstdlib>
using namespace std;

template <class T>
class PriorityQueue {
// variables
public:
  static T dummy;
  static const int CAPACITY = 2;
private:
  T* data;
  unsigned int size, capacity;
// functions
public:
  PriorityQueue( int initCap = CAPACITY ); // constructor
  virtual ~PriorityQueue() { clear(); } // destructor
  PriorityQueue( const PriorityQueue<T> & ); // copy constructor
  PriorityQueue<T>& operator=( const PriorityQueue<T> & ); // assignment operator
  void enqueue( const T & ); // adds a value to the queue
  T top() const; // gets the value in the front of the queue
  T dequeue(); // removes the MAX value in the queue
  bool isEmpty() const { return size == 0; } // returns true if the queue is empty, false otherwise
  void clear(); // removes all values from the queue
  unsigned int getSize() const { return size; } // returns the current size of the queue
  unsigned int getCapacity() const { return capacity; } // returns the current capacity of the queue
private:
  void doubleCapacity(); // doubles the capacity of the queue
  void copy( const PriorityQueue<T> & ); // deep copy
};

template<class T>
T PriorityQueue<T>::dummy = T();

// public functions
template <class T>
PriorityQueue<T>::PriorityQueue( int initCap ) {
  size = 0;
  capacity = initCap;
  data = new T[ capacity ];
}

template <class T>
PriorityQueue<T>::PriorityQueue( const PriorityQueue<T> &pq ) {
  data = NULL;
  copy( pq );
}

template <class T>
PriorityQueue<T>& PriorityQueue<T>::operator=( const PriorityQueue<T> &pq ) {
  if( this != &pq ) {
		clear();
		copy( pq );
	}
	return *this;
}

template <class T>
void PriorityQueue<T>::enqueue( const T &t ) {
  unsigned int index = size;
  if( index >= capacity )
    doubleCapacity();
  data[ index ] = t;
  int parentIndex;
  while( true ) {
    parentIndex = ( index + 1 ) / 2 - 1;
    if( parentIndex < 0 )
      break;
    if( data[ parentIndex ] >= data[ index ] )
      break;
    T temp = data[ parentIndex ];
    data[ parentIndex ] = data[ index ];
    data[ index ] = temp;
    index = parentIndex;
  }
  size++;
}

template <class T>
T PriorityQueue<T>::top() const {
  if( !size )
    return dummy;
  return data[ 0 ];
}

template <class T>
T PriorityQueue<T>::dequeue() {
  T firstValue = top();
  unsigned int index = 0, leftChild, rightChild;
  while( true ) {
    leftChild = index * 2 + 1;
    rightChild = index * 2 + 2;
    if( leftChild >= size )
      break;
    if( leftChild == size - 1 || data[ leftChild ] >= data[ rightChild ] ) {
      data[ index ] = data[ leftChild ];
      index = leftChild;
    } else {
      data[ index ] = data[ rightChild ];
      index = rightChild;
    }
  }
  size--;
  data[ index ] = data[ size ];
  unsigned int parentIndex;
  while( 1 ) {
    parentIndex = ( index + 1 ) / 2 - 1;
    if( parentIndex < 0 )
      break;
    if( data[ parentIndex ] >= data[ index ] )
      break;
    T temp = data[ parentIndex ];
    data[ parentIndex ] = data[ index ];
    data[ index ] = temp;
    index = parentIndex;
  }
  return firstValue;
}

template <class T>
void PriorityQueue<T>::clear() {
  if( data ) {
    delete [] data;
    data = NULL;
  }
  size = 0;
  capacity = CAPACITY;
  data = new T[ capacity ];
}

// private functions
template <class T>
void PriorityQueue<T>::doubleCapacity() {
  int newCapacity = capacity * 2;
  T* temp = new T[ newCapacity ];
  for( unsigned int i = 0; i < capacity; i++ ) {
    temp[ i ] = data[ i ];
  }
  capacity = newCapacity;
  delete [] data;
  data = temp;
}

template <class T>
void PriorityQueue<T>::copy( const PriorityQueue<T> &pq ) {
  size = pq.size;
  capacity = pq.capacity;
  data = new T[ capacity ];
  for( unsigned int i = 0; i < capacity; i++ ) {
    data[ i ] = pq.data[ i ];
  }
}

#endif // BOBEROLESLAB11APRIORITYQUEUE_H_INCLUDED
