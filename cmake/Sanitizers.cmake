function(enable_sanitizers target)

    if(ENABLE_ASAN)
        target_compile_options(${target} PRIVATE -fsanitize=address)
        target_link_options(${target} PRIVATE -fsanitize=address)
        target_compile_definitions(${target} PRIVATE ENABLE_ASAN=${ENABLE_ASAN})
    endif()

    if(ENABLE_TSAN)
        target_compile_options(${target} PRIVATE -fsanitize=thread)
        target_link_options(${target} PRIVATE -fsanitize=thread)
        target_compile_definitions(${target} PRIVATE ENABLE_TSAN=${ENABLE_TSAN})
    endif()

    if(ENABLE_UBSAN)
        target_compile_options(${target} PRIVATE -fsanitize=undefined)
        target_link_options(${target} PRIVATE -fsanitize=undefined)
        target_compile_definitions(${target} PRIVATE ENABLE_UBSAN=${ENABLE_UBSAN})
    endif()

endfunction()