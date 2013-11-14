#ifndef CrystalFitResultArtRecord_hh
#define CrystalFitResultArtRecord_hh

/** @file CrystalFitResultArtRecord.hh
 
    Implements the T-Method waveform fit results in art record
 
    @author loreto "pete" alonzi - alonzi@uw.edu
    @date 2013

 */

#include <vector>
#include "IslandArtRecord.hh"

namespace gm2dataproducts {
  struct CrystalFitResultArtRecord {
    
    /** calorimeter ID */
    int caloNum;
    
    /** crystal ID */
    int xtalNum;
    
    /** fitted energy */
    float energy;

    /** fitted time */
    float time;

    /** pedestal */
    float pedestal; 

    /** quality of fit */
    float fitQuality;

    /** PTR to parent Island */
    art::Ptr< IslandArtRecord > parentIsland;        
        
    CrystalFitResultArtRecord() :
      caloNum(0),xtalNum(0),energy(0),time(0),pedestal(0),fitQuality(0)
    {};
        
        virtual ~CrystalFitResultArtRecord(){};
        
    // ROOT doesn't need to know the rest
#ifndef __GCCXML__
    CrystalFitResultArtRecord(int cn, int xn, float e, float t,float ped,float Q,art::Ptr<IslandArtRecord> I) :
      caloNum(cn), xtalNum(xn), energy(e), time(t), pedestal(ped),fitQuality(Q),parentIsland(I)
    {}

    bool operator<( const CrystalFitResultArtRecord& other ) const {
	// Simply compare the weights
	return time < other.time;
	}

#endif // __GCCXML__
    
  }; //end of CrystalFitResultArtRecord struct
  
  typedef std::vector<CrystalFitResultArtRecord> CrystalFitResultArtRecordCollection;
} // end namespace gm2dataproducts

#endif // CrystalFitResultArtRecord_hh
