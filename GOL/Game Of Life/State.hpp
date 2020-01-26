#pragma once

namespace Aesel {
	class State {
	public:
		virtual void Init()=0;
		virtual void HandleInput()=0;
		virtual void Update(float dt)=0;
		virtual void Draw()=0;
	};
}