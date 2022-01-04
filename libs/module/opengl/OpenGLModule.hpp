/*
** Society: Creative Rift
** SHIPWRECK ENGINE, 2021
** Author: Guillaume S.
** File name: OpenGLModule.hpp
** Description: [CHANGE]
*/

#ifndef SWENGINE_GRAPHICAL_OPENGLMODULE_HPP
#define SWENGINE_GRAPHICAL_OPENGLMODULE_HPP

#include "glad/glad.h"
#include "GLFW/glfw3.h"

#include "SW/Engine.hpp"

#include "OpenGLModule_Config.hpp"

#include <memory>

namespace sw
{
    class SW_GRAPH_MODULE_EXPORT OpenGLModule : public sw::AModule
    {
        private:
            GLFWwindow *m_window{};

            static void resizeCallBack(GLFWwindow* window, int width, int height);
            void setUpCallBack();
        public:
            explicit OpenGLModule();
            ~OpenGLModule() override = default;

            void initialize() override;
            void update() override;
            void terminate() override;
            bool isOk() override;
            [[nodiscard]] std::string type() const override;

            std::unique_ptr<sw::AResources> createResourceInstance() override;
    }; // class OpenGLModule
} // namespace sw

#endif //SWENGINE_GRAPHICAL_OPENGLMODULE_HPP
