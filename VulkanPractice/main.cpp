#define GLFW_INCLUDE_VULKAN
#include <GLFW/glfw3.h>

#include  <vector>
#include <iostream>

#include <cstdlib>
#include "render.h"

const uint32_t WIDTH = 800;
const uint32_t HEIGHT = 600;

class HelloTriangleApplication {
public:
    void run() {
        initWindow();
        initVulkan();
        mainLoop();
        cleanup();
    }

private:
    GLFWwindow* window;
    VkInstance instance;

    void initWindow() {
        glfwInit();

        glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API);
        glfwWindowHint(GLFW_RESIZABLE, GLFW_FALSE);

        window = glfwCreateWindow(WIDTH, HEIGHT, "Vulkan", nullptr, nullptr);

    }

    void initVulkan() {
        createInstance();
    }

    void mainLoop() {
        while (!glfwWindowShouldClose(window)) {
            glfwPollEvents();
        }
    }

    void cleanup() {
        vkDestroyInstance(instance, nullptr);
        glfwDestroyWindow(window);
        glfwTerminate();

    }

    void listExtensions() {
        uint32_t extensionCount = 0;
        vk_check(vkEnumerateInstanceExtensionProperties(nullptr, &extensionCount, nullptr));
        std::vector<VkExtensionProperties> extensions(extensionCount);
        vk_check(vkEnumerateInstanceExtensionProperties(nullptr, &extensionCount, extensions.data()));

        std::cout << "available extensions:\n";

        for (const auto& extension : extensions) {
            std::cout << '\t' << extension.extensionName << '\n';
        }
    }

    void createInstance() {
        VkApplicationInfo appInfo{};
        appInfo.sType = VK_STRUCTURE_TYPE_APPLICATION_INFO;
        appInfo.pApplicationName = "Hello Triangle";
        appInfo.applicationVersion = VK_MAKE_VERSION(1, 0, 0);
        appInfo.pEngineName = "No Engine";
        appInfo.engineVersion = VK_MAKE_VERSION(1, 0, 0);
        appInfo.apiVersion = VK_API_VERSION_1_0;

        VkInstanceCreateInfo createInfo{};
        createInfo.sType = VK_STRUCTURE_TYPE_INSTANCE_CREATE_INFO;
        createInfo.pApplicationInfo = &appInfo;

        /* 
            // list available extensions and extensions required by glfw
            listExtensions();

            std::cout << "\nextensions requried by glfw:\n";
            uint32_t glfwExtensionCount = 0;
            const char** glfwExtensions;

            glfwExtensions = glfwGetRequiredInstanceExtensions(&glfwExtensionCount);

            for (int i = 0; i < glfwExtensionCount; i++)
            {
                std::cout << '\t' << glfwExtensions[i] << '\n';
            }

            createInfo.enabledExtensionCount = glfwExtensionCount;
            createInfo.ppEnabledExtensionNames = glfwExtensions;
        
        */
        
        createInfo.enabledLayerCount = 0;
        vk_check(vkCreateInstance(&createInfo, nullptr, &instance));																	


    }
};

int main() {
    HelloTriangleApplication app;

    try {
        app.run();
    }
    catch (const std::exception& e) {
        std::cerr << e.what() << std::endl;
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}
