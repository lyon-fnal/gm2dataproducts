#ifndef ClusterArtRecord_hh
#define ClusterArtRecord_hh

/** @file ClusterArtRecord.hh
 
    Implements the T-Method waveform fit results in art record
 
    @author loreto "pete" alonzi - alonzi@uw.edu
    @date 2013

 */

#include <vector>
#include "CrystalFitRecordArtRecord.hh"

namespace gm2dataproducts {
  struct ClusterArtRecord {
    
    /** calorimeter ID */
    int caloNum;
    
    /** fitted energy */
    float energy;

    /** fitted time */
    float time;

    /** coordinates - calorimeter basis*/
    float x,y,z;

    /** PTR to parent Island */
    std::vector< art::Ptr< CrystalFitResultArtRecord > > parentCrystals;        
        
    ClusterArtRecord() :
      caloNum(0),energy(0),time(0),x(0),y(0),z(0)
    {}
        
        virtual ~ClusterArtRecord(){};
        
    // ROOT doesn't need to know the rest
#ifndef __GCCXML__
    ClusterArtRecord(int cn, float e, float t, float x,float y,float z,std::vector< art::Ptr< CrystalFitResultArtRecord > > pcs) :
      caloNum(cn),energy(e),time(x),x(x),y(y),z(z),parentCrystals(pcs)
    {}
#endif // __GCCXML__
    
  }; //end of ClusterArtRecord struct
  
  typedef std::vector<ClusterArtRecord> ClusterArtRecordCollection;
} // end namespace gm2dataproducts

#endif // ClusterArtRecord_hh
