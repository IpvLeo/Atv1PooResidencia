"# Atv1PooResidencia" 

ATIVIDADE 2. Parte 1. Prática em Polimorfismo, Classes Abstratas e Interfaces

Você está convencendo os programadores da empresa de
pesquisas estatísticas DataFruta a utilizar técnicas melhores de
programação que você aprendeu durante sua residência de
software.

Uma das coisas que os programadores da DataFruta ainda não
dominaram completamente são os conceitos de classes (e
métodos) abstratos e de polimorfismo (além de interfaces).
Você então resolve montar um exemplo usando listas de dados
de diferentes tipos que implementam (de maneira polimórfica)
certas funções estatísticas que são comuns a todos.

No seu exemplo você cria uma classe abstrata chamada Lista.
Esta classe define, virtualmente, uma série de funções
estatísticas.

Em seguida você define uma série de tipos de lista que
implementam a classe virtual Lista. Listas d Datas, de nomes, de
salários, de idades.

Com o auxílio dos professores da Residência, você prepara uma
função main() que cria vector de listas (a classe abstrata).
Note que cada elemento do vector não está especificado. Pode
ser uma lista de nomes, de datas, de salários ou de idades.

Mas como todos implementam a classe Lista original, os
métodos devem funcionar. 

Qual não foi sua surpresa, porém, quando você descobriu que os 
professores se distraíram, e não implementaram corretamente a 
estrutura hierárquica de classes!

Como se não fosse o bastante, eles também não implementaram 
nenhum dos métodos estatísticos; os que estão ali apenas 
exibem uma mensagem genérica.
------------------------------------------------------------

Seu trabalho.

Abra o arquivo DataFruta.cpp e o corrija para que ele 
implemente a hierarquia corretamente, bem como iguamente 
implemente os métodos que estão em descrição genérica.

Importante: no cálculo da mediana, para dados do tipo Data ou 
do tipo String, pode ocorrer de não haver um valor exato (caso o 
conjunto de dados tenha uma quantidade par de elementos). 
Veja que, nestes casos, a mediana fica "indecidida" entre dois 
valores.

Se isto ocorrer, seu método deve mostrar o primeiro deles (a 
data mais anterior entre as duas ou o primeiro dos dois nomes 
em ordem alfabética). 

No caso dos dados numéricos, como salários ou idades, se isto 
ocorrer o seu método deve mostrar a média entre os dois 
valores.
