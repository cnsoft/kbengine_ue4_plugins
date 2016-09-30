// Copyright 1998-2016 Epic Games, Inc. All Rights Reserved.

#pragma once

#include "KBECommon.h"

class KBEngineArgs;
class Entity;

/*
这是KBEngine插件的核心模块
包括网络创建、持久化协议、entities的管理、以及引起对外可调用接口。

一些可以参考的地方:
http://www.kbengine.org/docs/programming/clientsdkprogramming.html
http://www.kbengine.org/docs/programming/kbe_message_format.html

http://www.kbengine.org/cn/docs/programming/clientsdkprogramming.html
http://www.kbengine.org/cn/docs/programming/kbe_message_format.html
*/
class KBENGINEPLUGINS_API KBEngineApp
{
public:
	KBEngineApp();
	virtual ~KBEngineApp();

public:
	KBEngineArgs* pArgs;
	
	FString username;
	FString password;

	// 服务端分配的baseapp地址
	FString baseappIP;
	uint16 baseappPort;

	// 服务端与客户端的版本号以及协议MD5
	FString serverVersion;
	FString clientVersion;
	FString serverScriptVersion;
	FString clientScriptVersion;
	FString serverProtocolMD5;
	FString serverEntitydefMD5;

	// 当前玩家的实体id与实体类别
	uint64 entity_uuid;
	int32 entity_id;
	FString entity_type;

	// space的数据，具体看API手册关于spaceData
	// https://github.com/kbengine/kbengine/tree/master/docs/api
	TMap<FString, FString> _spacedatas;
	
	// 所有实体都保存于这里， 请参看API手册关于entities部分
	// https://github.com/kbengine/kbengine/tree/master/docs/api
	TMap<int32, Entity*> entities;

	// 所有服务端错误码对应的错误描述
	TMap<uint16, FKServerErr> serverErrs;

	// 玩家当前所在空间的id， 以及空间对应的资源
	uint32 spaceID;
	FString spaceResPath;
	bool isLoadedGeometry;

	// 按照标准，每个客户端部分都应该包含这个属性
	FString component;

protected:

};
