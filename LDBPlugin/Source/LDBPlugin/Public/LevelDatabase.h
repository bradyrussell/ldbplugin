// Fill out your copyright notice in the Description page of Project Settings.

#pragma once
//#include "leveldb/leveldb.h"
#include "leveldb/db.h"
#include "CoreMinimal.h"
#include "LevelDatabase.generated.h"

/**
 * 
 */
UCLASS(BlueprintType)
class LDBPLUGIN_API ULevelDatabase: public UObject
{
	GENERATED_BODY()
public:

	ULevelDatabase();
	~ULevelDatabase();

	UFUNCTION(BlueprintCallable)
	bool Open(FString databaseName, bool bCreateIfNotFound = true);

	UFUNCTION(BlueprintCallable)
	void Put(FString key, FString value);
	void Put(std::string key, std::string value);

	UFUNCTION(BlueprintCallable)
	FString Get(FString key);
	std::string Get(std::string key);

	leveldb::DB* db;
	leveldb::Status status;
};
