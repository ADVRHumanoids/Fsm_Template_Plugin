#include <XBotInterface/StateMachine.h>


namespace myfsm{

    
    struct SharedData {
      
      XBot::RobotInterface::Ptr _robot;
     
    };
    
    class MacroState : public  XBot::FSM::State< MacroState , SharedData > {
      
    public:
	
	virtual void entry(const XBot::FSM::Message& msg) {};
	virtual void react(const XBot::FSM::Event& e){};
      
    };
    
    class Idle : public MacroState {
      
      virtual std::string get_name() const { return "Idle"; }
      
      virtual void run(double time, double period);   
      
      virtual void entry(const XBot::FSM::Message& msg);
      
      virtual void react(const XBot::FSM::Event& e);
      
      private:
      
	
    };
      
}