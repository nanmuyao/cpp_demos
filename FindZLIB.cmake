CMakePresets.json
        FindZLIB.cmake
        ZLIB-Target-release.cmake
        ZLIB-release-x86_64-data.cmake
        ZLIBConfig.cmake
        ZLIBConfigVersion.cmake
        ZLIBTargets.cmake
        cmakedeps_macros.cmake
        conan_toolchain.cmake
        conandeps_legacy.cmake
        module-ZLIB-Target-release.cmake
        module-ZLIB-release-x86_64-data.cmake
        module-ZLIBTargets.cmake
        mongoose-Target-release.cmake
        mongoose-config-version.cmake
        mongoose-config.cmake
        mongoose-release-x86_64-data.cmake
        mongooseTargets.cmake########## MACROS ###########################################################################
#############################################################################################

# Requires CMake > 3.15
if(${CMAKE_VERSION} VERSION_LESS "3.15")
    message(FATAL_ERROR "The 'CMakeDeps' generator only works with CMake >= 3.15")
endif()

if(ZLIB_FIND_QUIETLY)
    set(ZLIB_MESSAGE_MODE VERBOSE)
else()
    set(ZLIB_MESSAGE_MODE STATUS)
endif()

include(${CMAKE_CURRENT_LIST_DIR}/cmakedeps_macros.cmake)
include(${CMAKE_CURRENT_LIST_DIR}/module-ZLIBTargets.cmake)
include(CMakeFindDependencyMacro)

check_build_type_defined()

foreach(_DEPENDENCY ${zlib_FIND_DEPENDENCY_NAMES} )
    # Check that we have not already called a find_package with the transitive dependency
    if(NOT ${_DEPENDENCY}_FOUND)
        find_dependency(${_DEPENDENCY} REQUIRED ${${_DEPENDENCY}_FIND_MODE})
    endif()
endforeach()

set(ZLIB_VERSION_STRING "1.2.13")
set(ZLIB_INCLUDE_DIRS ${zlib_INCLUDE_DIRS_RELEASE} )
set(ZLIB_INCLUDE_DIR ${zlib_INCLUDE_DIRS_RELEASE} )
set(ZLIB_LIBRARIES ${zlib_LIBRARIES_RELEASE} )
set(ZLIB_DEFINITIONS ${zlib_DEFINITIONS_RELEASE} )


# Only the last installed configuration BUILD_MODULES are included to avoid the collision
foreach(_BUILD_MODULE ${zlib_BUILD_MODULES_PATHS_RELEASE} )
    message(${ZLIB_MESSAGE_MODE} "Conan: Including build module from '${_BUILD_MODULE}'")
    include(${_BUILD_MODULE})
endforeach()


include(FindPackageHandleStandardArgs)
set(ZLIB_FOUND 1)
set(ZLIB_VERSION "1.2.13")

find_package_handle_standard_args(ZLIB
                                  REQUIRED_VARS ZLIB_VERSION
                                  VERSION_VAR ZLIB_VERSION)
mark_as_advanced(ZLIB_FOUND ZLIB_VERSION)

set(ZLIB_FOUND 1)
set(ZLIB_VERSION "1.2.13")
mark_as_advanced(ZLIB_FOUND ZLIB_VERSION)

