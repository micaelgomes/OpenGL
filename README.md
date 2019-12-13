# CP-openGL

Para execução da atividade foi construída uma Esfera.
A mecânica consiste em incrementas as componente R.G.B e rotacionar a esferar em torno de um eixo

Porém, para esta atividade é possível ligar/desligar a iluminação:
- Ambiente
- Especular
- Difusa

OBS: Caso a luz especular não apareça, rotacione a Espera em algum eixo

## comandos

+ a -> incrementa o canal R e rotaciona em torno de X 
+ s -> incrementa o canal G e rotaciona em torno de X 
+ d -> incrementa o canal B e rotaciona em torno de X

+ shift + a -> Decrementa o canal R e rotaciona em torno de X, só que em sentido anti-horário 
+ shift + s -> Decrementa o canal G e rotaciona em torno de Y, só que em sentido anti-horário 
+ shift + d -> Decrementa o canal B e rotaciona em torno de Z, só que em sentido anti-horário


+ j -> Luz Ambiente
+ k -> Luz Especular
+ l -> Luz Difusa

+ esc -> Fecha a aplicação

## Compilação e execução

g++ main.c -o exe -lglut -lGLU -lGL && ./exe
