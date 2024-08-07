#ifndef UTL_SONG_H
#define UTL_SONG_H
#include "rndobj/Anim.h"
#include "rndobj/Overlay.h"
#include "midi/Midi.h"
#include "utl/MBT.h"
#include "beatmatch/HxMaster.h"
#include "beatmatch/HxSongData.h"
#include <map>

class HxSongData;
class HxMaster;

class Song : public RndAnimatable, public MidiReceiver, public RndOverlay::Callback {
public:
    Song();
    OBJ_CLASSNAME(Song);
    OBJ_SET_TYPE(Song);
    virtual DataNode Handle(DataArray*, bool);
    virtual bool SyncProperty(DataNode&, DataArray*, int, PropOp);
    virtual void Save(BinStream&);
    virtual void Copy(const Hmx::Object*, Hmx::Object::CopyType);
    virtual void Load(BinStream&);
    virtual ~Song();
    virtual void SetFrame(float frame, float blend);
    virtual float EndFrame();

    virtual float UpdateOverlay(RndOverlay*, float);
    virtual void OnNewTrack(int){}
    virtual void OnEndOfTrack(){}
    virtual void OnAllTracksRead(){}
    virtual void OnMidiMessage(int, unsigned char, unsigned char, unsigned char){}
    virtual void OnText(int, const char*, unsigned char);
    virtual DataNode OnMBTFromSeconds(const DataArray*);
    virtual void CreateSong(Symbol, DataArray*, HxSongData**, HxMaster**);

    void Unload();
    void Load();
    float GetBeat();
    void LoadSong();
    TempoMap* GetTempoMap();
    BeatMap* GetBeatMap();
    MeasureMap* GetMeasureMap();
    void SyncState();
    void SetStateDirty(bool);
    MBT GetMBTFromFrame(float, int*);
    MBT GetMBTFromTick(int, int*);
    ObjectDir* MainDir() const;
    void SetLoopStart(float);
    void SetLoopEnd(float);
    void JumpTo(int);
    void JumpTo(Symbol);
    void Play();
    void Pause();
    void SetSong(Symbol);
    void AddSection(Symbol, float);
    void UpdateDebugParsers();
    void SetSpeed();

    DataNode GetBookmarks();
    DataNode GetMidiParsers();

    NEW_OVERLOAD;
    DELETE_OVERLOAD;
    static Hmx::Object* sCallback;

    HxMaster* mHxMaster; // 0x1c
    HxSongData* mHxSongData; // 0x20
    std::map<int, Symbol> unk24; // 0x24
    ObjPtrList<Hmx::Object, ObjectDir> mDebugParsers; // 0x3c
    Symbol mSongName; // 0x4c
    Symbol unk50; // 0x50
    float mSongEndFrame; // 0x54
    float mSpeed; // 0x58
    // 5c and 60 could also be a Vector2?
    float unk5c; // 0x5c
    float unk60; // 0x60
    MBT mLoopStart; // 0x64
    MBT mLoopEnd; // 0x70
    bool unk7c; // 0x7c
};

#endif