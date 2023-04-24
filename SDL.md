# Utilisation de la SDL

## Présentation
La [SDL](https://libsdl.org) est la librairie graphique de C, qui permet typiquement d'ouvrir des fenêtres et d'y dessiner des formes.

Vous trouverez dans le fichier `graph.c` un exemple d'utilisation qui permet de dessiner des cercles et des flèches.

## Objectif
Votre programme étant pour l'instant très peu interactif, il faut à présent afficher visuellement le résultat à l'utilisateur.

Vous devez donc utiliser la SDL pour afficher dans une fenêtre l'ensemble des stations et des pistes, en mettant en avant le parcours de plaisir maximal et le plaisir qu'il procure.

Par exemple, avec comme entrée 
'''
6 5
0 1 -1
1 2 2
3 4 1
4 5 -1
5 3 1
'''

On peut obtenir la figure suivante : 

![](https://markdown.data-ensta.fr/uploads/upload_ad4a0c9f2e5966e5ef1b429fcc79f88e.png)

## Installation
### Linux (ou WSL)
Pour l'installer sous debian ou ubuntu (ou WSL), il faut installer le paquet `libsdl2-dev` :
```bash
sudo apt update
sudo apt install libsdl2-dev
```

### BYOD
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

## Compilation 
Pour compiler l'exemple `graph.c`, utilisez la ligne suivante :
```bash
gcc graph.c -o graph.x `sdl2-config --cflags --libs` -lm
```