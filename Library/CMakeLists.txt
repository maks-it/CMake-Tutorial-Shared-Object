# Error LNK1104: cannot open file 'Debug\Library.lib'
set(CMAKE_WINDOWS_EXPORT_ALL_SYMBOLS ON)

# add library as Shared Object
add_library(Library SHARED Library.cxx)

# state that anybody linking to us needs to include the current source dir
# to find Library.h, while we don't.
target_include_directories(Library
                           INTERFACE
                            $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}>
                            $<INSTALL_INTERFACE:include>
                           )

# should we use our own math functions
#to test the logic in your CMakeLists, delete the cache each time before re-running CMake
option(USE_MYMATH "Use tutorial provided math implementation" OFF)
if(USE_MYMATH)
endif(USE_MYMATH)


# example to add another library
add_library(AddLibrary STATIC add.cxx)

 set_target_properties(AddLibrary PROPERTIES
                        POSITION_INDEPENDENT_CODE ${BUILD_SHARED_LIBS}
                        )

target_link_libraries(Library PRIVATE AddLibrary)



target_compile_definitions(Library PRIVATE "$<$<BOOL:${USE_MYMATH}>:USE_MYMATH>")

# define the symbol stating we are using the declspec(dllexport) when
# building on windows
option(DLL_EXPORT "define the symbol stating we are using the declspec(dllexport)" ON)
target_compile_definitions(Library PRIVATE "$<$<BOOL:${DLL_EXPORT}>:DLL_EXPORT>")

# setup the version numbering
set_property(TARGET Library PROPERTY VERSION "1.0.0")
set_property(TARGET Library PROPERTY SOVERSION "1")

install(TARGETS Library
        DESTINATION lib
        EXPORT LibraryTargets)
install(FILES Library.h DESTINATION include)




