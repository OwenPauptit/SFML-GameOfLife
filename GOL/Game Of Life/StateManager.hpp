#pragma once

#include "State.hpp"
#include <stack>
#include <memory>

namespace Aesel {

	typedef std::unique_ptr<State> StateRef;

	class StateManager {
	public:

		StateManager();
		
		void ChangeState(StateRef newState);

		void ProcessChanges();

		StateRef& GetActiveState();

	private:
		StateRef _currentState;
		StateRef _newState;

		bool _isChanging;

	};

}