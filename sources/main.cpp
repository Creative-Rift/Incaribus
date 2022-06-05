/*
** Society: Creative Rift
** SHIPWRECK ENGINE, 2021
** Author: Guillaume S.
** File name: main.cpp
** Description: [CHANGE]
*/

#include "OpenGLModule.hpp"
#include "Project.hpp"
#include "scenes_manager/scene/Scene.hpp"

int main()
try
{
    sw::Speech::setDisplayed(true);

    sw::CreateScenes();
    sw::OpenGLModule::load();
    sw::OpenGLModule::sceneManager().loadScene("MainFile");
    sw::Speech::flush();
    while (sw::OpenGLModule::isOk())
        sw::OpenGLModule::update();
    sw::Speech::flush();
    sw::OpenGLModule::unload();
    sw::Speech::flush();
    return (0);
}
catch (sw::Error& error)
{
    sw::Speech::Error(error.getMessage(), error.getCode());
    sw::Speech::flush();
}
catch (const std::exception& error)
{
    sw::Speech::Error(error.what());
    sw::Speech::flush();
}