#pragma once

template <typename Key>
class Data {
private:
	Key key;
	string tag;

public: // �����͸� ��ӹ޴� ���� ������ Ŭ������ �ۼ��ϸ� �θ� �������� �޼ҵ�� ������Ƽ��� �����Ѵ�
	Data(Key key, string tag) {
		this->key = key;
		this->tag = tag;
	}
	virtual ~Data() {};

	Key getKey() {
		return key;
	}

	int compare(Data* dataPtr2) {
		if (typeid(Key) == typeid(int)) {
			if (key < dataPtr2->key) {
				return -1;
			}
			else if (key == dataPtr2->key){
				if (tag == dataPtr2->tag) {
					return 0;
				}
				else if (tag == "Folder") {
					return 1;
				}
				else {
					return -1;
				}
			}
			else {
				return 1;
			}
		} else if (typeid(Key) == typeid(string)) {
			if (key.compare(dataPtr2->key) < 0) {
				return -1;
			}
			else if (key.compare(dataPtr2->key) == 0) {
				if (tag == dataPtr2->tag) {
					return 0;
				}
				else if (tag == "Folder") {
					return 1;
				}
				else {
					return -1;
				}
			}
			else {
				return 1;
			}
		}
		else {
			cout << "compare �޼ҵ带 ����ϱ� ���� Key�� �ڷ����� int, char, string���� ���ѵ˴ϴ�. " << endl;
		}
	}

	virtual void display() {
		cout << key << endl;
	}
};