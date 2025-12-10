function(set_project_warnings target)

    if(NOT ENABLE_WARNINGS)
        return()
    endif()

    target_compile_options(${target} 
        PRIVATE
            -Wall
            -Wextra
            -Wpedantic
    )
    target_compile_definitions(${target} PRIVATE ENABLE_WARNINGS=${ENABLE_WARNINGS})

    if(ENABLE_WERROR)
        target_compile_options(${target} PRIVATE -Werror)
        target_compile_definitions(${target} PRIVATE ENABLE_WERROR=${ENABLE_WERROR})
    endif()

endfunction()