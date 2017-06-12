#include "fsm_definition.h"

void myfsm::Idle::react(const XBot::FSM::Event& e) {
  
  std::cout << "Idle..REACT" << std::endl;
  
}

void myfsm::Idle::entry(const XBot::FSM::Message& msg){
  
  std::cout << "Idle..ENTRY_DEFAULT_MESSAGE" << std::endl;
    
}

void myfsm::Idle::run(double time, double period){
  
   std::cout << "Idle RUN" << std::endl;
   
}

