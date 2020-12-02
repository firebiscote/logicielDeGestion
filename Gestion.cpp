#include "Gestion.h"

namespace Services {
	void Gestion::initGestion(void) {
		this->_cad = gcnew Composants::CAD();
		this->_ds = nullptr;
	}

	DataSet^ Gestion::simulation(String^ TVA, String^ margeCommerciale, String^ remiseCommerciale, String^ demarqueInconnue) {
		try {
			if (Convert::ToInt32(TVA) > 0 && Convert::ToInt32(TVA) < 100 && Convert::ToInt32(margeCommerciale) > 0 && Convert::ToInt32(margeCommerciale) < 100 && Convert::ToInt32(remiseCommerciale) > 0 && Convert::ToInt32(remiseCommerciale) < 100 && Convert::ToInt32(demarqueInconnue) > 0 && Convert::ToInt32(demarqueInconnue) < 100) {
				this->_ds = gcnew DataSet();
				this->_ds = this->_cad->getRows("SELECT sum(inter.valeur) AS simulation FROM (SELECT (stock*(1-('" + demarqueInconnue + "'/100))*(prixHT*(1+('" + TVA + "'/100))*(1+('" + margeCommerciale + "'/100))*(1-('" + remiseCommerciale + "'/100)))) AS valeur FROM article) AS inter", "article");
				return this->_ds;
			}
			else {
				throw gcnew String("Les paramètres doivent être compris entre 0 et 100");
			}
		}
		catch (FormatException^) {
			throw gcnew String("Les paramètres doivent être réel !");
		}
	}
}