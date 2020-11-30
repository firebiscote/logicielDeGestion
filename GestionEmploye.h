#pragma once
#include "pch.h"
#include "Gestion.h"
#include "CAD.h"
#include "MapEmploye.h"

namespace Services {
	ref class GestionEmploye {
	public:
		GestionEmploye(void);
		DataSet^ listeEmploye(void);
		void ajouter(String^, String^, String^, String^, DateTime^, Adresse^);
		void supprimer(String^, String^);
		void modifier(Composants::MapEmploye^);
	private:
		Composants::CAD^ _cad;
		Composants::MapEmploye^ _employe;
		DataSet^ _ds;
	};
}