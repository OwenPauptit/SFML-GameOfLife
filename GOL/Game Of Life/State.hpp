#pragma once

namespace Aesel {
	class State {
	public:
		virtual void Init();
		virtual void HandleInput();
		virtual void Update(float dt);
		virtual void Draw();

		virtual void Pause();
		virtual void Resume();
	};
}