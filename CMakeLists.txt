#  This file is the main CMakeLists.txt file for the @artg4@ package. It is used by the g-2 build system.
# h2. Introduction 

# h2. Main code

# Ensure we are using a moden version of CMake
CMAKE_MINIMUM_REQUIRED (VERSION 2.8)

# h3. Project definition

# --> Define the name of this project (replace @gm2artexamples@ with your 
# project name - use all lowercase)
PROJECT (gm2dataproducts)

# h3. Load CMake modules
set( CETBUILDTOOLS_VERSION $ENV{CETBUILDTOOLS_VERSION} )
if( NOT CETBUILDTOOLS_VERSION )
  message( FATAL_ERROR "ERROR: setup cetbuildtools to get the cmake modules" )
endif()
set( CMAKE_MODULE_PATH $ENV{CETBUILDTOOLS_DIR}/Modules ${CMAKE_MODULE_PATH} )

# art contains cmake modules that we use
set( ART_VERSION $ENV{ART_VERSION} )
if( NOT ART_VERSION )
  message( FATAL_ERROR "ERROR: setup art to get the cmake modules" )
endif()
set( CMAKE_MODULE_PATH $ENV{ART_DIR}/Modules ${CMAKE_MODULE_PATH} )

# Include the necessary macros
include(CetCMakeEnv)
include(BuildPlugins)
include(ArtMake)

# h3. Configure this product

# Configure
cet_cmake_env()

#set_install_root()

# Do the same compiler flag stuff as Art
cet_set_compiler_flags(DIAGS VIGILANT WERROR 
   EXTRA_FLAGS -pedantic
   EXTRA_CXX_FLAGS -std=c++11
)

cet_report_compiler_flags()


# Locate some UPS areas (the versions are just minimum required) and setup include paths
# These are needed for Art stuff

find_ups_product(cetbuildtools v3_07_00)
find_ups_product(art v1_08_10)

# Make sure we have gcc
cet_check_gcc()

# Macros for art_make and simple plugins
include(ArtDictionary)

# Build these directories
add_subdirectory( calo )
add_subdirectory( strawtracker )
add_subdirectory( ups )

# Packaging facility
include(UseCPack)
