#include "MapEmploye.h"

MapEmploye::MapEmploye(void) {
	this->_ID = -1;
	this->_nom = "";
	this->_prenom = "";
	this->_nomSuperieur = "";
	this->_prenomSuperieur = "";
	this->_dateEmbauche = gcnew DateTime();
	this->_adresseDomicile = gcnew Adresse();
}

MapEmploye::MapEmploye(String^ nom, String^ prenom, String^ nomSuperieur, String^ prenomSuperieur, DateTime^ dateEmbauche, Adresse^ adresseDomicile) {
	this->set_nom(nom);
	this->set_prenom(prenom);
	this->set_nomSuperieur(nomSuperieur);
	this->set_prenomSuperieur(prenomSuperieur);
	this->set_dateEmbauche(dateEmbauche);
	this->set_adresseDomicile(adresseDomicile);
}

String^ MapEmploye::SELECT(void) {
	return	"SELECT " + 
			"CONCAT(employe.prenom, employe.nom) AS employe, CONCAT(superieur.prenom, superieur.nom) AS superieur, date.date AS embauche, CONCAT(adresse.numeroDeVoie, adresse.complementDeNumero, adresse.typeDeVoie, adresse.nomDeVoie, adresse.codePostal, adresse.nomDeCommune) AS domicile " + 
			"FROM employe LEFT JOIN employe AS superieur ON employe.ID_employe = superieur.ID " + 
			"LEFT JOIN adresse ON employe.ID_adresse = adresse.ID " +
			"LEFT JOIN date ON employe.ID_date = date.ID";
}

String^ MapEmploye::INSERT(void) {
	return	"BEGIN TRANSACTION; DECLARE @idSuperieur INT; DELCARE @idDate INT; DECLARE @idAdresse INT;" +
			"SET @idSuperieur = (SELECT ID FROM employe WHERE nom = '" + this->get_nomSuperieur() + "' AND prenom = '" + this->get_prenomSuperieur() + "');" +
			"IF '" + this->get_dateEmbauche() + "' NOT IN (SELECT date FROM date) BEGIN" +
			"	INSERT INTO date (date) VALUES('" + this->get_dateEmbauche() + "');\nEND\n" +
			"SET @idDate = (SELECT ID FROM date WHERE date = '" + this->get_dateEmbauche() + "');" +
			"IF CONCAT('" + this->get_adresseDomicile()->get_numeroDeVoie() + "', '" + this->get_adresseDomicile()->get_complementDeNumero() + "', '" + this->get_adresseDomicile()->get_typeDeVoie() + "', '" + this->get_adresseDomicile()->get_nomDeVoie() + "', '" + this->get_adresseDomicile()->get_codePostal() + "', '" + this->get_adresseDomicile()->get_nomDeCommune() + "') NOT IN (SELECT CONCAT(numeroDeVoie, complementDeNumero, typeDeVoie, nomDeVoie, codePostal, nomDeCommune) FROM adresse) BEGIN" +
			"	INSERT INTO adresse (numeroDeVoie, complementDeNumero, typeDeVoie, nomDeVoie, codePostal, nomDeCommune) VALUES('" + this->get_adresseDomicile()->get_numeroDeVoie() + "', '" + this->get_adresseDomicile()->get_complementDeNumero() + "', '" + this->get_adresseDomicile()->get_typeDeVoie() + "', '" + this->get_adresseDomicile()->get_nomDeVoie() + "', '" + this->get_adresseDomicile()->get_codePostal() + "', '" + this->get_adresseDomicile()->get_nomDeCommune() + "');\nEND\n" +
			"SET @idAdresse = (SELECT ID FROM adresse WHERE numeroDeVoie = '" + this->get_adresseDomicile()->get_numeroDeVoie() + "' AND complementDeNumero = '" + this->get_adresseDomicile()->get_complementDeNumero() + "' AND typeDeVoie = '" + this->get_adresseDomicile()->get_typeDeVoie() + "' AND nomDeVoie = '" + this->get_adresseDomicile()->get_nomDeVoie() + "' and codePostal = '" + this->get_adresseDomicile()->get_codePostal() + "' AND nomDeCommune = '" + this->get_adresseDomicile()->get_nomDeCommune() + "');" +
			"IF CONCAT('" + this->get_nom() + "', '" + this->get_prenom() + ") NOT IN (SELECT CONCAT(nom, prenom) FROM employe) BEGIN" +
			"	INSERT INTO employe (nom, prenom, ID_employe, ID_adresse, ID_date) VALUES('" + this->get_nom() + "', '" + this->get_prenom() + "', @idSuperieur, @idAdresse, @idDate);\nEND\n" +
			"COMMIT";
}

String^ MapEmploye::DELETE(void) {
	return	"BEGIN TRANSACTION; DECLARE @idEmploye INT;" +
			"SET @idEmploye = (SELECT ID FROM employe WHERE nom = '" + this->get_nom() + "' AND prenom = '" + this->get_prenom() + "');" +
			"DELETE FROM employe WHERE ID = @idEmploye;" +
			"DELETE FROM adresse WHERE ID NOT IN (SELECT ID_adresse FROM employe);" +
			"DELETE FROM date WHERE ID NOT IN (SELECT ID_date FROM employe);" +
			"COMMIT";
}

String^ MapEmploye::UPDATE(MapEmploye^ employe) {
	return "";
}

void MapEmploye::set_ID(int ID) {
	if (ID > 0) {
		this->_ID = ID;
	} else {
		throw ("Un ID ne peut pas être négatif !");
	}
}

void MapEmploye::set_nom(String^ nom) {
	if (nom != "") {
		this->_nom = nom;
	} else {
		throw ("Un nom ne peut pas être vide !");
	}
}

void MapEmploye::set_prenom(String^ prenom) {
	if (prenom != "") {
		this->_prenom = prenom;
	} else {
		throw ("Un prenom ne peut pas être vide !");
	}
}

void MapEmploye::set_nomSuperieur(String^ nomSuperieur) {
	if (nomSuperieur != "") {
		this->_nomSuperieur = nomSuperieur;
	} else {
		throw ("Le nom du superieur doit être spécifié !");
	}
}

void MapEmploye::set_prenomSuperieur(String^ prenomSuperieur) {
	if (prenomSuperieur != "") {
		this->_prenomSuperieur = prenomSuperieur;
	} else {
		throw ("Le prénom du supérieur doit être spécifié !");
	}
}

void MapEmploye::set_dateEmbauche(DateTime^ dateEmbauche) {
	this->_dateEmbauche = dateEmbauche;
}

void MapEmploye::set_adresseDomicile(String^ numeroDeVoie, String^ typeDeVoie, String^ nomDeVoie, String^ codePostal, String^ nomDeCommune) {
	this->set_adresseDomicile(gcnew Adresse(numeroDeVoie, "", typeDeVoie, nomDeVoie, codePostal, nomDeCommune));
}

void MapEmploye::set_adresseDomicile(String^ numeroDeVoie, String^ complementDeNumero, String^ typeDeVoie, String^ nomDeVoie, String^ codePostal, String^ nomDeCommune) {
	this->set_adresseDomicile(gcnew Adresse(numeroDeVoie, complementDeNumero, typeDeVoie, nomDeVoie, codePostal, nomDeCommune));
}

void MapEmploye::set_adresseDomicile(Adresse^ adresseDomicile) {
	this->_adresseDomicile = adresseDomicile;
}

int^ MapEmploye::get_ID(void) {
	return this->_ID;
}

String^ MapEmploye::get_nom(void) {
	return this->_nom;
}

String^ MapEmploye::get_prenom(void) {
	return this->_prenom;
}

String^ MapEmploye::get_nomSuperieur(void) {
	return this->_nomSuperieur;
}

String^ MapEmploye::get_prenomSuperieur(void) {
	return this->_prenomSuperieur;
}

DateTime^ MapEmploye::get_dateEmbauche(void) {
	return this->_dateEmbauche;
}

Adresse^ MapEmploye::get_adresseDomicile(void) {
	return this->_adresseDomicile;
}