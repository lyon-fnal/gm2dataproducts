#ifndef IslandArtRecord_hh
#define IslandArtRecord_hh

/** @file IslandArtRecord.hh
 
    Implements the digitized samples in art record
 
    @author loreto "pete" alonzi - alonzi@uw.edu
    @date 2013

 */

#include <vector>

namespace gm2dataproducts {
    struct IslandArtRecord {
        
        /** Which calorimeter was hit. */
        int caloNum;
        
        /** Which XTAL was hit. */
        int xtalNum;
        
        /** Index of clock tick for sample */
        int time;
        
        /** voltage of sample 12-bit in real life but
	    we are using a 16-bit structure. Take care
	    to only use first 12 bits.*/
      std::vector<short int> voltage;
        
        IslandArtRecord() :
        caloNum(0), xtalNum(0), time(0)
        {}
        
        virtual ~IslandArtRecord(){};
        
        // ROOT doesn't need to know the rest
#ifndef __GCCXML__
      IslandArtRecord(int cn, int xn, int time,std::vectgor<short int> v) :
        caloNum(cn), xtalNum(xn), time(time), voltage(v)
       {}
#endif // __GCCXML__

    }; //end of IslandArtRecord struct
    
    typedef std::vector<IslandArtRecord> IslandArtRecordCollection;
} // end namespace gm2dataproducts

#endif // IslandArtRecord_hh
