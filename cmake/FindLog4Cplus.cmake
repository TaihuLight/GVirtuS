################################################################################
#
# CMake script for finding LOG4CPLUS.
# The default CMake search process is used to locate files.
#
# This script creates the following variables:
#  LOG4CPLUS_FOUND: Boolean that indicates if the package was found
#  LOG4CPLUS_INCLUDE_DIRS: Paths to the necessary header files
#  LOG4CPLUS_LIBRARIES: Package libraries
#  LOG4CPLUS_LIBRARY_DIRS: Path to package libraries
#
################################################################################

include(FindPackageHandleStandardArgs)

set(LOG4CPLUS_INC_LIST
        "/usr/include"
        "/usr/local/include"
        )

set(LOG4CPLUS_LIB_LIST
        "/usr/lib"
        "/usr/local/lib"
        )

# If LOG4CPLUS_ROOT is available, set up our hints
if(LOG4CPLUS_ROOT)
    # Includes
    list(APPEND LOG4CPLUS_INC_LIST
            "${LOG4CPLUS_ROOT}/include"
            "${LOG4CPLUS_ROOT}"
            )

    # Libraries win32
    if(MSVC)
        # Visual Studio 2008
        if(MSVC9)
            list(APPEND LOG4CPLUS_LIB_LIST "${LOG4CPLUS_ROOT}/lib/msvc2008")
        endif()
        # Visual Studio 2010
        if(MSVC10)
            list(APPEND LOG4CPLUS_LIB_LIST "${LOG4CPLUS_ROOT}/lib/msvc2010")
        endif()
    endif()

    # Libraries all
    list(APPEND LOG4CPLUS_LIB_LIST "${LOG4CPLUS_ROOT}/lib")
endif()

# Find headers
find_path(
        LOG4CPLUS_INCLUDE_DIR
        NAMES
        log4cplus/logger.h
        HINTS
        ${LOG4CPLUS_INC_LIST}
)

# Find release library
find_library(
        LOG4CPLUS_LIBRARY
        NAMES
        log4cplus
        HINTS
        ${LOG4CPLUS_LIB_LIST}
)

# Find debug library, if on UNIX this is the same as release
if(WIN32)
    find_library(LOG4CPLUS_LIBRARY_DEBUG NAMES LOG4CPLUS_d HINTS ${LOG4CPLUS_LIB_LIST})
else()
    set(LOG4CPLUS_LIBRARY_DEBUG ${LOG4CPLUS_LIBRARY})
endif()

# Set LOG4CPLUS_FOUND honoring the QUIET and REQUIRED arguments
find_package_handle_standard_args(LOG4CPLUS DEFAULT_MSG LOG4CPLUS_LIBRARY LOG4CPLUS_INCLUDE_DIR)

# Output variables
if(LOG4CPLUS_FOUND)
    # Include dirs
    set(LOG4CPLUS_INCLUDE_DIRS ${LOG4CPLUS_INCLUDE_DIR})

    # Release Libraries
    if(LOG4CPLUS_LIBRARY)
        LIST(APPEND LOG4CPLUS_LIBRARIES optimized ${LOG4CPLUS_LIBRARY})
    endif()

    # Debug Libraries
    if(LOG4CPLUS_LIBRARY_DEBUG)
        LIST(APPEND LOG4CPLUS_LIBRARIES debug ${LOG4CPLUS_LIBRARY_DEBUG})
    endif()

    # Link dirs
    get_filename_component(LOG4CPLUS_LIBRARY_DIRS ${LOG4CPLUS_LIBRARY} PATH)
else()
    message(FATAL_ERROR "LOG4CPLUS library not found")
endif()

# Advanced options for not cluttering the cmake UIs
mark_as_advanced(LOG4CPLUS_INCLUDE_DIR LOG4CPLUS_LIBRARY LOG4CPLUS_LIBRARY_DEBUG)
