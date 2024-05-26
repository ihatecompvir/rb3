#ifndef OBJ_UTL_H
#define OBJ_UTL_H
#include "utl/Symbol.h"
#include "obj/Data.h"
#include "obj/Object.h"
#include <vector>

// forward declarations
namespace Hmx {
    class Object;
}
class ObjectDir;

void InitObject(Hmx::Object*);
// const char* PathName(const Hmx::Object*); // declared in ObjMacros.h instead, which you can just include obj/Object.h for anyway
const char* SafeName(Hmx::Object*);
DataNode ObjectList(class ObjectDir*, Symbol, bool); // i think???
DataNode MakeFileList(const char*, bool, bool (*)(char*));
DataNode MakeFileListFullPath(const char*);

void ListSuperClasses(Symbol, std::vector<Symbol>&);
void RecurseSuperClasses(Symbol, std::vector<Symbol>&);
bool RecurseSuperClassesSearch(Symbol, Symbol);
bool IsASubclass(Symbol, Symbol);
void ReplaceObject(Hmx::Object*, Hmx::Object*, bool, bool, bool);
void CopyTypeProperties(Hmx::Object*, Hmx::Object*);
void ReserveToFit(class ObjectDir*, class ObjectDir*, int);
int SubDirStringUsed(class ObjectDir*);
int SubDirHashUsed(class ObjectDir*);
const char* NextName(const char*, class ObjectDir*);
bool StringMatchesFilter(const char*, const char*);
int GetPropSize(Hmx::Object*, DataArray*, int);
bool IsPropPathValid(Hmx::Object*, DataArray*);
bool PathCompare(DataArray*, DataArray*);
DataNode* GetPropertyVal(Hmx::Object*, DataArray*, bool);
void CopyObject(Hmx::Object*, Hmx::Object*, Hmx::Object::CopyType, bool);

// mergefilter classes go here
class MergeFilter {
public:
    enum Action { kMerge, kReplace, kKeep, kIgnore };
    enum Subdirs { kNoSubdirs, kAllSubdirs, kInlineSubdirs };

    MergeFilter();
    MergeFilter(Action a, Subdirs s) : mAction(a), mSubdirs(s) {}
    virtual ~MergeFilter(){}
    virtual Action Filter(Hmx::Object*, Hmx::Object*, class ObjectDir*){ return mAction; }
    virtual Action FilterSubdir(class ObjectDir* o1, class ObjectDir*){
        return DefaultSubdirAction(o1, mSubdirs);
    }

    static Action DefaultSubdirAction(class ObjectDir*, Subdirs);

    Action mAction;
    Subdirs mSubdirs;
};

class DataMergeFilter : public MergeFilter {
public:
    inline DataMergeFilter(const DataNode&, Subdirs);
    virtual ~DataMergeFilter(){}
    virtual Action Filter(Hmx::Object*, Hmx::Object*, class ObjectDir*);

    DataType mType;
    DataFunc* mFunc;
    Hmx::Object* mObj;
    int mInt;
};

void MergeDirs(ObjectDir*, ObjectDir*, MergeFilter&);

#endif
