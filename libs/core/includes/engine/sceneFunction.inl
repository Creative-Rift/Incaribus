/*
** SHIPWRECK ENGINE, 2021
** Software Engine Project
** File description:
** sceneFunction.inl
*/

template <ConcreteScene Scene>
inline Scene& sw::Engine::createScene(const std::string& sceneName)
{
    if (hasScene(sceneName))
        sw::Speech::Warning(sw::Log::warning123(FUNCTION, sceneName));

    auto it = m_scenes.try_emplace(sceneName, std::make_unique<Scene>(sceneName));
    if (it.second && m_activeScene.empty())
        m_activeScene = sceneName;
    return (static_cast<Scene&>(*(it.first->second)));
}

template <ConcreteScene Scene>
inline Scene& sw::Engine::getScene(const std::string& sceneName)
try
{
    return (static_cast<Scene&>(*m_scenes.at(sceneName)));
}
catch (std::out_of_range&) {
    throw sw::Error(sw::Log::error113(FUNCTION, sceneName));
}

template <ConcreteScene Scene>
Scene& sw::Engine::activeScene()
try
{
    return (static_cast<Scene&>(*m_scenes.at(m_activeScene)));
}
catch (std::out_of_range&) {
    throw sw::Error(sw::Log::error113(FUNCTION, m_activeScene));
}