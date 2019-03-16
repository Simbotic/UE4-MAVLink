

#include "MavLinkMsgs.h"
#include "MavlinkDispatch.h"


#define LOCTEXT_NAMESPACE "FMavLinkMsgsModule"

void FMavLinkMsgsModule::StartupModule()
{
	Dispatch = NewObject<UMavlinkDispatch>();
	Dispatch->AddToRoot();
}

void FMavLinkMsgsModule::ShutdownModule()
{

}

UMavlinkDispatch* FMavLinkMsgsModule::GetMavlinkDispatch() const
{
	
	return Dispatch;
}

#undef LOCTEXT_NAMESPACE
	
IMPLEMENT_MODULE(FMavLinkMsgsModule, MavLinkMsgs)