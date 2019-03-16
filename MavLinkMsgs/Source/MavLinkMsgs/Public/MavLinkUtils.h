#pragma once 

#include "CoreMinimal.h"
#include "MavLinkDispatch.h"
#include "MavLinkUtils.generated.h"


UCLASS(BlueprintType)
class MAVLINKMSGS_API UMavLinkUtils : public UBlueprintFunctionLibrary
{
    GENERATED_BODY()
public:
    UFUNCTION(BlueprintPure, Category="Mavlink|Messages")
    static UMavlinkDispatch* GetMavlinkMessages();

    template<typename MsgType>
    static FString GetStructAsText(const MsgType& msg)
    {
        FString str;
        FJsonObjectConverter::UStructToJsonObjectString(msg::StaticStruct(), &msg, str, 0, 0, 1, nullptr, true);
        return str;
    }
};