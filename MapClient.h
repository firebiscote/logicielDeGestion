#pragma once
#include "pch.h"
#include "Map.h"

namespace Composants {
	ref class MapClient : public Map {
	public:
		MapClient(void);
		MapClient(String^, String^);
		MapClient(String^, String^, DateTime^);
		virtual String^ SELECT(void) override;
		virtual String^ INSERT(void) override;
		virtual String^ DELETE(void) override;
		virtual String^ UPDATE(int^) override;
		void set_ID(int);
		void set_nom(String^);
		void set_prenom(String^);
		void set_dateNaissance(DateTime^);
		int get_ID(void);
		String^ get_nom(void);
		String^ get_prenom(void);
		DateTime^ get_dateNaissance(void);
	private:
		int _ID;
		String^ _nom;
		String^ _prenom;
		DateTime^ _dateNaissance;
	};
}