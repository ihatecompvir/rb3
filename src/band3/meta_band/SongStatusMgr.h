#ifndef METAGAME_SONGSTATUSMGR_H
#define METAGAME_SONGSTATUSMGR_H

#include "game/Defines.h"
#include "system/utl/BinStream.h"
#include "system/meta/FixedSizeSaveableStream.h"
#include "system/utl/Symbols.h"
#include "game/BandUser.h"
#include "meta_band/BandProfile.h"

class SongStatusGuitar {
public:
    unsigned char mHoposPercentage;
    unsigned char mSoloPercentage;
    unsigned char mPad1;
};

class SongStatusVocals {
public:
    unsigned char mAwesomes;
    unsigned char mDoubleAwesomes;
    unsigned char mTripleAwesomes;
};

union SongStatusInstrumentUnion {
    public:
    SongStatusGuitar mGuitarDrums;
    SongStatusVocals mVocals;
};

class SongStatusData {
    public:
    void Clear(ScoreType);
    void SaveSize(int);
    void SaveToStream(BinStream &, ScoreType) const;
    void LoadFromStream(BinStream &, ScoreType);

    int mScore;
    int mBREScore;
    int mStars : 4;
    int mAccuracy : 8;
    int mStreak : 8;
    int mUnisonPhrasesHit : 8;
    int mDirty : 4;
    unsigned char mFlags;
    SongStatusInstrumentUnion mShared;
};

class SongStatus : public FixedSizeSaveable {
    SongStatus();
    ~SongStatus();
    void Clear();
    void SaveSize(int);
    void SaveFixed(FixedSizeSaveableStream &) const;
    void LoadFixed(FixedSizeSaveableStream &, int);
    void SetDirty(ScoreType, Difficulty, bool);
    void SetLastPlayed(int);
    int GetLastPlayed() const;
    void SetPlayCount(int);
    void SetBitmapLessonComplete(unsigned int &, int, bool);
    void SetProGuitarLessonSectionComplete(Difficulty, int, bool);
    void SetProBassLessonSectionComplete(Difficulty, int, bool);
    void SetProKeyboardLessonSectionComplete(Difficulty, int, bool);
    void SetID(int);
    int GetID() const;
    void SetReview(unsigned char);
    void SetInstrumentMask(unsigned short);
    unsigned char GetSoloPercent(ScoreType, Difficulty) const;

    int mSongID;
    unsigned short mBandScoreInstrumentMask;
    unsigned char mReview;

    int mLastPlayed;
    int mPlayCount;
    unsigned int mProGuitarLessonParts[4];
    unsigned int mProBassLessonParts[4];
    unsigned int mProKeyboardLessonParts[4];
    class SongStatusData mSongData[4][11];
};

class SongStatusLookup {
    SongStatusLookup();
    ~SongStatusLookup();
    void Clear();
    void Save(FixedSizeSaveableStream &) const;
    void Load(FixedSizeSaveableStream &, int);
};

class SongStatusCacheMgr {};

class SongStatusMgr : public Hmx::Object, public FixedSizeSaveable {
    // SongStatusMgr(LocalBandUser*, BandSongMgr*);
    virtual ~SongStatusMgr();
    virtual DataNode Handle(DataArray*, bool);
    void Clear();
    void GetAccuracy(int, ScoreType, Difficulty) const;
    void GetScore(int, ScoreType) const;
    void GetStars(int, ScoreType, Difficulty) const;
    void GetBestStars(int, ScoreType, Difficulty) const;
    bool OnMsg(const RockCentralOpCompleteMsg&);


};

#endif // METAGAME_SONGSTATUSMGR_H
