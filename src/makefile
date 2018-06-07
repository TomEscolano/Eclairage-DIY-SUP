# Compile all
all:
	g++ -o /usr/lib/cgi-bin/index.cgi SUP.cpp Eclairage.cpp EclairageUnicolore.cpp EclairageMulticolore.cpp SqlitePersiBny.cpp Utility.cpp ClientTcpComBny.cpp TcpComBny.cpp -I . -lsqlite3 -pthread -lcgicc -D _UT_SUP_ -std=c++11
	g++ -o /usr/lib/cgi-bin/UcAjouter.cgi UcAjouter.cpp Eclairage.cpp EclairageMulticolore.cpp EclairageUnicolore.cpp SqlitePersiBny.cpp ClientTcpComBny.cpp TcpComBny.cpp Utility.cpp -I . -lsqlite3 -lcgicc -D _UT_UcAjouter_ -std=c++11
	g++ -o /usr/lib/cgi-bin/UcCommander.cgi UcCommander.cpp Eclairage.cpp ClientTcpComBny.cpp TcpComBny.cpp SqlitePersiBny.cpp EclairageUnicolore.cpp EclairageMulticolore.cpp Utility.cpp -I . -lsqlite3 -lcgicc -ljsoncpp -D _UT_UcCommander_ -std=c++11
	g++ -o /usr/lib/cgi-bin/UcExporter.cgi UcExporter.cpp -I . -lcgicc -D _UT_UcExporter_ -std=c++11
	g++ -o /usr/lib/cgi-bin/UcGerer.cgi UcGerer.cpp Eclairage.cpp EclairageUnicolore.cpp EclairageMulticolore.cpp ClientTcpComBny.cpp TcpComBny.cpp SqlitePersiBny.cpp -I . -lsqlite3 -lcgicc -D _UT_UcGerer_ -std=c++11
	g++ -o /usr/lib/cgi-bin/UcModifier.cgi UcModifier.cpp Eclairage.cpp EclairageUnicolore.cpp EclairageMulticolore.cpp ClientTcpComBny.cpp TcpComBny.cpp SqlitePersiBny.cpp -lsqlite3 -lcgicc -I . -D _UT_UcModifier_ -std=c++11
	g++ -o /usr/lib/cgi-bin/UcSupprimer.cgi Eclairage.cpp UcSupprimer.cpp SqlitePersiBny.cpp -I . -lsqlite3 -lcgicc -D _UT_UcSupprimer_ -std=c++11
	g++ -o /usr/lib/cgi-bin/UcImporter.cgi UcImporter.cpp UcAjouter.cpp UcModifier.cpp SqlitePersiBny.cpp Eclairage.cpp EclairageMulticolore.cpp EclairageUnicolore.cpp ClientTcpComBny.cpp TcpComBny.cpp -lcgicc -lsqlite3 -I . -D _UT_UcImporter_ -pthread -std=c++11
	g++ -o UcRecevoirInfo UcRecevoirInfo.cpp ServeurTcpComBny.cpp TcpComBny.cpp  SqlitePersiBny.cpp -ljsoncpp -I . -std=c++11 -lsqlite3

# Compile le SUP
sup:
	g++ -o /usr/lib/cgi-bin/index.cgi SUP.cpp Eclairage.cpp EclairageUnicolore.cpp EclairageMulticolore.cpp SqlitePersiBny.cpp Utility.cpp ClientTcpComBny.cpp TcpComBny.cpp -I . -lsqlite3 -pthread -lcgicc -D _UT_SUP_ -std=c++11

# Compile l'UcAjouter
ucajouter :
	g++ -o /usr/lib/cgi-bin/UcAjouter.cgi UcAjouter.cpp Eclairage.cpp EclairageMulticolore.cpp EclairageUnicolore.cpp SqlitePersiBny.cpp ClientTcpComBny.cpp TcpComBny.cpp Utility.cpp -I . -lsqlite3 -lcgicc -D _UT_UcAjouter_ -std=c++11

# Compile l'UcCommander
uccommander:
	g++ -o /usr/lib/cgi-bin/UcCommander.cgi UcCommander.cpp Eclairage.cpp ClientTcpComBny.cpp TcpComBny.cpp SqlitePersiBny.cpp EclairageUnicolore.cpp EclairageMulticolore.cpp Utility.cpp -I . -lsqlite3 -lcgicc -ljsoncpp -D _UT_UcCommander_ -std=c++11

# Compile l'UcExporter
ucexporter:
	g++ -o /usr/lib/cgi-bin/UcExporter.cgi UcExporter.cpp -I . -lcgicc -D _UT_UcExporter_ -std=c++11

# Compile l'UcGerer
ucgerer:
	g++ -o /usr/lib/cgi-bin/UcGerer.cgi UcGerer.cpp Eclairage.cpp EclairageUnicolore.cpp EclairageMulticolore.cpp ClientTcpComBny.cpp TcpComBny.cpp SqlitePersiBny.cpp Utility.cpp -I . -lsqlite3 -lcgicc -D _UT_UcGerer_ -std=c++11

# Compile l'UcImporter
ucimporter:
	g++ -o /usr/lib/cgi-bin/UcImporter.cgi UcImporter.cpp UcAjouter.cpp UcModifier.cpp SqlitePersiBny.cpp Eclairage.cpp EclairageMulticolore.cpp EclairageUnicolore.cpp ClientTcpComBny.cpp TcpComBny.cpp csv.cpp Utility.cpp -lcgicc -lsqlite3 -I . -D _UT_UcImporter_ -pthread -std=c++11

# Compile l'UcModifier
ucmodifier:
	g++ -o /usr/lib/cgi-bin/UcModifier.cgi UcModifier.cpp Eclairage.cpp EclairageUnicolore.cpp EclairageMulticolore.cpp ClientTcpComBny.cpp TcpComBny.cpp SqlitePersiBny.cpp Utility.cpp -lsqlite3 -lcgicc -I . -D _UT_UcModifier_ -std=c++11

# Compile l'UcSupprimer
ucsupprimer:
	g++ -o /usr/lib/cgi-bin/UcSupprimer.cgi Eclairage.cpp UcSupprimer.cpp SqlitePersiBny.cpp Utility.cpp -I . -lsqlite3 -lcgicc -D _UT_UcSupprimer_ -std=c++11

# Compile l'UcRecevoirInfo
ucrecevoirinfo:
	g++ -o UcRecevoirInfo UcRecevoirInfo.cpp ServeurTcpComBny.cpp TcpComBny.cpp  SqlitePersiBny.cpp -ljsoncpp -I . -std=c++11 -lsqlite3 -g

# Clean
clean:
	rm /usr/lib/cgi-bin/*.cgi
