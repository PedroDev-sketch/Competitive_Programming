% Legiao

Sabe-se que o Reino da Yogilândia se encontra em um mundo bi-dimensional, ou seja, em todas as batalhas travadas em seu mundo, o primeiro soldado do exército A enfrenta o primeiro soldado do exército B, quem vence, enfrenta o próximo soldado do exército oposto. A Yogilândia viveu décadas de paz e construiu uma vasta legião, entretanto, o General Socram da Carlândia se apaixonou pela Princesa Arual e decidiu com sua feroz horda, invadir o pacífico reino para tomar sua mão.

Para defender a princesa, o Rei convocou todos os guerreiros da Legião da Yogilândia, enquanto Socram colocou à frente seus mais brutais guerreiros da Horda. Cada soldado possui uma quantidade de vida (HP), pertence a um dos dois lados (“l” para Legião ou “h” para Horda), e pode ter um arqui-inimigo designado. Sempre que dois soldados se enfrentam, luta-se até que um caia, ou ambos. Porém, existe uma regra especial: caso um soldado enfrente seu arqui-inimigo, ele o elimina instantaneamente, sem sofrer qualquer dano no processo.

Cada exército segue rigidamente uma ordem, o último soldado da Legião enfrenta o primeiro da Horda, o vencedor continua no combate até cair ou até aniquilar todos os inimigos. Ao fim da guerra, determina-se qual reino prevaleceu — ou se ambos foram aniquilados.

Sua missão é simular essa batalha e determinar o desfecho da guerra.

## Regras da Batalha

- A luta é sempre **1 contra 1**, entre o último soldado da Legião e o primeiro soldado da Horda.
- Se um soldado enfrenta o próprio **arqui-inimigo**, ele o derrota imediatamente, sem perder HP.
    - Vale ressaltar que um soldado pode ser o arqui-inimigo de seu arqui-inimigo, nesse caso, ambos morrem.
- Caso contrário, o soldado com menor HP morre e o soldado com maior HP leva dano equivalente ao HP que o seu oponente tinha na hora da morte.
  - Se o HP de ambos for igual, os dois morrem.
- O soldado sobrevivente continua na linha de frente do seu exército, enfrentando o próximo inimigo.
- A guerra termina quando um dos exércitos fica sem soldados — ou ambos.

## Entrada

- A primeira linha contém um inteiro **N** (1 ≤ N ≤ 10<sup>5</sup>), o número de soldados.
- A segunda linha contém **N inteiros** a<sub>i</sub>, representando o HP do i-ésimo soldado (1 ≤ a<sub>i</sub> ≤ 10<sup>8</sup>).
- A terceira linha contém **N caracteres** b<sub>i</sub>, cada um sendo `l` ou `h`, indicando se o soldado pertence à **Legião** ou à **Horda**.
- A quarta linha contém **N inteiros** c<sub>i</sub>, onde o i-ésimo número é o índice (1 ≤ c<sub>i</sub> ≤ 10<sup>5</sup>) do arqui-inimigo do soldado i, ou **-1** caso não possua um.

## Saída

Imprima:

- **Legiao** caso a Legião vença;
- **Horda** caso a Horda vença;
- **Empate** caso ambos os lados sejam completamente destruídos.

### Exemplo 1
**Entrada:**
```
5
10 10 10 10 10
l h l h l
-1 5 -1 1 -1
```

**Saída:**
```
Horda
```

### Exemplo 2
**Entrada:**
```
4
10 10 10 10
h l h l
2 -1 4 -1
```

**Saída:**
```
Empate
```

*Explicação Exemplo 1:*
*Entrada: S<sub>1</sub>->Legião, S<sub>2</sub>->Horda, S<sub>3</sub>->Legião, S<sub>4</sub>->Horda, S<sub>5</sub>->Legião*
*Legião: S<sub>1</sub>, S<sub>3</sub>, S<sub>5</sub>; Horda: S<sub>2</sub>, S<sub>4</sub>*

*S<sub>1</sub>, S<sub>3</sub> ... S<sub>5</sub> x S<sub>2</sub> ... S<sub>4</sub> - O arqui-inimigo de S<sub>2</sub> é S<sub>5</sub>, logo, S<sub>5</sub>, morre de imediato.*
*S<sub>1</sub> ... S<sub>3</sub> x S<sub>2</sub> ... S<sub>4</sub> - S<sub>2</sub> e S<sub>3</sub> tem a mesma quantidade de HP, logo, ambos morrem.*
*S<sub>1</sub> x S<sub>4</sub> - S<sub>1</sub> é o arqui-inimigo de S<sub>4</sub>, logo, S<sub>1</sub> é morto e a vitória é da Horda.*

*Nota de esclarecimento:*
*- A Legião luta na ordem em que foi lida de trás para frente.*
*- A Horda luta na ordem em que foi lida de frente para trás.*
*- E não importa se os soldados de cada exército estão separados na leitura, os exércitos sempre marcham juntos.*