#pragma once
#include "pch.h"
#include "Gestion.h"
#include "CAD.h"
#include "MapCommande.h"

namespace Services {
	ref class GestionCommande : public Gestion {
	public:
		GestionCommande(void);
		GestionCommande(String^, String^);
		GestionCommande(String^, String^, String^, String^, String^, String^);
		virtual DataSet^ liste(void) override;
		virtual void ajouter(void) override;
		virtual void supprimer(void) override;
		virtual void modifier(int^) override;
	private:
		Composants::MapCommande^ _commande;
	};
}