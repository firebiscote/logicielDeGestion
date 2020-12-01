#pragma once
#include "pch.h"

namespace Composants {
	ref class MapClient {
	public:
		MapClient(void);
		MapClient(String^, String^);
		MapClient(String^, String^, String^);
		virtual String^ SELECT(void) override;
		virtual String^ INSERT(void) override;
		virtual String^ DELETE(void) override;
		virtual String^ UPDATE(int^) override;
	private:
		int^ _ID;
		String^ _nom;
		String^ _prenom;
		DateTime^ _dateNaissance;
	};
}