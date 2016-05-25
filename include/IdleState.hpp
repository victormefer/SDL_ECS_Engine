#ifndef IDLESTATE_HPP
#define IDLESTATE_HPP

#include <string>

#include "EntityState.hpp"
#include "EntityStateMachine.hpp"

class IdleState : public EntityState
{
public:
	IdleState(EntityStateMachine& stateMachine) : EntityState(stateMachine, "IdleState") {}
	// bool is(std::string type)
	// { 
	// 	if (type == "IdleState") 
	// 		return true; 
	// 	else
	// 		return false;
	// }
};

#endif