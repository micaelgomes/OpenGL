# CP-openGL

Quando a aplicação é iniciada, a camera está dentro do CUBO, pressione W, até ver completamente o CUBO para interagir.

A mecânica consiste em incrementas as componente R.G.B e variar o posicionamento da câmera em X ou Y

## comandos

a -> decrementa em X
s -> decrementa em Y
d -> incrementa em X
w -> incrementa em Y

o -> Projeção Ortogonal
p -> Projeção perspectiva

esc -> Fecha a aplicação

## Compilação e execução

g++ main.c -o exe -lglut -lGLU -lGL && ./exe
