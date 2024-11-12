// datio.h: interface for the CDATFile class.
//
//////////////////////////////////////////////////////////////////////
#if !defined(AFX_DATIO_H__43AF3EA3_F383_11D3_A667_D7E821528379__INCLUDED_)
#define AFX_DATIO_H__43AF3EA3_F383_11D3_A667_D7E821528379__INCLUDED_

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000


#include <windows.h>
#include "zlib\zlib.h"

class CDATFile  
{
public:

	struct DATFILEDESCRIPTOR {
       BYTE  Type; //���� ��� 1, �� ���� ��������� ����������������. 
       DWORD RealSize; //������ ����� ��� ������������ 
       DWORD PackedSize; //������ ������� ����� 
       DWORD Offset; //����� ����� � ���� �������� �� ������ DAT-�����. 
     };

	bool FindByName(char *fname, DATFILEDESCRIPTOR *pFileDescriptor);
	char m_DATName[256];
	UINT GetRealSize (char *fname);
	HANDLE m_hDat;
	BYTE *m_pDirectoryBuffer;
	BYTE *m_pInBuf;
	bool m_bError;

	UINT FilesTotal;
	signed long int TreeSize;
	UINT DataSize;
	UINT DATSize;
	
	UINT ReadFile(char *fname, BYTE *pBuffer);	
//	void DATInitFail(LPCTSTR string);

	CDATFile(char *dat_filename);
	virtual ~CDATFile();

protected:
	UINT IsNameMatches(BYTE *pDescriptor, char *fname);
	BYTE current_name[256];


};

#endif // !defined(AFX_DATIO_H__43AF3EA3_F383_11D3_A667_D7E821528379__INCLUDED_)


