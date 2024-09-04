// Copyright © 2024 Boring Games. All rights reserved.


#include "GameplayTagStackInterface.h"
#include "GameFramework/Actor.h"
#include "GameplayTagStackContainer.h"


UGameplayTagStackInterface::UGameplayTagStackInterface(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
}

bool IGameplayTagStackInterface::HasMatchingGameplayTagStack(const FGameplayTag TagToCheck) const
{
	FGameplayTagStackContainer OwnedTagStacks;
	GetOwnedGameplayTagStacks(OwnedTagStacks);
	
	return OwnedTagStacks.ContainsTag(TagToCheck);
}

int32 IGameplayTagStackInterface::GetGameplayTagStackCount(const FGameplayTag TagToCheck) const
{
	FGameplayTagStackContainer OwnedTagStacks;
	GetOwnedGameplayTagStacks(OwnedTagStacks);

	return OwnedTagStacks.GetStackCount(TagToCheck);
}

void IGameplayTagStackInterface::AddGameplayTagStack(const FGameplayTag Tag, const int32 StackCount)
{
	FGameplayTagStackContainer* OwnedTagStacks = nullptr;
	GetOwnedGameplayTagStacks(*OwnedTagStacks);

	OwnedTagStacks->AddStack(Tag, StackCount);
}

void IGameplayTagStackInterface::RemoveGameplayTagStack(const FGameplayTag Tag, const int32 StackCount)
{
	FGameplayTagStackContainer* OwnedTagStacks = nullptr;
	GetOwnedGameplayTagStacks(*OwnedTagStacks);

	OwnedTagStacks->RemoveStack(Tag, StackCount);
}

void UGameplayTagStackLibrary::GetOwnedGameplayTagStacks(AActor* TargetActor, FGameplayTagStackContainer& TagStackContainer)
{
	// Check for the interface on the actor (Works for c++ implementations)
	if (const IGameplayTagStackInterface* TagStackInterface = Cast<IGameplayTagStackInterface>(TargetActor))
	{
		TagStackInterface->GetOwnedGameplayTagStacks(TagStackContainer);
		return;
	}
	
	// Check for the interface on the actor (Works for blueprint implementations)
	if (TargetActor->GetClass()->ImplementsInterface(UGameplayTagStackInterface::StaticClass()))
	{
		//@TODO: Implement blueprint version of GetOwnedGameplayTagStacks
		return;
	}
}

bool UGameplayTagStackLibrary::HasMatchingGameplayTagStack(AActor* TargetActor, const FGameplayTag TagToCheck)
{
	// Check for the interface on the actor (Works for c++ implementations)
	if (const IGameplayTagStackInterface* TagStackInterface = Cast<IGameplayTagStackInterface>(TargetActor))
	{
		return TagStackInterface->HasMatchingGameplayTagStack(TagToCheck);
	}

	// Check for the interface on the actor (Works for blueprint implementations)
	if (TargetActor->GetClass()->ImplementsInterface(UGameplayTagStackInterface::StaticClass()))
	{
		//@TODO: Implement blueprint version of HasMatchingGameplayTagStack
	};

	return false;
}

bool UGameplayTagStackLibrary::HasMatchingGameplayTagStackContainer(const FGameplayTagStackContainer& TagStackContainer, const FGameplayTag TagToCheck)
{
	return TagStackContainer.ContainsTag(TagToCheck);
}

int32 UGameplayTagStackLibrary::GetGameplayTagStackCount(AActor* TargetActor, const FGameplayTag TagToCheck)
{
	// Check for the interface on the actor (Works for c++ implementations)
	if (const IGameplayTagStackInterface* TagStackInterface = Cast<IGameplayTagStackInterface>(TargetActor))
	{
		return TagStackInterface->GetGameplayTagStackCount(TagToCheck);
	}

	// Check for the interface on the actor (Works for blueprint implementations)
	if (TargetActor->GetClass()->ImplementsInterface(UGameplayTagStackInterface::StaticClass()))
	{
		//@TODO: Implement blueprint version of GetGameplayTagStackCount
	}

	return 0;
}

int32 UGameplayTagStackLibrary::GetGameplayTagStackCountContainer(const FGameplayTagStackContainer& TagStackContainer, const FGameplayTag TagToCheck)
{
	return TagStackContainer.GetStackCount(TagToCheck);
}

