## CMAKE VAR
## <=====================================>
cmake_minimum_required( VERSION 3.17...3.20 )
set( CMAKE_BUILD_TYPE Release ) # Release / RelWithDebInfo / Debug
set( CMAKE_CXX_STANDARD 20 )
set( CMAKE_CXX_STANDARD_REQUIRED True )
set( CMAKE_RUNTIME_OUTPUT_DIRECTORY ${ABS_PATH}/ )
set( CMAKE_LIBRARY_OUTPUT_DIRECTORY ${ABS_PATH}/lib/ )
set( CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${ABS_PATH}/lib/ )
## <=====================================>


## PROJECT VAR
## <=====================================>
project( Incaribus
        VERSION
        0.1
        DESCRIPTION
        "Example project to test ShipWreckEngine"
        LANGUAGES
        CXX
        )
set( EXEC incaribus )
set( EXT cpp )

## SOURCE FOLDERS
set( SRC_FOLDERS
        ${CMAKE_SOURCE_DIR}/sources/
        ${CMAKE_SOURCE_DIR}/sources/scenes/
        )
## INCLUDE FOLDERS
set( INC_FOLDERS
        ${CMAKE_SOURCE_DIR}/libs/
        ${CMAKE_SOURCE_DIR}/libs/module/
        ${CMAKE_SOURCE_DIR}/libs/core/includes
        ${CMAKE_SOURCE_DIR}/includes/
        ${CMAKE_SOURCE_DIR}/includes/scenes/
        )
## IMPORTED SHARED LIBRARY NAME
set( SHARED_LIB_NAME
        Jsnp
        SWEngine-Core
        SWEngine-OpenGLModule
        glfw
        )
## IMPORTED SHARED LIBRARY LOCATION
set( SHARED_LIB_LOCATION
        ${CMAKE_SOURCE_DIR}/libs/libJsnp.so
        ${CMAKE_SOURCE_DIR}/libs/libSWEngine-Core.so
        ${CMAKE_SOURCE_DIR}/libs/libSWEngine-OpenGLModule.so
        ${CMAKE_SOURCE_DIR}/libs/libglfw.so
        )
## <=====================================>


## GET SOURCES
## <=====================================>
foreach(filePath ${SRC_FOLDERS})
    string(APPEND TMP "${filePath}*.${EXT};")
endforeach()
file(GLOB SRC ${TMP})
## <=====================================>


## OUTPUT
## <=====================================>
## EXECUTABLE
add_executable(${EXEC} ${SRC})

## or SHARED LIB
# add_library(${EXEC} SHARED ${SRC})

## or STATIC LIB
# add_library(${EXEC} STATIC ${SRC})
## <=====================================>


## ADD INCLUDES
## <=====================================>
target_include_directories(${EXEC} PRIVATE ${INC_FOLDERS})
## <=====================================>

## ADD PARAMETER
## <=====================================>
if (UNIX)
    target_compile_options(${EXEC} PRIVATE -g3)
endif (UNIX)
## <=====================================>


## SHARED LIBRARY LINKING
## <=====================================>
list(LENGTH SHARED_LIB_NAME  list_len)
math(EXPR LIST_LEN "${list_len} - 1")

foreach(ctr RANGE ${LIST_LEN})
    list(GET SHARED_LIB_NAME ${ctr} lib)
    list(GET SHARED_LIB_LOCATION ${ctr} loc)
    add_library(${lib} SHARED IMPORTED)
    set_target_properties(${lib} PROPERTIES
            IMPORTED_LOCATION ${loc}
            )
endforeach()
target_link_libraries(${EXEC}
        PUBLIC
        ${SHARED_LIB_NAME}
        )
## <=====================================>


## PACKAGE LINKING
## <=====================================>
## <=====================================>