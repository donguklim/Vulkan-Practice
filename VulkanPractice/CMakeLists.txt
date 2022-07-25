# CMakeList.txt : CMake project for VulkanPractice, include source and define
# project specific logic here.
#
cmake_minimum_required (VERSION 3.8)

# Add source to this project's executable.
add_executable (VulkanPractice "main.cpp" )

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET VulkanPractice PROPERTY CXX_STANDARD 20)
endif()

find_package(Vulkan REQUIRED)
target_link_libraries(${PROJECT_NAME} ${Vulkan_LIBRARIES})
target_include_directories(${PROJECT_NAME} PUBLIC ${Vulkan_INCLUDE_DIR})


include_directories("${GLFW_PATH}/include")


target_link_libraries(VulkanPractice "${GLFW_PATH}/lib-vc2022/glfw3.lib")

# TODO: Add tests and install targets if needed.
