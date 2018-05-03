//https://www.sqlite.org/cintro.html
#include <SqlitePersiBny.h>
#include <iostream>
#include <unistd.h>

SqlitePersiBny::SqlitePersiBny(const char* fichierBdd)
		throw (SqlitePersiBnyException) :
		db(NULL) {
	int rc = sqlite3_open(fichierBdd, &db);
	if (rc != SQLITE_OK) {
		throw SqlitePersiBnyException("sqlite3_open",
				sqlite3_errcode(this->db));
	}
}

SqlitePersiBny::~SqlitePersiBny() throw (SqlitePersiBnyException) {
	int rc = SQLITE_OK;
	if (this->db != NULL)
		rc = sqlite3_close(db);
	if (rc != SQLITE_OK)
		rc = sqlite3_close(db);
		//throw SqlitePersiBnyException("sqlite3_close",
				//sqlite3_errcode(this->db));
}

int SqlitePersiBny::executerSql(std::string requete,
		SqlitePersiBny::Resultat& resultat) throw (SqlitePersiBnyException) {
	sqlite3_stmt *stmt;
	

	//std::cout << requete << "<br>" << std::endl;
	

	sqlite3_busy_timeout(this->db, 2000); // Attente de 2sec si la bdd est occupée
	int rc;
	do
	{
		rc = sqlite3_prepare_v2(this->db, requete.c_str(), -1, &stmt, NULL); // Reessaye tant ue la BDD est occupée
		usleep(500);
	}while(rc == SQLITE_BUSY);

	if (rc != SQLITE_OK) {
		throw SqlitePersiBnyException("sqlite3_prepare_v2",
				sqlite3_errcode(this->db));
	}
	do {
		rc = sqlite3_step(stmt);
		if (rc != SQLITE_ROW && rc != SQLITE_DONE) {
			sqlite3_finalize(stmt);
			throw SqlitePersiBnyException("sqlite3_step",
					sqlite3_errcode(this->db));
		}
		if (rc == SQLITE_DONE) {
			break;
		}
		int nbChamps = sqlite3_column_count(stmt);
		SqlitePersiBny::Ligne ligne;
		for (int i = 0; i < nbChamps; i++) {
			ligne.push_back(
					SqlitePersiBny::Champs(sqlite3_column_name(stmt, i),
							(const char*) sqlite3_column_text(stmt, i)));
		}
		resultat.push_back(ligne);
	} while (rc == SQLITE_ROW);
	rc = sqlite3_finalize(stmt);
	if (rc != SQLITE_OK)
		throw SqlitePersiBnyException("sqlite3_finalize",
				sqlite3_errcode(this->db));
	return resultat.size();
}

void SqlitePersiBny::executerSql(std::string requete)
		throw (SqlitePersiBnyException) {

	//std::cout << requete << "<br>" << std::endl;

	char *zErrMsg = 0;

	sqlite3_busy_timeout(this->db, 2000); // Attente de 2sec si la bdd est occupée
	int rc;
	do
	{
		rc = sqlite3_exec(db, requete.c_str(), NULL, NULL, &zErrMsg); // Reessaye tant que la BDD est occupée
		usleep(500);
	}while(rc == SQLITE_BUSY );

	if (rc != SQLITE_OK) {
		sqlite3_free(zErrMsg);
		throw SqlitePersiBnyException("sqlite3_exec",
				sqlite3_errcode(this->db));
	}
	sqlite3_exec(this->db, "END TRANSACTION", 0, 0, 0);
}

int SqlitePersiBny::getDernierId() {
	return sqlite3_last_insert_rowid(this->db);
}
#include <sstream>

int SqlitePersiBny::getDernierId(std::string table) throw (SqlitePersiBnyException) {
	SqlitePersiBny::Resultat resultat;
	this->executerSql("select id from " + table + " order by id desc limit 1;",resultat);
	try{
		return std::stoi(resultat.at(0).at(0).second);
	}catch(const std::out_of_range &e){
		return 0;
	}
}

std::string SqlitePersiBny::resultatToString(
		SqlitePersiBny::Resultat& resultat) {
	std::ostringstream os;
	for (SqlitePersiBny::Ligne ligne : resultat) {
		for (SqlitePersiBny::Champs champs : ligne)
			os << champs.first << ":" << champs.second << ";";
		os << std::endl;
	}
	return os.str();
}

#ifdef NDEBUG
/*
 g++ -o SqlitePersiBnyUt SqlitePersiBny.cpp SqlitePersiBnyException.cpp -std=c++14 -I. -pthread -l sqlite3 -D SQLITEPERSIBNY_Ut_ -DSQLITE_THREADSAFE=1  && ./SqlitePersiBnyUt ; rm SqlitePersiBnyUt

 g++ -c SqlitePersiBny.cpp  -I . -std=c++11 -DNDEBUG
 */
#ifdef SQLITEPERSIBNY_Ut_
#include <iostream>
#define NOM_BD "SqlitePersiBny.db"
#define DROP "drop table if exists entite;"
#define SCHEMA "create table entite( id integer primary key autoincrement not null, name text not null, age integer  not null, address char(50), salary real);"
#define INSERT1 "insert into entite (name,age,address,salary) values ('eric',55,'paris',1000.56);"
#define INSERT2 "insert into entite (name,age,address,salary) values ('pierre',25,'nice',2300.56);"
#define DERNIER_ID 2
#define SELECT_NAME_ADDRESS_ID1 "select name, address from entite where id=1"
#define RESULTAT_SELECT_NAME_ADDRESS_ID1 "name:eric;address:paris;\n"
#define NB_LIGNES_SELECT_NAME_ADDRESS_ID1 1
#define RESULTAT_SELECT_NAME_ADDRESS_ID2 "name:pierre;address:nice;\n"
#define SELECT_NAME_ADDRESS_ID2 "select name,address from entite where id=2"
#define NB_LIGNES_SELECT_NAME_ADDRESS_ID2 1
#define SELECT_AGE "select age from entite"
#define RESULTAT_SELECT_AGE "age:55;\nage:25;\n"
#define NB_LIGNES_SELECT_AGE 2
#define UPDATE_AGE_ID2 "update entite set age=122 where id=2"
#define SELECT_ADDRESS "select address from entite"
#define RESULTAT_SELECT_ADDRESS "address:paris;\naddress:nice;\n"
#define NB_LIGNES_SELECT_ADDRESS 2
#define SELECT_ALL "select id,age,address,salary from entite"
#define NB_LIGNES_SELECT_ALL 2
#define RESULTAT_SELECT_ALL "id:1;age:55;address:paris;salary:1000.56;\nid:2;age:25;address:nice;salary:2300.56;\n"
#define NB_LIGNES_SELECT_ALL 2
#define SELECT_AGE_ID2 "select age from entite where id=2"
#define NB_LIGNES_SELECT_AGE_ID2 1
#define RESULTAT_SELECT_AGE_ID2 "age:25;\n"
#define NB_LIGNES_SELECT_AGE_ID2 1
#define RESULTAT_UPDATE_AGE_ID2 "age:122;\n"
#include <thread>
#include <exception>
#include <cassert>
#include <unistd.h>
void doIt1(SqlitePersiBny* sqlitePersiBny );
void doIt2(SqlitePersiBny* sqlitePersiBny );
int main(int argc, char **argv) {
	try { //bd population
		SqlitePersiBny sqlitePersiBny(NOM_BD);
		sqlitePersiBny.executerSql(DROP SCHEMA INSERT1 INSERT2);
		assert(DERNIER_ID == sqlitePersiBny.getDernierId());
		assert(DERNIER_ID == sqlitePersiBny.getDernierId("entite"));
	} catch (std::exception& e) {
		std::cerr << e.what() << std::endl;
		return 1;
	}
	std::thread t1(doIt1,new SqlitePersiBny(NOM_BD));
	std::thread t2(doIt2,new SqlitePersiBny(NOM_BD));
	t1.join();
	t2.join();
	return 0;
}
void doIt1(SqlitePersiBny* sqlitePersiBny) {
	try {
		SqlitePersiBny::Resultat resultat;
		int nbLignes=0;
		nbLignes=sqlitePersiBny->executerSql(SELECT_NAME_ADDRESS_ID1,resultat);
		//fprintf(stderr,"->%s\n",SqlitePersiBny::resultatToString(resultat).c_str());
		assert(NB_LIGNES_SELECT_NAME_ADDRESS_ID1 == nbLignes);
		assert(RESULTAT_SELECT_NAME_ADDRESS_ID1 == SqlitePersiBny::resultatToString(resultat));
		resultat.clear();
		nbLignes=sqlitePersiBny->executerSql(SELECT_AGE,resultat);
		assert(NB_LIGNES_SELECT_AGE == nbLignes);
		//fprintf(stderr,"->%s\n",SqlitePersiBny::resultatToString(resultat).c_str());
		assert(RESULTAT_SELECT_AGE == SqlitePersiBny::resultatToString(resultat));
		resultat.clear();
		nbLignes=sqlitePersiBny->executerSql(SELECT_ALL,resultat);
		//fprintf(stderr,"->%s\n",SqlitePersiBny::resultatToString(resultat).c_str());
		assert(NB_LIGNES_SELECT_ALL == nbLignes);
		assert(RESULTAT_SELECT_ALL == SqlitePersiBny::resultatToString(resultat));
	} catch (std::exception& e) {
		std::cerr << e.what() << std::endl;
		delete sqlitePersiBny;
	}
	delete sqlitePersiBny;
}
void doIt2(SqlitePersiBny* sqlitePersiBny) {
	try {
		SqlitePersiBny::Resultat resultat;
		int nbLignes=0;
		nbLignes=sqlitePersiBny->executerSql(SELECT_NAME_ADDRESS_ID2,resultat );
		//fprintf(stderr,"->%s\n",SqlitePersiBny::resultatToString(resultat).c_str());
		assert(NB_LIGNES_SELECT_NAME_ADDRESS_ID2 == nbLignes);
		assert(RESULTAT_SELECT_NAME_ADDRESS_ID2 == SqlitePersiBny::resultatToString(resultat));
		resultat.clear();
		nbLignes=sqlitePersiBny->executerSql(SELECT_ADDRESS,resultat);
		//fprintf(stderr,"->%s\n",SqlitePersiBny::resultatToString(resultat).c_str());
		assert(NB_LIGNES_SELECT_ADDRESS == nbLignes);
		assert(RESULTAT_SELECT_ADDRESS == SqlitePersiBny::resultatToString(resultat));
		resultat.clear();
		nbLignes=sqlitePersiBny->executerSql(SELECT_AGE_ID2,resultat);
		assert(NB_LIGNES_SELECT_AGE_ID2 == nbLignes );
		//fprintf(stderr,"->%s\n",SqlitePersiBny::resultatToString(resultat).c_str());
		assert(RESULTAT_SELECT_AGE_ID2 == SqlitePersiBny::resultatToString(resultat));
		resultat.clear();
		sqlitePersiBny->executerSql(UPDATE_AGE_ID2);
		nbLignes=sqlitePersiBny->executerSql(SELECT_AGE_ID2,resultat);
		assert(NB_LIGNES_SELECT_AGE_ID2 == nbLignes );
		//fprintf(stderr,"->%s\n",SqlitePersiBny::resultatToString(resultat).c_str());
		assert(RESULTAT_UPDATE_AGE_ID2 == SqlitePersiBny::resultatToString(resultat));

	} catch (std::exception& e) {
		std::cerr << e.what() << std::endl;
		delete sqlitePersiBny;
	}
	delete sqlitePersiBny;
}
#endif
#endif
