#include "GestionCommande.h"

namespace Services {
	GestionCommande::GestionCommande(void) {
		this->initGestion();
		this->_commande = gcnew Composants::MapCommande();
	}

	GestionCommande::GestionCommande(String^ reference, String^ nomClient, String^ prenomClient) {
		this->initGestion();
		this->_commande = gcnew Composants::MapCommande(reference, nomClient, prenomClient);
	}

	GestionCommande::GestionCommande(String^ reference, String^ nomClient, String^ prenomClient, DateTime^ dateDernierSolde, DateTime^ dateLivraison, Adresse^ adresseLivraison, Adresse^ adressePaiement, String^ referenceObjet, String^ quantite, DateTime^ datePaiement, String^ moyenDePaiement) {
		this->initGestion();;
		this->_commande = gcnew Composants::MapCommande(reference, nomClient, prenomClient, dateDernierSolde, dateLivraison, adresseLivraison, adressePaiement, referenceObjet, quantite, datePaiement, moyenDePaiement);
	}

	DataSet^ GestionCommande::liste(int choix) {
		this->_ds = gcnew DataSet();
		this->_ds = this->_cad->getRows(this->_commande->SELECT(choix), "commande");
		return this->_ds;
	}

	void GestionCommande::ajouter(void) {
		if (this->_cad->actionRowsID("SELECT * FROM commande WHERE commande.reference = '" + this->_commande->get_reference() + "'") != 0) {
			this->_cad->actionRows(this->_commande->INSERT(1));
			throw gcnew bool(1);
		}
		this->_cad->actionRows(this->_commande->INSERT(0));
		if (this->_cad->actionRowsID("SELECT * FROM commande WHERE commande.reference = '" + this->_commande->get_reference() + "'") != 0) {
			throw gcnew bool(1);
		}
		else {
			throw gcnew bool(0);
		}
	}

	void GestionCommande::supprimer(void) {
		if (this->_cad->actionRowsID("SELECT * FROM commande WHERE commande.reference = '" + this->_commande->get_reference() + "'") == 0) {
			throw gcnew String("Cette commande n\'existe pas !");
		}
		this->_cad->actionRows(this->_commande->DELETE());
		if (this->_cad->actionRowsID("SELECT * FROM commande WHERE commande.reference = '" + this->_commande->get_reference() + "'") == 0) {
			throw gcnew bool(1);
		}
		else {
			throw gcnew bool(0);
		}
	}

	void GestionCommande::modifier(String^ id) {
		this->_cad->actionRows(this->_commande->UPDATE(id));
	}
}