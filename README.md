

Ce projet contient les fichiers pour le gradient conjugué. Les fichiers header se trouvent dans le sous-répertoire hpp, 
les autres fichiers du programme sont dans cpp. 
Il y a également un script pour la comparaison des erreurs afin de visualiser les résultats. je met en dessous la ligne de commande
pour l'éxecution avec VERROU ( cela peut changer d'un utilisateur à l'autre, tout dépend où verrou est installé) : 


../../verrou-install-2.6.0/bin/valgrind --tool=verrou --float=yes --exclude=exclude.txt ./test_gradient


