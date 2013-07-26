// This file defines the WireID struct that is used by the tracking analysis
// framework to identify an individual wire.  Specification for the wire
// includes tracker number (which scallop it's in) station, view, layer, and
// wire number.
//
// For now, it is not a 'smart struct' as suggested in docDB entry 1153 (Data
// structure study for tracking software), but a naive struct. Expansion to a
// smart struct is anticipated to be fairly straightforward.
//
// For now, this is a pretty long header file without a corresponding *.cc file.
// This is so that other classes can #include it without having to alter their
// CMakeLists.txt to link against gm2dataproducts_strawtracker, but could change
// in the future.

// @author Tasha Arvanitis
// @date July 2013

// Include guard
#ifndef WIREID_HH
#define WIREID_HH

#include <ostream>
#include <string>

#include "messagefacility/MessageLogger/MessageLogger.h"

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
        // Constructor initializes everything to -1 - set the fields you care
        // about!
        WireID() :
            trackerNumber(-1),
            station(-1),
            view(na_view),
            layer(-1),
            wire(-1)
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
    // The printing function for ease of debugging: tracker number ~ station ~
    // view ~ layer ~ wire (Use tilde separation instead of '-' in order to
    // avoid confusion with negative numbers)
    std::ostream& operator<<(std::ostream& os, const WireID& id) {
        os << id.trackerNumber << " ~ " << id.station << " ~ " << id.view
            //id.view == u_view ? "u" : (id.view == v_view ? "v" : "na")
            << " ~ " << id.layer << " ~ " << id.wire;
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

    // Code modified from stackoverflow question 236129. This function takes a
    // string and a string containing delimiters as arguments and returns a
    // vector of the tokens resulting from such a split. 
    std::vector<std::string> split(const std::string& str, const std::string& delimiters)
    {
        std::vector<std::string> tokens;

        // Skip delimiters at beginning.
        std::string::size_type lastPos = str.find_first_not_of(delimiters, 0);
        // Find first "non-delimiter".
        std::string::size_type pos     = str.find_first_of(delimiters, lastPos);

        while (std::string::npos != pos || std::string::npos != lastPos)
        {
            // Found a token, add it to the vector.
            tokens.push_back(str.substr(lastPos, pos - lastPos));
            // Skip delimiters.  Note the "not_of"
            lastPos = str.find_first_not_of(delimiters, pos);
            // Find next "non-delimiter"
            pos = str.find_first_of(delimiters, lastPos);
        }

        return tokens;
    }

    // Check if a string is a positive integer (all the fields should be!)
    bool is_number(const std::string& s)
    {
        std::string::const_iterator it = s.begin();
        while (it != s.end() && std::isdigit(*it)) {
            ++it;
        }
        return !s.empty() && it == s.end();
    }

    // A construction function to reconstruct a WireID based on its standard
    // name (as provided in operator<<) - needed for WireID specification to be
    // linked to specific volumes in Geant. If an invalid string of some sort is
    // provided (not enough tokens, some tokens either empty or not numbers,
    // etc.), then an error message is printed and the WireID returned is filled
    // with -1's.
    WireID wireIDfromString(std::string str) {
        // Based on the output format in operator<<, the delimiters we want are
        // '~' and ' ' (space). Split the string.
        std::vector<std::string> tokens = split(str, "~ ");

        // Create the WireID - by default, it has invalid parameters.
        WireID wire;

        // Error checking 
        // Check that it's long enough.
        if (tokens.size() != 5) {
            mf::LogError("WireID") 
                << "Wrong number of tokens in conversion from string" 
                << " to WireID!! Returning invalid WireID." << std::endl;

            return wire;
        }
        // Check that the tokens are actually positive integers. This doesn't
        // check that the tokens fall in the appropriate ranges, as it isn't
        // linked to the geometry description.
        for (size_t i = 0; i < tokens.size(); i++) {
            if (!is_number(tokens[i])) {
                // Not a number: return the invalid (default) WireID
                mf::LogError("WireID") 
                    << "One or more tokens provided for conversion to "
                    << "WireID not numeric!! Returning invalid WireID." << std::endl;
                return wire;
            }
        }

        // Once we reach this point, we appear to have a valid string. Let's now
        // fill the WireID based on the tokens
        wire.setTrackerNumber(atoi(tokens[0].c_str()));
        wire.setStation(atoi(tokens[1].c_str()));
        // The view is moderately complicated - I'm hoping to change the
        // printout to actually say 'u' or 'v', rather than '0' or '1'.
        int viewInt = atoi(tokens[2].c_str());
        wire.setView(viewInt == 0 ? u_view : 
                (viewInt == 1 ? v_view : na_view));
        wire.setLayer(atoi(tokens[3].c_str()));
        wire.setWire(atoi(tokens[4].c_str()));

        return wire;
    }
#endif // __GCCXML__
}

#endif

