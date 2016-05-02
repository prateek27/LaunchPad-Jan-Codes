#ifndef NODE_H
#define NODE_H

template<typename T>
class Node{
public: 
	T data;
	Node<T> *next;
public:
	Node(T d):data(d){}
};

#endif