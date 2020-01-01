// Fill out your copyright notice in the Description page of Project Settings.


#include "LevelDatabase.h"
#include "Misc/Paths.h"


ULevelDatabase::ULevelDatabase() {

}

ULevelDatabase::~ULevelDatabase() { delete db; }

bool ULevelDatabase::Open(FString databaseName, bool bCreateIfNotFound) {
	leveldb::Options options;
	options.create_if_missing = bCreateIfNotFound;

	FString fullDBname = FPaths::ProjectSavedDir() + databaseName;

	status = leveldb::DB::Open(options, std::string(TCHAR_TO_UTF8(*fullDBname)), &db);
	return status.ok();
}

void ULevelDatabase::Put(FString key, FString value) { status = db->Put(leveldb::WriteOptions(), std::string(TCHAR_TO_UTF8(*key)), std::string(TCHAR_TO_UTF8(*value))); }

void ULevelDatabase::Put(std::string key, std::string value) {
	if (db)
		status = db->Put(leveldb::WriteOptions(), key, value);
	else
	UE_LOG(LogTemp, Warning, TEXT("Error DB is invalid."));
}

FString ULevelDatabase::Get(FString key) {
	std::string out;
	status = db->Get(leveldb::ReadOptions(), std::string(TCHAR_TO_UTF8(*key)), &out);
	return FString(out.c_str());
}

std::string ULevelDatabase::Get(std::string key) {
	std::string out;
	status = db->Get(leveldb::ReadOptions(), key, &out);
	return out;
}

FString ULevelDatabase::GetChecked(FString key, bool& success) {
	std::string out;
	if(!db) {
		success = false;
		return FString("no such database");
	}
	status = db->Get(leveldb::ReadOptions(), std::string(TCHAR_TO_UTF8(*key)), &out);
	success = !status.IsNotFound();
	return FString(out.c_str());
}

std::string ULevelDatabase::GetChecked(std::string key, bool& success) {
	std::string out;
	status = db->Get(leveldb::ReadOptions(), key, &out);
	success = !status.IsNotFound();
	return out;
}
