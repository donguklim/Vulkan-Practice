#pragma once

#include <GLFW/glfw3.h>

#include <format>
#include <stdexcept>


inline void vk_check(VkResult result)
{
	if (result != VK_SUCCESS)
	{
		throw std::runtime_error(std::format("Vulkan Error: {}", static_cast<int>(result)));
		__debugbreak();
	}
}