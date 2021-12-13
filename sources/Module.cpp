/*
** Society: Creative Rift
** SHIPWRECK ENGINE, 2021
** Author: Guillaume S.
** File name: Module.cpp
** Description: [CHANGE]
*/

#include "opengl/OpenGLModule.hpp"
#include "scenes/Main.hpp"

void sw::OpenGLModule::onInitialize()
{
    sw::Engine::createScene<Main>("Main");
}

void sw::OpenGLModule::onUpdate()
{

}

void sw::OpenGLModule::onTerminate()
{

}