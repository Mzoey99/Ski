# Suite du sujet  

Voici trois extensions possibles pour le sujet. 
Elles sont classées de la plus facile à la plus difficile. 

## Option 1  : Passer par tous les points d'interet

Ce problème est aussi connu sous le nom de **voyageur de commerce**. 

L'énoncé est légérement modifié, maintenant les noeuds sont des points de vues. 
L'objectif est de passer **une et unique fois** par chaque point et de revenir à la position de départ en parcourant une **distance minimale**.

Vous devez afficher le chemin suivi et la distance parcourue. 

Fichier d'entrée : 
- sur la première ligne le nombre de noeuds (donc de points de vues) noté n
- sur les n lignes suivantes les coordonnées de chacune des villes

Sortie attendue : 
- Sur la première ligne le chemin à suivre 
- Sur la seconde ligne la distance parcourue 

Hypothèses : 
- Dans un premier temps, on peut étudier un graphe complet, c'est à dire qu'entre toutes les villes i et j il existe une route. 
- On utilise la norme L2 pour calculer des distances

Exemple de graphe complet : 
![](https://markdown.data-ensta.fr/uploads/upload_3ca2c60ab0a182bb1fa3b2bb126bbb22.png)

Pour en savoir plus sur les graphes complets vous pouvez vous referrer au lien : https://fr.wikipedia.org/wiki/Graphe_complet

### Exemple 1 

Considérons les 8 villes suivantes : 
```
8
1 1
4 2
5 2
6 4
4 4
3 6
1 5
2 3
```

Ce qu'on peut représenter ainsi : 
![](https://markdown.data-ensta.fr/uploads/upload_287b84c7c3cf1ec30f092a296cc95577.png)

On peut alors construire le graphe complet suivant 
![](https://markdown.data-ensta.fr/uploads/upload_facd3b73b7ef18e79199f1819e4ad52a.png)

La question est donc comment passer par toutes les villes une et une seule fois et revenir au point de départ en minimisant la distance parcourue. 

Voici un exemple de chemin 
![](https://markdown.data-ensta.fr/uploads/upload_40a12b64c7910bf8f7f51166111449f7.png)

Cependant ce chemin n'est pas le plus court, en effet celui ci est plus court :  
![](https://markdown.data-ensta.fr/uploads/upload_1ecce3937b7fef401bc5d6641be60372.png)
Avec une longueur totale de : 17.34261754766733, qui est donc la réponse attendue 
Ce chemin est effectivement le plus court que l'on puisse faire en respectant les contraintes. 

Attention, le problème du voyageur de commerce est NP-complet, c'est-à-dire que l'on ne peut pas le résoudre en temps polynomial. Autrement dit, pour des tailles d'instances très grandes, le temps de calcul devient très important. 

Il existe donc deux grandes catégories de méthodes de résolution : 
- Les méthodes exactes permettent d’obtenir une solution optimale à chaque fois, mais le temps de calcul peut être long si le problème est compliqué à résoudre.
-  Les méthodes approchées, ou heuristiques, permettent  d’obtenir rapidement une solution approchée, mais qui n’est donc pas toujours optimale.

A vous de choisir si vous preferez implémenter une solution exacte (vous pouvez alors regarder la Procédure par Séparation et Evaluation (PSE), ou une solution approchées (algorithme génétique, algorithme glouton, recuit simulé, etc.)

### Soutenance 
Pour la soutenance il sera intéressant de comparer les deux problèmes. Qu'ont-ils en commun ? Quelles sont les différences ? Comment cela se traduit-il dans les algorithmes de résolution ? Est-ce qu'un de vos algorithmes pourrait résoudre les deux problèmes ? 


## Option 2 : Combien de skieurs au maximum dans la station 

Ce problème est connu sous le nom de flot maximal : https://fr.wikipedia.org/wiki/Probl%C3%A8me_de_flot_maximum

L'idée est la suivante :  chaque piste a une capacité maximale, c'est-à-dire un nombre de skieurs maximum qui peuvent l'emprunter simultanément. 

On définit un point de départ s et un point d'arrivée t. 
On définit des noeuds et des aretes. 
Pour chaque arête, on définit une capacité maximale, c'est à dire le nombre de skieurs maximal qu'il peut y avoir sur la piste simultanément. 

On cherche à savoir combien il peut y avoir au maximum de skieurs dans la station.

### Données d'entrée : 
- sur la première ligne le nombre de sommets $n$ et le nombre d'arêtes $m$
- sur les $m$  lignes suivantes, une arete avec sa capacité sous la forme x, y, c avec x le sommet de départ, y le sommet d'arrivée et c la capacité maximale de l'arête. 

### Exemple : 
Imagions la station suivante, nous avons notre source $S$ (le sommet 0) et notre arrivée $T$ (le sommet 5) et nous avons également 4 autres noeuds

```
6 10
0 1 2
0 2 6
0 3 4 
1 2 3 
1 4 7 
4 1 3
2 4 2 
2 5 5 
3 2 1
4 5 6 
```
On obtient le graphe suivant :
![](https://markdown.data-ensta.fr/uploads/upload_8dbac43b472565eba0888f05dfced826.jpg)

On a alors un nombre maximal de skieurs possible de 9 : 
![](https://markdown.data-ensta.fr/uploads/upload_3c45bedfb4323664d5077b89319b56a4.jpg)

La disposition des skieurs n'est pas unique, en revanche peu importe votre disposition, la capacité maximale est de 9 skieurs. 

Avant de chercher sur internet, essayer de résoudre le problème à la main, en tatonnant. 
Différents algorithmes existent pour résoudre ce problème : 
- Ford Fulkerson : https://fr.wikipedia.org/wiki/Algorithme_de_Ford-Fulkerson
- Edmonds Karp : https://fr.wikipedia.org/wiki/Algorithme_d%27Edmonds-Karp
- Dinic : https://fr.wikipedia.org/wiki/Algorithme_de_Dinic


## Option 3 : interface graphique pour déplier le graphe 

La [SDL](https://libsdl.org) est la librairie graphique de C, qui permet typiquement d'ouvrir des fenêtres et d'y dessiner des formes.

Vous trouverez dans le fichier `graph.c` un exemple d'utilisation qui permet de dessiner des cercles et des flèches.

### Objectif
Votre programme étant pour l'instant très peu interactif, il faut à présent afficher visuellement le résultat à l'utilisateur.

Vous devez donc utiliser la SDL pour afficher dans une fenêtre l'ensemble des stations et des pistes, en mettant en avant le parcours de plaisir maximal et le plaisir qu'il procure.

Par exemple, avec comme entrée 
```
6 5
0 1 -1
1 2 2
3 4 1
4 5 -1
5 3 1
```

On peut obtenir la figure suivante : 

![](https://markdown.data-ensta.fr/uploads/upload_ad4a0c9f2e5966e5ef1b429fcc79f88e.png)

Ne cherchez pas à transformer le plaisir d'une piste en une distance entre les noeuds (les nombres négatifs poseraient problèmes). De plus, vous pourriez alors avoir un problème sur-contraint (imaginer que je vous demande de placer Paris à 100km de Marseille et de Lille, cela risque d'être difficile). 

Dans un premier temps, vous devez trouver un moyen de passer d'une matrice d'adjacence à un graphe. 

Dans un second temps, vous pouvez essayer de minimiser le nombre de chevauchement sur votre graphe, c'est-à-dire d'éviter que des aretes ne se croisent, pour gagner en visibilité. 


###  Installation de la SDL 
####  Linux (ou WSL)
Pour l'installer sous debian ou ubuntu (ou WSL), il faut installer le paquet `libsdl2-dev` :
```bash
sudo apt update
sudo apt install libsdl2-dev
```

#### BYOD
Sur BYOD, la librairie est normalement préinstallée. Cependant, il faut lancer SSH avec les bonnes options pour qu'il redirige aussi la session graphique. Pour cela, ouvrez un terminal PowerShell depuis votre poste et exécutez la ligne suivante :
```powershell
ssh -X <nom d'utilisateur>@byod.ensta.fr
```
Si cela ne fonctionne pas, il est possible qu'il faille modifier la configuration de OpenSSH sur votre poste. Dans le terminal PowerShell, lancez :
```powershell
New-Item -Path $HOME\.ssh\config -ItemType File
code $HOME\.ssh\config
```
et ajoutez les lignes suivantes :
```
ForwardX11 yes
ForwardX11Trusted yes
```

#### Compilation 
Pour compiler l'exemple `graph.c`, utilisez la ligne suivante :
```bash
gcc graph.c -o graph.x `sdl2-config --cflags --libs` -lm
```


