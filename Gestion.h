#pragma once
#include "pch.h"
#include "CAD.h"
#include "Map.h"

namespace Services {
	ref class Gestion {
	public:
		virtual DataSet^ liste(int) abstract;
		virtual void ajouter(void) abstract;
		virtual void supprimer(void) abstract;
		virtual void modifier(String^) abstract;
		DataSet^ simulation(String^, String^, String^, String^);
	protected:
		void initGestion(void);
		Composants::CAD^ _cad;
		DataSet^ _ds;
	};
}