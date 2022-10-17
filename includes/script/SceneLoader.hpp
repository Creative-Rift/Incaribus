/*
** ShipWreck Engine , 2022
** SceneLoader.hpp
*/

#ifndef INCARIBUS_SCENELOADER_HPP
#define INCARIBUS_SCENELOADER_HPP

#include "components/Components.hpp"
#include "utils/async/AsyncScene.hpp"

namespace inc
{
    class SceneLoader : public sw::Component
    {
    private:
        std::shared_ptr<sw::AsyncScene> m_operation;

    public:
        explicit SceneLoader(sw::GameObject& gameObject);
        ~SceneLoader() override;
        void start();
        void update();
    };
} // namespace inc

#endif //INCARIBUS_SCENELOADER_HPP
