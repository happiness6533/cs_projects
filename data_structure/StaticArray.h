#pragma once
#include "ArrayDataContainer.h"
#include "SortAndSearch.h"
#include "IteratorForArray.h"

template <typename Data>
class StaticArray : public ArrayDataContainer<Data> {
private:
	const int SIZE = 99;
	int IndexOfFinalDataPtr = -1;
	Data* staticArray[99];

public:
	bool isEmpty() {
		if (IndexOfFinalDataPtr == -1) {
			return true;
		}
		else {
			return false;
		}
	}

	bool isFull() {
		if (IndexOfFinalDataPtr == SIZE - 1) {
			return true;
		}
		else {
			return false;
		}
	}

	int searchIndex(Data* dataPtr) {
		int resultIndex = binarySearch(0, IndexOfFinalDataPtr, staticArray, dataPtr);
		return resultIndex;
	}

	void addData(Data* dataPtr) {
		if (isEmpty()) {
			staticArray[IndexOfFinalDataPtr + 1] = dataPtr;
			IndexOfFinalDataPtr++;
			quickSort(0, IndexOfFinalDataPtr, staticArray);
			cout << "������ �߰� ����. " << endl;
		}
		else if (isFull()) {
			cout << "������ �߰� ���� : �迭�� �� á���ϴ�. " << endl;
		}
		else {
			int resultIndex = searchIndex(dataPtr);
			if (resultIndex == -1) {
				staticArray[IndexOfFinalDataPtr + 1] = dataPtr;
				IndexOfFinalDataPtr++;
				quickSort(0, IndexOfFinalDataPtr, staticArray);
				cout << "������ �߰� ����. " << endl;
			}
			else {
				cout << "������ �߰� ���� : �迭�� �����Ͱ� �����մϴ�. " << endl;
			}
		}
	}

	void deleteData(Data* dataPtr) {
		if (isEmpty()) {
			cout << "������ ���� ���� : ������ ����ֽ��ϴ�. " << endl;
		}
		else {
			int resultIndex = searchIndex(dataPtr);
			if (resultIndex != -1) {
				for (int i = resultIndex; i <= IndexOfFinalDataPtr - 1; i++) {

					staticArray[i] = staticArray[i + 1];
				}
				staticArray[IndexOfFinalDataPtr] = nullptr;
				IndexOfFinalDataPtr--;
			}
			else {
				cout << "������ ���� ���� : �迭�� �����Ͱ� �������� �ʽ��ϴ�. " << endl;
			}
		}
	}

	void displayAll() {
		for (int i = 0; i <= IndexOfFinalDataPtr; i++) {
			if (i != IndexOfFinalDataPtr) {
				staticArray[i]->display();
			}
			else {
				staticArray[i]->display();
				cout << endl;
			}
		}
	}

	IteratorForArray<Data>* makeIterator() {
		Data** startPtr = staticArray;
		Data** endPtr = staticArray + IndexOfFinalDataPtr + 1;
		IteratorForArray<Data>* Iterator = new IteratorForArray<Data>(startPtr, endPtr);
		return Iterator;
	}
};
