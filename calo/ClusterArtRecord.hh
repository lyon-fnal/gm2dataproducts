#ifndef ClusterArtRecord_hh
#define ClusterArtRecord_hh

/** @file ClusterArtRecord.hh
 
    Implements the T-Method waveform fit results in art record
 
    @author loreto "pete" alonzi - alonzi@uw.edu
    @date 2013

 */

#include <vector>
#include "CrystalFitResultArtRecord.hh"

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

//     /** PTR to parent Island */
//     art::PtrVector< CrystalFitResultArtRecord  > parentCrystals;        
        
    ClusterArtRecord() :
      caloNum(0),energy(0),time(0),x(0),y(0),z(0)
    {}
        
        virtual ~ClusterArtRecord(){};
        
    // ROOT doesn't need to know the rest
#ifndef __GCCXML__
    ClusterArtRecord(int cn_, float e_, float t_, float x_,float y_,float z_ /*,art::PtrVector< CrystalFitResultArtRecord > pcs */) :
      caloNum(cn_),energy(e_),time(t_),x(x_),y(y_),z(z_)//,parentCrystals(pcs)
    {}
#endif // __GCCXML__
    
  }; //end of ClusterArtRecord struct
  
  typedef std::vector<ClusterArtRecord> ClusterArtRecordCollection;
} // end namespace gm2dataproducts

#endif // ClusterArtRecord_hh
