#ifndef IslandArtRecord_hh
#define IslandArtRecord_hh

/** @file IslandArtRecord.hh
 
    Implements the T-Method waveform islands in art record
 
    @author loreto "pete" alonzi - alonzi@uw.edu
    @date 2013

 */

#include <vector>

namespace gm2dataproducts {
    struct IslandArtRecord {
        
        /** calorimeter ID */
        int caloNum;
        
        /** crystal ID */
        int xtalNum;
        
        /** clock tick for start of island */
        int time;
        
        /** voltage vector, the length is variable
	    but quantized. The quanta (L) is a 
	    characteristic pulse length. The number (n) of
	    them that appear in the vector is a decision
	    made by the "island chopper".*/
      std::vector<short int> voltage;
        
        IslandArtRecord() :
        caloNum(0), xtalNum(0), time(0)
        {}
        
        virtual ~IslandArtRecord(){};
        
        // ROOT doesn't need to know the rest
#ifndef __GCCXML__
      IslandArtRecord(int cn, int xn, int time,std::vector<short int> v) :
        caloNum(cn), xtalNum(xn), time(time), voltage(v)
       {}
#endif // __GCCXML__

    }; //end of IslandArtRecord struct
    
    typedef std::vector<IslandArtRecord> IslandArtRecordCollection;
} // end namespace gm2dataproducts

#endif // IslandArtRecord_hh
