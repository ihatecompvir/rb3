#include "RockCentral.h"

Symbol PerformanceData::GetMode() const {
    return mMode;
}

int PerformanceData::GetSongID() const {
    return mSongId;
}

bool PerformanceData::IsPlaytest() const {
    return mIsPlaytest;
}

bool PerformanceData::IsOnline() const {
    return mIsOnline;
}

bool PerformanceData::IsCheating() const {
    return mIsCheating;
}

ScoreType PerformanceData::GetScoreType() const {
    return mScoreType;
}

Difficulty PerformanceData::GetDifficulty() const {
    return mDifficulty;
}

int PerformanceData::GetTimeStamp() const {
    return mTimestamp;
}

// Stats& PerformanceData::GetStats() const {
//     return mStats;
// }

int PerformanceData::GetStars() const {
    return mStars;
}

int PerformanceData::GetBattleID() const {
    return mBattleId;
}

RockCentral::RockCentral() : mJobMgr(this) {}

RockCentral::~RockCentral() {}

#pragma push
#pragma dont_inline on
BEGIN_HANDLERS(RockCentral)
HANDLE_ACTION(clear_pending_invitations, ClearPendingInvitations())
HANDLE_ACTION(force_logout, ForceLogout())
HANDLE_EXPR(is_online, IsOnline())
HANDLE_ACTION(toggle_block_login, BlockLoginToggle())
HANDLE_ACTION(block_login, BlockLogin(_msg->Int(2)))
HANDLE_SUPERCLASS(MsgSource)
HANDLE_CHECK(0xD98)
END_HANDLERS
#pragma pop
