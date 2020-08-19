# Controle_Ar_condicionado_Android
O Mini projeto tem por finalidade o acionamento remoto de um Ar condicionado remotamente, utilizando a linguagem JAVA e um Arduino.

App_Android X Servidor_JAVA_Socket_Serial X Arduino_ledInfravermelho

# A historia.
tudo começou quando precisei acionar o ar condicionado, assim que chegava no escritório a sala estava quente e mesmo ligando o Ar condicionado demora uns 15 min para fica na temperatura agradavél :) , foi ai que pensei "gostaria sair de casa e ao chegar na minha sala com ambiente na temperatura agradável ". Então tive ideia de usar meu arduinoUNO para ligar o "Ar", mas precisava acessa-lo de forma remota, como não tenho Ethernet Shield, olhei para o computador e vi o quão ele poderoso em relação ao arduino e pensei se eu usa-se os conhecimentos em java será que conseguiria acionar o arduino ?  :D.
desenvolvi um servidor soquete em JAVA, para comunicação com o APP Android e sim ele é controlado pelo pelo celular, e usei a porta Serial do arduino pra fazer a escuta. bingo!!
já tinha um meio entre eles. 
O Servidor recebe o soquete do App Android, ler e enviar pela Serial ao arduino que enviar o comando infravermelho. :D

### Assistir ao Vídeo de exemplo.
[![Acionando Ar condicionado pela internet (Remoto) - App Android - JAVA - Arduino.](http://img.youtube.com/vi/Zf3eASwBFTs/0.jpg)](http://www.youtube.com/watch?v=Zf3eASwBFTs "Clique para Assistir")
#
Obs: este projeto, tem por finalidade ser um objeto de estudo e Conhecimento.
