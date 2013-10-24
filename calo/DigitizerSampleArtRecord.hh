#ifndef DigitizerSampleArtRecord_hh
#define DigitizerSampleArtRecord_hh

/** @file DigitizerSampleArtRecord.hh
 
    Implements the digitized samples in art record
 
    @author loreto "pete" alonzi - alonzi@uw.edu
    @date 2013

 */

#include <vector>

namespace gm2dataproducts {
    struct DigitizerSampleArtRecord {
        
        /** Which calorimeter was hit. */
        int caloNum;
        
        /** Which XTAL was hit. */
        int xtalNum;
        
        /** Index of clock tick for sample */
        int time;
        
        /** voltage of sample 12-bit in real life but
	    we are using a 16-bit structure. Take care
	    to only use first 12 bits.*/
        short int voltage;
        
        DigitizerSampleArtRecord() :
        caloNum(0), xtalNum(0), time(0), voltage(0.)
        {}
        
        virtual ~DigitizerSampleArtRecord(){};
        
        // ROOT doesn't need to know the rest
#ifndef __GCCXML__
      DigitizerSampleArtRecord(int cn, int xn, int time,float v) :
        caloNum(cn), xtalNum(xn), time(time), voltage(v)
       {}
#endif // __GCCXML__

    }; //end of DigitizerSampleArtRecord struct
    
    typedef std::vector<DigitizerSampleArtRecord> DigitizerSampleArtRecordCollection;
} // end namespace gm2dataproducts

#endif // DigitizerSampleArtRecord_hh
