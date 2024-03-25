**ATIV 1**
**O que será impresso na tela quando esse programa for executado?**
Será impresso a string de criação de cada thread (--Cria a thread %d), além disso, cada thread irá imprimir um "Hello World" e, ao fim do programa, iremos imprimir a finalização da main com (--Thread principal terminou)

**Os resultados estão de acordo com o esperado?**
Não, tendo em vista que 1. não terminamos de criar todas as threads antes de começar a executar alguma e 2. não estamos esperando o término de todas as threads antes de seguir com o código da main. Com isso tudo, a nossa ordem de print acaba sendo alterada como no exemplo a seguir:

```
--Cria a thread 0
--Cria a thread 1
Hello World
--Cria a thread 2
Hello World
--Cria a thread 3
Hello World
--Thread principal terminou
Hello World
```

**ATIV 2**
**Por que foi necessário usar long int na variável iteradora?**
Como a gente vai transformar (fazer um typecast) de `int -> ponteiro -> int`, poderia gerar Warning de perda de informação por ir de `4 bytes -> 8 bytes -> 4 bytes`. Colocando o long int, iremos transformar de `8 bytes -> 8 bytes`, sem gerar esse warning;

**ATIV 3**
**Por que foi necessário criar uma estrutura de dados nova?**
Como só é possível passar um único argumento para a nossa thread, é necessário criar uma struct para que seja possível passar todos os dados necessários para a thread dentro da nossa struct/objeto.

**ATIV 4**
**O que aconteceu de diferente em relação às versões/execuções anteriores?**
Nessa execução, a grande diferença é que só voltamos para o fluxo da main quando todas as threads terminam sua execução. Sendo assim, a última coisa a ser impressa pelo programa é a string "--Thread principal terminou"