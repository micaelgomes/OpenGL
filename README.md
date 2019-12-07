# CP-openGL

Para execução da atividade foi construída uma Esfera (porém como não há iluminação não é possível ver a forma da esfera, mas é possível perceber o movimento).

A mecânica consiste em incrementas as componente R.G.B e rotacionar a esferar em torno de um eixo

## comandos

a -> incrementa o canal R e rotaciona em torno de X 
s -> incrementa o canal G e rotaciona em torno de X
d -> incrementa o canal B e rotaciona em torno de X

shift + a -> Decrementa o canal R e rotaciona em torno de X, só que em sentido anti-horário
shift + s -> Decrementa o canal G e rotaciona em torno de Y, só que em sentido anti-horário
shift + d -> Decrementa o canal B e rotaciona em torno de Z, só que em sentido anti-horário

esc -> Fecha a aplicação

## Compilação e execução

g++ main.c -o exe -lglut -lGLU -lGL && ./exe