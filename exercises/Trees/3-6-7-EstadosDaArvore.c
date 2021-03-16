/*
Mostre os estados de uma árvore AVL após cada inserção da sequência. Detalhe as rotações que forem necessárias, 
dizendo em qual nó elas ocorreram, para qual lado, e durante a inserção de qual número.

-------------------------------------------------------------------------------------------------------------------------------

Sequecia {12, 23, 41, 36, 44, 38}

insere(12) 

        12 p=0

insere(23) 

         12 p = -1
           \                Balanceada          
            23 p = 0

insere(41)

        12 p=-2
          \                  rotação para esquerda         23 p=0
           23 p=-1                   ===>                 /  \              Balanceada
            \                                       p=0 12    41 p=0
             41 p=0 

insere(36)

         23 p=-1
        /  \
  p=0 12    36 p=-1         Balanceada
              \
               41 p=0

insere(44)


         23 p=-2                                                                    23 p=-1
        /  \                                                                       /  \              
  p=0 12    36 p=-2         rotacao para esquerda no 41 que vira nó          p=0 12    41 p=0           Balanceada
              \                             ===>                                      /  \
               41 p=-1                                                          p=0 36    44 p=0
                 \
                  44 p=0


insere(38)

         23 p=-2                                                                38 p=0
        /  \                                                                   /  \
  p=0 12    41 p=1                                                       p=0 23    41 p=-1          Balanceada
           /  \                                                             /  \     \
     p=1 36    44 p=0                                                 p=0 12    36    44 p=0
           \                                                                    ^
            38 p=0                                                              |  
                                                                               p=0   

-------------------------------------------------------------------------------------------------------------------------------

Sequencia  {15, 30, 40, 32, 48, 36}

insere(15) 

        15

insere(30) 

         15 p = -1
           \                Balanceada          
            30 p = 0

insere(40)

        15 p=-2
          \                  rotação para esquerda         30 p=0
           30 p=-1                   ===>                 /  \              Balanceada
            \                                       p=0 15    40 p=0
             40 p=0 

insere(32)

        30 p=0
        /  \                        ===>                  30 p=-1
  p=0 15    40 p=0                                       /  \                             
                                                   p=0 15    32 p=-1
                                                               \
                                                                 40 p=0

insere(48)

            30 p=-1
           /  \             
     p=0 15    40 p=-1
                 \
                  48 p=0

insere(36)

                30 p=-2                                                 36 p=0
               /  \                                                    /  \
         p=0 15     36 p=-2                     ===>             p=1 30    40 p=-1
                     \                                              /        \
                      40 p=-1                                 p=0 15          48 p=0
                        \
                         48 p=0
                
-------------------------------------------------------------------------------------------------------------------------------

Sequencia {10, 20, 15, 25, 30, 16, 18, 19}

insere(10)

        10 p=0

insere(20)

        10 p=-1
          \
           20 p=0

insere(15)

        10 p=-2                                                    15 p=0
          \                                                       /  \   
           15 p=-1                      ===>                p=0 10    20 p=0
             \
              20 p=0

insere(25)



insere(30)



insere(16)



insere(18)



insere(19)



*/