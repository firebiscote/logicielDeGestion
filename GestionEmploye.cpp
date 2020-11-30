#include "GestionEmploye.h"

namespace Services {
	GestionEmploye::GestionEmploye(void) {
		this->_cad = gcnew Composants::CAD();
		this->_employe = gcnew Composants::MapEmploye();
		this->_ds = nullptr;
	}

	DataSet^ GestionEmploye::listeEmploye(void) {
		this->_ds = gcnew DataSet();
		this->_ds = this->_cad->getRows(this->_employe->SELECT(), "employe");
		return this->_ds;
	}

	void GestionEmploye::ajouter(String^ nom, String^ prenom, String^ nomSuperieur, String^ prenomSuperieur, DateTime^ dateEmbauche, Adresse^ adresseDomicile) {
		if (this->_cad->actionRowsID("SELECT * FROM employe WHERE employe.nom = '" + nom + "' AND employe.prenom = '" + prenom + "'") != 0) {
			throw gcnew String("Cet employé existe deja !");
		}
		this->_employe = gcnew Composants::MapEmploye(nom, prenom, nomSuperieur, prenomSuperieur, dateEmbauche->Date, adresseDomicile);
		this->_cad->actionRows(this->_employe->INSERT());
		if (this->_cad->actionRowsID("SELECT * FROM employe WHERE employe.nom = '" + nom + "' AND employe.prenom = '" + prenom + "'") != 0) {
			throw gcnew bool(1);
		} else {
			throw gcnew bool(0);
		}
	}

	void GestionEmploye::supprimer(String^ nom, String^ prenom) {
		if (this->_cad->actionRowsID("SELECT * FROM employe WHERE employe.nom = '" + nom + "' AND employe.prenom = '" + prenom + "'") == 0) {
			throw gcnew String("Cet employé n\'existe pas !");
		}
		this->_employe->set_nom(nom);
		this->_employe->set_prenom(prenom);
		this->_cad->actionRows(this->_employe->DELETE());
		if (this->_cad->actionRowsID("SELECT * FROM employe WHERE employe.nom = '" + nom + "' AND employe.prenom = '" + prenom + "'") == 0) {
			throw gcnew bool(1);
		} else {
			throw gcnew bool(0);
		}
	}

	void GestionEmploye::modifier(Composants::MapEmploye^ employe) {
		this->_cad->actionRows(this->_employe->UPDATE(employe));
	}
}