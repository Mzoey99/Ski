# Un jour au ski 

URL du leaderboard : https://in104.lapinou.me/
Lien vers le tuto git : https://learngitbranching.js.org/?locale=fr_FR
## Introduction 

L'objectif de ce projet d'IN104 est de mettre en application une grande partie des concepts que vous avez pu voir au cours de l'année. 
Le projet devra être réalisé en binome.

Le sujet se décompose en plusieurs parties, le rendu minimum attendu correspond aux briques notées obligatoires. Parmi les briques optionnelles vous pouvez choisir lesquelles vous souhaitez réalisées. 

En cas de problème de compréhension ou de code, n'hésitez pas à venir me voir au début de chaque séance où à m'envoyer un mail à marine.saintmezard@gmail.com en mettant [IN104] en objet. 

Le code doit-être écrit en C. Un seul projet doit être rendu par binôme. 

## Problème 

### Enoncé 
Après une dure semaine de partiels, vous partez en vacances bien méritées ! Vous voici arrivés dans une station de ski. C’est votre dernier jour, vous avez déjà testé toutes les pistes et vous savez quel plaisir chaque piste vous procure.

Vous disposez donc d’une carte avec l’ensemble des pistes et un entier qui représente le plaisir généré lorsque vous dévalez cette piste. Ce chiffre peut-être négatif si cette piste est ennuyeuse.

Les croisements des pistes sont numérotés et vous partez de celui qui parte le numéro 0.

Votre objectif est de déterminer le meilleur itinéraire possible pour la journée. Bien sur rien ne vous interdit de passer plusieurs fois sur la même piste et donc de ressentir un plaisir infini. Vous pouvez aussi décider que la meilleure solution est de ne pas skier !

Alors quel itinéraire empruntez vous ?

### Données d'entrées 
Les données d'entrées comprennent les informations suivantes : 
* $n$ : le nombre de croisements 
* $m$ : le nombre de pistes 
* pour chaque piste un entier $x_i \in [0,n-1]$, un entier $y_i \in [0,n-1]$ et un entier $f_i \in \mathbb{Z}$. Cela signifie que la piste $i$ part du croisement $x_i$, arrive au croisement $y_i$ et vous procure un plaisir $f_i$

### Sortie attendue

Vous afficherez la quantité maximale de plaisir que vous pouvez prendre. 
Si jamais cette quantité est infinie vous afficherez : "SKY IS THE LIMIT". 
### Exemples 
Exemple d'entrée
```
5 6 
0 1 -10 
1 2 5
2 3 -2 
3 4 -7
3 1 -3
4 3 -2
```
Cela correspond au schéma suivant : 
![](https://markdown.data-ensta.fr/uploads/upload_770a0dca308e9786eb85694fb6709723.jpg)



Sortie attendue : 
```
SKY IS THE LIMIT 
```
En effet, le cycle 1,2,3 procure un plaisir de 6 points. Puisqu'on peut répéter ce cycle autant de fois qu'on le désire, il n'y a aucune limite au plaisir ! 

Autre exemple 
```
6 5 
0 1 -1
1 2 2 
3 4 1 
4 5 -1
5 3 -1 
```
Cela correspond au schéma suivant : ![](https://markdown.data-ensta.fr/uploads/upload_a9edab37e856e9bfd1a5b593027f1ef0.jpg)


Sortie attendue : 
```
1
```

## Contraintes et critères d'évaluation

### Git 

**VOUS DEVEZ UTILISER GIT**, tout au long de votre projet. 

La première séance sera dédiée à la création d'un projet git. 
Un tutoriel est disponible dans le répertoire du projet. Prenez le temps de le suivre et de créer correctement votre projet. 
Les bonnes pratiques seront rappelées pendant la première séance, il est important de les suivre pour éviter des problèmes par la suite. 
La bonne utilisation de git et le caractère régulier des commits seront pris en compte pour l'évaluation. 

### Lisibilité du code 

Une attention particulière sera portée à la lisibilité du code. 
Votre code doit être lisible et facilement compréhensible par n'importe qui. 

Les bonnes pratiques seront rappelées pendant la première séance, il est important de les suivre. 
Quelques conseils : 
* donner des noms clairs à vos variables et vos fonctions 
* séparer le code en différents modules et créer à chaque fois un fichier .h
* séparer chaque module en fonction 
* commenter rapidement ce que fait chaque fonction 

### Tests unitaires 

Afin de s'assurer que votre code fonctionne correctement, il vous est demandé d'implémenter des tests unitaires. 
Le fonctionnement et les bonnes pratiques seront rappelés. 

Nous vous proposons d'utiliser la librairie Unity : https://github.com/ThrowTheSwitch/Unity
La documentatation est disponible ici : http://www.throwtheswitch.org/unity

Un exemple vous est donné dans le fichier test.c 
Pour le compiler, tapez la ligne suivante 
```gcc -Wall -IUnity/src test.c utils.c Unity/src/unity.c -o test.x```
Modifiez les fonctions présentes dans le fichier utils.c pour que tous les tests passent et que les fonctions ne présentent plus d'erreurs. 

### Performances du code 

La performance de votre code, en terme de temps d'exécution et d'utilisation de la mémoire sera un critère important. 

**Prenez le temps de comparer le temps d'exécution de vos différentes implémentations. Un graphique montrant l'évolution en commentant les différentes améliorations pendant la soutenance orale sera grandement valorisé.**

## Grandes lignes du projet 

Si vous ne savez pas comment commencer ce projet, voici quelques grandes étapes : 
* créer un module pour lire les données d'entrée
* écrire quelques cas à la main et les résoudre à la main 
* proposer un pseudo code et le découper en petits modules 
* pour chaque module écrire des tests unitaires 
* coder les modules un à un, en les testant 
* créer un module permettant de générer des fichiers d'entrées 
* créer un module permettant d'appeler votre algorithme avec vos fichiers d'entrées, mesurer le temps d'execution en fonction de la taille d'entrée et générer des graphes 

**Gardez des traces de l'ensemble de vos améliorations pour etre capable de les expliquer clairement lors de la soutenance à l'oral.**

Améliorer la complexité de votre code **dans un nouveau fichier** , optimisez le code et réitérer l'étape de génération de graphes et superposant vos courbes. Pour pouvoir tracer les deux courbes il faut donc que vous ayez les deux fichiers. 
Pour améliorer la complexité posez-vous les questions suivantes : 
* Quelle partie de mon code consomme de la RAM ? Est-ce que je libère bien la mémoire dès que je n'en ai plus besoin ? 
* Quelle partie de mon code s'exécute à de multiples reprises ? 
* Pour mon algorithme quel est le pire des cas ? Dans ce cas là combien de fois s'éxecute chaque étape ? 
* Ai-je besoin de toutes les variables que j'ai déclarées ? 
* Est-ce que j'utilise les structures les plus adaptées à mon problème ? 

