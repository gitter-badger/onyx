file(GLOB_RECURSE IMGUI_SOURCES
     ${ONYX_LIB_DIR}/imgui/*.cpp
     ${ONYX_LIB_DIR}/imgui/*.h)
add_library(imgui STATIC ${IMGUI_SOURCES})

set_target_properties(imgui PROPERTIES FOLDER lib)

target_include_directories(imgui PUBLIC ${ONYX_LIB_DIR}/imgui)
