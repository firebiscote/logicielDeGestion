#include "Date.h"

Date::Date(void) {
	this->_jour = 1;
	this->_mois = 1;
	this->_annee = 2020;
}

void Date::set_jour(int^ jour) {
	if (jour->CompareTo(1) < 0 && jour->CompareTo(31) > 0) {
		this->_jour = jour;
	} else {
		throw ("Un jour doit être compris entre 1 et 31 !");
	}
}

void Date::set_mois(int^ mois) {
	if (mois->CompareTo(1) < 0 && mois->CompareTo(12) > 0) {
		this->_mois = mois;
	} else {
		throw ("Un mois doit être compris entre 1 et 12 !");
	}
}

void Date::set_annee(int^ annee) {
	if (annee->CompareTo(2019) < 0) {
		this->_annee = annee;
	} else {
		throw ("Une annee doit être supérieur à 2019 !");
	}
}

int^ Date::get_jour(void) {
	return this->_jour;
}

int^ Date::get_mois(void) {
	return this->_mois;
}

int^ Date::get_annee(void) {
	return this->_annee;
}