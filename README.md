[![Open in Visual Studio Code](https://classroom.github.com/assets/open-in-vscode-2e0aaae1b6195c2367325f4f02e2d04e9abb55f0b24a779b69b11b9e10269abc.svg)](https://classroom.github.com/online_ide?assignment_repo_id=17224757&assignment_repo_type=AssignmentRepo)
# INF0063 - AED1

202403003 - Gabriel Eduardo Paulino Florentino

202302569 - Matheus Teixeira Pires

202302540 - Gabriel Ferreira Dos Santos

## SEÇÃO 1 (INTRODUÇÃO)
### Problema
A proposta do seminário aborda a construção de um sistema para gerenciamento de eleições simples, no qual candidatos são cadastrados, votos são registrados, e resultados são apresentados. Este sistema se aplica em contextos educacionais, pequenas organizações ou simulações que demandem uma ferramenta para eleições rápidas e funcionais. 
### Literatura
(Por que a urna eletrônica é segura - Rodrigo Carneiro Munhoz Coimbra - https://www.tse.jus.br/institucional/escola-judiciaria-eleitoral/publicacoes/revistas-da-eje/artigos/revista-eletronica-eje-n.-6-ano-4/por-que-a-urna-eletronica-e-segura)

(Linguagem C - Aula 104 - EX36 Repetição - Programa de Votos de uma Eleição com While e Switch Case - https://www.youtube.com/watch?v=SaGvitYCDwY)

([C] - #Lista simplesmente encadeada - https://www.youtube.com/watch?v=OjjWA37WhoM)

### Dataset
Os dados a serem explorados no desenvolvimento e na aplicação do projeto serão as informações pertinentes de todos os canditados a serem registrados, bem como o registro de todos os seus respectivos votos recebidos. Os dados referentes aos eleitores não serão explorados, visto que a aplicação busca adotar a ideia de sigilo eleitoral. Além disso, também serão tratatos os votos nulos e brancos.

### Métodos

Os candidatos serão registrados em uma estrutura sequencial que permita a adição, remoção e modificação de seus elementos, como listas simplesmente encadeadas, de modo que seja possível atualizar as informações dos canditados e a contagem dos votos referentes a eles. Além disso, será necessário atribuir um tratamento especial aos votos, de modo que seja possível realizar a contagem de forma eficiente e transparente.

### Avaliação

Para avaliar o desempenho da aplicação, deverão ser realizados diversos testes para analisar o seu comportamento perante um grande volume de canditados e de votos, pois é uma situação esperada para esse tipo de sistema. A aplicação deve manter a sua eficiência e praticidade nas mais variadas situações. Além disso, será preciso verificar se todos os votos estão sendo corretamente contabilizados, para que não haja problemas relacionados a esse aspecto.

## SEÇÃO 3 (METODOLOGIA)
A metodologia consiste em, primeiramente, registrar todos os candidatos que participarão da respectiva eleição. Além disso, será possível realizar edições nos candidatos registrados, um recurso a ser utilizado em casos de erros no registro, e também será possível ver todos os candidatos que estão registrados. Após isso, será possível fazer o registro dos votos, e então fazer a contagem dos mesmos. Por fim, será possível exibir o resultado final, mostrando a quantidade de votos que cada candidato recebeu, bem como os votos brancos e nulos. Essa metodologia está resumida no fluxo abaixo:
![Fluxo](https://github.com/user-attachments/assets/299c1bc2-0f1e-44c9-bb26-f440761819f3)
