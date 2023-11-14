// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

/**
 * 
 */
class FKeyBindUtils
{
public:
	FKeyBindUtils();
	~FKeyBindUtils();
	static void AddAction(FName Name, const FKey& Key, bool WithAlt, bool WithCtrl, bool WithShift);
	static void AddAxisAction(FName Name, const FKey& Key);
	static void RemoveAction(FName Name);
	static void RemoveAxisAction(FName Name);
};
