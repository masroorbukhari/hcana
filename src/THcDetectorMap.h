#ifndef ROOT_THcDetectorMap
#define ROOT_THcDetectorMap

//////////////////////////////////////////////////////////////////////////
//
// THcDetectorMap
//
//////////////////////////////////////////////////////////////////////////

#include "TObject.h"
#include "THaDetMap.h"
#include <list>

class THcDetectorMap : public TObject {

 public:
  THcDetectorMap();
  virtual ~THcDetectorMap();
  
  virtual void Load(const char *fname);
  virtual Int_t FillMap(THaDetMap* detmap, const char* detectorname);

  Int_t fNchans;  // Number of hardware channels

  struct Channel { // Mapping for one hardware channel
    Int_t roc;
    Int_t slot;
    Int_t channel;
    Int_t did;
    Int_t plane;
    Int_t counter;
    Int_t signal;
    Int_t model;
  };
  Channel fTable[10000]; // Big ugly cache of the map file

  struct ChaninMod {
    Int_t channel;
    Int_t plane;
    Int_t counter;
    Int_t signal;
  };
  struct ModChanList {
    Int_t roc;
    Int_t slot;
    Int_t model;
    std::list<ChaninMod> clist;
      
  };
  std::list<ModChanList> mlist;

  bool compare(const ChaninMod *first, const ChaninMod *second);

 protected:

  ClassDef(THcDetectorMap,0);
};
#endif

  
  
