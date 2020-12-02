#include "MapCommande.h"

namespace Composants {
	MapCommande::MapCommande(void) {
		this->_ID = -1;
		this->_reference = "";
		this->_nomClient = "";
	}

	MapCommande::MapCommande(String^ reference, String^ nomClient, String^ prenomClient) {
		this->set_reference(reference);
		this->set_nomClient(nomClient);
		this->set_prenomClient(prenomClient);
	}

	MapCommande::MapCommande(String^ reference, String^ nomClient, String^ prenomClient, DateTime^ dateDernierSolde, DateTime^ dateLivraison, Adresse^ adresseLivraison, Adresse^ adressePaiement, String^ referenceObjet, String^ quantite, DateTime^ datePaiement, String^ moyenDePaiement) {
		this->set_reference(reference);
		this->set_nomClient(nomClient);
		this->set_prenomClient(prenomClient);
		this->set_dateDernierSolde(dateDernierSolde);
		this->set_dateLivraison(dateLivraison);
		this->set_adresseLivraison(adresseLivraison);
		this->set_adressePaiement(adressePaiement);
		this->set_referenceObjet(referenceObjet);
		this->set_quantite(quantite);
		this->set_datePaiement(datePaiement);
		this->set_moyenDePaiement(moyenDePaiement);
	}

	String^ MapCommande::SELECT(int choix) {
		switch (choix) {
		case 0:
			return "SELECT CONCAT(SUBSTRING(client.nom, 0, 2), SUBSTRING(client.prenom, 0, 2), YEAR(date.date), SUBSTRING(adresse.nomDeCommune, 0, 3), commande.ID) AS reference, date.date AS livraison FROM commande LEFT JOIN daterCommande ON commande.ID = daterCommande.ID_commande LEFT JOIN date ON daterCommande.ID_date = date.ID LEFT JOIN client ON commande.ID_client = client.ID LEFT JOIN localiserCommande ON commande.ID = localiserCommande.ID_commande LEFT JOIN adresse ON localiserCommande.ID_adresse = adresse.ID WHERE localiserCommande.livraison = 1 AND daterCommande.envois = 1";
			break;
		case 1:
			return "";
			break;
		case 2:
			return "";
			break;
		case 3:
			return "";
			break;
		}
	}

	String^ MapCommande::INSERT(void) {
		String^ na = gcnew String("NA");
		return "BEGIN TRANSACTION; DECLARE @idCommande INT;" +
			"INSERT INTO commande (ID_client) VALUES ((SELECT client.ID FROM client WHERE client.nom = '" + this->get_nomClient() + "' AND client.prenom = '" + this->get_prenomClient() + "'));" +
			"SET @idCommande = 1;" +
			"INSERT INTO daterCommande (ID_commande, ID_date, envois, moyenDePaiement) VALUES (@idCommande, (SELECT date.ID FROM date WHERE date.date = '" + this->get_dateLivraison() + "'), 1, '" + na + "');" +
			"INSERT INTO daterCommande (ID_commande, ID_date, envois, moyenDePaiement) VALUES (@idCommande, (SELECT date.ID FROM date WHERE date.date = '" + this->get_dateDernierSolde() + "'), 0, '" + this->get_moyenDePaiement() + "');" +
			"INSERT INTO localiserCommande (ID_commande, ID_adresse, livraison) VALUES (@idCommande, (SELECT adresse.ID FROM adresse WHERE adresse.numeroDeVoie = '" + this->get_adresseLivraison()->get_numeroDeVoie() + "' AND adresse.complementDeNumero = '" + this->get_adresseLivraison()->get_complementDeNumero() + "' AND adresse.typeDeVoie = '" + this->get_adresseLivraison()->get_typeDeVoie() + "' AND adresse.nomDeVoie = '" + this->get_adresseLivraison()->get_nomDeVoie() + "' and adresse.codePostal = '" + this->get_adresseLivraison()->get_codePostal() + "' AND adresse.nomDeCommune = '" + this->get_adresseLivraison()->get_nomDeCommune() + "'), 1);" +
			"INSERT INTO localiserCommande (ID_commande, ID_adresse, livraison) VALUES (@idCommande, (SELECT adresse.ID FROM adresse WHERE adresse.numeroDeVoie = '" + this->get_adressePaiement()->get_numeroDeVoie() + "' AND adresse.complementDeNumero = '" + this->get_adressePaiement()->get_complementDeNumero() + "' AND adresse.typeDeVoie = '" + this->get_adressePaiement()->get_typeDeVoie() + "' AND adresse.nomDeVoie = '" + this->get_adressePaiement()->get_nomDeVoie() + "' and adresse.codePostal = '" + this->get_adressePaiement()->get_codePostal() + "' AND adresse.nomDeCommune = '" + this->get_adressePaiement()->get_nomDeCommune() + "'), 0);" +
			"INSERT INTO contenir (ID_commande, ID_article, quantite) VALUES (@idCommande, (SELECT article.ID FROM article WHERE article.reference = '" + this->get_referenceObjet() + "'), '" + this->get_quantite() + "');" +
			"COMMIT";
	}

	String^ MapCommande::DELETE(void) {
		return "BEGIN TRANSACTION;" +
			"DELETE FROM daterCommande" +
			"DELETE FROM localiserCommande" +
			"DELETE FROM contenir" +
			"DELETE FROM commande;" +
			"COMMIT";
	}

	String^ MapCommande::UPDATE(int^ id) {
		return "";
	}

	void MapCommande::set_ID(int ID) {
		if (ID > 0) {
			this->_ID = ID;
		}
		else {
			throw gcnew String("Un ID ne peut pas être négatif !");
		}
	}

	void MapCommande::set_reference(String^ reference) {
		if (reference != "") {
			this->_reference = reference;
		}
		else {
			throw gcnew String("La reference de la commande doit être spécifiée !");
		}
	}

	void MapCommande::set_nomClient(String^ nomClient) {
		if (nomClient != "") {
			this->_nomClient = nomClient;
		}
		else {
			throw gcnew String("Le nom du client doit être spécifié !");
		}
	}

	void MapCommande::set_prenomClient(String^ prenomClient) {
		if (prenomClient != "") {
			this->_prenomClient = prenomClient;
		}
		else {
			throw gcnew String("Le prenom du client doit être spécifié !");
		}
	}

	void MapCommande::set_dateDernierSolde(DateTime^ dateDernierSolde) {
		this->_dateDernierSolde = dateDernierSolde;
	}

	void MapCommande::set_dateLivraison(DateTime^ dateLivraison) {
		this->_dateLivraison = dateLivraison;
	}

	void MapCommande::set_adresseLivraison(Adresse^ adresseLivraison) {
		this->_adresseLivraison = adresseLivraison;
	}

	void MapCommande::set_adressePaiement(Adresse^ adressePaiement) {
		this->_adressePaiement = adressePaiement;
	}

	void MapCommande::set_referenceObjet(String^ referenceObjet) {
		if (referenceObjet != "") {
			this->_referenceObjet = referenceObjet;
		}
		else {
			throw gcnew String("La reference de l'article doit être spécifiée !");
		}
	}

	void MapCommande::set_quantite(String^ quantite) {
		if (quantite == "") {
			throw gcnew String("La quantite doit être definie !");
		}
		try {
			if (Convert::ToInt32(quantite) >= 0) {
				this->_quantite = quantite;
			}
			else {
				throw gcnew String("La quantite ne peut pas être négative !");
			}
		}
		catch (FormatException^) {
			throw gcnew String("La quantite doit être numérique !");
		}
	}

	void MapCommande::set_datePaiement(DateTime^ datePaiement) {
		this->_datePaiement = datePaiement;
	}

	void MapCommande::set_moyenDePaiement(String^ moyenDePaiement) {
		if (moyenDePaiement != "") {
			this->_moyenDePaiement = moyenDePaiement;
		}
		else {
			throw gcnew String("Le moyen de paiement doit être spécifié !");
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

	String^ MapCommande::get_prenomClient(void) {
		return this->_prenomClient;
	}

	DateTime^ MapCommande::get_dateDernierSolde(void) {
		return this->_dateDernierSolde;
	}

	DateTime^ MapCommande::get_dateLivraison(void) {
		return this->_dateLivraison;
	}

	Adresse^ MapCommande::get_adresseLivraison(void) {
		return this->_adresseLivraison;
	}

	Adresse^ MapCommande::get_adressePaiement(void) {
		return this->_adressePaiement;
	}

	String^ MapCommande::get_referenceObjet(void) {
		return this->_referenceObjet;
	}

	String^ MapCommande::get_quantite(void) {
		return this->_quantite;
	}

	DateTime^ MapCommande::get_datePaiement(void) {
		return this->_datePaiement;
	}

	String^ MapCommande::get_moyenDePaiement(void) {
		return this->_moyenDePaiement;
	}
}