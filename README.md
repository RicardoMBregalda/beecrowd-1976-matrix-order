# 📌 Beecrowd 1976 — Multiplicação de Matrizes Otimizada

Este repositório contém a solução em **C** para o problema **1976 - Multiplicação de Matrizes** da plataforma [Beecrowd](https://www.beecrowd.com.br/), utilizando **Programação Dinâmica** para determinar a ordem ótima de multiplicação que minimize o número total de operações.

---

## 📋 Descrição do Problema

Gustavo está aprendendo multiplicação de matrizes e percebeu que a **ordem** com que as multiplicações são feitas **afeta a quantidade de contas** necessárias. O objetivo do problema é encontrar a **ordem ótima de multiplicação** de uma cadeia de matrizes, de modo a **minimizar o número de multiplicações escalares**.

### 📥 Entrada

- A primeira linha de cada caso de teste contém um inteiro `N` (1 ≤ N ≤ 1000), indicando o número de matrizes.
- As próximas `N` linhas contêm dois inteiros `L` e `C` representando as dimensões da matriz.
- A entrada termina quando `N = 0`.

### 📤 Saída

- Se houver **apenas uma forma ótima**, imprima a **ordem de multiplicação** com parênteses e nomes `A1`, `A2`, ..., `AN`.
- Se houver **mais de uma forma ótima**, imprima apenas o **número mínimo de multiplicações** necessárias.

---

## 💡 Exemplo

### Entrada

```
6
30 35
35 15
15 5
5 10
10 20
20 25
3
5 5
5 5
5 5
0
```

### Saída

```
((A1(A2A3))((A4A5)A6))
250
```

---

## 🚀 Como Compilar e Executar

1. Salve o código como `matriz_otima.c`.
2. Compile com um compilador C:

```bash
gcc matriz_otima.c -o matriz_otima
```

3. Execute:

```bash
./matriz_otima
```

---

## 🧠 Estratégia Utilizada

- Usa o clássico algoritmo de **Programação Dinâmica** para otimizar a multiplicação de matrizes (Matrix Chain Multiplication).
- A matriz `custo[i][j]` armazena o custo mínimo de multiplicar as matrizes de `i` a `j`.
- A matriz `divisao[i][j]` guarda o índice onde a multiplicação foi dividida.
- Caso o mesmo custo seja encontrado por mais de uma divisão, a flag `-1` é usada para indicar múltiplas soluções.

---

## 📎 Requisitos

- Compilador C compatível com C99 ou superior (ex: `gcc`).

---

## 🏁 Resultado

O programa é eficiente mesmo para grandes cadeias de matrizes (`N` até 1000), utilizando `O(N^3)` de tempo e `O(N^2)` de espaço.

---

## ✍️ Autor

**Ricardo Bregalda**  
Estudante de Ciência da Computação - UCS  
🔗 [GitHub](https://github.com/RicardoMBregalda) | [Beecrowd](https://judge.beecrowd.com/pt/profile/635895)
