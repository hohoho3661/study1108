#include "stdafx.h"
#include "TextData.h"



TextData::TextData()
{
}


TextData::~TextData()
{
}

bool TextData::Init()
{
	return true;
}

void TextData::Release()
{
	getSingleton()->releaseSingleton();
}

void TextData::txtSave(const TCHAR * saveFileName, vector<string> vStr)	// vector�� ����ִ� �ڷḦ ���Ϸ� ������ ���� �۾�,,
{
	HANDLE	file;
	TCHAR	str[128];
	DWORD	write;

	_tcsncpy_s(str, 128, vectorArrayCombine(vStr), 126);

	// ������ api�� ����
	//                �����̸� ,     ������ ���,  ������� �Ұ���, ���� �Ӽ�, �������,       ���ϼӼ�,               ���ø�����
	file = CreateFile(saveFileName, GENERIC_WRITE, NULL,         NULL,      CREATE_ALWAYS, FILE_ATTRIBUTE_NORMAL, NULL); // ������ �ڵ��� ���
	//        �ڵ�, ����, ����Ʈ, ���ۻ�����, lpOverlapped
	WriteFile(file, str, 128,    &write,    NULL);																// ���� �ڵ�� ���
	CloseHandle(file);																						// ���� �ݱ�


	//// �� ��Ÿ�� ������ ����
	//FILE*	pf;
	//fopen_s(&pf, "���", "���");
	//fread(buffer, ������, ī��Ʈ, pf);
	//fwrite(buffer, ������, ī��Ʈ, pf);
	//fclose(pf);
}

TCHAR * TextData::vectorArrayCombine(vector<string> vArray) // ���͸� ��Ʈ������ �������,,    ����?
{
	char str[128];				// ������ ������ �ִ�. --> ����ū ������
	ZeroMemory(str, sizeof(str));

	for (int i = 0; i < vArray.size(); i++)
	{
		_tcsncat_s(str, 128, vArray[i].c_str(), 126);

		if (i + 1 < vArray.size())
		{
			_tcscat_s(str, sizeof(str), ",");
		}
	}
	
	return str;
}

vector<string> TextData::txtLoad(const TCHAR * loadFileName)
{
	HANDLE	file;
	char	str[128];
	DWORD	read;

	file = CreateFile(loadFileName, GENERIC_READ, FALSE, NULL, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL);

	ReadFile(file, str, 128, &read, NULL);

	CloseHandle(file);

	return charArraySeparation(str);
}

vector<string> TextData::charArraySeparation(TCHAR charArray[])
{
	vector<string> vArray;

	const TCHAR* separator = TEXT(","); // �и� ��ȣ�� ����
	TCHAR* token;

	token = _tcstok(charArray, separator);
	vArray.push_back(token);
	while (NULL != (token = _tcstok(NULL, separator)))
	{
		vArray.push_back(token);
	}
	
	return vArray;	
}

string TextData::GetINIFileInfo(const TCHAR * pszSection, const TCHAR * pszKey, const TCHAR * pszFile)
{
	return string();
}

void TextData::SetINIFileInfo(const TCHAR * pszSection, const TCHAR * pszKey, const TCHAR * pszData, const TCHAR * pszFile)
{
}
