##---------------------------------------------------------------------------
## Author:      nohal aka. Pavel Kalian
## Copyright:   
## License:     wxWidgets License
##---------------------------------------------------------------------------
 
# define minimum cmake version
CMAKE_MINIMUM_REQUIRED(VERSION 2.6.2)

PROJECT(findit_pi)

SET(PACKAGE_NAME findit_pi)
SET(VERBOSE_NAME Findit)
SET(TITLE_NAME FINDIT)
SET(CPACK_PACKAGE_CONTACT "Del Elson")

SET(BUNDLE_DATA FALSE)

INCLUDE( VERSION.cmake )
SET(PLUGIN_VERSION "${PLUGIN_VERSION_MAJOR}.${PLUGIN_VERSION_MINOR}.${PLUGIN_VERSION_PATCH}" )

SET(VERSION_MAJOR ${PLUGIN_VERSION_MAJOR})
SET(VERSION_MINOR "${PLUGIN_VERSION_MINOR}${PLUGIN_VERSION_PATCH}")
SET(VERSION_DATE ${PLUGIN_VERSION_DATE})

#SET(CMAKE_BUILD_TYPE Debug)

INCLUDE("cmake/PluginConfigure.cmake")

SET(SRC_FINDIT
	src/findit_pi.cpp
	src/findit_pi.h
	src/findit.cpp
	src/findit.h
	src/icons.cpp
	src/icons.h
    	src/gui.cpp
	src/gui.h
    	src/json_defs.h
    	src/jsonreader.h
    	src/jsonval.h
    	src/jsonwriter.h
    	src/jsonreader.cpp
    	src/jsonval.cpp
    	src/jsonwriter.cpp
)
IF(WIN32)
SET(SRC_TINYXML
	src/tinyxml/tinyxml.cpp
	src/tinyxml/tinyxml.h
	src/tinyxml/tinyxmlerror.cpp
	src/tinyxml/tinyxmlparser.cpp
	src/tinyxml/tinystr.cpp
	src/tinyxml/tinystr.h 
)
ENDIF(WIN32)


ADD_DEFINITIONS(-DTIXML_USE_STL)
ADD_LIBRARY(${PACKAGE_NAME} SHARED ${SRC_FINDIT} ${SRC_TINYXML})

INCLUDE("cmake/PluginInstall.cmake")
INCLUDE("cmake/PluginLocalization.cmake")
INCLUDE("cmake/PluginPackage.cmake")
