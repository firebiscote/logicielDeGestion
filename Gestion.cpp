#include "Gestion.h"

namespace Services {
	void Gestion::initGestion(void) {
		this->_cad = gcnew Composants::CAD();
		this->_ds = nullptr;
	}

	DataSet^ Gestion::stat1(void) {
		this->_ds = gcnew DataSet();
		this->_ds = this->_cad->getRows("SELECT CONCAT(CAST(sum(prixHT*stock*tauxDeTVA/100) as float), ' €') FROM article", "article");
		return this->_ds;
	}

	DataSet^ Gestion::stat2(void) {
		this->_ds = gcnew DataSet();
		this->_ds = this->_cad->getRows("SELECT CONCAT(CAST(sum(prixHT*stock) as float), ' €') AS valeurAchat FROM article", "article");
		return this->_ds;
	}

	DataSet^ Gestion::stat3(void) {
		this->_ds = gcnew DataSet();
		this->_ds = this->_cad->getRows("SELECT CONCAT(CAST(avg(inter.montant) as float), ' €') AS PanierMoyen FROM (SELECT sum(prixHT*quantite*tauxDeTVA/100) AS montant FROM commande LEFT JOIN contenir ON commande.ID = contenir.ID_commande LEFT JOIN article ON contenir.ID_article = article.ID GROUP BY commande.ID) AS inter", "article");
		return this->_ds;
	}

	DataSet^ Gestion::stat4(void) {
		this->_ds = gcnew DataSet();
		this->_ds = this->_cad->getRows("SELECT CONCAT(CAST(sum(inter.montant) as float), ' €') AS valeurVente FROM (SELECT commande.ID as ID, sum(prixHT*quantite*tauxDeTVA/100) AS montant FROM commande LEFT JOIN contenir ON commande.ID = contenir.ID_commande LEFT JOIN article ON contenir.ID_article = article.ID GROUP BY commande.ID) AS inter LEFT JOIN (SELECT daterCommande.ID_commande AS ID, date.date AS date FROM daterCommande LEFT JOIN date ON daterCommande.ID_date = date.ID) AS date ON inter.ID = date.ID WHERE MONTH(date.date) = MONTH(GETDATE())", "article");
		return this->_ds;
	}

	DataSet^ Gestion::stat5(void) {
		this->_ds = gcnew DataSet();
		this->_ds = this->_cad->getRows("SELECT article.reference, article.designation, article.seuilDeReapprovisionnement, article.stock FROM article WHERE article.seuilDeReapprovisionnement > article.stock", "article");
		return this->_ds;
	}

	DataSet^ Gestion::stat6(void) {
		this->_ds = gcnew DataSet();
		this->_ds = this->_cad->getRows("SELECT client.client, CONCAT(CAST(sum(inter.montant) as float), ' €') AS panier FROM (SELECT commande.ID as ID, sum(prixHT*quantite*tauxDeTVA/100) AS montant FROM commande LEFT JOIN contenir ON commande.ID = contenir.ID_commande LEFT JOIN article ON contenir.ID_article = article.ID GROUP BY commande.ID) AS inter LEFT JOIN (SELECT commande.ID AS ID, CONCAT(client.nom, ' ', client.prenom) AS client FROM commande LEFT JOIN client ON commande.ID_client = client.ID) AS client ON inter.ID = client.ID GROUP BY client.client", "article");
		return this->_ds;
	}

	DataSet^ Gestion::stat7(void) {
		this->_ds = gcnew DataSet();
		this->_ds = this->_cad->getRows("SELECT * FROM (SELECT article.reference, article.designation, sum(contenir.quantite) AS quantite FROM article LEFT JOIN contenir ON article.ID = contenir.ID_article GROUP BY article.reference, article.designation) AS inter ORDER BY inter.quantite DESC", "article");		
		return this->_ds;
	}

	DataSet^ Gestion::stat8(void) {
		this->_ds = gcnew DataSet();
		this->_ds = this->_cad->getRows("SELECT * FROM (SELECT article.reference, article.designation, sum(contenir.quantite) AS quantite FROM article LEFT JOIN contenir ON article.ID = contenir.ID_article GROUP BY article.reference, article.designation) AS inter ORDER BY inter.quantite ASC", "article");
		return this->_ds;
	}

	DataSet^ Gestion::simulation(double TVA, double margeCommerciale, double remiseCommerciale, double demarqueInconnue) {
		this->_ds = gcnew DataSet();
		this->_ds = this->_cad->getRows("SELECT CONCAT(CAST(sum(inter.valeur) as float), ' €') AS simulation FROM (SELECT ((stock*'" + (100-demarqueInconnue) + "'/100)*(prixHT*'" + (100+TVA) + "'*'" + (100+margeCommerciale) + "'*'" + (100-remiseCommerciale) + "'/1000000)) AS valeur FROM article) AS inter", "article");
		return this->_ds;
	}
}
