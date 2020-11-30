#pragma once
#include "pch.h"
#include "Gestion.h"
#include "CAD.h"
#include "MapArticle.h"

namespace Services {
	ref class GestionArticle {
	public:
		GestionArticle(void);
		DataSet^ listeArticle(void);
		void ajouter(String^, String^, String^, String^, String^, String^);
		void supprimer(String^, String^);
		void modifier(Composants::MapArticle^);
	private:
		Composants::CAD^ _cad;
		Composants::MapArticle^ _article;
		DataSet^ _ds;
	};

}