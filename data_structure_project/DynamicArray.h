#pragma once
#include "ArrayDataContainer.h"
#include "SortAndSearch.h"

template <typename Data>
class DynamicArray : public ArrayDataContainer<Data> {
private:
	int IndexOfFinalDataPtr;
	int finalIndexOfDynamicArray;
	Data* dynamicArray[];

public:
	DynamicArray() {
		IndexOfFinalDataPtr = -1;
		finalIndexOfDynamicArray = 4;
		dynamicArray = new Data*[finalIndexOfDynamicArray + 1];
	}

	bool isEmpty() {
		if (IndexOfFinalDataPtr == -1) {
			return true;
		}
		else {
			return false;
		}
	}

	bool isFull() {
		if (IndexOfFinalDataPtr == finalIndexOfDynamicArray) {
			return true;
		}
		else {
			return false;
		}
	}

	int searchIndex(Data* dataPtr) {
		quickSort(0, IndexOfFinalDataPtr, dynamicArray);
		int resultIndex = binarySearch(0, IndexOfFinalDataPtr, dynamicArray, dataPtr);
		return resultIndex;
	}

	void addData(Data* dataPtr) {
		if (isEmpty()) {
			dynamicArray[IndexOfFinalDataPtr + 1] = dataPtr;
			IndexOfFinalDataPtr++;
			quickSort(0, IndexOfFinalDataPtr, dynamicArray);
			cout << "������ �߰� ����. " << endl;
		}
		else if (isFull()) {
			int resultIndex = searchIndex(dataPtr);
			if (resultIndex == -1) {
				cout << "������ �߰� ���� : �迭�� �� á���ϴ�. �迭�� ũ�⸦ Ȯ���ŵ�ϴ�. " << endl;
				makeExpandDynamicArrray();
				dynamicArray[IndexOfFinalDataPtr + 1] = dataPtr;
				IndexOfFinalDataPtr++;
				quickSort(0, IndexOfFinalDataPtr, dynamicArray);
				cout << "������ �߰� ����. " << endl;
			}
			else {
				cout << "������ �߰� ���� : �迭�� �����Ͱ� �����մϴ�. " << endl;
			}
		}
		else {
			int resultIndex = searchIndex(dataPtr);
			if (resultIndex == -1) {
				dynamicArray[IndexOfFinalDataPtr + 1] = dataPtr;
				IndexOfFinalDataPtr++;
				quickSort(0, IndexOfFinalDataPtr, dynamicArray);
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
					dynamicArray[i] = dynamicArray[i + 1];
				}
				dynamicArray[IndexOfFinalDataPtr] = nullptr;
				IndexOfFinalDataPtr--;
				cout << "������ ���� ����. " << endl;
			}
			else {
				cout << "������ ���� ���� : �迭�� �����Ͱ� �������� �ʽ��ϴ�. " << endl;
			}
		}
	}

	void displayAll() {
		for (int i = 0; i <= IndexOfFinalDataPtr; i++) {
			if (i != IndexOfFinalDataPtr) {
				dynamicArray[i]->display();
			}
			else {
				dynamicArray[i]->display();
				cout << endl;
			}
		}
	}

	void makeExpandDynamicArrray() {
		Data* copyDynamicArrrayPtr[] = new Data*[finalIndexOfDynamicArray + 5];
		for (int i = 0; i <= IndexOfFinalDataPtr; i++) {
			copyDynamicArrrayPtr[i] = dynamicArray[i];
		}
		delete[] dynamicArray;
		dynamicArray = copyDynamicArrrayPtr;
	}
};