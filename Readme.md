# INSTITUTO FEDERAL DE SÃO PAULO - CAMPUS PIRITUBA
## TECNOLOGIA EM ANÁLISE E DESENVOVLIMENTO DE SISTEMAS
 
---
 
# PROJETO FINAL DA DISCIPLINA - LEDA

Thiago Bernardes Ribeiro - PT3008452

A lista detalhada de Exercícios pode ser acessada em [aqui].
Cada diretório contém o enunciado dos exercícios e, quando necessário, uma breve explicação.

### Como testar os códigos?

Para testar os codigos contidos, basta clonar este repositório para a sua máquina através do comando:
~~~bash
git clone https://github.com/rib-thiago/projeto_final.git
~~~

### Dependências

O único requisito necessário para executar estes códigos é um compilador da linguagem C.
Por praticidade, neste projeto eu utilizei o Tiny C compiler (TCC), que oferece a funcionalidade de executar o programa sem gerar um arquivo binário. O Download do TCC pode ser feito neste [link].
Para utilizá-lo, no seu terminal utilize a seguinte sintaxe:
~~~bash
tcc -run source.c lib.h
~~~
Neste link encontramos a [Documentação] deste compilador.
~~~bash
tcc -run source.c lib.h
~~~
Também é possível utilizar o popular GNU C Compiler, com as seguintes instruções:
~~~bash
gcc -o output source.c
~~~
A Documentação do GCC está disponível neste [endereço].

[aqui]: <https://docs.google.com/document/d/1VHGm9mtKK1hV7UjA3BKXLku7h1YMADnTJCQs01t_-QQ/edit>
[endereço]: <https://gcc.gnu.org/onlinedocs/gcc-12.2.0/gcc/>
[link]: <http://download.savannah.gnu.org/releases/tinycc/>
[Documentação]: <https://bellard.org/tcc/tcc-doc.html>