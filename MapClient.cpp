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

	MapClient::MapClient(String^ nom, String^ prenom, DateTime^ dateNaissance, Adresse^ adresse) {
		this->set_nom(nom);
		this->set_prenom(prenom);
		this->set_dateNaissance(dateNaissance);
		this->set_adresse(adresse);
	}

	String^ MapClient::SELECT(int choix) {
		switch (choix) {
		case 0:
			return "SELECT client.ID, CONCAT(client.nom, ' ', client.prenom) AS client, date.date AS naissance FROM client LEFT JOIN date ON client.ID_date = date.ID";
			break;
		case 1:
			return "SELECT client.ID, CONCAT(client.nom, ' ', client.prenom) AS client, date.date AS naissance FROM client LEFT JOIN date ON client.ID_date = date.ID WHERE client.nom = '" + this->get_nom() + "' AND client.prenom = '" + this->get_prenom() + "')";
			break;
		case 2:
			return "SELECT CONCAT(adresse.numeroDeVoie, ' ', adresse.complementDeNumero) AS numero, CONCAT(adresse.typeDeVoie, ' ', adresse.nomDeVoie) AS voie, CONCAT(adresse.codePostal, ' ', adresse.nomDeCommune) AS ville FROM client LEFT JOIN localiserClient ON client.ID = localiserClient.ID_client LEFT JOIN adresse ON localiserClient.ID_adresse = adresse.ID WHERE client.nom = '" + this->get_nom() + "' AND client.prenom = '" + this->get_prenom() + "')";
			break;
		}
		
	}

	String^ MapClient::INSERT(void) {
		return "BEGIN TRANSACTION; DECLARE @idClient INT; DECLARE @idDate INT; DECLARE @idAdresse INT;" +
			"IF '" + this->get_dateNaissance() + "' NOT IN (SELECT date.date FROM date) BEGIN" +
			"	INSERT INTO date (date.date) VALUES('" + this->get_dateNaissance() + "');\nEND\n" +
			"SET @idDate = (SELECT date.ID FROM date WHERE date.date = '" + this->get_dateNaissance() + "');" +
			"IF CONCAT('" + this->get_adresse()->get_numeroDeVoie() + "', '" + this->get_adresse()->get_complementDeNumero() + "', '" + this->get_adresse()->get_typeDeVoie() + "', '" + this->get_adresse()->get_nomDeVoie() + "', '" + this->get_adresse()->get_codePostal() + "', '" + this->get_adresse()->get_nomDeCommune() + "') NOT IN (SELECT CONCAT(adresse.numeroDeVoie, adresse.complementDeNumero, adresse.typeDeVoie, adresse.nomDeVoie, adresse.codePostal, adresse.nomDeCommune) FROM adresse) BEGIN" +
			"	INSERT INTO adresse (adresse.numeroDeVoie, adresse.complementDeNumero, adresse.typeDeVoie, adresse.nomDeVoie, adresse.codePostal, adresse.nomDeCommune) VALUES('" + this->get_adresse()->get_numeroDeVoie() + "', '" + this->get_adresse()->get_complementDeNumero() + "', '" + this->get_adresse()->get_typeDeVoie() + "', '" + this->get_adresse()->get_nomDeVoie() + "', '" + this->get_adresse()->get_codePostal() + "', '" + this->get_adresse()->get_nomDeCommune() + "');\nEND\n" +
			"SET @idAdresse = (SELECT adresse.ID FROM adresse WHERE adresse.numeroDeVoie = '" + this->get_adresse()->get_numeroDeVoie() + "' AND adresse.complementDeNumero = '" + this->get_adresse()->get_complementDeNumero() + "' AND adresse.typeDeVoie = '" + this->get_adresse()->get_typeDeVoie() + "' AND adresse.nomDeVoie = '" + this->get_adresse()->get_nomDeVoie() + "' and adresse.codePostal = '" + this->get_adresse()->get_codePostal() + "' AND adresse.nomDeCommune = '" + this->get_adresse()->get_nomDeCommune() + "');" +
			"IF CONCAT('" + this->get_nom() + "', '" + this->get_prenom() + "') NOT IN (SELECT CONCAT(employe.nom, employe.prenom) FROM employe) BEGIN" +
			"	INSERT INTO client (client.nom, client.prenom) VALUES('" + this->get_nom() + "', '" + this->get_prenom() + "');\nEND\n" +
			"SET @idClient = (SELECT client.ID FROM client WHERE client.nom = '" + this->get_nom() + "' AND client.prenom = '" + this->get_prenom() + "')" +
			"IF CONCAT(@idClient, @idDate) NOT IN (SELECT CONCAT(daterClient.ID_client, daterClient.ID_date) FROM daterClient) BEGIN" +
			"	INSERT INTO daterClient (daterClient.ID_client, daterClient.ID_date, daterClient.naissance) VALUES(@idClient, @idDate, 1);\nEND\n" +
			"IF CONCAT(@idClient, @idAdresse) NOT IN (SELECT CONCAT(localiserClient.ID_client, localiserClient.ID_adresse) FROM localiserClient) BEGIN" +
			"	INSERT INTO localiserClient (localiserClient.ID_client, localiserClient.ID_adresse) VALUES(@idClient, @idAdresse);\nEND\n" +
			"COMMIT";
	}

	String^ MapClient::DELETE(void) {
		return	"BEGIN TRANSACTION; DECLARE @idClient INT;" +
			"SET @idClient = (SELECT ID FROM client WHERE nom = '" + this->get_nom() + "' AND prenom = '" + this->get_prenom() + "');" +
			"DELETE FROM client WHERE ID = @idClient;" +
			"DELETE FROM localiserClient WHERE ID_client = @idClient;" +
			"DELETE FROM adresse WHERE ID NOT IN (SELECT ID_adresse FROM localiserClient);" +
			"DELETE FROM daterClient WHERE ID_client = @idClient;" +
			"DELETE FROM date WHERE ID NOT IN (SELECT ID_date FROM daterClient);" +
			"COMMIT";
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

	void MapClient::set_adresse(String^ numeroDeVoie, String^ typeDeVoie, String^ nomDeVoie, String^ codePostal, String^ nomDeCommune) {
		this->set_adresse(gcnew Adresse(numeroDeVoie, "", typeDeVoie, nomDeVoie, codePostal, nomDeCommune));
	}

	void MapClient::set_adresse(String^ numeroDeVoie, String^ complementDeNumero, String^ typeDeVoie, String^ nomDeVoie, String^ codePostal, String^ nomDeCommune) {
		this->set_adresse(gcnew Adresse(numeroDeVoie, complementDeNumero, typeDeVoie, nomDeVoie, codePostal, nomDeCommune));
	}

	void MapClient::set_adresse(Adresse^ adresse) {
		this->_adresse = adresse;
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

	Adresse^ MapClient::get_adresse(void) {
		return this->_adresse;
	}
}