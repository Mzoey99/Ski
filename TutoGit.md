# Utilisation de GITHUB 

A faire dans un terminal linux comme celui de VSCode par exemple.

## Création d'une clé SSH 

La première chose à faire est de créer une clé SSH sur votre compte GITHUB. Sans cette clé vous ne pourrez pas utiliser correctement Github. 

* Connectez vous sur votre compte github
* Cliquez sur votre avatar en haut à droite, puis cliquez sur settings

![](https://markdown.data-ensta.fr/uploads/upload_efb5beb4eb2dba144d2e30553d359210.png)


 
* Cliquez sur SSH and GPG keys et cliquez sur new SSH keys 
* ![](https://markdown.data-ensta.fr/uploads/upload_c570b4f2318bbcf6bb51bf02aeb02775.png)

* Ouvrez un terminal et suivez les instructions suivantes  
`ssh-keygen -t ed25519 -C "your_email@example.com"`
Pensez à changer l'adresse mail 
On vous demande dans quel dossier l'enregistrer appuyer sur entrée pour laisser la localisation par défaut.
On vous demande ensuite de rentrer une passphrase, appuyez sur entrée pour ne pas en mettre. 
Appuyer de nouveau sur entrée pour valider. 

Une clé et son image apparaissent alors à l'écran. 
ATTENTION ce n'est pas cette clé que vous devez copier dans git

Tapez ensuite `eval "$(ssh-agent -s)"`
Puis `ssh-add ~/.ssh/id_ed25519`

Il ne vous reste plus qu'à afficher votre clé : avec l'instruction `cat ~/.ssh/id_ed25519.pub
`
Copier-coller l'intégralité de ce qui s'affiche sur la page github dédiée.

En cas de soucis sur cette partie n'hésitez à vous référer au tutoriel complet : https://docs.github.com/en/authentication/connecting-to-github-with-ssh/generating-a-new-ssh-key-and-adding-it-to-the-ssh-agent


## Création d'un nouveau projet 

* Verifiez que la clé a bien été ajoutée, quittez la page puis revenez sur votre profil-> settings-> SSH and GPG keys vous devriez voir un cadre dans le partie SSH keys avec le nom que vous avez choisi pour votre clé. 
### Etape 1 : Créer un dossier sur votre PC (à faire par un seul membre du binome)

Aller à l'emplacement souhaité et créer un nouveau dossier avec la commande suivante 

`mkdir In104Projet`



### Etape 2 : Gitter votre projet (à faire par un seul membre du binome)

Nous allons maintenant gitter votre projet. 

Revenez sur la page d'accueil de git, dans la partie gauche de l'écran se trouve un 


Remplissez le nom du projet. 

**ATTENTION : vous devez créer un projet privé, vous devez donc sélectionner l'option PRIVATE**

![](https://markdown.data-ensta.fr/uploads/upload_4ca8516878ecd29ac5646f0037bb33a6.png)

**ATTENTION NE PAS AJOUTER DE README donc décocher la case "ADD a README file"**

Puis cliquez sur "Create repository"

Une page "Quick setup" devrait s'afficher avec les instructions pour initialiser votre projet. Vous pouvez copier-coller directement les instuctions dans un terminal en vous plaçant dans le répertoire où vous souhaitez travailler.

Pensez à selectionner SSH (le bouton surligné en jaune) dans la barre en haut et non HTTPS : 

![](https://markdown.data-ensta.fr/uploads/upload_9c54fa5816ba881dbff085e850910f2d.png)

Si le quick setup ne s'affiche pas, voici les commandes à éxecuter (pensez à adapter les éléments en jaune à votre projet)

![](https://markdown.data-ensta.fr/uploads/upload_4ccdd00283cb3b4a246b9d929ebff236.png)

Il est possible que lors du premier commit, on vous demande des informations sur l'utilisateur (donc vous). Vous devez simplement éxecuter les 2 lignes de commande qui vous seront suggérées en remplacant l'exemple de nom et d'adresse mail pour vos informations. 

Les deux commandes sont : 
`git config --global user.name votre_nom`
`git config --global user.email adresse@gmail.com`

Une fois que vous avez push (et si vous n'avez pas de message d'erreur) alors votre projet est gitté ! 

### Etape 3 : Inviter votre binome et les enseignants

Vous devez maintenant inviter sur votre projet: 
* votre binome
* le chargé de TP de votre projet
* la responsable du cours IN104 : id = nguyensaomai, email= sao-mai.nguyen@ensta-paris.fr.



| Nom du projet | Dépot git | Id github | Id Ensta-gitlab |
| ------------- | --------- | --------- | --------------- |
|Un jour de ski	|https://github.com/Mzoey99/Ski | Mzoey99 | @saint1|
|Tetris 2023	|https://github.com/XiaoxuanHEI/Tetris2023| XiaoxuanHEI (https://github.com/XiaoxuanHEI) | https://gitlab.ensta.fr/hei |
|Transcription piano	|  | | |
|4 jeux	|| eliot-tabet | |
|Apprentissage par renforcement | https://github.com/nguyensaomai/RlMaze| nguyensaomai ( sao-mai.nguyen@ensta-paris.fr ) | @nguyen (https://gitlab.ensta.fr/nguyen) |
|2048 number merge game	| https://github.com/mrsgzg/N104-C-Programe.git| mrsgzg| |
|Bomberman	|  |dbouchabou | |
|Se localiser 	| https://github.com/iad-ABDUL-RAOUF/pfmag | iad-ABDUL-RAOUF| |

Pour cela rendez vous sur la page de votre projet. 
Cliquez sur settings 

![](https://markdown.data-ensta.fr/uploads/upload_6b1b190aa225b78cccf775dd723a0598.png)

Cliquez sur collaborators dans la colonne de gauche puis sur "Add people" et saississez l'adresse mail ou le pseudo de votre binome. 

![](https://markdown.data-ensta.fr/uploads/upload_2e870070330e7a339d03ea543795fd3d.png)


### Etape 4 : Cloner le projet (à faire par le second membre du binome)

Cliquez sur le lien qui vous a été envoyé par mail pour rejoindre le projet. 

Ouvrez la page git du projet. 
CLiquez sur le bouton code (le bouton vert) et copier l'adresse qui apparait (vérifier que vous avez choisi SSH dans les 3 options qui se trouvent au dessus)

![](https://markdown.data-ensta.fr/uploads/upload_b924e3ae8b460e02aec3c0cbfa9b7f4b.png)


Ouvrez un terminal et placez vous là où vous souhaitez cloner votre projet 

Executez la commande : `git clone adresse_copiée`
Lisez le message qui apparait et tapez 'yes'. 

Si vous n'avez pas de message d'erreur, vous devriez alors voir un nouveau dossier dans votre répertoire, le dossier de votre projet. 

## Etape 5 : créer votre premier fichier et faites votre premier commit (n'importe quel membre du binome)

Vous pouvez maintenant commencer votre projet. 
Créer un nouveau fichier par exemple jeu.c

Vous pouvez maintenant gitter ce nouveau fichier en tapant les instructions suivantes : 
`git add jeu.c`
`git commit -am "ajout du fichier jeu.c"`
`git push`

Si vous retournez sur la page principal de votre projet sur github, vous devriez maintenant voir ce nouveau fichier apparaitre. 

Le second membre du binome peut maintenant récuperer ce fichier en ouvrant un terminal dans le dossier du projet et en tapant : `git pull`

## Recupérer un projet déjà présent sur git 

Pour certains projets, une base est mise à disposition par l'enseignant. 
Vous devez donc commencer par récupérer cette base. 

ATTENTION : assurez-vous d'avoir créé une clé SSH avant de faire les étapes suivantes.
Une fois que vous êtes sûrs d'avoir une clé SSH, vous devez : 

* Commencez par vous rendre sur la page git du projet
* Cliquez sur code 
* Cliquez sur ssh 
* Copier l'adresse qui s'affiche 
![](https://markdown.data-ensta.fr/uploads/upload_aa47fde4888633be600b4ab6228489b1.png)

* Ouvrez un terminal
* Déplacez vous dans le dossier dans lequel vous voulez récupérer le code 
* Executez la commande suivante 
`git clone ADRESSE_A_COPIER`

Le projet se copie alors dans un sous dossier. 
![](https://markdown.data-ensta.fr/uploads/upload_6572f88335f36d84d4c46bc2094aad38.png)

Vous pouvez alors faire 
`ls` 
un sous dossier portant le nom de votre projet devrait alors apparaitre. 

ATTENTION : ce répertoire git est celui de votre chargé de TD, ce n'est pas dans celui-ci que vous devez envoyer vos modifications personnelles. Vous devez donc suivre les étapes nécessaires à la création d'un nouveau projet.

