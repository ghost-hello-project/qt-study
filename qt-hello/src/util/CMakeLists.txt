aux_source_directory(. JANNA_LIB_UTIL_SOURCES)
list(APPEND JANNA_LIB_UTIL_SOURCES
    ${CMAKE_SOURCE_DIR}/include/qt-hello/util/app_config.h
    ${CMAKE_SOURCE_DIR}/include/qt-hello/util/configuration.h
    ${CMAKE_SOURCE_DIR}/include/qt-hello/util/log_util.h
)
qt_add_library(${janna_lib_util_lib_name} SHARED ${JANNA_LIB_UTIL_SOURCES})

target_link_libraries(${janna_lib_util_lib_name} PUBLIC
    Qt${QT_VERSION_MAJOR}::Core
)

if(UNIX)
    set_target_properties(${janna_lib_util_lib_name} PROPERTIES LIBRARY_OUTPUT_DIRECTORY ${lib_dir})
endif()

if(WIN32)
    # 构建后动作
    add_custom_command(TARGET ${janna_lib_util_lib_name} POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E echo "===> janna util library path: $<TARGET_FILE:${janna_lib_util_lib_name}>"
        COMMAND ${CMAKE_COMMAND} -E copy $<TARGET_FILE:${janna_lib_util_lib_name}> ${bin_dir}

        COMMAND ${CMAKE_COMMAND} -E copy $<TARGET_FILE:${janna_lib_util_lib_name}> ${dist_dir}/test/
    )
endif()