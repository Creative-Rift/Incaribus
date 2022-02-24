/*
** Society: Creative Rift
** SHIPWRECK ENGINE, 2021
** Author: Guillaume S.
** File name: main.cpp
** Description: [CHANGE]
*/

#include "SW/Engine.hpp"
#include "OpenGLModule.hpp"
#include "Project.hpp"

int main()
try
{
    sw::Speech::setDisplayed(true);

    sw::Engine::createModule<sw::OpenGLModule>();
    sw::CreateScenes();
    sw::Engine::initialize();
    sw::Engine::activeScene().load();
    sw::Speech::flush();
    while (sw::Engine::getModule().isOk())
        sw::Engine::update();
    sw::Speech::flush();
    sw::Engine::terminate();
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