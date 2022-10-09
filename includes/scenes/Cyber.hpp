/*
** Society: Creative Rift
** SHIPWRECK ENGINE, 2021
** Author: Guillaume S.
** File name: Main.hpp
** Description: [CHANGE]
*/

#ifndef INCARIBUS_CYBER_HPP
#define INCARIBUS_CYBER_HPP

#include "event/EventInfo.hpp"

class Cyber {
    public:
        std::string name() {return ("Cyber");}
        void onLoad(sw::EventInfo& info);
};

#endif //INCARIBUS_CYBER_HPP
