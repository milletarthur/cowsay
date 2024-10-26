# Tamagoshi
## Compilation
gcc tamagoshi.c newcow.c -o exec

## Règles du jeu

On doit s'occuper d'une vache, et la maintenir en vie le plus longtemps possible.
Elle possède 3 états de santé : en pleine forme / nauséeuse / décédée.
On dispose d'une réserve de nourriture qui évolue à chaque tour qui est comprise entre 0 et 10.
À chaque tour, on doit décider de la quantité de nourriture qu'on donne à notre vache. Celle-ci va donc plus ou moins bien digérer ce qu'on lui donne, pouvant directelent impacté son état de santé.
Enfin il est possible que la nourriture de la réserve devienne avariée, ce qui peut faire chuter la quantité de nourriture en stock.

Pour quitter le jeu, entrer le caractère '-'.

Réalisé par [Grégory Toureille](https://github.com/nyoukki) et Arthur Millet
