# So_Long
So Long é um jogo desenvolvido em C como parte da formação da 42SP.

<img src="http://img.shields.io/static/v1?label=STATUS&message=100/100&color=GREEN&style=for-the-badge"/>

* [Resumo](#Resumo)
* [Aprendizado](#Aprendizado)
* [Funcionamento](#Funcionamento)
* [Mapas](#Mapas)

> ## Resumo

Neste projeto desenvolvi um jogo usando a biblioteca MiniLibX, é um jogo simples em 2D com visão top-down. O mapa é obtido atravéz de um arquivo de texto com a extensão .ber, onde são aceitos somente os caracteres "10PCE".

<br>

> ## Aprendizado

Nesse projeto fui capaz de desenvolver meus conhecimentos para o básico de projetos gráficos, gerenciamento de janelas, manipulação de eventos, cores, texturas, etc.

<br>

> ## Funcionamento

Para o projeto funcionar basta clonar o repositório e executar o comando ```make``` no shell, a biblioteca MLX sera copilada, logo após minha biblioteca ft_printf e libft serão copiladas, então o jogo sera copilado, sera gerado um arquivo so_long, basta executar o arquivo e como argumento o nome do mapa. Exemplo: ```so_long map.ber```. Você támbem pode usar o comando ```make clean``` para excluir os objetos.

<br>

> ## Mapas

Os mapas devem ter um formato retangular, somente com os caracteres "10PCE", sendo 1 para paredes, 0 os caminhos livres, P a posição do player, C os coletáveis e E a saída. Deve ser cercado por 1, e conter somente um P e um E, além disso, todos os coletáveis e a saída devem ser acessíveis para o player.

Exemplo de mapa válido:

 ```
 1111111111
 1P00010001
 11000C10C1
 1C0100C0E1
 1111111111
 ```
 Todos os mapas devem seguir esse padrão de construção, e possuir um extensão .ber, além que devem ser salvos na pasta maps.
