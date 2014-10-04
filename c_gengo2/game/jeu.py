# -------------------------------- #
# Auteur : Suzy                    #
# Créé le : 09/07/2010             #
# -------------------------------- #
# Ce petit programme de simulation #
# permet de modéliser une forme de #
# vie simplicime ! Vous pourrez y  #
# voir apparaître des formes qui   #
# se perpétuent dans le temps ou   #
# qui restent constantes.          #
# -------------------------------- # 
# Moteur du jeu de la vie :        #
# Contient toutes les fonctions    #
# qui permettent d'effectuer des   #
# opérations sur la grille et      #
# d'émuler la vie !                #
####################################

from random import random

#Constantes :
FORMES_POSSIBLES = ("plan","cylindre","tore")

def creerGrille(lignes = 20, colonnes = 20, proba = 0.5) :
    """
    Permet de créer une grille du nombre de lignes et de colonnes
    spécifiées. Les cellules seront vivantes selon la probabilité
    données en paramètre.
    lignes = 20 : Le nombre de lignes pour la grille.
    colonnes = 20 : La nombre de colonnes pour la grille.
    proba = 0.5 : La probabilité qu'une cellule créée soit vivante.
    Retourne : Retourne une grille de lignes x colonnes cellules
               aléatoirement vivantes.
    """
    aRetourner = []
    for i in range(lignes) :
        ligne = []
        for j in range(colonnes) :
            if random() > proba :
                ligne.append(0)
            else :
                ligne.append(1)
        aRetourner.append(ligne)
    return aRetourner


def chargerGrille(nomFichier) :
    """
    Permet de charger une grille à partir d'un fichier. Le fichier
    doit être composé de lignes de 0 (mort) et de 1 (vivant). Si
    elles ne sont pas toutes de la même taille, une exception sera
    levée.
    nomFichier : Le chemin vers le fichier à charger.
    Retourne : La grille chargée à partir du fichier.
    Exception : - IOError : Si le fichier n'existe pas.
                - ValueError : quelque chose n'est pas un nombre dans la grille.
                - AssertionError : un nombre différent de 0 ou 1.
                - AssertionError : lignes de différentes longueurs.
                - AssertionError : une seule ligne dans le fichier.
                - AssertionError : pas de cellule vivante.
    """
    aRetourner = []
    #Lecture du fichier :
    fichier = open(nomFichier, 'r')
    for ligne in fichier :
        ligne = ligne.split()
        #Conversion en entier :
        for i, cellule in enumerate(ligne) :
            ligne[i] = int(cellule)
            #Vérification 0 ou 1 :
            assert ligne[i] == 0 or ligne[i] == 1
        aRetourner.append(ligne)
    fichier.close()
    #Vérification de la longueur des lignes :
    memeLongueur = True
    longueur = len(aRetourner[0])
    for ligne in aRetourner :
        memeLongueur = memeLongueur and len(ligne) == longueur
    assert memeLongueur
    assert len(aRetourner) > 1
    assert encoreDeLaVie(aRetourner)
    return aRetourner
    

def sauvegarderGrille(grille, nomFichier) :
    """
    Permet d'enregistrer une grille dans un fichier qui pourra
    être chargé par la suite. Le fichier sera préalablement effacé
    s'il existe déjà.
    grille : La grille à sauvegarder.
    nomFichier : Le nom du fichier à utiliser pour la sauvegarde.
    Retourne : 0 si l'opération s'est bien passée, 1 sinon.
    """
    aEcrire = ""
    for ligne in grille :
        for cellule in ligne :
            aEcrire += "%i " % cellule
        aEcrire += "\n"
    try :
        fichier = open(nomFichier, "w")
        fichier.write(aEcrire)
        fichier.close()
        return 0
    except :
        return 1


def voisines(grille, i, j, forme) :
    """
    Permet d'obtenir une liste des voisines d'une cellule aux coordonnées
    demandées dans une grille demandée. La forme du modèle est prise en compte.
    grille : La grille contenant la cellule à étudier.
    i : L'indice de la ligne de la cellule.
    j : L'indice de la colonne de la cellule.
    forme : La forme du modèle (plan, cylindre, tore).
    Retourne : La liste des voisines de la cellule demandée.
    Exception : - IndexError si i et/ou j sort de la grille.
                - AssertionError si la forme demandée n'est pas reconnue.
    """
    aRetourner = []
    nbLignes = len(grille)
    nbColonnes = len(grille[0])
    if forme == "plan" :
        #On considère 9 cellules :
        for k in range(-1, 2) :
            for l in range(-1, 2) :
                if 0 <= (i + k) < nbLignes and 0 <= (j + l) < nbColonnes :
                    aRetourner.append(grille[i + k][j + l])
        #On retire la cellule elle-même (ou une valeur équivalente...) :
        aRetourner.remove(grille[i][j])
    elif forme == "cylindre" :
        #On considère 9 cellules :
        for k in range(-1, 2) :
            for l in range(-1, 2) :
                if 0 <= (i + k) < nbLignes :
                    aRetourner.append(grille[i + k][(j + l)%nbColonnes])
        #On retire la cellule elle-même (ou une valeur équivalente...) :
        aRetourner.remove(grille[i][j])
    elif forme == "tore" :
        #On considère 9 cellules :
        for k in range(-1, 2) :
            for l in range(-1, 2) :
                aRetourner.append(grille[(i + k)%nbLignes][(j + l)%nbColonnes])
        #On retire la cellule elle-même (ou une valeur équivalente...) :
        aRetourner.remove(grille[i][j])
    else :
        assert False
    return aRetourner


def tourSuivant(grille, regle1 = 3, regle2 = 2, forme = "tore") :
    """
    Permet de créer le tour suivant de la grille en fonction des
    règles en vigueur dans la source de vie que vous avez créée.
    grille : La grille de cellules à faire évoluer.
    regle1 = 3 : Le nombre de cellules à avoir pour qu'une cellule
                 soit vivante au prochain tour.
    regle2 = 2 : Le nombre de cellules à avoir pour qu'une cellule
                 reste dans le même état au tour suivant.
    forme = "plan" : Le modèle peut prendre différentes formes, soit
                     un plan fermé ("plan"), soit un cylindre ("cylindre"),
                     soit un tore ("tore").
                     Change les voisines aux bords du modèle.
    Retourne : Retourne la nouvelle grille après évolution.
    Exception : AssertionError : la forme donnée n'est pas reconnue.
    """
    global FORMES_POSSIBLES
    assert forme in FORMES_POSSIBLES
    aRetourner = []
    #Parcours de la grille :
    for i, ligne in enumerate(grille) :
        nouvelleLigne = []
        for j, cellule in enumerate(ligne) :
            #Compter les voisines vivantes :
            voisinesVivantes = sum(voisines(grille, i, j, forme))
            #Appliquer les règles de vie ou de mort :
            if voisinesVivantes == regle1 :
                nouvelleLigne.append(1)
            elif voisinesVivantes == regle2 :
                nouvelleLigne.append(cellule)
            else :
                nouvelleLigne.append(0)
        aRetourner.append(nouvelleLigne)
    return aRetourner


def encoreDeLaVie(grille) :
    """
    Permet de savoir si la grille contient encore de la vie ou non.
    grille : La grille a tester.
    Retourne : Retourne True si la grille contient de la vie, False sinon.
    """
    aRetourner = False
    for ligne in grille :
        for cellule in ligne :
            aRetourner = aRetourner or cellule
    return aRetourner


# Tests des fonctions :
if __name__ == "__main__" :
    print("********************\n" +
          "* Test du moteur ! *\n" +
          "********************")
    
    print("\n*****\n" +
          "* Création d'une grille vivante :\n" +
          "*****")
    grille = creerGrille(proba = 1)
    vivantes = 0
    for ligne in grille :
        print(ligne)
        for cellule in ligne :
            if cellule :
                vivantes += 1
    print("Nombre de cellules vivantes : %i (normalement à 400)" % vivantes)
    
    print("\n*****\n" +
          "* Création d'une grille aléatoire :\n" +
          "*****")
    grille = creerGrille()
    vivantes = 0
    for ligne in grille :
        print(ligne)
        for cellule in ligne :
            if cellule :
                vivantes += 1
    print("Nombre de cellules vivantes : %i (aux alentours de 200)" % vivantes)
    
    print("\n*****\n" +
          "* Sauvegarde de la grille aléatoire :\n" +
          "*****")
    echec = sauvegarderGrille(grille, "Test/TestMoteur.txt")
    if echec :
        print("La grille n'a pas été sauvegardée...")
    else :
        print("Le fichier TestMoteur.txt a bien été écrit !")
        
    print("\n*****\n" +
          "* Chargement de la grille sauvegardée :\n" +
          "*****")
    grille2 = chargerGrille("Test/TestMoteur.txt")
    if grille2 == [] :
        print("Le fichier TestMoteur.txt n'a pas été chargé correctement...")
    else :
        print("Le fichier TestMoteur.txt a été correctement chargé !")
        for ligne in grille2 :
            print(ligne)

    print("\n*****\n" +
          "* Chargement d'une grille incorrecte :\n" +
          "*****")
    print("Lignes pas de la même longueur :")
    try :
        grille3 = chargerGrille("Test/Longueur.txt")
        print("La grille a tout de même été chargée...")
    except AssertionError:
        print("Le fichier existe mais est incorrect !")
    except :
        print("Le fichier ne semble pas exister...")
        raise
    print("Autre chose que 0 ou 1 dans le fichier :")
    
    try :
        grille4 = chargerGrille("Test/PasBonNombre.txt")
        print("La grille a tout de même été chargée...")
    except AssertionError:
        print("Le fichier existe mais est incorrect !")
    except :
        print("Le fichier ne semble pas exister...")
        raise
        
    print("\n\n***********************\n" +
          "* Test des voisines : *\n" +
          "***********************\n")
    grille = creerGrille()
    for ligne in grille :
        print(ligne)
    print("Test de la forme tore :")
    print("Test coin haut gauche :")
    print(voisines(grille, 0, 0, "tore"))
    print("Test coin haut droit :")
    print(voisines(grille, 0, 19, "tore"))
    print("Test coin bas gauche :")
    print(voisines(grille, 19, 0, "tore"))
    print("Test coin bas droit :")
    print(voisines(grille, 19, 19, "tore"))
    print("Test au milieu (4,4) :")
    print(voisines(grille, 4, 4, "tore"))
    print("Test côté haut (0, 4) :")
    print(voisines(grille, 0, 4, "tore"))
    print("Test côté bas (19, 4) :")
    print(voisines(grille, 19, 4, "tore"))
    print("Test côté gauche (4, 0) :")
    print(voisines(grille, 4, 0, "tore"))
    print("Test côté droit (4, 19) :")
    print(voisines(grille, 4, 19, "tore"))
    
    print("\nTest de la forme plan :")
    print("Test coin haut gauche :")
    print(voisines(grille, 0, 0, "plan"))
    print("Test coin haut droit :")
    print(voisines(grille, 0, 19, "plan"))
    print("Test coin bas gauche :")
    print(voisines(grille, 19, 0, "plan"))
    print("Test coin bas droit :")
    print(voisines(grille, 19, 19, "plan"))
    print("Test au milieu (4,4) :")
    print(voisines(grille, 4, 4, "plan"))
    print("Test côté haut (0, 4) :")
    print(voisines(grille, 0, 4, "plan"))
    print("Test côté bas (19, 4) :")
    print(voisines(grille, 19, 4, "plan"))
    print("Test côté gauche (4, 0) :")
    print(voisines(grille, 4, 0, "plan"))
    print("Test côté droit (4, 19) :")
    print(voisines(grille, 4, 19, "plan"))

    print("\nTest de la forme cylindre :")
    print("Test coin haut gauche :")
    print(voisines(grille, 0, 0, "cylindre"))
    print("Test coin haut droit :")
    print(voisines(grille, 0, 19, "cylindre"))
    print("Test coin bas gauche :")
    print(voisines(grille, 19, 0, "cylindre"))
    print("Test coin bas droit :")
    print(voisines(grille, 19, 19, "cylindre"))
    print("Test au milieu (4,4) :")
    print(voisines(grille, 4, 4, "cylindre"))
    print("Test côté haut (0, 4) :")
    print(voisines(grille, 0, 4, "cylindre"))
    print("Test côté bas (19, 4) :")
    print(voisines(grille, 19, 4, "cylindre"))
    print("Test côté gauche (4, 0) :")
    print(voisines(grille, 4, 0, "cylindre"))
    print("Test côté droit (4, 19) :")
    print(voisines(grille, 4, 19, "cylindre"))

    print("*****\n" +
          "* Test de quelques tours de simu :\n" +
          "*****")
    grille = chargerGrille("Test/PeriodiqueStable.txt")
    print("Grille initiale :")
    for ligne in grille :
        print(ligne)
    grille = tourSuivant(grille)
    print("Grille après 1 tour :")
    for ligne in grille :
        print(ligne)
    grille = tourSuivant(grille)
    print("Grille après 2 tours :")
    for ligne in grille :
        print(ligne)
    grille = tourSuivant(grille)
    print("Grille après 3 tours :")
    for ligne in grille :
        print(ligne)
    input()
