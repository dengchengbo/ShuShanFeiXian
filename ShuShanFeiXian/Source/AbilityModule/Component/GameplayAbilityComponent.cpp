// Fill out your copyright notice in the Description page of Project Settings.


#include "GameplayAbilityComponent.h"
#include "../Base/GameplayAbilityBase.h"


// Sets default values for this component's properties
UGameplayAbilityComponent::UGameplayAbilityComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...

	
	//AbilitySystemComponent = CreateDefaultSubobject<UAbilitySystemComponent>(TEXT("AbilitySystemComponent"));
	AbilitySystemComponent = this;
}


// Called when the game starts
void UGameplayAbilityComponent::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}


// Called every frame
void UGameplayAbilityComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}



UAbilitySystemComponent* UGameplayAbilityComponent::GetAbilitySystemComponent() const
{
	return  AbilitySystemComponent;
}



bool UGameplayAbilityComponent::Init_Implementation(AActor* InOwnerActor, AActor* InAvatarActor)
{


	if (AbilitySystemComponent != nullptr) {

		if (GetOwner()->HasAuthority()) {


			if (AbilitiesArray.Num()) {

				for (FString Abilities : AbilitiesArray) {

					if (GiveAbility_A(InOwnerActor, Abilities))continue;
				}

			}


			AbilitySystemComponent->InitAbilityActorInfo(InOwnerActor, InAvatarActor);

			//Cast<ASXCharacter>(InAvatarActor)->GetAbilityController(InOwnerActor);
			bIsInit = true;
			return true;


		}
	}

	bIsInit = false;
	return false;
}


bool UGameplayAbilityComponent::GiveAbility_Implementation(const UObject* WorldContext, const FString& _AbilityID)
{

	bool IsSuccess = GiveAbility_A(WorldContext, _AbilityID);

	if (IsSuccess) {
		AbilitiesArray.AddUnique(_AbilityID);
	}

	return IsSuccess;
}

bool UGameplayAbilityComponent::RemoveAbility_Implementation(const FString& _AbilityID)
{
	return RemoveAbility_A(_AbilityID);
}

bool UGameplayAbilityComponent::GiveAbility_A(const UObject* WorldContext, const FString& _AbilityID)
{
	FAbilityInfo* info = GetAbilityInfo(_AbilityID);


	if (info == nullptr || AbilitiesHandleMap.Contains(_AbilityID)) { return false; }

	TPair<FString, FAbilityInfo> AbilityPair(_AbilityID, *info);

	//GetAbilitiesMap()->Add(AbilityPair); 

	return GiveAbility_B(AbilityPair);
}

bool UGameplayAbilityComponent::GiveAbility_B(TPair<FString, FAbilityInfo> _AbilityPair)
{

	FString AbilityID = _AbilityPair.Key;
	FAbilityInfo Ability = _AbilityPair.Value;

	auto AbilityClass = Ability.AbilityClass;

	if (AbilityID == "" || AbilityClass == nullptr) { return false; }


	AbilityClass.GetDefaultObject()->InItData(&Ability);
	FGameplayAbilitySpecHandle sHandle = AbilitySystemComponent->GiveAbility(FGameplayAbilitySpec(AbilityClass.GetDefaultObject(), 1, 0));
	//UGameplayAbility* AbilityObj = AbilityClass.GetDefaultObject();

	AbilitiesHandleMap.Add(AbilityID, sHandle);

	if (Ability.AddSkillBook) {
		SkillBookMap.Add(_AbilityPair);
	}
	return true;
}

bool UGameplayAbilityComponent::RemoveAbility_A(const FString& _AbilityID)
{
	if (!AbilitiesHandleMap.Contains(_AbilityID)) { return false; }

	FGameplayAbilitySpecHandle sHandle = *AbilitiesHandleMap.Find(_AbilityID);

	AbilitySystemComponent->ClearAbility(sHandle);

	AbilitiesHandleMap.Remove(_AbilityID);
	//GetAbilitiesMap()->Remove(_AbilityID);
	AbilitiesArray.Remove(_AbilityID);
	SkillBookMap.Remove(_AbilityID);

	return true;
}


bool UGameplayAbilityComponent::TryActivateAbilityByID_Implementation(const FString& _AbilityID)
{
	if (!bCanAbility) {
		return false;
	}

	if (!AbilitiesHandleMap.Contains(_AbilityID)) {
		return false;
	}

	FGameplayAbilitySpecHandle sHandle = *AbilitiesHandleMap.Find(_AbilityID);
	//FGameplayAbilitySpec* Spec = AbilitySystemComponent->FindAbilitySpecFromHandle(AbilityToActivate);
	return AbilitySystemComponent->TryActivateAbility(sHandle);

}

FAbilityInfo* UGameplayAbilityComponent::GetAbilityInfo(const FString& _AbilityID)
{
	FAbilityInfo* OutFormation;
	if (AbilityInfoDataTable == nullptr)
	{
		return  nullptr;
	}

	TArray<FName> Names = AbilityInfoDataTable->GetRowNames();

	for (auto Name : Names)
	{
		OutFormation = AbilityInfoDataTable->FindRow<FAbilityInfo>(Name, "");
		if (OutFormation != nullptr && OutFormation->AbilityID == _AbilityID) {
			return OutFormation;
		}
	}

	return nullptr;
}

void UGameplayAbilityComponent::GetAbilityInfo_Blueprint(const FString& _AbilityID, FAbilityInfo& __AbilityInfo)
{
	FAbilityInfo* OutFormation = GetAbilityInfo(_AbilityID);
	if (OutFormation == nullptr) { return; }
	__AbilityInfo = *OutFormation;
}

UGameplayAbilityBase* UGameplayAbilityComponent::GetAbilityObject(const FString& _AbilityID)
{
	if (!AbilitiesHandleMap.Contains(_AbilityID)) {
		return nullptr;
	}

	FGameplayAbilitySpecHandle sHandle = *AbilitiesHandleMap.Find(_AbilityID);
	FGameplayAbilitySpec* Spec = AbilitySystemComponent->FindAbilitySpecFromHandle(sHandle);

	if (!Spec) {
		return nullptr;
	}

	UGameplayAbility* Ability = Spec->Ability;

	if (!Ability) {
		return nullptr;
	}

	return Cast<UGameplayAbilityBase>(Ability);
}


bool UGameplayAbilityComponent::SendGameplayEvent(FGameplayTag EventTag, FGameplayEventData Payload)
{
	if (AbilitySystemComponent != nullptr && !AbilitySystemComponent->IsPendingKill())
	{
		FScopedPredictionWindow NewScopedWindow(AbilitySystemComponent, true);
		AbilitySystemComponent->HandleGameplayEvent(EventTag, &Payload);
		return true;
	}
	else
	{
		//UE_LOG(Error, TEXT("UAbilitySystemBlueprintLibrary::SendGameplayEventToActor: Invalid ability system component retrieved from Actor %s. EventTag was %s"), *Actor->GetName(), *EventTag.ToString());
		return false;
	}

	return false;
}
