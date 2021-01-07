#pragma once
#include "Iterator.h"
#include "SinglyNode.h"

// �� ������ �����ε��� �ȵǴ°�?
template <typename Data>
class IteratorForSinglyLinkedList : public Iterator<Data> {
private:
	SinglyNode<Data>* startNodePtr;
	SinglyNode<Data>* endNodePtr;
	SinglyNode<Data>* currentNodePtr;

public:
	IteratorForSinglyLinkedList(SinglyNode<Data>* startNodePtr, SinglyNode<Data>* endNodePtr) {
		this->startNodePtr = startNodePtr;
		this->endNodePtr = endNodePtr;
		currentNodePtr = startNodePtr;
	}

	void getNext() {
		currentNodePtr = currentNodePtr->getNextNodePtr();
	}

	Data* getData() {
		return currentNodePtr->getDataPtr();
	}

	bool hasNext() {
		if (currentNodePtr->getNextNodePtr() != endNodePtr) {
			return true;
		}
		else {
			return false;
		}
	}
};
