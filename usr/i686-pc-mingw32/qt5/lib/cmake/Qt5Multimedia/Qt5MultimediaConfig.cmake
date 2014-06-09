
if (CMAKE_VERSION VERSION_LESS 2.8.3)
    message(FATAL_ERROR "Qt 5 requires at least CMake version 2.8.3")
endif()

get_filename_component(_qt5Multimedia_install_prefix "${CMAKE_CURRENT_LIST_DIR}/../../../" ABSOLUTE)

# For backwards compatibility only. Use Qt5Multimedia_VERSION instead.
set(Qt5Multimedia_VERSION_STRING 5.1.0)

set(Qt5Multimedia_LIBRARIES Qt5::Multimedia)

macro(_qt5_Multimedia_check_file_exists file)
    if(NOT EXISTS "${file}" )
        message(FATAL_ERROR "The imported target \"Qt5::Multimedia\" references the file
   \"${file}\"
but this file does not exist.  Possible reasons include:
* The file was deleted, renamed, or moved to another location.
* An install or uninstall procedure did not complete successfully.
* The installation package was faulty and contained
   \"${CMAKE_CURRENT_LIST_FILE}\"
but not all the files it references.
")
    endif()
endmacro()


macro(_populate_Multimedia_target_properties Configuration LIB_LOCATION IMPLIB_LOCATION)
    set_property(TARGET Qt5::Multimedia APPEND PROPERTY IMPORTED_CONFIGURATIONS ${Configuration})

    set(imported_location "${_qt5Multimedia_install_prefix}/lib/${LIB_LOCATION}")
    _qt5_Multimedia_check_file_exists(${imported_location})
    set_target_properties(Qt5::Multimedia PROPERTIES
        "IMPORTED_LINK_INTERFACE_LIBRARIES_${Configuration}" "${_Qt5Multimedia_LIB_DEPENDENCIES}"
        "IMPORTED_LOCATION_${Configuration}" ${imported_location}
    )

    set(imported_implib "${_qt5Multimedia_install_prefix}/lib/${IMPLIB_LOCATION}")
    _qt5_Multimedia_check_file_exists(${imported_implib})
    if(NOT "${IMPLIB_LOCATION}" STREQUAL "")
        set_target_properties(Qt5::Multimedia PROPERTIES
        "IMPORTED_IMPLIB_${Configuration}" ${imported_implib}
        )
    endif()
endmacro()

if (NOT TARGET Qt5::Multimedia)

    set(_Qt5Multimedia_OWN_INCLUDE_DIRS "${_qt5Multimedia_install_prefix}/include/" "${_qt5Multimedia_install_prefix}/include/QtMultimedia")
    set(Qt5Multimedia_PRIVATE_INCLUDE_DIRS
        "${_qt5Multimedia_install_prefix}/include/QtMultimedia/${Qt5Multimedia_VERSION_STRING}"
        "${_qt5Multimedia_install_prefix}/include/QtMultimedia/${Qt5Multimedia_VERSION_STRING}/QtMultimedia"
    )

    foreach(_dir ${_Qt5Multimedia_OWN_INCLUDE_DIRS}
                 ${Qt5Multimedia_PRIVATE_INCLUDE_DIRS}
                 )
        _qt5_Multimedia_check_file_exists(${_dir})
    endforeach()

    set(Qt5Multimedia_INCLUDE_DIRS ${_Qt5Multimedia_OWN_INCLUDE_DIRS})

    set(Qt5Multimedia_DEFINITIONS -DQT_MULTIMEDIA_LIB)
    set(Qt5Multimedia_COMPILE_DEFINITIONS QT_MULTIMEDIA_LIB)

    set(_Qt5Multimedia_MODULE_DEPENDENCIES "Gui;Network;Core")

    set(_Qt5Multimedia_FIND_DEPENDENCIES_REQUIRED)
    if (Qt5Multimedia_FIND_REQUIRED)
        set(_Qt5Multimedia_FIND_DEPENDENCIES_REQUIRED REQUIRED)
    endif()
    set(_Qt5Multimedia_FIND_DEPENDENCIES_QUIET)
    if (Qt5Multimedia_FIND_QUIETLY)
        set(_Qt5Multimedia_DEPENDENCIES_FIND_QUIET QUIET)
    endif()
    set(_Qt5Multimedia_FIND_VERSION_EXACT)
    if (Qt5Multimedia_FIND_VERSION_EXACT)
        set(_Qt5Multimedia_FIND_VERSION_EXACT EXACT)
    endif()

    foreach(_module_dep ${_Qt5Multimedia_MODULE_DEPENDENCIES})
        if (NOT Qt5${_module_dep}_FOUND)
            find_package(Qt5${_module_dep}
                ${Qt5Multimedia_VERSION_STRING} ${_Qt5Multimedia_FIND_VERSION_EXACT}
                ${_Qt5Multimedia_DEPENDENCIES_FIND_QUIET}
                ${_Qt5Multimedia_FIND_DEPENDENCIES_REQUIRED}
                PATHS "${CMAKE_CURRENT_LIST_DIR}/.." NO_DEFAULT_PATH
            )
        endif()

        if (NOT Qt5${_module_dep}_FOUND)
            set(Qt5Multimedia_FOUND False)
            return()
        endif()

        list(APPEND Qt5Multimedia_INCLUDE_DIRS "${Qt5${_module_dep}_INCLUDE_DIRS}")
        list(APPEND Qt5Multimedia_PRIVATE_INCLUDE_DIRS "${Qt5${_module_dep}_PRIVATE_INCLUDE_DIRS}")
        list(APPEND Qt5Multimedia_DEFINITIONS ${Qt5${_module_dep}_DEFINITIONS})
        list(APPEND Qt5Multimedia_COMPILE_DEFINITIONS ${Qt5${_module_dep}_COMPILE_DEFINITIONS})
        list(APPEND Qt5Multimedia_EXECUTABLE_COMPILE_FLAGS ${Qt5${_module_dep}_EXECUTABLE_COMPILE_FLAGS})
    endforeach()
    list(REMOVE_DUPLICATES Qt5Multimedia_INCLUDE_DIRS)
    list(REMOVE_DUPLICATES Qt5Multimedia_PRIVATE_INCLUDE_DIRS)
    list(REMOVE_DUPLICATES Qt5Multimedia_DEFINITIONS)
    list(REMOVE_DUPLICATES Qt5Multimedia_COMPILE_DEFINITIONS)
    if (Qt5Multimedia_EXECUTABLE_COMPILE_FLAGS)
        list(REMOVE_DUPLICATES Qt5Multimedia_EXECUTABLE_COMPILE_FLAGS)
    endif()

    set(_Qt5Multimedia_LIB_DEPENDENCIES "Qt5::Gui;Qt5::Network;Qt5::Core")

    add_library(Qt5::Multimedia STATIC IMPORTED)
    set_property(TARGET Qt5::Multimedia PROPERTY IMPORTED_LINK_INTERFACE_LANGUAGES CXX)

    set_property(TARGET Qt5::Multimedia PROPERTY
      INTERFACE_INCLUDE_DIRECTORIES ${_Qt5Multimedia_OWN_INCLUDE_DIRS})
    set_property(TARGET Qt5::Multimedia PROPERTY
      INTERFACE_COMPILE_DEFINITIONS QT_MULTIMEDIA_LIB)

    _populate_Multimedia_target_properties(RELEASE "libQt5Multimedia.a" "" )

    if (EXISTS "${_qt5Multimedia_install_prefix}/lib/libQt5Multimediad.a" )
        _populate_Multimedia_target_properties(DEBUG "libQt5Multimediad.a" "" )
    endif()





_qt5_Multimedia_check_file_exists("${CMAKE_CURRENT_LIST_DIR}/Qt5MultimediaConfigVersion.cmake")

endif()
