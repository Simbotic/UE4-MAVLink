#include "MavLinkUtils.h"
#include "ModuleManager.h"
#include "MavLinkMsgs.h"
UMavlinkDispatch* UMavLinkUtils::GetMavlinkMessages()
{
    FMavLinkMsgsModule& msgs = FModuleManager::Get().LoadModuleChecked<FMavLinkMsgsModule>("MavLinkMsgs");
    return msgs.GetMavlinkDispatch();
}
