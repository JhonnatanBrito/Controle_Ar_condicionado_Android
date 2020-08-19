# Controle_Ar_condicionado_Android
O Mini projeto tem por finalidade o acionamento remoto de um Ar condicionado remotamente, utilizando a linguagem JAVA e um Arduino.

App_Android X Servidor_JAVA_Socket_Serial X Arduino_ledInfravermelho

# A historia.
tudo começou quando precisei acionar o ar condicionado, assim que chegava no escritório a sala estava quente e ar demora uns 15 min para fica na temperatura agradavél :) , foi ai que pensei "gostaria sair de casa e ao chegar na minha sala que o ambiente já estivesse agradável ". Então tive ideia de usar meu arduinoUNO para ligar o Ar, mas precisava acessa-lo de forma remota, como não tenho Ethernet Shield, olhei para o computador e vi o quão ele poderoso em relação ao arduino :( e decidir em usar ele  para o acionamento do arduino, ele já tinha que ficar ligado mesmo :D.

desenvolvi um servidor soquete, para comunicação com o Android e sim ele é controlado pelo pelo celular, e usei a porta Serial do arduino pra fazer a escuta. bingo!!
já tinha um meio entre eles. 

Obs: este projeto, tem po finalidade ser um como estudo.
