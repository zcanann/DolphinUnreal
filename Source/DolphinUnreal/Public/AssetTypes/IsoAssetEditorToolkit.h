#pragma once

#include "CoreMinimal.h"

#include "EditorUndoClient.h"
#include "Templates/SharedPointer.h"
#include "Toolkits/AssetEditorToolkit.h"

class FSpawnTabArgs;
class ISlateStyle;
class IToolkitHost;
class SDockTab;
class UIsoAsset;

class FIsoAssetEditorToolkit : public FAssetEditorToolkit, public FEditorUndoClient, public FGCObject
{
public:
	FIsoAssetEditorToolkit(const TSharedRef<ISlateStyle>& InStyle);

	virtual ~FIsoAssetEditorToolkit();

public:
	void Initialize(UIsoAsset* InIsoAsset, const EToolkitMode::Type InMode, const TSharedPtr<IToolkitHost>& InToolkitHost);

public:
	virtual FString GetDocumentationLink() const override;
	virtual void RegisterTabSpawners(const TSharedRef<FTabManager>& InTabManager) override;
	virtual void UnregisterTabSpawners(const TSharedRef<FTabManager>& InTabManager) override;

public:
	virtual FText GetBaseToolkitName() const override;
	virtual FName GetToolkitFName() const override;
	virtual FLinearColor GetWorldCentricTabColorScale() const override;
	virtual FString GetWorldCentricTabPrefix() const override;

public:
	virtual void AddReferencedObjects(FReferenceCollector& Collector) override;

protected:
	virtual void PostUndo(bool bSuccess) override;
	virtual void PostRedo(bool bSuccess) override;

private:
	TSharedRef<SDockTab> HandleTabManagerSpawnTab(const FSpawnTabArgs& Args, FName TabIdentifier);

private:
	UIsoAsset* IsoAsset;
	TSharedRef<ISlateStyle> Style;
};
