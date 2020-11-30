#include "GestionEmploye.h"

namespace Services {
	GestionEmploye::GestionEmploye(void) {
		this->_cad = gcnew CAD();
		this->_employe = gcnew MapEmploye();
		this->_ds = nullptr;
	}

	DataSet^ GestionEmploye::listeEmploye(void) {
		this->_ds = gcnew DataSet();
		this->_ds = this->_cad->getRows(this->_employe->SELECT(), "employe");
		return this->_ds;
	}

	void GestionEmploye::ajouter(String^ nom, String^ prenom, String^ nomSuperieur, String^ prenomSuperieur, DateTime^ dateEmbauche, Adresse^ adresseDomicile) {
		this->_employe = gcnew MapEmploye(nom, prenom, nomSuperieur, prenomSuperieur, dateEmbauche, adresseDomicile);
		this->_cad->actionRows(this->_employe->INSERT());
	}

	void GestionEmploye::supprimer(String^ nom, String^ prenom) {
		this->_employe->set_nom(nom);
		this->_employe->set_prenom(prenom);
		this->_cad->actionRows(this->_employe->DELETE());
	}

	void GestionEmploye::modifier(MapEmploye^ employe) {
		this->_cad->actionRows(this->_employe->UPDATE(employe));
	}
}