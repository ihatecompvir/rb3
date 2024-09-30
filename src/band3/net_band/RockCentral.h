#ifndef NETBAND_ROCKCENTRAL_H
#define NETBAND_ROCKCENTRAL_H

#include "band3/meta_band/PerformanceData.h"
#include "obj/MsgSource.h"
#include "bandobj/PatchDir.h"
#include "system/utl/MemStream.h"
#include "system/utl/Symbols.h"
#include "system/utl/DataPointMgr.h"
#include "system/utl/JobMgr.h"
#include "system/utl/HxGuid.h"
#include "DataResults.h"

class RockCentral : public MsgSource {
public:
    RockCentral();
    virtual DataNode Handle(DataArray *, bool);
    virtual ~RockCentral();

    void AddBuildInfoToDP(DataPoint &);
    void BlockLogin(bool);
    void BlockLoginToggle();
    void CancelOutstandingCalls();
    void CheckBattleLimits();
    void ClearPendingInvitations();
    void ConvertToStr(PatchDir *, String *);
    void ConvertToStr(MemStream *, String *);
    void DecodeMessage(const char *, unsigned int *, String *);
    void DeleteNextUser();
    void ForceLogout();
    bool IsOnline();

    DataResultList mConfigResultList; // DataResultList *
    unsigned int unk_0x38;
    unsigned int unk_0x3c;
    Timer mTime; // 0x40

    float mRetryTime; // 0x70
    JobMgr mJobMgr; // 0x74

    bool mLoginBlocked; // 0x84
    bool unk_0x85; // 0x85
    HxGuid mGuid; // 0x88
    unsigned int unk_0x98;
    unsigned int unk_0x9C;
    unsigned int unk_0xA0;
    unsigned int unk_0xA4;
    Timer mTimer1; // 0xA8
    unsigned int unk_0xD8;
    unsigned int unk_0xDC;
    Timer mTimer2; // 0xE0
    bool mUnitTest; // 0x110
    bool unk_0x111;
    bool unk_0x112;
};

#endif // NETBAND_ROCKCENTRAL_H