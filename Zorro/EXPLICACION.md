Haciendo uso de POO, construya una animación con el sprite.png adjunto. 
La animación consiste en un personaje Zorro que avanza en el campo verde (fondo del canvas) en dirección aleatoria en modo normal, 
teniendo unas monedas (esferas amarillas) distribuidas aleatoriamente por todo el canvas.

- El programa inicia con la imagen del zorro avanzando en dirección aleatoria.
- Las monedas aparecen fijas en posiciones aleatorias por todo el canvas, un total de 15 (deben de estar en un arreglo en la clase juego) 
  y desaparecen cada 4 segundos (se eliminan del arreglo). 
-	Si se presiona la tecla B, el personaje zorro debe cambiar a color gris claro
-	Si se presiona la tecla V, el personaje zorro debe cambiar a color naranja claro
-	Si se presiona la tecla Z, el personaje zorro debe cambiar a color marrón claro
-	Si se presiona la tecla A, el personaje zorro debe cambiar a color amarillo
-	Si el personaje zorro en movimiento automático choca con los límites del canvas debe rebotar y cambiar de color en forma aleatoria.
-	Cuando desaparecen todas las monedas, termina el juego y debe aparecer un cuadro de mensaje con el reporte del número de veces el zorro cambió de color.
-	Debe utilizar “buffer” para evitar el parpadeo.

Creará una clase controladora juego que administre la animación.
