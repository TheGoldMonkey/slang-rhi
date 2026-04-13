#!MCVM cd ${mdir} \
#!MCVM && rm -rf build \\
#!MCVM && cmake -Bbuild -Cmcvm.cmake --fresh \
#!MCVM && cmake --build build

# set(CMAKE_CXX_COMPILER clang++ CACHE STRING "" FORCE)
# set(CMAKE_C_COMPILER clang CACHE STRING "" FORCE)

# set(CMAKE_C_COMPILER_WORKS 1 CACHE STRING "")
# set(CMAKE_CXX_COMPILER_WORKS 1 CACHE STRING "")
set(EMSCRIPTEN_ROOT_PATH "/home/mcvm/dev/emscripten" CACHE STRING "Path to Emscripten root")
# include("/home/mcvm/dev/emscripten/cmake/Modules/Platform/Emscripten.cmake")
set(CMAKE_TOOLCHAIN_FILE /home/mcvm/dev/emscripten/mcvm/Emscripten.cmake CACHE STRING "" FORCE)

# TODO: https://github.com/DiligentGraphics/DiligentCore/pull/727
# this wont build until ^

# for dilligent samples on emscripten, dont use multi config as it breaks relative paths between .html and .js
set(CMAKE_GENERATOR "Ninja" CACHE STRING "" FORCE)
set(CMAKE_EXPORT_COMPILE_COMMANDS 1 CACHE STRING "" FORCE)
list(APPEND COMPILER_FLAGS
  -fcolor-diagnostics
  # -Wno-deprecated-pragma
#   -v
)

list(APPEND LINKER_FLAGS
  -Wl,--color-diagnostics
  # -sPTHREAD_POOL_SIZE=32
  # -sINITIAL_MEMORY=1310720000
  # -Wl,--thinlto-cache-dir=.cache/lto
)
string(REPLACE ";" " " COMPILER_FLAGS "${COMPILER_FLAGS}")
string(REPLACE ";" " " LINKER_FLAGS "${LINKER_FLAGS}")

set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} ${COMPILER_FLAGS}" CACHE STRING "" FORCE)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${COMPILER_FLAGS}" CACHE STRING "" FORCE)
set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} ${LINKER_FLAGS}" CACHE STRING "" FORCE)

set(CMAKE_COLOR_DIAGNOSTICS 1 CACHE STRING "" FORCE)
# set(CMAKE_INSTALL_PREFIX /home/mcvm/install CACHE STRING "" FORCE)

set(CMAKE_BUILD_TYPE Debug CACHE STRING "" FORCE)
# set(CMAKE_VERBOSE_MAKEFILE 1 CACHE STRING "" FORCE)
# set(CMAKE_FIND_DEBUG_MODE 1 CACHE STRING "" FORCE)


# include(cmake_cached_cache.cmake)

#####################
# set(CMAKE_CXX_COMPILER clang++ CACHE STRING "" FORCE)
# set(CMAKE_C_COMPILER clang CACHE STRING "" FORCE)
# set(CMAKE_GENERATOR "Ninja Multi-Config" CACHE STRING "" FORCE)
# set(CMAKE_EXPORT_COMPILE_COMMANDS 1 CACHE STRING "" FORCE)
# list(APPEND COMPILER_FLAGS
#   -fcolor-diagnostics
# )
# list(APPEND LINKER_FLAGS
#   -Wl,--color-diagnostics
#   # -Wl,--thinlto-cache-dir=.cache/lto
# )
# string(REPLACE ";" " " COMPILER_FLAGS "${COMPILER_FLAGS}")
# string(REPLACE ";" " " LINKER_FLAGS "${LINKER_FLAGS}")

# set(CMAKE_C_FLAGS_INIT ${COMPILER_FLAGS} CACHE STRING "" FORCE)
# set(CMAKE_CXX_FLAGS_INIT ${COMPILER_FLAGS} CACHE STRING "" FORCE)
# set(CMAKE_EXE_LINKER_FLAGS_INIT ${LINKER_FLAGS} CACHE STRING "" FORCE)

# set(CMAKE_COLOR_DIAGNOSTICS 1 CACHE STRING "" FORCE)
# # set(CMAKE_INSTALL_PREFIX /home/mcvm/install CACHE STRING "" FORCE)
# set(CMAKE_BUILD_TYPE Debug CACHE STRING "" FORCE)
# # set(CMAKE_VERBOSE_MAKEFILE 1 CACHE STRING "" FORCE)
# # set(CMAKE_FIND_DEBUG_MODE 1 CACHE STRING "" FORCE)

# # set(X11_INC_SEARCH_PATH /usr/include CACHE STRING "" FORCE)
# # set(X11_LIB_SEARCH_PATH /usr/lib CACHE STRING "" FORCE)
####################
