/*
** Society: Creative Rift
** SHIPWRECK ENGINE, 2021
** Author: Guillaume S.
** File name: Main.hpp
** Description: [CHANGE]
*/

#ifndef INCARIBUS_MAINFILE_HPP
#define INCARIBUS_MAINFILE_HPP

#include "event/EventInfo.hpp"

class MainFile{
    public:
        std::string name() {return ("ye");}
        void onLoad(sw::EventInfo& info);
};

#endif //INCARIBUS_MAINFILE_HPP
