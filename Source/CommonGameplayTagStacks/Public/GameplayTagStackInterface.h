// Copyright © 2024 Boring Games. All rights reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "UObject/Interface.h"
#include "GameplayTagStackInterface.generated.h"

struct FGameplayTagStackContainer;

/** Interface for actors that can be tagged with gameplay tag stacks. */
UINTERFACE(BlueprintType, MinimalAPI, meta=(CannotImplementInterfaceInBlueprint))
class UGameplayTagStackInterface : public UInterface
{
	GENERATED_UINTERFACE_BODY()
};

class IGameplayTagStackInterface
{
	GENERATED_IINTERFACE_BODY()

public:
	/**
	 * Get any owned gameplay tag stacks on the actor
	 *
	 * @param TagStackContainer	[OUT] Set of tag stacks on the actor
	 */
	virtual void GetOwnedGameplayTagStacks(FGameplayTagStackContainer& TagStackContainer) const = 0;

	/**
	 * Check if the actor has at least one stack of the specified tags
	 * @param TagToCheck	Tag to check for a match
	 * @returns True if the actor has a stack of the specified tags, false if not
	 */
	COMMONGAMEPLAYTAGSTACKS_API virtual bool HasMatchingGameplayTagStack(FGameplayTag TagToCheck) const;

	/**
	 * Returns the stack count of the specified tag
	 * Or 0 if the tag is not found
	 * @param TagToCheck Tag to check for a match
	 * @returns The stack count of the specified tag (0 if not found)
	 */
	COMMONGAMEPLAYTAGSTACKS_API virtual int32 GetGameplayTagStackCount(FGameplayTag TagToCheck) const;

	/**
	 * Adds a specified number of stacks of the specified tag to the actor.
	 * Does nothing if StackCount is below 1
	 * @param Tag Tag to add stacks to
	 * @param StackCount Number of stacks to add
	 */
	UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly, Category = GameplayTags)
	COMMONGAMEPLAYTAGSTACKS_API virtual void AddGameplayTagStack(FGameplayTag Tag, int32 StackCount);

	/**
	 * Removes a specified number of stacks of the specified tag from the actor.
	 * Does nothing if StackCount is below 1
	 * @param Tag Tag to remove stacks from
	 * @param StackCount Number of stacks to remove
	 */
	UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly, Category = GameplayTags)
	COMMONGAMEPLAYTAGSTACKS_API virtual void RemoveGameplayTagStack(FGameplayTag Tag, int32 StackCount);
};

/** Blueprint function library for working with gameplay tag stacks. */
UCLASS()
class COMMONGAMEPLAYTAGSTACKS_API UGameplayTagStackLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

public:
	/**
	 * Get any owned gameplay tag stacks on the actor
	 * @param TargetActor	Actor to get tag stacks from
	 * @param TagStackContainer	[OUT] Set of tag stacks on the actor
	 */
	UFUNCTION(BlueprintCallable, BlueprintPure, Category = GameplayTags)
	static void GetOwnedGameplayTagStacks(AActor* TargetActor, FGameplayTagStackContainer& TagStackContainer);

	/**
	 * Check if the actor has at least one stack of the specified tags
	 * @param TargetActor	Actor to get tag stacks from
	 * @param TagToCheck	Tag to check for a match
	 * @returns True if the actor has a stack of the specified tags, false if not
	 */
	UFUNCTION(BlueprintCallable, BlueprintPure, Category = GameplayTags)
	static bool HasMatchingGameplayTagStack(AActor* TargetActor, const FGameplayTag TagToCheck);

	/**
	 * Check if that tag stack container has at least one stack of the specified tags
	 * @param TagStackContainer	Tag stack container to check for a match
	 * @param TagToCheck	Tag to check for a match
	 * @returns True if the tag stack container has a stack of the specified tags, false if not
	 */
	UFUNCTION(BlueprintCallable, BlueprintPure, Category = GameplayTags)
	static bool HasMatchingGameplayTagStackContainer(const FGameplayTagStackContainer& TagStackContainer, const FGameplayTag TagToCheck);

	/**
	 * Returns the stack count of the specified tag
	 * Or 0 if the tag is not found
	 * @param TargetActor	Actor to get tag stacks from
	 * @param TagToCheck Tag to check for a match
	 * @returns The stack count of the specified tag (0 if not found)
	 */
	UFUNCTION(BlueprintCallable, BlueprintPure, Category = GameplayTags)
	static int32 GetGameplayTagStackCount(AActor* TargetActor, const FGameplayTag TagToCheck);

	/**
	 * Returns the stack count of the specified tag
	 * Or 0 if the tag is not found
	 * @param TagStackContainer	Tag stack container to check for a match
	 * @param TagToCheck Tag to check for a match
	 * @returns The stack count of the specified tag (0 if not found)
	 */
	UFUNCTION(BlueprintCallable, BlueprintPure, Category = GameplayTags)
	static int32 GetGameplayTagStackCountContainer(const FGameplayTagStackContainer& TagStackContainer, const FGameplayTag TagToCheck);
};