 #pragma once
#include "GraphNode.h"
#include "Stack.h"
#include "Queue.h"

template <typename Data ,typename Key>
class Graph {
private:
	int numOfNodes;
	GraphNode<Data, Key>** graphNodePtrList;

public:
	void setNodes(int numOfNodes, Data** dataPtrList) {
		this->numOfNodes = numOfNodes;
		graphNodePtrList = new GraphNode<Data, Key>*[numOfNodes];
		for (int i = 0; i < numOfNodes; i++) {
			GraphNode<Data, Key>* graphNodePtr = new GraphNode<Data, Key>(dataPtrList[i]);
			graphNodePtrList[i] = graphNodePtr;
		}
	}
	
	void setEdges(Data* dataPtr1, Data* dataPtr2) {
		for (int i = 0; i < numOfNodes; i++) {
			GraphNode<Data, Key>* graphNodePtr1 = graphNodePtrList[i];
			if (graphNodePtr1->getKey() == dataPtr1->getKey()) {
				for (int j = 0; j < numOfNodes; j++) {
					GraphNode<Data, Key>* graphNodePtr2 = graphNodePtrList[j];
					if (graphNodePtr2->getKey() == dataPtr2->getKey()) {
						cout << graphNodePtr1->getKey() << ", " << dataPtr1->getKey() << endl;
						cout << graphNodePtr2->getKey() << ", " << dataPtr2->getKey() << endl;
						graphNodePtr1->addAdjacentNode(graphNodePtr2);
					}					
				}
			}
		}
	}

	void resetVisitStatus() {
		for (int i = 0; i < numOfNodes; i++) {
			graphNodePtrList[i]->setVisitStatus(false);
		}
	}

	void dfsDisplayAndReset() {
		Stack<GraphNode<Data, Key>>* dfsStackPtr = new Stack<GraphNode<Data, Key>>();
		dfsStackPtr->push(graphNodePtrList[0]);
		graphNodePtrList[0]->setVisitStatus(true);// ���ÿ� ���� ������ visit���� �Ѵ�?

		while(dfsStackPtr->isEmpty() != true) {
			GraphNode<Data, Key>* graphNodePtr = dfsStackPtr->pop();
			graphNodePtr->display();

			DoublyLinkedList<GraphNode<Data, Key>>* adjacentNodeList = graphNodePtr->getAdjacentNodeList();
			DoublyNode<GraphNode<Data, Key>>* adjacentCurrentNodePtr = adjacentNodeList->getHeadNodePtr();
			if (adjacentCurrentNodePtr != nullptr) {
				while (adjacentCurrentNodePtr->getNextNodePtr() != nullptr) {
					if (adjacentCurrentNodePtr->getDataPtr()->getVisitStatus() == false) {
						dfsStackPtr->push(adjacentCurrentNodePtr->getDataPtr());
						adjacentCurrentNodePtr->getDataPtr()->setVisitStatus(true);// ���ÿ� ���� ������ visit���� �Ѵ�?
					}
					adjacentCurrentNodePtr = adjacentCurrentNodePtr->getNextNodePtr();
				}
				if (adjacentCurrentNodePtr->getDataPtr()->getVisitStatus() == false) {
					dfsStackPtr->push(adjacentCurrentNodePtr->getDataPtr());
					adjacentCurrentNodePtr->getDataPtr()->setVisitStatus(true); // ���ÿ� ���� ������ visit���� �Ѵ�?
				}
			}
		}
		resetVisitStatus();
	}

	void dfsRecursiveDisplay(Data* dataPtr) {
		GraphNode<Data, Key>* currentGraphNodePtr = nullptr;
		for (int i = 0; i < numOfNodes; i++) {
			if (graphNodePtrList[i]->getKey() == dataPtr->getKey()) {
				currentGraphNodePtr = graphNodePtrList[i];
				currentGraphNodePtr->setVisitStatus(true);
				currentGraphNodePtr->display();
				break;
			}
		}
		DoublyLinkedList<GraphNode<Data, Key>>* adjacentNodeList = currentGraphNodePtr->getAdjacentNodeList();
		DoublyNode<GraphNode<Data, Key>>* adjacentCurrentNodePtr = adjacentNodeList->getHeadNodePtr();
		if (adjacentCurrentNodePtr != nullptr) {
			while (adjacentCurrentNodePtr->getNextNodePtr() != nullptr) {
				if (adjacentCurrentNodePtr->getDataPtr()->getVisitStatus() == false) {
					Data* dataPtr = adjacentCurrentNodePtr->getDataPtr()->getDataPtr();
					dfsRecursiveDisplay(dataPtr);
				}
				adjacentCurrentNodePtr = adjacentCurrentNodePtr->getNextNodePtr();
			}
			if (adjacentCurrentNodePtr->getDataPtr()->getVisitStatus() == false) {
				Data* dataPtr = adjacentCurrentNodePtr->getDataPtr()->getDataPtr();
				dfsRecursiveDisplay(dataPtr);
			}
		}
	}

	void dfsRecursiveDisplayAndReset(Data* dataPtr) {
		dfsRecursiveDisplay(dataPtr);
		resetVisitStatus();
	}

	void bfsDisplayAndReset() {
		Queue<GraphNode<Data, Key>>* bfsQueuePtr = new Queue<GraphNode<Data, Key>>();
		bfsQueuePtr->push(graphNodePtrList[0]);
		graphNodePtrList[0]->setVisitStatus(true); // ť�� ���� ������ visit���� �Ѵ�?


		while (bfsQueuePtr->isEmpty() != true) {
			GraphNode<Data, Key>* graphNodePtr = bfsQueuePtr->pop();
			graphNodePtr->display();

			DoublyLinkedList<GraphNode<Data, Key>>* adjacentNodeList = graphNodePtr->getAdjacentNodeList();
			DoublyNode<GraphNode<Data, Key>>* adjacentCurrentNodePtr = adjacentNodeList->getHeadNodePtr();
			if (adjacentCurrentNodePtr != nullptr) {
				while (adjacentCurrentNodePtr->getNextNodePtr() != nullptr) {
					if (adjacentCurrentNodePtr->getDataPtr()->getVisitStatus() == false) {
						bfsQueuePtr->push(adjacentCurrentNodePtr->getDataPtr());
						adjacentCurrentNodePtr->getDataPtr()->setVisitStatus(true);// ť�� ���� ������ visit���� �Ѵ�?
					}
					else {
						cout << "�湮 �̹� ��" << endl;
					}
					adjacentCurrentNodePtr = adjacentCurrentNodePtr->getNextNodePtr();
				}
				if (adjacentCurrentNodePtr->getDataPtr()->getVisitStatus() == false) {
					bfsQueuePtr->push(adjacentCurrentNodePtr->getDataPtr());
					adjacentCurrentNodePtr->getDataPtr()->setVisitStatus(true);// ť�� ���� ������ visit���� �Ѵ�?
				}
			}
		}
		resetVisitStatus();
	}
};
