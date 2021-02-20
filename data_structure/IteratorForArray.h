#pragma once
#include "Iterator.h"
// ���� 2�� �ذ��ؾ� �Ѵ�
// �� ������ �����ε��� �ȵǴ°�?
template <typename Data>
class IteratorForArray : public Iterator<Data>{
private:
	Data** startPtr;
	Data** endPtr;
	Data** currentPtr;

public:
	IteratorForArray(Data** startPtr, Data** endPtr) {
		this->startPtr = startPtr;
		this->endPtr = endPtr;
		currentPtr = startPtr;
	}

	void getNext() {
		this->currentPtr += 1;
	}

	Data* getData() {
		return *(this->currentPtr);
	}

	bool hasNext() {
		if (this->currentPtr + 1 != this->endPtr) {
			return true;
		}
		else {
			return false;
		}
	}
};
