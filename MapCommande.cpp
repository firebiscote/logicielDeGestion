#include "MapCommande.h"

namespace Composants {
	MapCommande::MapCommande(void) {
		this->_ID = -1;
		this->_reference = "";
		this->_nomClient = "";
	}

	MapCommande::MapCommande(String^ reference) {
		this->set_reference(reference);
	}

	MapCommande::MapCommande(String^ reference, String^ nomClient) {
		this->set_reference(reference);
		this->set_nomClient(nomClient);
	}

	String^ MapCommande::SELECT(void) {
		return "";
	}

	String^ MapCommande::INSERT(void) {
		return "";
	}

	String^ MapCommande::DELETE(void) {
		return "";
	}

	String^ MapCommande::UPDATE(int^ id) {
		return "";
	}

	void MapCommande::set_ID(int ID) {
		if (ID > 0) {
			this->_ID = ID;
		}
		else {
			throw gcnew String("Un ID ne peut pas �tre n�gatif !");
		}
	}

	void MapCommande::set_reference(String^ reference) {
		if (reference != "") {
			this->_reference = reference;
		}
		else {
			throw gcnew String("La reference de la commande doit �tre sp�cifi�e !");
		}
	}

	void MapCommande::set_nomClient(String^ nomClient) {
		if (nomClient != "") {
			this->_nomClient = nomClient;
		}
		else {
			throw gcnew String("Le nom du client doit �tre sp�cifi� !");
		}
	}

	int MapCommande::get_ID(void) {
		return this->_ID;
	}

	String^ MapCommande::get_reference(void) {
		return this->_reference;
	}

	String^ MapCommande::get_nomClient(void) {
		return this->_nomClient;
	}
}