/*
** Society: Creative Rift
** SHIPWRECK ENGINE, 2022
** Author: Guillaume S.
** File name: Project.cpp
** Description: [CHANGE]
*/

#include "OpenGLModule.hpp"
#include "Project.hpp"
#include "scenes/Game.hpp"
#include "Main.hpp"
#include "MainFile.hpp"
#include "Cyber.hpp"
#include "Loading.hpp"

void sw::CreateScenes()
{
    auto game = new Game();
    auto main = new Main();
    auto cyber = new Cyber();
    auto loading = new Loading();
    auto mainfile = new MainFile();
    sw::OpenGLModule::eventManager().create("SceneLoad");
    sw::OpenGLModule::sceneManager().createScene("Main");
    sw::OpenGLModule::sceneManager().createScene("Cyber");
    sw::OpenGLModule::sceneManager().createScene("MainFile");
    sw::OpenGLModule::sceneManager().createScene("Game");
    sw::OpenGLModule::sceneManager().createScene("Loading");

    sw::OpenGLModule::eventManager()["SceneLoad"].subscribe(game, &Game::onLoad);
    sw::OpenGLModule::eventManager()["SceneLoad"].subscribe(main, &Main::onLoad);
    sw::OpenGLModule::eventManager()["SceneLoad"].subscribe(mainfile, &MainFile::onLoad);
    sw::OpenGLModule::eventManager()["SceneLoad"].subscribe(cyber, &Cyber::onLoad);
    sw::OpenGLModule::eventManager()["SceneLoad"].subscribe(loading, &Loading::onLoad);
}