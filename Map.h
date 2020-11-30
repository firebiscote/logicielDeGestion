#pragma once
#include "pch.h"

namespace Composants {
	ref class Map {
	public:
		virtual String^ SELECT(void) = 0;
		virtual String^ INSERT(void) = 0;
		virtual String^ DELETE(void) = 0;
		virtual String^ UPDATE(Map^);
	};
}