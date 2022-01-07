/*
** Society: Creative Rift
** SHIPWRECK ENGINE, 2022
** Author: Guillaume S.
** File name: Project.cpp
** Description: [CHANGE]
*/

#include "SW/Engine.hpp"
#include "scenes/Main.hpp"
#include "Project.hpp"

void sw::CreateScenes()
{
    sw::Engine::createScene<Main>(std::string("Main"));
}