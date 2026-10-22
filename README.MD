# Sistema de Atendimento Hospitalar

**Integrantes:** Maria Eduarda da Silva Moss de Oliveira e Eduardo Casubek Martins  
**Disciplina:** Programação e Sistemas Computacionais II — Campo Real

projeto em C++ utilizando fila de pacientes, pilha de histórico e lista encadeada de médicos, sem classes da STL.

## Como compilar e executar

```bash
g++ -std=c++17 -Wall -o atendimento atendimento_template.cpp
./atendimento
```

no Windows, execute `atendimento.exe`.

## Estruturas utilizadas

- **Fila:** organiza os pacientes.
- **Pilha:** registra os atendimentos.
- **Lista encadeada:** organiza os médicos disponíveis.
- **Relatório:** exibe o histórico sem apagar os registros.