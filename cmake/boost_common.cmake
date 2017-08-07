#boost common config

SET(BOOST_VERSION 1_61_0)
SET(BOOST_FOLDER boost_${BOOST_VERSION})
SET(Boost_NO_BOOST_CMAKE ON)

if(WIN32)

SET(BOOST_INCLUDE_PATH L:/boost/${BOOST_FOLDER})
SET(BOOST_LIB_PATH L:/boost/${BOOST_FOLDER}/stage/lib)

set(Boost_USE_STATIC_RUNTIME OFF)

elseif(UNIX)

SET(BOOST_INCLUDE_PATH /usr/lib64/${BOOST_FOLDER}/include)
SET(BOOST_LIB_PATH /usr/lib64/${BOOST_FOLDER}/lib)

set(Boost_USE_STATIC_RUNTIME ON)

endif()

#set(Boost_USE_STATIC_RUNTIME ON)

#set(BOOST_ROOT ${BOOST_INCLUDE_PATH})
set(BOOST_INCLUDEDIR ${BOOST_INCLUDE_PATH})
set(BOOST_LIBRARYDIR ${BOOST_LIB_PATH})

message(STATUS "BOOST_ROOT="${BOOST_ROOT})
message(STATUS "BOOST_INCLUDEDIR="${BOOST_INCLUDEDIR})
message(STATUS "BOOST_LIBRARYDIR="${BOOST_LIBRARYDIR})

set(Boost_USE_STATIC_LIBS ON)
set(Boost_USE_MULTITHREADED ON)

find_package(Boost REQUIRED COMPONENTS chrono program_options thread system filesystem date_time regex)

if(NOT Boost_FOUND)
    message(SEND_ERROR "Boost not found.")
endif()

include_directories(
    ${BOOST_INCLUDE_PATH}
)
