#pragma once
#include "pch.h"
#include "Map.h"

namespace Composants {
	ref class MapCommande : public Map {
	public:
		MapCommande(void);
		MapCommande(String^);
		MapCommande(String^, String^);
		virtual String^ SELECT(void) override;
		virtual String^ INSERT(void) override;
		virtual String^ DELETE(void) override;
		virtual String^ UPDATE(int^) override;
		void set_ID(int);
		void set_reference(String^);
		void set_nomClient(String^);
		int get_ID(void);
		String^ get_reference(void);
		String^ get_nomClient(void);
	private:
		int _ID;
		String^ _reference;
		String^ _nomClient;
	};
}