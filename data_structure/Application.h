#pragma once
#include <iostream>
#include <string>
using namespace std;

#include "Folder.h"
#include "File.h"

class Application {
private:
//	Folder* rootFolderPtr;
	//Folder* garbageFolderPtr;

//	Folder* currentFolderPtr;

//	Stack<Folder>* frontStackPtr;
//	Stack<Folder>* backStackPtr;

	// ���̳ʸ����� : ����Ʈ���� �������� add delete �ϸ� ������Ʈ : ���ڿ��� �Ǿ�����

public:
	Application();

	void init();

	void addFolder();

	void addFile();

	void deleteFolder();

	void deleteFile();

	void searchFolder();

	void searchFile();

	void openFolder();

	void openFile();

	void goBack();

	void goFront();

	void copyFolder();

	void copyFile();

	void cutAndPasteFolder();

	void cutAndPasteFile();

	void saveAll();

	void perfectDelete();

	void resetAll();

	void recovery();
};