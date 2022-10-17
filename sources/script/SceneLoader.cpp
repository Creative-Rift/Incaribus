/*
** ShipWreck Engine , 2022
** SceneLoader.cpp
*/

#include "script/SceneLoader.hpp"
#include "OpenGLModule.hpp"
#include "window/Window.hpp"

inc::SceneLoader::SceneLoader(sw::GameObject &gameObject) :
sw::Component(gameObject)
{
    gameObject.scene().eventManager["Start"].subscribe(this, &inc::SceneLoader::start);
    gameObject.scene().eventManager["Update"].subscribe(this, &inc::SceneLoader::update);
}

inc::SceneLoader::~SceneLoader() noexcept
= default;

void inc::SceneLoader::start()
{
    m_operation = sw::OpenGLModule::sceneManager().loadSceneAsync("Cyber");
    sw::GameObject& text = m_gameObject.scene().createGameObject("LoadingText");
    auto& textCpt = text.createComponent<sw::Text>("TextManager");
    std::string font("Pixel");
    std::string ye("Loading complete press SPACE");
    textCpt.setPosition(380, 900).setText(ye).setColor(sw::Color(105.0f / 255.0f, 166.0f / 255.0f, 31.0f / 255.0f)).setFont(font);

}

void inc::SceneLoader::update()
{
    if (m_operation->isDone() && sw::isKeyDown(sw::Keyboard::SPACE))
        sw::OpenGLModule::sceneManager().swapSceneFromAsync(*m_operation, "Cyber");
}
