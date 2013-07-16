// This file defines the WireID struct that is used by the tracking analysis
// framework to identify an individual wire.  Specification for the wire
// includes tracker number (which scallop it's in) station, view, layer, and
// wire number.
//
// For now, it is not a 'smart struct' as suggested in docDB entry 1153 (Data
// structure study for tracking software), but a naive struct. Expansion to a
// smart struct is anticipated to be fairly straightforward.
//
// TODO: Add #ifndef gccxml things so that ROOT doesn't hate our guts. Though
// come to think of it, it probably still will.

// @author Tasha Arvanitis
// @date July 2013

// Include guard
#ifndef WIREID_HH
#define WIREID_HH

#include <ostream>

// All in the namespace for straw tracking
namespace gm2strawtracker {

    // Define the StrawView enum to keep track of the views.
    enum StrawView {
        u_view,
        v_view,
        // A N/A view for any errors and initialization.
        na_view
    };

    struct WireID {
        private:
        // Tracker number should range from 0-1 and describes which of the
        // tracking stations contains this wire: 0 for the one directly opposite
        // the inflector, and 1 for the 270 degree one.
        short trackerNumber; 

        // Station number (describes which of the straw station/boxes this wire
        // is in) should range from 0 to around 20 at most.
        short station;

        // View is a member of the StrawView enum and describes whether the
        // wire in question is a u-view or a v-view wire. We still need to
        // figure out or define which direction is u-view.
        StrawView view;

        // Layer describes which of the two layers of that view this wire is in
        // (see the 3d model). It should range from 0-1.
        short layer;

        // Wire gives the wire number within the previously-specified layer. It
        // will range from 0-n, depending on the size of the station in
        // question, and wire 0 is (I think?) the one closest to the scallop
        // edge.
        short wire;

        public:
        // Constructor initializes everything
        WireID() :
            trackerNumber(0),
            station(0),
            view(na_view),
            layer(0),
            wire(0)
        {}
        
        // ROOT shouldn't see these
#ifndef __GCCXML__
        // For the sake of future expansion to a smart struct, access to the
        // fields is through methods. Names are self-explanatory, and the
        // methods are simple enough to put in here. Should they be inlined?
        // Getters
        short getTrackerNumber() const {
            return trackerNumber;
        }
        short getStation() const {
            return station;
        }
        StrawView getView() const {
            return view;
        }
        short getLayer() const {
            return layer;
        }
        short getWire() const {
            return wire;
        }

        // Setters
        void setTrackerNumber(short newValue) {
            trackerNumber = newValue;
        }
        void setStation(short newValue) {
            station = newValue;
        }
        void setView(StrawView newValue) {
            view = newValue;
        }
        void setLayer(short newValue) {
            layer = newValue;
        }
        void setWire(short newValue) {
            wire = newValue;
        }

        // Print information about the tracker
        friend std::ostream& operator<<(std::ostream& os, const WireID& id);
#endif // __GCCXML__

    };

    // ROOT shouldn't see these things.
#ifndef __GCCXML__
    // The printing function for ease of debugging: tracker number - station -
    // view - layer - wire
    std::ostream& operator<<(std::ostream& os, const WireID& id) {
        os << id.trackerNumber << " - " << id.station << " - " << id.view
            //id.view == u_view ? "u" : (id.view == v_view ? "v" : "na")
            << " - " << id.layer << " - " << id.wire;
        return os;
    }

    // A comparison function for the WireID, so that it can be sorted. This is
    // also essential in order to use a WireID as a key in a std::map.
    inline bool operator<(WireID const& left, WireID const& right) {
        // Compare the 'most significant' things first:
        // The order of comparison is tracker number, station, view, layer, and
        // then wire.
        if (left.getTrackerNumber() != right.getTrackerNumber()) {
            return left.getTrackerNumber() < right.getTrackerNumber();
        }
        if (left.getStation() != right.getStation()) {
            return left.getStation() < right.getStation();
        }
        if (left.getView() != right.getView()) {
            return left.getView() < right.getView();
        }
        if (left.getLayer() != right.getLayer()) {
            return left.getLayer() < right.getLayer();
        }
        if (left.getWire() != right.getWire()) {
            return left.getWire() < right.getWire();
        }
        // If we get here, we have identical WireID's, so we have to return
        // false (WireID 1 is *not* less than WireID 2). If you return true, all
        // hell breaks loose, because a map can't possibly find an entry, since
        // no two keys will ever look the same!
        return false;
    }
#endif // __GCCXML__

}

#endif

