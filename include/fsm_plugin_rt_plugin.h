/*
 * Copyright (C) 2017 IIT-ADVR
 * Author:
 * email:
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU Lesser General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public License
 * along with this program. If not, see <http://www.gnu.org/licenses/>
*/

#ifndef fsm_plugin_H_
#define fsm_plugin_PLUGIN_H_

#include <XCM/XBotControlPlugin.h>
#include "fsm_definition.h"


namespace XBotPlugin {

/**
 * @brief fsm_plugin XBot RT Plugin
 *
 **/
class fsm_plugin : public XBot::XBotControlPlugin
{

public:

    virtual bool init_control_plugin(std::string path_to_config_file,
                                     XBot::SharedMemory::Ptr shared_memory,
                                     XBot::RobotInterface::Ptr robot);

    virtual bool close();

    virtual void on_start(double time);

    virtual void on_stop(double time);

protected:

    virtual void control_loop(double time, double period);

private:

    XBot::RobotInterface::Ptr _robot;

    double _start_time;

    Eigen::VectorXd _q0;

    XBot::MatLogger::Ptr _logger;
    
     
    XBot::FSM::StateMachine< myfsm::MacroState , myfsm::SharedData > fsm;

};

}

#endif // fsm_plugin_PLUGIN_H_