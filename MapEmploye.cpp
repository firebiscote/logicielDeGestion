#include "MapEmploye.h"

MapEmploye::MapEmploye(void) {
	this->_ID = -1;
	this->_nom = "";
	this->_prenom = "";
	this->_nomSuperieur = "";
	this->_prenomSuperieur = "";
	this->_dateEmbauche = gcnew Date();
	this->_adresseDomicile = gcnew Adresse();
}

String^ MapEmploye::SELECT(void) {
	return "";
}

String^ MapEmploye::INSERT(void) {
	return "";
}

String^ MapEmploye::DELETE(void) {
	return "";
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

void MapEmploye::set_dateEmbauche(int^ jour, int^ mois, int^ annee) {
	this->_dateEmbauche->set_jour(jour);
	this->_dateEmbauche->set_mois(mois);
	this->_dateEmbauche->set_annee(annee);
}

void MapEmploye::set_dateEmbauche(Date^ dateEmbauche) {
	this->_dateEmbauche->set_jour(dateEmbauche->get_jour());
	this->_dateEmbauche->set_mois(dateEmbauche->get_mois());
	this->_dateEmbauche->set_annee(dateEmbauche->get_annee());
}

void MapEmploye::set_adresseDomicile(Adresse^ adresseDomicile) {
	this->_adresseDomicile->set_nomDeVoie(adresseDomicile->get_numeroDeVoie());
	this->_adresseDomicile->set_complementDeNumero(adresseDomicile->get_complementDeNumero());
	this->_adresseDomicile->set_typeDeVoie(adresseDomicile->get_typeDeVoie());
	this->_adresseDomicile->set_nomDeVoie(adresseDomicile->get_nomDeVoie());
	this->_adresseDomicile->set_codePostal(adresseDomicile->get_codePostal());
	this->_adresseDomicile->set_nomDeCommune(adresseDomicile->get_nomDeCommune());
}