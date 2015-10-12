#ifndef ROOT_THcShowerArray
#define ROOT_THcShowerArray 

//////////////////////////////////////////////////////////////////////////////
//                         
// THcShowerArray
//
// A Hall C Fly's Eye Shower Array
//
// Subdetector for the fly's eye part of the SHMS shower counter.
// 
//////////////////////////////////////////////////////////////////////////////

#include "THaSubDetector.h"
#include "TClonesArray.h"

#include <iostream>

#include <fstream>

class THaEvData;
class THaSignalHit;

class THcShowerArray : public THaSubDetector {

public:
  THcShowerArray( const char* name, const char* description,
		  Int_t planenum, THaDetectorBase* parent = NULL);
  virtual ~THcShowerArray();

  virtual void    Clear( Option_t* opt="" );
  virtual Int_t Decode( const THaEvData& );
  virtual EStatus Init( const TDatime& run_time );

  virtual Int_t CoarseProcess( TClonesArray& tracks );
  virtual Int_t FineProcess( TClonesArray& tracks );
  Bool_t   IsTracking() { return kFALSE; }
  virtual Bool_t   IsPid()      { return kFALSE; }

  virtual Int_t ProcessHits(TClonesArray* rawhits, Int_t nexthit);
  virtual Int_t AccumulatePedestals(TClonesArray* rawhits, Int_t nexthit);
  virtual void  CalculatePedestals( );
  virtual void  InitializePedestals( );

  //  Double_t fSpacing;   not used

  TClonesArray* fParentHitList;

  // Return zero for now
  Double_t GetEplane() {
    return 0.0;
  };


protected:

  Double_t* fA;                 // [fNelem] ADC amplitude of blocks

  TClonesArray* fADCHits;	// List of ADC hits

  Int_t fNPedestalEvents;	/* Pedestal event counter */
  Int_t fMinPeds;		/* Only analyze/update if num events > */

  // Parameters
  Int_t fNRows;
  Int_t fNColumns;

  Int_t fLayerNum;		// 2 for SHMS
  // Accumulators for pedestals go here
  // 2D arrays

  virtual Int_t  ReadDatabase( const TDatime& date );
  virtual Int_t  DefineVariables( EMode mode = kDefine );
  //virtual void  InitializePedestals( );
  ClassDef(THcShowerArray,0); // Fly;s Eye calorimeter array
};
#endif