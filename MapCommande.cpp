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
			return "SELECT commande.reference, CONCAT(client.nom, ' ', client.prenom) AS client, date1.date AS livraison, date2.date AS paiement, date2.moyenDePaiement, SUM(article.prixHT*contenir.quantite) AS totalHT, SUM((article.prixHT*(1+(article.tauxDeTVA/100)))*contenir.quantite) AS total FROM commande LEFT JOIN (SELECT ID_commande, date.date FROM daterCommande LEFT JOIN date ON ID_date = ID WHERE envois = 1) AS date1 ON commande.ID = date1.ID_commande LEFT JOIN (SELECT TOP(1) ID_commande, date.date, daterCommande.moyenDePaiement FROM daterCommande LEFT JOIN date ON ID_date = ID WHERE envois = 0) AS date2 ON commande.ID = date2.ID_commande LEFT JOIN client ON commande.ID_client = client.ID LEFT JOIN contenir ON commande.ID = contenir.ID_commande LEFT JOIN article ON contenir.ID_article = article.ID GROUP BY commande.reference, client.nom, client.prenom, date1.date, date2.date, date2.moyenDePaiement";
			break;
		case 1:
			return "SELECT commande.reference, CONCAT(client.nom, ' ', client.prenom) AS client, date1.date AS livraison, date2.date AS paiement, date2.moyenDePaiement, SUM(article.prixHT*contenir.quantite) AS totalHT, SUM((article.prixHT*(1+(article.tauxDeTVA/100)))*contenir.quantite) AS total FROM commande LEFT JOIN (SELECT ID_commande, date.date FROM daterCommande LEFT JOIN date ON ID_date = ID WHERE envois = 1) AS date1 ON commande.ID = date1.ID_commande LEFT JOIN (SELECT TOP(1) ID_commande, date.date, daterCommande.moyenDePaiement FROM daterCommande LEFT JOIN date ON ID_date = ID WHERE envois = 0) AS date2 ON commande.ID = date2.ID_commande LEFT JOIN client ON commande.ID_client = client.ID LEFT JOIN contenir ON commande.ID = contenir.ID_commande LEFT JOIN article ON contenir.ID_article = article.ID WHERE commande.reference = '" + this->get_reference() + "' GROUP BY commande.reference, client.nom, client.prenom, date1.date, date2.date, date2.moyenDePaiement";
			break;
		case 2:
			return "SELECT article.reference, article.designation, contenir.quantite FROM commande LEFT JOIN contenir ON commande.ID = ID_commande LEFT JOIN article ON ID_article = article.ID WHERE commande.reference = '" + this->get_reference() + "'";
			break; 
		case 3:
			return "SELECT CONCAT(numeroDeVoie, ' ', complementDeNumero) AS numero, CONCAT(typeDeVoie, ' ', nomDeVoie) AS rue, CONCAT(codePostal, ' ', nomDeCommune) AS ville, livraison FROM commande LEFT JOIN localiserCommande ON commande.ID = ID_commande LEFT JOIN adresse ON ID_adresse = adresse.ID WHERE commande.reference = '" + this->get_reference() + "' ORDER BY livraison";
			break;
		default:
			throw gcnew String("Erreur fatale");
			break;
		}
	}

	String^ MapCommande::INSERT(int choix) {
		String^ na = gcnew String("NA");
		switch (choix) {
		case 0:
			return "BEGIN TRANSACTION; DECLARE @idCommande INT; DECLARE @idDateEnvois INT; DECLARE @idDatePaiement INT; DECLARE @idAdresseLivraison INT; DECLARE @idAdressePaiement INT;" +
				"INSERT INTO commande (ID_client, reference) VALUES ((SELECT TOP(1) client.ID FROM client WHERE client.nom = '" + this->get_nomClient() + "' AND client.prenom = '" + this->get_prenomClient() + "'), '" + this->get_reference() + "');" +
				"SET @idCommande = (SELECT TOP(1) ID FROM commande ORDER BY ID DESC);" +
				"INSERT INTO date (date) VALUES ('" + this->get_dateLivraison() + "');" +
				"SET @idDateEnvois = (SELECT TOP(1) ID FROM date ORDER BY ID DESC);" +
				"INSERT INTO date (date) VALUES ('" + this->get_dateDernierSolde() + "');" +
				"SET @idDatePaiement = (SELECT TOP(1) ID FROM date ORDER BY ID DESC);" +
				"INSERT INTO daterCommande (ID_commande, ID_date, envois, moyenDePaiement) VALUES (@idCommande, @idDateEnvois, 1, '" + na + "');" +
				"INSERT INTO daterCommande (ID_commande, ID_date, envois, moyenDePaiement) VALUES (@idCommande, @idDatePaiement, 0, '" + this->get_moyenDePaiement() + "');" +
				"INSERT INTO adresse (numeroDeVoie, complementDeNumero, typeDeVoie, nomDeVoie, codePostal, nomDeCommune) VALUES ('" + this->get_adresseLivraison()->get_numeroDeVoie() + "', '" + this->get_adresseLivraison()->get_complementDeNumero() + "', '" + this->get_adresseLivraison()->get_typeDeVoie() + "', '" + this->get_adresseLivraison()->get_nomDeVoie() + "', '" + this->get_adresseLivraison()->get_codePostal() + "', '" + this->get_adresseLivraison()->get_nomDeCommune() + "');" +
				"SET @idAdresseLivraison = (SELECT TOP(1) ID FROM adresse ORDER BY ID DESC);" +
				"INSERT INTO adresse (numeroDeVoie, complementDeNumero, typeDeVoie, nomDeVoie, codePostal, nomDeCommune) VALUES ('" + this->get_adressePaiement()->get_numeroDeVoie() + "', '" + this->get_adressePaiement()->get_complementDeNumero() + "', '" + this->get_adressePaiement()->get_typeDeVoie() + "', '" + this->get_adressePaiement()->get_nomDeVoie() + "', '" + this->get_adressePaiement()->get_codePostal() + "', '" + this->get_adressePaiement()->get_nomDeCommune() + "');" +
				"SET @idAdressePaiement = (SELECT TOP(1) ID FROM adresse ORDER BY ID DESC);" +
				"INSERT INTO localiserCommande (ID_commande, ID_adresse, livraison) VALUES (@idCommande, @idAdresseLivraison, 1);" +
				"INSERT INTO localiserCommande (ID_commande, ID_adresse, livraison) VALUES (@idCommande, @idAdressePaiement, 0);" +
				"INSERT INTO contenir (ID_commande, ID_article, quantite) VALUES (@idCommande, (SELECT TOP(1) article.ID FROM article WHERE article.reference = '" + this->get_referenceObjet() + "'), '" + this->get_quantite() + "');" +
				"COMMIT";
			break;
		case 1:
			return "BEGIN TRANSACTION; DECLARE @idCommande INT;" +
				"SET @idCommande = (SELECT ID from commande WHERE reference = '" + this->get_reference() + "');" +
				"INSERT INTO contenir (ID_commande, ID_article, quantite) VALUES (@idCommande, (SELECT TOP(1) article.ID FROM article WHERE article.reference = '" + this->get_referenceObjet() + "'), '" + this->get_quantite() + "');" +
				"COMMIT";
			break;
		default:
			throw gcnew String("Erreur fatale");
			break;
		}
	}

	String^ MapCommande::DELETE(void) {
		return "BEGIN TRANSACTION; DECLARE @idCommande INT;" +
			"SET @idCommande = (SELECT ID FROM commande WHERE reference = '" + this->get_reference() + "');" +
			"DELETE FROM daterCommande WHERE ID_commande = @idCommande;" +
			"DELETE FROM localiserCommande WHERE ID_commande = @idCommande;" +
			"DELETE FROM contenir WHERE ID_commande = @idCommande;" +
			"DELETE FROM commande WHERE ID = @idCommande;" +
			"COMMIT";
	}

	String^ MapCommande::UPDATE(String^ id) {
		return "BEGIN TRANSACTION; DECLARE @idCommande INT;" +
			"COMMIT";
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

	void MapCommande::set_prenomClient(String^ prenomClient) {
		if (prenomClient != "") {
			this->_prenomClient = prenomClient;
		}
		else {
			throw gcnew String("Le prenom du client doit �tre sp�cifi� !");
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
			throw gcnew String("La reference de l'article doit �tre sp�cifi�e !");
		}
	}

	void MapCommande::set_quantite(String^ quantite) {
		if (quantite == "") {
			throw gcnew String("La quantite doit �tre definie !");
		}
		try {
			if (Convert::ToInt32(quantite) >= 0) {
				this->_quantite = quantite;
			}
			else {
				throw gcnew String("La quantite ne peut pas �tre n�gative !");
			}
		}
		catch (FormatException^) {
			throw gcnew String("La quantite doit �tre num�rique !");
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
			throw gcnew String("Le moyen de paiement doit �tre sp�cifi� !");
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