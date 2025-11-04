#!MCVM cd ${mdir} && cmake -Bbuild -Cmcvm.cmake --fresh && cmake --build build
cmake_minimum_required(VERSION 3.31)
project(mcvm_slang_rhi)

include(mcvm_stdlib/cmake/utils.cmake)
include(mcvm_stdlib/cmake/init.cmake)
init_cpm()

set_cache(SLANG_RHI_BUILD_SHARED 0)
set_cache(SLANG_RHI_BUILD_TESTS 0)
set_cache(SLANG_RHI_BUILD_TESTS_WITH_GLFW 0)
set_cache(SLANG_RHI_BUILD_EXAMPLES 0)
set_cache(SLANG_RHI_ENABLE_COVERAGE 0)
set_cache(SLANG_RHI_INSTALL 0)
set_cache(SLANG_RHI_ENABLE_CPU 1)
set_cache(SLANG_RHI_ENABLE_D3D11 0)
set_cache(SLANG_RHI_ENABLE_D3D12 0)
set_cache(SLANG_RHI_ENABLE_AGILITY_SDK 0)
set_cache(SLANG_RHI_ENABLE_NVAPI 0)
set_cache(SLANG_RHI_ENABLE_VULKAN 0)
set_cache(SLANG_RHI_ENABLE_METAL 0)
set_cache(SLANG_RHI_ENABLE_CUDA 0)
set_cache(SLANG_RHI_ENABLE_OPTIX 0)
set_cache(SLANG_RHI_ENABLE_WGPU 1)
set_cache(SLANG_RHI_BUILD_EXAMPLES 0)

CPMAddPackage(
    NAME emdawnwebgpu
    # GIT_REPOSITORY https://dawn.googlesource.com/dawn.git
    # https://github.com/google/dawn/releases
    # GIT_REPOSITORY https://github.com/google/dawn.git
    # GIT_TAG v20250817.184140
    # GIT_PROGRESS ON
    VERSION v20250916.182450
    URL https://github.com/google/dawn/releases/download/v20250916.182450/emdawnwebgpu_pkg-v20250916.182450.zip
    DOWNLOAD_ONLY YES
)

if(emdawnwebgpu_ADDED)
    file(GLOB_RECURSE emdawnwebgpu_cpp CONFIGURE_DEPENDS ${emdawnwebgpu_SOURCE_DIR}/*.cpp)
    add_library(emdawnwebgpu EXCLUDE_FROM_ALL ${emdawnwebgpu_cpp})
    file(GLOB_RECURSE emdawnwebgpu_js CONFIGURE_DEPENDS ${emdawnwebgpu_SOURCE_DIR}/*.js)

    target_include_directories(emdawnwebgpu PUBLIC
        # ${emdawnwebgpu_SOURCE_DIR}/webgpu/include
        # ${emdawnwebgpu_SOURCE_DIR}/webgpu_cpp/include
        ${CMAKE_CURRENT_SOURCE_DIR}/../../dawn/mcvm/build/dawn/gen/include
    )
    # list(TRANSFORM emdawnwebgpu_js PREPEND --js-library=)
    # target_link_libraries(emdawnwebgpu INTERFACE
    #     # ${emdawnwebgpu_js}
    #     --Wl,--whole-archive
    #     --js-library=${emdawnwebgpu_SOURCE_DIR}/webgpu/src/library_webgpu_enum_tables.js
    #     --js-library=${emdawnwebgpu_SOURCE_DIR}/webgpu/src/library_webgpu_generated_struct_info.js
    #     --js-library=${emdawnwebgpu_SOURCE_DIR}/webgpu/src/library_webgpu_generated_sig_info.js
    #     --js-library=${emdawnwebgpu_SOURCE_DIR}/webgpu/src/library_webgpu.js
    #     --Wl,--no-whole-archive
    # )
    target_compile_options(emdawnwebgpu PRIVATE
        -std=c++20
        -Wall
        -Werror
        -g
    )
endif()
add_subdirectory(${CMAKE_SOURCE_DIR}/.. ${CMAKE_BINARY_DIR}/slang-rhi)
target_include_directories(slang-rhi
    PUBLIC
    #  emdawnwebgpu
    ${emdawnwebgpu_SOURCE_DIR}/webgpu/include
    ${emdawnwebgpu_SOURCE_DIR}/webgpu_cpp/include
)
