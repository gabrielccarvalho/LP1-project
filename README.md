# Gerenciador de Dados do Estudante
- Neste trabalho, criamos um programa em C++ que gerencia uma lista de estudantes com informações como nome, idade, matrícula e aulas que estão matriculados.
- O programa carrega esses dados do arquivo `studentData.txt`, manipula as informações e grava os dados atualizados no mesmo arquivo.

# Funções Principais:
	•	findStudent: Busca um estudante na lista usando o ﻿registrationID.
	•	addStudent: Adiciona um novo estudante à lista. Agora, podemos também adicionar aulas para o estudante no momento da adição.
	•	removeStudent: Remove o estudante da lista usando o ﻿registrationID. A função cuida da indexação do vetor durante a remoção.
	•	editStudentClasses: Edita as aulas do estudante.

## Main Function:
- O programa é dividido em três partes principais dentro da função `main()`.

## Carregamento de Dados:
- O programa abre o arquivo `studentData.txt`, lê cada linha (cada uma representando um estudante), divide a linha em atributos e cria um novo objeto ﻿Student que é adicionado à lista de estudantes.

## Manipulação de Dados:
- Depois de carregar os dados, temos funcionalidades para adicionar novos estudantes, remover estudantes existentes ou modificar as aulas em que estão matriculados.

## Atualização do Arquivo:
- Por fim, o programa grava os dados atualizados dos estudantes no arquivo `updatedStudentData.txt`.

## OBS:
- O programa também gerencia erros, como problemas ao abrir os arquivos. Além disso, faz uso de `unique_ptr` para evitar vazamentos de memória.