#pragma once
#include "pch.h"
#include "CAD.h"
#include "Map.h"

namespace Services {
	ref class Gestion {
	public:
		virtual DataSet^ liste(void) abstract;
		virtual void ajouter(void) abstract;
		virtual void supprimer(void) abstract;
		virtual void modifier(int^) abstract;
	protected:
		void initGestion(void);
		Composants::CAD^ _cad;
		DataSet^ _ds;
	};
}