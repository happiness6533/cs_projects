#pragma once

#include "Data.h"
#include <string.h>
#include "BinarySearchTree.h"

class File : public Data<string> {
private:
	string nameOfFile;
	string extName;
	char* content;

public:
	File(string nameOfFile, string tag) : Data(nameOfFile, tag) {
		this->nameOfFile = nameOfFile;
	}

	void readFile() {
		// ���̳ʸ� �迭 �������� �о �ֿܼ� �ؽ�Ʈ�� ���
	}

	bool saveFile() {

	}

	bool changeFileOfContent() {

	}

	bool changeFileOfName() {

	}
};