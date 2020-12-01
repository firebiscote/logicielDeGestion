#pragma once
#include "pch.h"
#include "Gestion.h"
#include "CAD.h"
#include "MapArticle.h"

namespace Services {
	ref class GestionArticle : public Gestion {
	public:
		GestionArticle(void);
		GestionArticle(String^, String^);
		GestionArticle(String^, String^, String^, String^, String^, String^);
		virtual DataSet^ liste(void) override;
		virtual void ajouter(void) override;
		virtual void supprimer(void) override;
		virtual void modifier(int^) override;
	private:
		Composants::MapArticle^ _article;
	};

}