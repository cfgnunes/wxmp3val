# =============================================================================
# Initialization
# =============================================================================

cmake_minimum_required(VERSION 3.10)

# Set the project name and version
project(
    wxMP3val
    VERSION 4.1.0.0
    DESCRIPTION "wxMP3val is a free front-end for the MP3val."
    HOMEPAGE_URL "https://github.com/cfgnunes/wxmp3val"
)

# Specify the C++ standard
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Define a lowercase project name
string(TOLOWER ${CMAKE_PROJECT_NAME} CMAKE_BIN_NAME)

# =============================================================================
# Project dependencies
# =============================================================================

# -----------------------------------------------------------------------------
# wxWidgets
# -----------------------------------------------------------------------------
find_package(wxWidgets REQUIRED)

if(WIN32)
    set(wxWidgets_ROOT_DIR "C:/wxWidgets-3.1.1")
    set(wxWidgets_LIB_DIR "C:/wxWidgets-3.1.1/lib/gcc810_dll")
    set(wxWidgets_CONFIGURATION mwsu)
endif()

include(${wxWidgets_USE_FILE})

# -----------------------------------------------------------------------------
# Gettext
# -----------------------------------------------------------------------------
find_package(Gettext)

# =============================================================================
# Set some default paths
# =============================================================================

# Set the root folder, where all sources are located in
if(NOT DEFINED CMAKE_SOURCES_ROOT_DIR)
    set(CMAKE_SOURCES_ROOT_DIR ${CMAKE_CURRENT_SOURCE_DIR})
endif()

# Set a folder for the data
if(NOT DEFINED CMAKE_DATA_DIR)
    set(CMAKE_DATA_DIR "data")
endif()

# Set a folder for the dcoumentation
if(NOT DEFINED CMAKE_DOC_DIR)
    set(CMAKE_DOC_DIR "doc")
endif()

# =============================================================================
# Configure templates
# =============================================================================

# Set some strings for the templates: author
if(NOT DEFINED CMAKE_PROJECT_AUTHOR)
    set(CMAKE_PROJECT_AUTHOR "Cristiano Fraga G. Nunes")
endif()

# Set some strings for the templates: e-mail
if(NOT DEFINED CMAKE_PROJECT_EMAIL)
    set(CMAKE_PROJECT_EMAIL "cfgnunes@gmail.com")
endif()

# Set some strings for the templates: PPA distro
if(NOT DEFINED CMAKE_PROJECT_S_DESCRIPTION)
    set(CMAKE_PROJECT_S_DESCRIPTION "Free front-end for the MP3val")
endif()

# Get the current year
if(NOT DEFINED CMAKE_CURRENT_YEAR)
    string(TIMESTAMP CMAKE_CURRENT_YEAR "%Y")
endif()

# Strings for Debian packaging
if(UNIX)
    # Get the current timestamp
    if(NOT DEFINED CMAKE_CURRENT_TIMESTAMP)
        string(TIMESTAMP CMAKE_CURRENT_TIMESTAMP "%a, %d %b %Y %H:%M:%S" UTC)
    endif()

    # Set 'distro'
    if(NOT DEFINED CMAKE_DEBIAN_NAME)
        set(CMAKE_DEBIAN_NAME "focal")
    endif()

    # Set 'build depends'
    if(NOT DEFINED CMAKE_DEBIAN_BUILD_DEPENDS)
        set(CMAKE_DEBIAN_BUILD_DEPENDS "debhelper (>= 9), libwxgtk3.0-gtk3-dev | libwxgtk3.0-dev | libwxgtk2.8-dev, cmake")
    endif()

    # Set 'depends'
    if(NOT DEFINED CMAKE_DEBIAN_DEPENDS)
        set(CMAKE_DEBIAN_DEPENDS "\${shlibs:Depends}, \${misc:Depends}, mp3val (>= 0.1.8)")
    endif()
endif()

# Header template
configure_file(
    "${PROJECT_SOURCE_DIR}/src/Constants.hpp.in"
    "${PROJECT_SOURCE_DIR}/src/Constants.hpp"
)

configure_file(
    "${PROJECT_SOURCE_DIR}/packaging/debian/changelog.in"
    "${PROJECT_SOURCE_DIR}/packaging/debian/changelog"
)

configure_file(
    "${PROJECT_SOURCE_DIR}/packaging/debian/control.in"
    "${PROJECT_SOURCE_DIR}/packaging/debian/control"
)

# =============================================================================
# Build process
# =============================================================================

# -----------------------------------------------------------------------------
# Translation files
# -----------------------------------------------------------------------------

# Set the source files
file(GLOB PO_FILES
    po/*.po
)

# Compile translation files
if(GETTEXT_FOUND)
    foreach(PO_FILE ${PO_FILES})
        # Remove path and extension of 'PO_FILE'
        get_filename_component(PO_NAME ${PO_FILE} NAME_WE)

        # Compile each '.po' file to '.gmo' file
        GETTEXT_PROCESS_PO_FILES(${PO_NAME} ALL PO_FILES "po/${PO_NAME}.po")

        # Define the files location during install process
        if(WIN32)
            install(
                FILES "${CMAKE_CURRENT_BINARY_DIR}/${PO_NAME}.gmo"
                DESTINATION "data/po/${PO_NAME}/"
                RENAME "${CMAKE_BIN_NAME}.mo"
            )
        else()
            install(
                FILES "${CMAKE_CURRENT_BINARY_DIR}/${PO_NAME}.gmo"
                DESTINATION "share/${CMAKE_BIN_NAME}/data/po/${PO_NAME}/"
                RENAME "${CMAKE_BIN_NAME}.mo"
            )
        endif()
    endforeach()
else()
    message(WARNING "gettext tools not found. Translations will not be built.")
endif()

# -----------------------------------------------------------------------------
# Source files
# -----------------------------------------------------------------------------

# Set compiler parameters
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -ansi -s -Wall -Wextra -Wpedantic")

# Set the source files
file(GLOB SRC_FILES
    src/*.c*
    src/*.h*
    src/ui/*.c*
    src/ui/*.h*
)

# Compile the main executable
if(WIN32)
    set(SRC_FILES ${SRC_FILES} packaging/windows/resource.rc)

    # Add the executable with a WinMain entry point on Windows.
    # See https://cmake.org/cmake/help/latest/prop_tgt/WIN32_EXECUTABLE.html
    add_executable(${CMAKE_BIN_NAME} WIN32 ${SRC_FILES})
else()
    add_executable(${CMAKE_BIN_NAME} ${SRC_FILES})
endif()

target_link_libraries(${CMAKE_BIN_NAME} ${wxWidgets_LIBRARIES})

# =============================================================================
# Install process
# =============================================================================

# Define the file locations during install process
if(WIN32)
    install(TARGETS ${CMAKE_BIN_NAME} DESTINATION "/")
    install(DIRECTORY "${CMAKE_DATA_DIR}" DESTINATION "${CMAKE_DATA_DIR}")
    install(FILES "${CMAKE_DOC_DIR}/CHANGELOG" DESTINATION "/" RENAME "Changelog.txt")
    install(FILES "${CMAKE_DOC_DIR}/COPYING" DESTINATION "/" RENAME "License.txt")
    install(FILES "${CMAKE_DOC_DIR}/README" DESTINATION "/" RENAME "Readme.txt")
    install(FILES "C:/wxWidgets-3.1.1/lib/gcc810_dll/wxmsw313u_core_gcc810.dll" DESTINATION "/")
    install(FILES "C:/wxWidgets-3.1.1/lib/gcc810_dll/wxbase313u_gcc810.dll" DESTINATION "/")
else()
    install(TARGETS ${CMAKE_BIN_NAME} DESTINATION "bin")
    install(DIRECTORY "${CMAKE_DATA_DIR}/" DESTINATION "share/${CMAKE_BIN_NAME}/${CMAKE_DATA_DIR}")
    install(DIRECTORY "${CMAKE_DOC_DIR}/" DESTINATION "share/${CMAKE_DOC_DIR}/${CMAKE_BIN_NAME}")
    install(FILES "packaging/debian/menu/icon32x32.png" DESTINATION "share/icons/hicolor/32x32/apps/" RENAME "${CMAKE_BIN_NAME}.png")
    install(FILES "packaging/debian/menu/icon48x48.png" DESTINATION "share/icons/hicolor/48x48/apps/" RENAME "${CMAKE_BIN_NAME}.png")
    install(FILES "packaging/debian/menu/icon64x64.png" DESTINATION "share/icons/hicolor/64x64/apps/" RENAME "${CMAKE_BIN_NAME}.png")
    install(FILES "packaging/debian/menu/icon128x128.png" DESTINATION "share/icons/hicolor/128x128/apps/" RENAME "${CMAKE_BIN_NAME}.png")
    install(FILES "packaging/debian/menu/${CMAKE_BIN_NAME}.desktop" DESTINATION "share/applications/")
endif()

# =============================================================================
# Custom targets
# =============================================================================

# Define the 'run' target
add_custom_target(run
    COMMAND ${CMAKE_BIN_NAME}
    DEPENDS ${CMAKE_BIN_NAME}
    WORKING_DIRECTORY ../${CMAKE_PROJECT_DIR}
)
