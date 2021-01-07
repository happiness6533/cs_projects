#pragma once
#include "ListDataContainer.h"
#include "SinglyNode.h"
#include "IteratorForSinglyLinkedList.h"

template <typename Data>
class SinglyLinkedList : public ListDataContainer<Data> {
private:
	SinglyNode<Data>* headNodePtr;
	SinglyNode<Data>* currentNodePtr;
	int numOfNodes;
	
public:
	SinglyLinkedList() {
		numOfNodes = 0;
	}

	bool isEmpty() {
		if (numOfNodes == 0) {
			cout << "�̱۸� ��ũ�帮��Ʈ�� ����ֽ��ϴ�. " << endl;
			return true;
		}
		else {
			return false;
		}
	}

	void resetCurrentNodePtr() {
		if (isEmpty() == false) {
			currentNodePtr = headNodePtr;
		}
	}

	Data* searchData(Data* dataPtr) {
		if (numOfNodes == 0) {
			cout << "��ũ�帮��Ʈ�� ����ֽ��ϴ�" << endl;
			return nullptr;
		} 

		resetCurrentNodePtr();
		while (currentNodePtr->getNextNodePtr() != nullptr) {
			if (dataPtr->getKey() == currentNodePtr->getDataPtr()->getKey()) {
				cout << "�����Ͱ� �����մϴ�" << endl;
				return dataPtr;
			}
			else {
				currentNodePtr = currentNodePtr->getNextNodePtr();
			}
		}
		cout << "�����Ͱ� �������� �ʽ��ϴ�" << endl;
		return nullptr;
	}

	bool addData(Data* dataPtr) {
		if (numOfNodes == 0) {
			headNodePtr = new SinglyNode<Data>(dataPtr);
			currentNodePtr = headNodePtr;
			numOfNodes++;
			return true;
		}

		resetCurrentNodePtr();
		Data* searchResult = searchData(dataPtr);
		if (searchResult == nullptr) {
			SinglyNode<Data>* addNode = new SinglyNode<Data>(dataPtr);
			currentNodePtr->setNextNodePtr(addNode);
			return true;
		}
		else {
			cout << "�����Ͱ� �̹� �����Ѵ�" << endl;
			return false;
		}
	}
	
	bool deleteData(Data* dataPtr) {
		if (numOfNodes == 0) {
			cout << "��ũ�帮��Ʈ�� ����ֽ��ϴ�" << endl;
			return false;
		}

		resetCurrentNodePtr();
		Data* searchResult = searchData(dataPtr);
		if (searchResult == nullptr) {
			cout << "������ �����ʹ� �������� �ʴ´�" << endl;
			return false;
		}
		else {
			Data* tempDataPtr = currentNodePtr->getNextNodePtr()->getDataPtr();
			SinglyNode<Data>* tempNodePtr = currentNodePtr->getNextNodePtr()->getNextNodePtr();

			delete currentNodePtr->getDataPtr();
			currentNodePtr->setDataPtr(tempDataPtr);

			delete currentNodePtr->getNextNodePtr();
			currentNodePtr->setNextNodePtr(tempNodePtr);
			return true;
		}
	}

	void display() {
		if (numOfNodes == 0) {
			cout << "��ũ�帮��Ʈ�� ����ֽ��ϴ�" << endl;
		}
		else {
			resetCurrentNodePtr();
			while (currentNodePtr->getNextNodePtr() != nullptr) {
				currentNodePtr->getDataPtr()->display();
				currentNodePtr = currentNodePtr->getNextNodePtr();
			}
			currentNodePtr->getDataPtr()->display();
		}
	}

	Iterator<Data>* makeIterator() {
		resetCurrentNodePtr();
		while (currentNodePtr->getNextNodePtr() != nullptr) {
			currentNodePtr = currentNodePtr->getNextNodePtr();
		}
		currentNodePtr = currentNodePtr->getNextNodePtr();
		Iterator<Data>* iterator = new IteratorForSinglyLinkedList<Data>(headNodePtr, currentNodePtr);
		return iterator;
	}	
};
