project(CppTestLib)

set(HEADER_FILES
        dice.h
        animal.h
)

set(SOURCE_FILES
        dice.cpp
        animal.cpp
)

add_library(CppTestLib_lib STATIC ${SOURCE_FILES} ${HEADER_FILES})
