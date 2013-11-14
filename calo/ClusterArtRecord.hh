#ifndef ClusterArtRecord_hh
#define ClusterArtRecord_hh

/** @file ClusterArtRecord.hh
 
    Implements the T-Method cluster finding
 
    @author loreto "pete" alonzi - alonzi@uw.edu
    @date 2013

 */

#include <vector>
#include "CrystalFitResultArtRecord.hh"
#include "art/Persistency/Common/PtrVector.h"

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

    /** PtrVector to parent Islands */
    art::PtrVector< gm2dataproducts::CrystalFitResultArtRecord  > parentCrystals;        
        
    ClusterArtRecord() {}
        
        virtual ~ClusterArtRecord(){};
        
    // ROOT doesn't need to know the rest
#ifndef __GCCXML__
    ClusterArtRecord(int cn_, float e_, float t_, float x_,float y_,float z_ ,const art::PtrVector< gm2dataproducts::CrystalFitResultArtRecord >& pcs ) :
      caloNum(cn_),energy(e_),time(t_),x(x_),y(y_),z(z_),parentCrystals(pcs)
    {}
#endif // __GCCXML__
    
  }; //end of ClusterArtRecord struct
  
  typedef std::vector<gm2dataproducts::ClusterArtRecord> ClusterArtRecordCollection;
} // end namespace gm2dataproducts

#endif // ClusterArtRecord_hh
