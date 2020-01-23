#include "StateManager.hpp"

namespace Aesel {

	StateManager::StateManager() {
		_isChanging = false;
	}

	// Prepares variables for the next time ProcessChanges() function is called
	void StateManager::ChangeState(StateRef newState) {
		_newState = std::move(newState);
		_isChanging = true;

	}

	// Updates the current state if the state is being changed
	void StateManager::ProcessChanges() {
		if (_isChanging) {
			_isChanging = false;
			_currentState = std::move(_newState);
			_currentState->Init();
		}
	}

	StateRef& StateManager::GetActiveState() {
		return _currentState;
	}
}
