/*
** Society: Creative Rift
** SHIPWRECK ENGINE, 2021
** Author: Guillaume S.
** File name: Main.hpp
** Description: [CHANGE]
*/

#ifndef INCARIBUS_MAIN_HPP
#define INCARIBUS_MAIN_HPP

#include "event/EventInfo.hpp"

class Main{
    public:
        std::string name() {return ("ye");}
        void onLoad(sw::EventInfo& info);
};

#endif //INCARIBUS_MAIN_HPP
