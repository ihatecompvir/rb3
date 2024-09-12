#pragma once
#include "bandobj/TrackPanelDirBase.h"
#include "bandobj/VocalTrackDir.h"
#include "bandobj/BandCrowdMeter.h"
#include "bandobj/EndingBonus.h"
#include "bandobj/GemTrackResourceManager.h"
#include "rndobj/EventTrigger.h"

class TrackPanelDir : public TrackPanelDirBase {
public:
    TrackPanelDir();
    OBJ_CLASSNAME(TrackPanelDir)
    OBJ_SET_TYPE(TrackPanelDir)
    virtual DataNode Handle(DataArray*, bool);
    virtual bool SyncProperty(DataNode&, DataArray*, int, PropOp);
    virtual void Save(BinStream&);
    virtual void Copy(const Hmx::Object*, Hmx::Object::CopyType);
    virtual ~TrackPanelDir();
    virtual void PreLoad(BinStream&);
    virtual void PostLoad(BinStream&);
    virtual void SyncObjects();
    virtual void ConfigureTracks(bool);
    virtual void ConfigureTrack(int);
    virtual void AssignTracks();
    virtual void AssignTrack(int, TrackInstrument, bool);
    virtual void RemoveTrack(int);
    virtual void SetConfiguration(Hmx::Object*, bool);
    virtual void ReapplyConfiguration(bool);
    virtual void Reset();
    virtual void ResetAll();
    virtual void PlayIntro();
    virtual bool TracksExtended() const;
    virtual void GameOver();
    virtual void HideScore();
    virtual void Coda();
    virtual void CodaEnd();
    virtual void SetCodaScore(int);
    virtual void SoloEnd(BandTrack*, int, Symbol);
    virtual void SetTrackPanel(TrackPanelInterface*);
    virtual void ResetPlayers();
    virtual void StartFinale();
    virtual void SetMultiplier(int, bool);
    virtual void SetCrowdRating(float);
    virtual void CodaSuccess();
    virtual void UnisonStart(int);
    virtual void UnisonEnd();
    virtual void UnisonSucceed();
    virtual int GetEndingBonus(); // ptr to EndingBonus*
    virtual int GetCrowdMeter(); // ptr
    virtual void SetupApplauseMeter(int, const char*, const char*, RndDir*, RndDir*, bool, Symbol);
    virtual void DisablePlayer(int, bool);
    virtual void EnablePlayer(int);
    virtual void FadeBotbBandNames(bool);
    virtual void CleanUpChordMeshes();
    virtual void SetApplauseMeterScale(int, int);
    virtual void StartPulseAnims(float);
    virtual int GetGemTrackResourceManager() const; // also a ptr

    int unk244; // 0x244
    int unk248; // 0x248
    int unk24c; // 0x24c
    int unk250; // 0x250
    int unk254; // 0x254
    ObjPtr<VocalTrackDir, ObjectDir> unk258; // 0x258
    ObjPtr<BandCrowdMeter, ObjectDir> unk264; // 0x264
    ObjPtr<RndDir, ObjectDir> unk270; // 0x270
    ObjPtr<EventTrigger, ObjectDir> unk27c; // 0x27c
    ObjPtr<EndingBonus, ObjectDir> unk288; // 0x288
    ObjPtr<RndDir, ObjectDir> unk294; // 0x294
    ObjPtr<RndGroup, ObjectDir> unk2a0; // 0x2a0
    bool unk2ac; // 0x2ac
    bool unk2ad; // 0x2ad
    bool unk2ae; // 0x2ae
    ObjPtr<GemTrackResourceManager, ObjectDir> unk2b0; // 0x2b0
    bool unk2bc; // 0x2bc
    bool unk2bd; // 0x2bd
};