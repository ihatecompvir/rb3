#include "SongStatusMgr.h"

void SongStatusData::Clear(ScoreType) {
}
void SongStatusData::SaveSize(int) {}
void SongStatusData::SaveToStream(BinStream &, ScoreType) const {}
void SongStatusData::LoadFromStream(BinStream &, ScoreType) {}

SongStatus::SongStatus() {
    Clear();
}
SongStatus::~SongStatus() {}
void SongStatus::Clear() {}
void SongStatus::SaveSize(int) {}
void SongStatus::SaveFixed(FixedSizeSaveableStream &) const {}
void SongStatus::LoadFixed(FixedSizeSaveableStream &, int) {}
void SongStatus::SetDirty(ScoreType, Difficulty, bool) {}
void SongStatus::SetLastPlayed(int lastPlayed) {
    mLastPlayed = lastPlayed;
}
int SongStatus::GetLastPlayed() const {
    return mLastPlayed;
}
void SongStatus::SetPlayCount(int playCount) {
    mPlayCount = playCount;
}
void SongStatus::SetBitmapLessonComplete(unsigned int &i, int i2, bool b) {
    if (b != false) {
        i = i | 1 << i2;
    } else {
        i = i & ~(1 << i2);
    }
}
void SongStatus::SetProGuitarLessonSectionComplete(Difficulty difficulty, int i, bool b) {
    SetBitmapLessonComplete(mProGuitarLessonParts[difficulty], i, b);
}
void SongStatus::SetProBassLessonSectionComplete(Difficulty difficulty, int i, bool b) {
    SetBitmapLessonComplete(mProBassLessonParts[difficulty], i, b);
}
void SongStatus::SetProKeyboardLessonSectionComplete(Difficulty difficulty, int i, bool b) {
    SetBitmapLessonComplete(mProKeyboardLessonParts[difficulty], i, b);
}
void SongStatus::SetID(int songID) {
    mSongID = songID;
}
int SongStatus::GetID() const {
    return mSongID;
}
void SongStatus::SetReview(unsigned char review) {
    mReview = review;
}
void SongStatus::SetInstrumentMask(unsigned short mask) {
    mBandScoreInstrumentMask = mask;
}

unsigned char SongStatus::GetSoloPercent(ScoreType scoreType, Difficulty difficulty) const {
}

SongStatusLookup::SongStatusLookup() {}
SongStatusLookup::~SongStatusLookup() {}
void SongStatusLookup::Clear() {}
void SongStatusLookup::Save(FixedSizeSaveableStream &) const {}
void SongStatusLookup::Load(FixedSizeSaveableStream &, int) {}

SongStatusMgr::~SongStatusMgr() {}
void SongStatusMgr::Clear() {}
void SongStatusMgr::GetAccuracy(int, ScoreType, Difficulty) const {}
void SongStatusMgr::GetScore(int, ScoreType) const {}
void SongStatusMgr::GetStars(int, ScoreType, Difficulty) const {}
void SongStatusMgr::GetBestStars(int, ScoreType, Difficulty) const {}

BEGIN_HANDLERS(SongStatusMgr)
    HANDLE_ACTION(get_stars, GetStars)
    HANDLE_ACTION(get_accuracy, GetAccuracy)
    HANDLE_MESSAGE(RockCentralOpCompleteMsg)
    HANDLE_SUPERCLASS(Hmx::Object)
    HANDLE_CHECK(0x8ea)
END_HANDLERS


