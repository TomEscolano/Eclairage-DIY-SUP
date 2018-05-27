#Script d'installation de la supervision

sudo mkdir -p /var/eclairage/ /usr/lib/cgi-bin/

cd src
make all

sudo cp -r html/ /usr/lib/cgi-bin/
sudo cp -r img/ /var/www/html/

sudo chmod -r 777 /var/eclairage/*
sudo chmod -r 777 /var/www/html/*
sudo chmod -r 777 /usr/lib/cgi-bin/*

sudo echo "ScriptAlias /cgi-bin/ /usr/lib/cgi-bin/
<Directory '/usr/lib/cgi-bin'>
	AllowOverride None
	Options +ExecCGI -MultiViews +SymLinksIfOwnerMatch
	Allow from all
	Require all granted
</Directory>
" >> /etc/apache2/apache2.conf

sudo service apache2 restart

echo "Installation terminée !"
