#include "GestionClient.h"

namespace Services {
	GestionClient::GestionClient(void) {
		this->initGestion();
		this->_client = gcnew Composants::MapClient();
	}

	GestionClient::GestionClient(String^ nom, String^ prenom) {
		this->initGestion();
		this->_client = gcnew Composants::MapClient(nom, prenom);
	}

	GestionClient::GestionClient(String^ nom, String^ prenom, DateTime^ dateNaissance) {
		this->initGestion();
		this->_client = gcnew Composants::MapClient(nom, prenom, dateNaissance);
	}

	DataSet^ GestionClient::liste(void) {
		this->_ds = gcnew DataSet();
		this->_ds = this->_cad->getRows(this->_client->SELECT(), "client");
		return this->_ds;
	}

	void GestionClient::ajouter(void) {
		if (this->_cad->actionRowsID("SELECT * FROM client WHERE client.nom = '" + this->_client->get_nom() + "' AND client.prenom = '" + this->_client->get_prenom() + "'") != 0) {
			throw gcnew String("Cet employé existe deja !");
		}
		this->_cad->actionRows(this->_client->INSERT());
		if (this->_cad->actionRowsID("SELECT * FROM client WHERE client.nom = '" + this->_client->get_nom() + "' AND client.prenom = '" + this->_client->get_prenom() + "'") != 0) {
			throw gcnew bool(1);
		}
		else {
			throw gcnew bool(0);
		}
	}

	void GestionClient::supprimer(void) {
		if (this->_cad->actionRowsID("SELECT * FROM client WHERE client.nom = '" + this->_client->get_nom() + "' AND client.prenom = '" + this->_client->get_prenom() + "'") == 0) {
			throw gcnew String("Cet employé n\'existe pas !");
		}
		this->_cad->actionRows(this->_client->DELETE());
		if (this->_cad->actionRowsID("SELECT * FROM client WHERE client.nom = '" + this->_client->get_nom() + "' AND client.prenom = '" + this->_client->get_prenom() + "'") == 0) {
			throw gcnew bool(1);
		}
		else {
			throw gcnew bool(0);
		}
	}

	void GestionClient::modifier(int^ id) {
		this->_cad->actionRows(this->_client->UPDATE(id));
	}
}