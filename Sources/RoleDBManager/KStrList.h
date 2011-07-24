//---------------------------------------------------------------------------
// Sword3 Engine (c) 1999-2000 by Kingsoft
//
// File:	KStrList.h
// Date:	2000.08.08
// Code:	WangWei(Daphnis)
// Desc:	Header File
//---------------------------------------------------------------------------
#ifndef	KStrList_H
#define	KStrList_H
//---------------------------------------------------------------------------
#include "KList.h"
#include "KStrNode.h"
//---------------------------------------------------------------------------
class ENGINE_API KStrList : public KList
{
public:
	KStrNode* Find(char* str);
};
//---------------------------------------------------------------------------
#endif
