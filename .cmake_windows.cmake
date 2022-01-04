
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
        ${CMAKE_SOURCE_DIR}/libs/module/opengl/
        ${CMAKE_SOURCE_DIR}/libs/core/includes/
        ${CMAKE_SOURCE_DIR}/includes/
        ${CMAKE_SOURCE_DIR}/includes/scenes/
        )
## IMPORTED SHARED LIBRARY NAME
set( SHARED_LIB_NAME
        Jsnp
        SWEngine-Core
        SWEngine-OpenGLModule
        glfw3
        )
## IMPORTED SHARED LIBRARY LOCATION
set( SHARED_LIB_LOCATION
        ${CMAKE_SOURCE_DIR}/libs/Jsnp.dll
        ${CMAKE_SOURCE_DIR}/libs/SWEngine-Core.dll
        ${CMAKE_SOURCE_DIR}/libs/SWEngine-OpenGLModule.dll
        ${CMAKE_SOURCE_DIR}/libs/glfw3.dll
        )
## IMPORTED SHARED LIBRARY lib file
set( SHARED_LIB
        ${CMAKE_SOURCE_DIR}/libs/Jsnp.lib
        ${CMAKE_SOURCE_DIR}/libs/SWEngine-Core.lib
        ${CMAKE_SOURCE_DIR}/libs/SWEngine-OpenGLModule.lib
        ${CMAKE_SOURCE_DIR}/libs/glfw3.lib
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
    list(GET SHARED_LIB ${ctr} filelib)
    add_library(${lib} SHARED IMPORTED)
    set_target_properties(${lib} PROPERTIES
            IMPORTED_LOCATION ${loc}
            IMPORTED_IMPLIB ${filelib}
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