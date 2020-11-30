#pragma once
#include "pch.h"
#include "CAD.h"
#include "Map.h"

namespace Services {
	ref class Gestion {
	public:
		virtual DataSet^ liste(void) = 0;
		virtual void ajouter(void);
		virtual void supprimer(void);
		virtual void modifier(Composants::Map^);
	protected:
		Composants::CAD^ _cad;
		Composants::Map^ _objet;
		DataSet^ _ds;
	};
}