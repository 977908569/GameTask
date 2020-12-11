#pragma once
#include "GameTaskEditorGraphTypes.generated.h"

USTRUCT()
struct GAMETASKEDITOR_API FGameTaskGraphNodeClassData
{
	GENERATED_USTRUCT_BODY()

	FGameTaskGraphNodeClassData(): bIsHidden(0), bHideParent(0)
	{
	}

	FGameTaskGraphNodeClassData(UClass* InClass, const FString& InDeprecatedMessage);
	FGameTaskGraphNodeClassData(const FString& InAssetName, const FString& InGeneratedClassPackage, const FString& InClassName, UClass* InClass);

	FString ToString() const;
	FString GetClassName() const;
	FText GetCategory() const;
	FString GetDisplayName() const;
	UClass* GetClass(bool bSilent = false);
	bool IsAbstract() const;

	FORCEINLINE bool IsBlueprint() const { return AssetName.Len() > 0; }
	FORCEINLINE bool IsDeprecated() const { return DeprecatedMessage.Len() > 0; }
	FORCEINLINE FString GetDeprecatedMessage() const { return DeprecatedMessage; }
	FORCEINLINE FString GetPackageName() const { return GeneratedClassPackage; }

	/** set when child class masked this one out (e.g. always use game specific class instead of engine one) */
	uint32 bIsHidden : 1;
	/** set when class wants to hide parent class from selection (just one class up hierarchy) */
	uint32 bHideParent : 1;

private:

	/** pointer to uclass */
	TWeakObjectPtr<UClass> Class;

	/** path to class if it's not loaded yet */
	UPROPERTY()
		FString AssetName;

	UPROPERTY()
		FString GeneratedClassPackage;

	/** resolved name of class from asset data */
	UPROPERTY()
		FString ClassName;

	/** User-defined category for this class */
	UPROPERTY()
		FText Category;

	/** message for deprecated class */
	FString DeprecatedMessage;
};

struct GAMETASKEDITOR_API FGameTaskGraphNodeClassNode
{
	FGameTaskGraphNodeClassData Data;
	FString ParentClassName;

	TSharedPtr<FGameTaskGraphNodeClassNode> ParentNode;
	TArray<TSharedPtr<FGameTaskGraphNodeClassNode> > SubNodes;

	void AddUniqueSubNode(TSharedPtr<FGameTaskGraphNodeClassNode> SubNode);
};

struct GAMETASKEDITOR_API FGameTaskGraphNodeClassHelper
{
	DECLARE_MULTICAST_DELEGATE(FOnPackageListUpdated);

	FGameTaskGraphNodeClassHelper(UClass* InRootClass);
	~FGameTaskGraphNodeClassHelper();

	void GatherClasses(const UClass* BaseClass, TArray<FGameTaskGraphNodeClassData>& AvailableClasses);
	static FString GetDeprecationMessage(const UClass* Class);

	void OnAssetAdded(const struct FAssetData& AssetData);
	void OnAssetRemoved(const struct FAssetData& AssetData);
	void InvalidateCache();
	void OnHotReload(bool bWasTriggeredAutomatically);

	static void AddUnknownClass(const FGameTaskGraphNodeClassData& ClassData);
	static bool IsClassKnown(const FGameTaskGraphNodeClassData& ClassData);
	static FOnPackageListUpdated OnPackageListUpdated;

	static int32 GetObservedBlueprintClassCount(UClass* BaseNativeClass);
	static void AddObservedBlueprintClasses(UClass* BaseNativeClass);
	void UpdateAvailableBlueprintClasses();

private:

	UClass* RootNodeClass;
	TSharedPtr<FGameTaskGraphNodeClassNode> RootNode;
	static TArray<FName> UnknownPackages;
	static TMap<UClass*, int32> BlueprintClassCount;

	TSharedPtr<FGameTaskGraphNodeClassNode> CreateClassDataNode(const struct FAssetData& AssetData);
	TSharedPtr<FGameTaskGraphNodeClassNode> FindBaseClassNode(TSharedPtr<FGameTaskGraphNodeClassNode> Node, const FString& ClassName);
	void FindAllSubClasses(TSharedPtr<FGameTaskGraphNodeClassNode> Node, TArray<FGameTaskGraphNodeClassData>& AvailableClasses);

	UClass* FindAssetClass(const FString& GeneratedClassPackage, const FString& AssetName);
	void BuildClassGraph();
	void AddClassGraphChildren(TSharedPtr<FGameTaskGraphNodeClassNode> Node, TArray<TSharedPtr<FGameTaskGraphNodeClassNode> >& NodeList);

	bool IsHidingClass(UClass* Class);
	bool IsHidingParentClass(UClass* Class);
	bool IsPackageSaved(FName PackageName);
};
