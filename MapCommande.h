#pragma once
#include "pch.h"
#include "Map.h"

namespace Composants {
	ref class MapCommande : public Map {
	public:
		MapCommande(void);
		MapCommande(String^, String^);
		MapCommande(String^, String^, String^, String^, String^, String^);
		virtual String^ SELECT(void) override;
		virtual String^ INSERT(void) override;
		virtual String^ DELETE(void) override;
		virtual String^ UPDATE(int^) override;
	private:

	};
}