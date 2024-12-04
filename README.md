[![Open in Visual Studio Code](https://classroom.github.com/assets/open-in-vscode-2e0aaae1b6195c2367325f4f02e2d04e9abb55f0b24a779b69b11b9e10269abc.svg)](https://github.com/2024-2-INF0063-AED1/semin-rio-garotos-de-xandao/blob/main/LICENCE)
# INF0063 - AED1
# TEMA - SISTEMA ELEITORAL

202403003 - Gabriel Eduardo Paulino Florentino

202302569 - Matheus Teixeira Pires

202302540 - Gabriel Ferreira Dos Santos

# SEÇÃO 1 (INTRODUÇÃO)
## Problema
A proposta do seminário aborda a construção de um sistema para gerenciamento de eleições simples, no qual candidatos são cadastrados, votos são registrados, e resultados são apresentados. Este sistema se aplica em contextos educacionais, pequenas organizações ou simulações que demandem uma ferramenta para eleições rápidas e funcionais. 

## Literatura
(Por que a urna eletrônica é segura - Rodrigo Carneiro Munhoz Coimbra - https://www.tse.jus.br/institucional/escola-judiciaria-eleitoral/publicacoes/revistas-da-eje/artigos/revista-eletronica-eje-n.-6-ano-4/por-que-a-urna-eletronica-e-segura)

(Linguagem C - Aula 104 - EX36 Repetição - Programa de Votos de uma Eleição com While e Switch Case - https://www.youtube.com/watch?v=SaGvitYCDwY)

([C] - #Lista simplesmente encadeada - https://www.youtube.com/watch?v=OjjWA37WhoM)

## Dataset
Os dados a serem explorados no desenvolvimento e na aplicação do projeto serão as informações pertinentes de todos os canditados a serem registrados, bem como o registro de todos os seus respectivos votos recebidos. Os dados referentes aos eleitores não serão explorados, visto que a aplicação busca adotar a ideia de sigilo eleitoral. Além disso, também serão tratatos os votos nulos e brancos.

## Métodos
Os candidatos serão registrados em uma estrutura sequencial que permita a adição, remoção e modificação de seus elementos, como listas simplesmente encadeadas, de modo que seja possível atualizar as informações dos canditados e a contagem dos votos referentes a eles. Além disso, será necessário atribuir um tratamento especial aos votos, de modo que seja possível realizar a contagem de forma eficiente e transparente.

## Avaliação
Para avaliar o desempenho da aplicação, deverão ser realizados diversos testes para analisar o seu comportamento perante um grande volume de canditados e de votos, pois é uma situação esperada para esse tipo de sistema. A aplicação deve manter a sua eficiência e praticidade nas mais variadas situações. Além disso, será preciso verificar se todos os votos estão sendo corretamente contabilizados, para que não haja problemas relacionados a esse aspecto.

# Seção 2 (Fundamentos Teóricos)

O sistema eleitoral foi desenvolvido utilizando listas simplesmente encadeadas para o armazenamento e gerenciamento de candidatos. Essa escolha se baseia na eficiência na manipulação dinâmica de memória, permitindo inserções, remoções e buscas sem necessidade de realocação de grandes blocos de memória, característica que seria necessária em estruturas como arrays.

## Mecanismos e Técnicas Utilizados:
### Listas Simplesmente Encadeadas:
Implementadas para armazenar candidatos de forma dinâmica, possibilitando inserções e remoções de forma eficiente, principalmente em cenários onde o número de candidatos pode variar durante a execução do sistema.
O uso de ponteiros facilita a ligação entre os nós, minimizando o tempo de execução durante operações de busca e inserção.
## Estrutura de Candidato:
Cada nó da lista contém informações críticas como nome, partido, número do candidato e a contagem de votos.
A vinculação entre candidatos é feita por meio de ponteiros, o que otimiza o uso de memória ao evitar alocações fixas.
## Métricas e Avaliação:
A eficiência do sistema foi medida considerando o tempo de inserção de cada candidato. Isso foi feito através de uma função que insere quantos candidatos foram pedidos e retorna o tempo de execução para inserir todos esses candidatos.
Essas métricas foram testadas com vários números de candidatos, e o tempo de execução foi cronometrado para medir o desempenho do sistema.
## Controle de Acesso e Autenticação: 
Além do gerenciamento de candidatos, o sistema conta com a funcionalidade de autenticação para garantir que operações críticas, juntamente com a inserção e remoção de candidatos, sejam restritas a usuários com privilégios administrativos.
Entrada de senha: Ao iniciar, o sistema solicita ao usuário a senha administrativa.
verificação de senha: Se a senha inserida for “admin123”, o usuário recebe privilégios administrativos. Caso contrário, o acesso é negado.
## Controle de Acesso:
Administradores podem adicionar e remover candidatos, enquanto usuários comuns apenas votam.


# SEÇÃO 3 (METODOLOGIA)
A metodologia consiste em, primeiramente, registrar todos os candidatos que participarão da respectiva eleição. Além disso, será possível realizar edições nos candidatos registrados, um recurso a ser utilizado em casos de erros no registro, e também será possível ver todos os candidatos que estão registrados. Após isso, será possível fazer o registro dos votos, e então fazer a contagem dos mesmos. Por fim, será possível exibir o resultado final, mostrando a quantidade de votos que cada candidato recebeu, bem como os votos brancos e nulos. Essa metodologia está resumida no fluxo abaixo:
![Fluxo](https://github.com/user-attachments/assets/299c1bc2-0f1e-44c9-bb26-f440761819f3)

# Seção IV - Resultados e Conclusões
## Resultados Obtidos:
### Desempenho:
Tempo de Inserção: O tempo de inserção para um número muito pequeno de candidatos, como 100, é tão pequeno que nem mesmo é contabilizado pela função teste. Para 1000 candidatos, o tempo foi de 0,004. A partir daí, observou-se um aumento exponencial do tempo de inserção. Quanto maior a quantidade de candidatos inseridos, maior o tempo. Para 20 mil candidatos, por exemplo, o tempo foi de 1,107 segundos. Já para 50 mil candidatos, o tempo foi de 6,768, o que não é diretamente proporcional. Para 70 mil candidatos, o tempo foi maior ainda, de 13,283 segundos. Isso ocorre porque no código de inserção de candidatos, existe uma verificação que analisa se já existe algum candidato na lista com o mesmo número que o candidato a ser adicionado, e para isso, percorre toda a lista. Isso é necessário para o bom funcionamento do programa.
Os resultados demonstram que a implementação com listas simplesmente encadeadas é eficaz para lidar com grandes volumes de candidatos sem comprometer a performance.
## Visualização dos Resultados:
![image](https://github.com/user-attachments/assets/056a69d7-8740-4750-8648-5386819437d2)

## Conclusões:
### Durante o desenvolvimento e execução do projeto, as seguintes lições foram aprendidas:

#### O projeto demonstrou a eficiência das listas simplesmente encadeadas para aplicações dinâmicas, onde o volume de dados pode variar consideravelmente. Essa escolha foi crucial para garantir a flexibilidade e o gerenciamento eficiente de memória, evitando desperdícios e permitindo inserções e remoções rápidas.
#### O sistema demonstrou-se não apenas funcional, mas também escalável, sendo capaz de lidar com uma quantidade significativa de candidatos sem degradação severa do desempenho. A inclusão de um mecanismo de autenticação simples reforçou o controle de acesso, permitindo que somente usuários autorizados realizassem operações críticas, o que é fundamental para garantir a integridade e segurança dos dados em um ambiente eleitoral.
#### Portanto, o projeto não só alcançou os objetivos iniciais de criar uma aplicação para gestão de eleições simples, mas também abriu caminho para futuras expansões, como a integração de interfaces mais amigáveis, algoritmos de segurança aprimorados e maior robustez na manipulação de grandes volumes de dados. Este trabalho representa um passo importante na compreensão e implementação de sistemas que requerem eficiência, escalabilidade e segurança, servindo de base para projetos mais complexos no futuro.

# Execução do programa:  
![teste](https://github.com/user-attachments/assets/12dd78d2-4449-4010-8680-c476e2fa8018)


