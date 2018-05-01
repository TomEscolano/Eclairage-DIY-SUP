# Compile le SUP
sup: /usr/lib/cgi-bin/index.cgi 
	g++ -o /usr/lib/cgi-bin/index.cgi SUP.cpp Eclairage.cpp EclairageUnicolore.cpp EclairageMulticolore.cpp SqlitePersiBny.cpp Utility.cpp -I . -lsqlite3 -pthread -lcgicc -D _UT_SUP_

# Compile l'UcAjouter
ucajouter : /usr/lib/cgi-bin/UcAjouter.cgi
	g++ -o /usr/lib/cgi-bin/UcAjouter.cgi UcAjouter.cpp Eclairage.cpp EclairageMulticolore.cpp EclairageUnicolore.cpp SqlitePersiBny.cpp -I . -lsqlite3 -lcgicc -D _UT_UcAjouter_

# Compile l'UcCommander
uccommander: /usr/lib/cgi-bin/UcCommander.cgi
	g++ -o UcCommander UcCommander.cpp Eclairage.cpp SqlitePersiBny.cpp -I . -lsqlite3 -lcgicc -D _UT_UcCommander_

# Compile l'UcExporter
ucexporter: /usr/lib/cgi-bin/UcExporter.cgi-bin
	g++ -o UcExporter.cgi UcExporter.cpp -I . -D _UT_UcExporter_

# Compile l'UcGerer
ucgerer: /usr/lib/cgi-bin/UcGerer.cgi
	g++ -o /usr/lib/cgi-bin/UcGerer.cgi UcGerer.cpp Eclairage.cpp SqlitePersiBny.cpp -I . -lsqlite3 -lcgicc -D _UT_UcGerer_

# Compile l'UcImporter
ucimporter: /usr/lib/cgi-bin/UcImporter.cgi
	g++ -o /usr/lib/cgi-bin/UcImporter.cgi UcImporter.cpp UcAjouter.cpp UcModifier.cpp SqlitePersiBny.cpp Eclairage.cpp EclairageMulticolore.cpp EclairageUnicolore.cpp -lcgicc -lsqlite3 -I . -D _UT_UcImporter_ -pthread

# Compile l'UcModifier
ucmodifier: /usr/lib/cgi-bin/UcModifier.cgi
	g++ -o /usr/lib/cgi-bin/UcModifier.cgi UcModifier.cpp Eclairage.cpp EclairageUnicolore.cpp EclairageMulticolore.cpp SqlitePersiBny.cpp -lsqlite3 -lcgicc -I . -D _UT_UcModifier_

# Compile l'UcSupprimer
ucsupprimer: /usr/lib/cgi-bin/UcSupprimer.cgi
	g++ -o UcSupprimer Eclairage.cpp UcSupprimer.cpp SqlitePersiBny.cpp -I . -lsqlite3 -lcgicc -D _UT_UcSupprimer_

# Clean
clean:
	rm /usr/lib/cgi-bin/*.cgi