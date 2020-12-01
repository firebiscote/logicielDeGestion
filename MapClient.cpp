#include "MapClient.h"

namespace Composants {
	MapClient::MapClient(void) {
		this->_ID = -1;
		this->_nom = "";
		this->_prenom = "";
		this->_dateNaissance = nullptr;
	}

	MapClient::MapClient(String^ nom, String^ prenom) {
		this->set_nom(nom);
		this->set_prenom(prenom);
	}

	MapClient::MapClient(String^ nom, String^ prenom, DateTime^ dateNaissance) {
		this->set_nom(nom);
		this->set_prenom(prenom);
		this->set_dateNaissance(dateNaissance);
	}

	String^ MapClient::SELECT(void) {
		return "";
	}

	String^ MapClient::INSERT(void) {
		return "";
	}

	String^ MapClient::DELETE(void) {
		return "";
	}

	String^ MapClient::UPDATE(int^ id) {
		return "";
	}

	void MapClient::set_ID(int ID) {
		if (ID > 0) {
			this->_ID = ID;
		}
		else {
			throw gcnew String("Un ID ne peut pas être négatif !");
		}
	}

	void MapClient::set_nom(String^ nom) {
		if (nom != "") {
			this->_nom = nom;
		}
		else {
			throw gcnew String("Le nom de du client doit être spécifié !");
		}
	}

	void MapClient::set_prenom(String^ prenom) {
		if (prenom != "") {
			this->_prenom = prenom;
		}
		else {
			throw gcnew String("Le prénom de du client doit être spécifié !");
		}
	}

	void MapClient::set_dateNaissance(DateTime^ dateNaissance) {
		this->_dateNaissance = dateNaissance;
	}

	int MapClient::get_ID(void) {
		return this->_ID;
	}

	String^ MapClient::get_nom(void) {
		return this->_nom;
	}

	String^ MapClient::get_prenom(void) {
		return this->_prenom;
	}

	DateTime^ MapClient::get_dateNaissance(void) {
		return this->_dateNaissance;
	}
}