// This file defines the WireID struct that is used by the tracking analysis
// framework to identify an individual wire.  Specification for the wire
// includes station number (which scallop it's in) module, view, layer, and
// wire number.
//
// For now, it is not a 'smart struct' as suggested in docDB entry 1153 (Data
// structure study for tracking software), but a naive struct. Expansion to a
// smart struct is anticipated to be fairly straightforward.

// @author Tasha Arvanitis
// @date July 2013

// Include guard
#ifndef WIREID_HH
#define WIREID_HH

#include <ostream>
#include <string>
#include <vector>

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
        // tracking modules contains this wire: 0 for the one directly opposite
        // the inflector, and 1 for the 270 degree one.
        short station; 

        // Module number (describes which of the straw modules/boxes this wire
        // is in) should range from 0 to around 20 at most.
        short module;

        // View is a member of the StrawView enum and describes whether the
        // wire in question is a u-view or a v-view wire. We still need to
        // figure out or define which direction is u-view.
        StrawView view;

        // Layer describes which of the two layers of that view this wire is in
        // (see the 3d model). It should range from 0-1.
        short layer;

        // Wire gives the wire number within the previously-specified layer. It
        // will range from 0-n, depending on the size of the module in
        // question, and wire 0 is (I think?) the one closest to the scallop
        // edge.
        short wire;

        public:
        // Constructors
        WireID();
        
        // ROOT shouldn't see these
#ifndef __GCCXML__
        // Two other constructors, which ROOT can't see but other classes
        // can.
        // An easy constructor - just pass in all the relevant information
        WireID(short station_in, short module_in, StrawView view_in,
                short layer_in, short wire_in);

        // A copy constructor
        WireID(const WireID& other);

        // For the sake of future expansion to a smart struct, access to the
        // fields is through methods. Names are self-explanatory, and the
        // methods are simple enough to put in here. Should they be inlined?
        // Getters
        inline short getStation() const {
            return station;
        }
        inline short getModule() const {
            return module;
        }
        inline StrawView getView() const {
            return view;
        }
        inline short getLayer() const {
            return layer;
        }
        inline short getWire() const {
            return wire;
        }

        // Setters
        inline void setStation(short newValue) {
            station = newValue;
        }
        inline void setModule(short newValue) {
            module = newValue;
        }
        inline void setView(StrawView newValue) {
            view = newValue;
        }
        inline void setLayer(short newValue) {
            layer = newValue;
        }
        inline void setWire(short newValue) {
            wire = newValue;
        }

        
        // A useful function for splitting strings on various delimiters
        static std::vector<std::string> split(const std::string& str, 
                const std::string& delimiters);
        // Method to check if a string is a positive integer (all the
        // fields should be!)
        static bool is_number(const std::string& s);

        // Give special functions access to the member data
        friend std::ostream& operator<<(std::ostream& os, const WireID& id);
        friend bool operator<(WireID const& left, WireID const& right);
#endif // __GCCXML__

    };

    // ROOT shouldn't see the various non-member functions pertaining to
    // WireIDs
#ifndef __GCCXML__
    // A printing function for the WireID
    std::ostream& operator<<(std::ostream& os, const WireID& id);

    // A comparison function for the WireID, so that it can be sorted. This is
    // also essential in order to use a WireID as a key in a std::map.
    bool operator<(WireID const& left, WireID const& right);

    // A publicly-available function to get a WireID from its string
    // representation.
    WireID wireIDfromString(std::string str);
#endif // __GCCXML__
}

#endif // WIREID_HH

