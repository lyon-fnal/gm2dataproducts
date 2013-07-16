#ifndef TRACKERGEOMHITARTRECORD_HH
#define TRACKERGEOMHITARTRECORD_HH

// Provides the declaration of the ROOT-storable class used as a second step
// for the straw tracker analysis (after the tracker hits). This class simply
// holds a hit's information as well as tracker coordinates of the wire and
// drift distance in the straw
//
// @author Leah Welty-Rieger
// @author Tasha Arvanitis
// @date July 2013

#include <vector>
#include "WireID.hh"

namespace gm2strawtracker {
    struct TrackerGeomHitArtRecord {
        // Specification for the wire: includes station, view, layer,
        // wire #
        WireID id;

        // Time at which the hit was registered (includes both the time of the
        // hit and drift) (units: nanoseconds)
        double time;

        // Width of the pulse from the sensors (in ns)
        double width;

        // Index of the hit (this is the nth time that this straw was hit in the
        // fill)
        int index;

        // Was there some sort of error in reading this out?
        bool errorFlag;

        // Coordinates in tracking coordinates of the wire that was hit. In mm
        // by default.
        double x;
        double y;
        double z;

        // Drift distance, in mm.
        double driftDistance;

        // Default constructor
        TrackerGeomHitArtRecord() :
            id(),
            time(0.),
            width(0.),
            index(0),
            errorFlag(false),
            x(0.),
            y(0.),
            z(0.),
            driftDistance(0.)
        {}

        // A nicer constructor: ROOT doesn't see it, but other classes can.
#ifndef __GCCXML__
        TrackerGeomHitArtRecord(WireID inid, double intime, double inwidth, 
                int inindex, bool inerrorFlag, double inx, double iny, 
                double inz, double indriftDistance) :
            id(inid),
            time(intime),
            width(inwidth),
            index(inindex),
            errorFlag(inerrorFlag),
            x(inx),
            y(iny),
            z(inz),
            driftDistance(indriftDistance)
        {}
#endif // __GCCXML__

    }; // TrackerGeomHitArtRecord struct definition

    typedef std::vector<TrackerGeomHitArtRecord> TrackerGeomHitArtRecordCollection;
    
} // namespace

#endif

