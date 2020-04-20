# my_rpg
By Loïc d'Eyssautier, malo le moing, robin coudert and sevan sarikaya


Dans le fichier game_loop.c :

la fonction game_loop est la game_loop du prog

Si vous ajoutez une nouvelle structure,
il faut l'ajouter dans la structure de structure hub et en la déclare pointeur*
puis la malloc dans la fonction structuring_malloc.

La fonction initialization sert à appeler les fonctions d'initiation (ex: pour les sprites ou les positions)



Dans le fichier event_analysis.c :

la fonction analyse_events sert a analyser les évente,
si c'est un evente de type click souris vous pouvez aller dans la fonction button_click_detection,
et en fonction de la scène ou vous êtes (ex : scenes = 1 c'est le jeu, 0 c'est le menu start),
vous pouvez appeler votre fonction pour l'event



Dans le fichier initialization.c :

les fonctions pour initialiser (ex : les spite, ...) son ici



Dans le fichier display.c :

toutes les fonctions d'affichages,
la fonction game_display est la fonction principale pour afficher (ex:les Sprite,) etc ...


Dans le fichier menu_pause.c et menu_start.c:

Ils servent pour le menu pause et le menu start