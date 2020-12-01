#include "GestionCommande.h"

namespace Services {
	GestionCommande::GestionCommande(void) {
		this->initGestion();
		this->_commande = gcnew Composants::MapCommande();
	}

	GestionCommande::GestionCommande(String^ reference) {
		this->initGestion();
		this->_commande = gcnew Composants::MapCommande(reference);
	}

	GestionCommande::GestionCommande(String^ reference, String^ nomClient) {
		this->initGestion();
		this->_commande = gcnew Composants::MapCommande(reference, nomClient);
	}

	DataSet^ GestionCommande::liste(int choix) {
		this->_ds = gcnew DataSet();
		this->_ds = this->_cad->getRows(this->_commande->SELECT(choix), "commande");
		return this->_ds;
	}

	void GestionCommande::ajouter(void) {
		/*if (this->_cad->actionRowsID("SELECT * FROM commande WHERE commande.nom = '" + this->_commande->get_nom() + "' AND commande.prenom = '" + this->_commande->get_prenom() + "'") != 0) {
			throw gcnew String("Cette commande existe deja !");
		}*/
		this->_cad->actionRows(this->_commande->INSERT());
		/*if (this->_cad->actionRowsID("SELECT * FROM commande WHERE commande.nom = '" + this->_commande->get_nom() + "' AND commande.prenom = '" + this->_commande->get_prenom() + "'") != 0) {
			throw gcnew bool(1);
		}
		else {
			throw gcnew bool(0);
		}*/
	}

	void GestionCommande::supprimer(void) {
		/*if (this->_cad->actionRowsID("SELECT * FROM commande WHERE commande.nom = '" + this->_commande->get_nom() + "' AND commande.prenom = '" + this->_commande->get_prenom() + "'") == 0) {
			throw gcnew String("Cette commande n\'existe pas !");
		}*/
		this->_cad->actionRows(this->_commande->DELETE());
		/*if (this->_cad->actionRowsID("SELECT * FROM commande WHERE commande.nom = '" + this->_commande->get_nom() + "' AND commande.prenom = '" + this->_commande->get_prenom() + "'") == 0) {
			throw gcnew bool(1);
		}
		else {
			throw gcnew bool(0);
		}*/
	}

	void GestionCommande::modifier(int^ id) {
		this->_cad->actionRows(this->_commande->UPDATE(id));
	}
}