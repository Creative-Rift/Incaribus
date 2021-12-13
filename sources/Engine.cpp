/*
** Society: Creative Rift
** SHIPWRECK ENGINE, 2021
** Author: Guillaume S.
** File name: Engine.cpp
** Description: [CHANGE]
*/

#include "SW/Engine.hpp"
#include "opengl/OpenGLModule.hpp"

///////////////////////////////////////////////////////////////////////////////
///
///     Initialize your Module here
//
void sw::Engine::onInitialize()
{
    sw::Engine::createModule<sw::OpenGLModule>("OpenGL");
}

///////////////////////////////////////////////////////////////////////////////
///
///     Update your Module here
//
void sw::Engine::onUpdate()
{}

///////////////////////////////////////////////////////////////////////////////
///
///     Terminate your Module here
//
void sw::Engine::onTerminate()
{}