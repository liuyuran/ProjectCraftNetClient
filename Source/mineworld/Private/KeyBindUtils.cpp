// Fill out your copyright notice in the Description page of Project Settings.


#include "KeyBindUtils.h"

#include "GameFramework/InputSettings.h"
#include "GameFramework/PlayerInput.h"

FKeyBindUtils::FKeyBindUtils()
{
}

FKeyBindUtils::~FKeyBindUtils()
{
}

void FKeyBindUtils::AddAction(const FName Name, const FKey& Key, const bool WithAlt, const bool WithCtrl, const bool WithShift)
{
	FInputActionKeyMapping ActionMap;
	ActionMap.ActionName = Name;
	ActionMap.bAlt = WithAlt;
	ActionMap.bCtrl = WithCtrl;
	ActionMap.bShift = WithShift;
	ActionMap.Key = Key;
	UInputSettings::GetInputSettings()->AddActionMapping(ActionMap);
}

void FKeyBindUtils::AddAxisAction(const FName Name, const FKey& Key)
{
	FInputAxisKeyMapping ActionMap;
	ActionMap.AxisName = Name;
	ActionMap.Key = Key;
	UInputSettings::GetInputSettings()->AddAxisMapping(ActionMap);
}

void FKeyBindUtils::RemoveAction(const FName Name)
{
	FInputActionKeyMapping ActionMap;
	ActionMap.ActionName = Name;
	UInputSettings::GetInputSettings()->RemoveActionMapping(ActionMap);
}

void FKeyBindUtils::RemoveAxisAction(const FName Name)
{
	FInputAxisKeyMapping ActionMap;
	ActionMap.AxisName = Name;
	UInputSettings::GetInputSettings()->RemoveAxisMapping(ActionMap);
}
