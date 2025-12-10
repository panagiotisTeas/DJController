option(ENABLE_WARNINGS      "Enable extra warnings"             ON)
option(ENABLE_WERROR        "Treat warnings as errors"          ON)
option(ENABLE_ASAN          "Enable AddressSanitizer"           OFF)
option(ENABLE_TSAN          "Enable ThreadSanitizer"            OFF)
option(ENABLE_UBSAN         "Enable UndefinedBehaviorSanitizer" OFF)

if(NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE Release CACHE STRING "Choose the build type" FORCE)
endif()