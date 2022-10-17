/*
** ShipWreck Engine , 2022
** Loading.hpp
*/

#ifndef INCARIBUS_LOADING_HPP
#define INCARIBUS_LOADING_HPP

#include "event/EventInfo.hpp"

class Loading
{
public:
    std::string name() {return ("ye");}
    void onLoad(sw::EventInfo& info);
};

#endif //INCARIBUS_LOADING_HPP
