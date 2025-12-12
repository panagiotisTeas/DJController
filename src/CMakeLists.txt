add_executable(dj-console)

target_sources(dj-console
    PRIVATE
        main.c
        ui/ui_component.c
        ui/panels/browser_panel.c
)

set_project_warnings(dj-console)
enable_sanitizers(dj-console)

target_include_directories(dj-console
    PRIVATE
        ${CMAKE_CURRENT_SOURCE_DIR}/../include
)

target_link_libraries(dj-console
    PRIVATE
        ${CMAKE_CURRENT_SOURCE_DIR}/../libs/libraylib.a
)

target_link_libraries(dj-console 
    PRIVATE 
        m
)

target_compile_features(dj-console PRIVATE c_std_11)