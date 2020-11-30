#pragma once
#include "pch.h"
#include "CAD.h"
#include "MapEmploye.h"

namespace Services {
	ref class GestionEmploye {
	public:
		GestionEmploye(void);
		DataSet^ listeEmploye(void);
		void ajouter(String^, String^, String^, String^, DateTime^, Adresse^);
		void supprimer(String^, String^);
		void modifier(MapEmploye^);
	private:
		CAD^ _cad;
		MapEmploye^ _employe;
		DataSet^ _ds;
	};
}