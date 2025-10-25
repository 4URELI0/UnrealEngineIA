// Copyright Epic Games, Inc. All Rights Reserved.

#include "TrabajoPracticoIAGameMode.h"
#include "TrabajoPracticoIACharacter.h"
#include "UObject/ConstructorHelpers.h"

ATrabajoPracticoIAGameMode::ATrabajoPracticoIAGameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPerson/Blueprints/BP_ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}
