#include "AssetTypes/IsoAssetEditorToolkit.h"

#include "Editor.h"
#include "EditorReimportHandler.h"
#include "EditorStyleSet.h"
#include "UObject/NameTypes.h"
#include "Widgets/Docking/SDockTab.h"

#include "AssetTypes/IsoAsset.h"

#define LOCTEXT_NAMESPACE "IsoAssetToolkit"

DEFINE_LOG_CATEGORY_STATIC(LogIsoAssetEditor, Log, All);

namespace IsoAssetEditor
{
	static const FName AppIdentifier("IsoAssetEditorApp");
	static const FName TabId("TextEditor");
}

FIsoAssetEditorToolkit::FIsoAssetEditorToolkit(const TSharedRef<ISlateStyle>& InStyle)
	: IsoAsset(nullptr)
	, Style(InStyle)
{ }


FIsoAssetEditorToolkit::~FIsoAssetEditorToolkit()
{
	FReimportManager::Instance()->OnPreReimport().RemoveAll(this);
	FReimportManager::Instance()->OnPostReimport().RemoveAll(this);

	GEditor->UnregisterForUndo(this);
}

void FIsoAssetEditorToolkit::Initialize(UIsoAsset* InIsoAsset, const EToolkitMode::Type InMode, const TSharedPtr<class IToolkitHost>& InToolkitHost)
{
	IsoAsset = InIsoAsset;

	// Support undo/redo
	IsoAsset->SetFlags(RF_Transactional);
	GEditor->RegisterForUndo(this);

	// create tab layout
	const TSharedRef<FTabManager::FLayout> Layout = FTabManager::NewLayout("Standalone_IsoAssetEditor")
		->AddArea
		(
			FTabManager::NewPrimaryArea()
			->SetOrientation(Orient_Horizontal)
			->Split
			(
				FTabManager::NewSplitter()
				->SetOrientation(Orient_Vertical)
				->SetSizeCoefficient(0.66f)
				->Split
				(
					FTabManager::NewStack()
					->AddTab(GetToolbarTabId(), ETabState::OpenedTab)
					->SetHideTabWell(true)
					->SetSizeCoefficient(0.1f)

				)
				->Split
				(
					FTabManager::NewStack()
					->AddTab(IsoAssetEditor::TabId, ETabState::OpenedTab)
					->SetHideTabWell(true)
					->SetSizeCoefficient(0.9f)
				)
			)
		);

	FAssetEditorToolkit::InitAssetEditor(
		InMode,
		InToolkitHost,
		IsoAssetEditor::AppIdentifier,
		Layout,
		true /*bCreateDefaultStandaloneMenu*/,
		true /*bCreateDefaultToolbar*/,
		InIsoAsset
	);

	RegenerateMenusAndToolbars();
}


FString FIsoAssetEditorToolkit::GetDocumentationLink() const
{
	return FString(TEXT("https://github.com/ue4plugins/IsoAsset"));
}


void FIsoAssetEditorToolkit::RegisterTabSpawners(const TSharedRef<FTabManager>& InTabManager)
{
	WorkspaceMenuCategory = InTabManager->AddLocalWorkspaceMenuCategory(LOCTEXT("WorkspaceMenu_IsoAssetEditor", "Text Asset Editor"));
	auto WorkspaceMenuCategoryRef = WorkspaceMenuCategory.ToSharedRef();

	FAssetEditorToolkit::RegisterTabSpawners(InTabManager);

	InTabManager->RegisterTabSpawner(IsoAssetEditor::TabId, FOnSpawnTab::CreateSP(this, &FIsoAssetEditorToolkit::HandleTabManagerSpawnTab, IsoAssetEditor::TabId))
		.SetDisplayName(LOCTEXT("TextEditorTabName", "Text Editor"))
		.SetGroup(WorkspaceMenuCategoryRef)
		.SetIcon(FSlateIcon(FEditorStyle::GetStyleSetName(), "LevelEditor.Tabs.Viewports"));
}


void FIsoAssetEditorToolkit::UnregisterTabSpawners(const TSharedRef<FTabManager>& InTabManager)
{
	FAssetEditorToolkit::UnregisterTabSpawners(InTabManager);

	InTabManager->UnregisterTabSpawner(IsoAssetEditor::TabId);
}

FText FIsoAssetEditorToolkit::GetBaseToolkitName() const
{
	return LOCTEXT("AppLabel", "Text Asset Editor");
}


FName FIsoAssetEditorToolkit::GetToolkitFName() const
{
	return FName("IsoAssetEditor");
}


FLinearColor FIsoAssetEditorToolkit::GetWorldCentricTabColorScale() const
{
	return FLinearColor(0.3f, 0.2f, 0.5f, 0.5f);
}


FString FIsoAssetEditorToolkit::GetWorldCentricTabPrefix() const
{
	return LOCTEXT("WorldCentricTabPrefix", "IsoAsset ").ToString();
}

void FIsoAssetEditorToolkit::AddReferencedObjects(FReferenceCollector& Collector)
{
	Collector.AddReferencedObject(IsoAsset);
}

void FIsoAssetEditorToolkit::PostUndo(bool bSuccess)
{ }


void FIsoAssetEditorToolkit::PostRedo(bool bSuccess)
{
	PostUndo(bSuccess);
}

TSharedRef<SDockTab> FIsoAssetEditorToolkit::HandleTabManagerSpawnTab(const FSpawnTabArgs& Args, FName TabIdentifier)
{
	TSharedPtr<SWidget> TabWidget = SNullWidget::NullWidget;

	if (TabIdentifier == IsoAssetEditor::TabId)
	{
		// TabWidget = SNew(SIsoAssetEditor, IsoAsset, Style);
	}

	return SNew(SDockTab)
		.TabRole(ETabRole::PanelTab)
		[
			TabWidget.ToSharedRef()
		];
}

#undef LOCTEXT_NAMESPACE
