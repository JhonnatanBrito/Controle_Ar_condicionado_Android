# Controle_Ar_condicionado_Android
O Mini projeto tem por finalidade o acionamento remoto de um Ar condicionado, utilizando a linguagem JAVA e um Arduino.

App_Android X Servidor_JAVA_Socket_Serial X Arduino_ledInfravermelho

# A historia.
tudo começou quando precisei acionar o ar condicionado, e assim que chegava no escritório a sala estava quente muito quente, e mesmo ligando o Ar condicionado demorava uns 15 min para fica na temperatura ideal :) , foi ai que pensei "como seria bom que ao sair de casa, e ao chegar no escritório a temperatura ambiente da sala já estivesse agradável ". Então tive a ideia de usar meu arduinoUNO para ligar o "Ar", mas precisava acessa-lo de forma remota, como não tenho Ethernet Shield, olhei para o computador e vi o quão ele poderoso  me refiro a isto comparando ele em relação ao arduino, e pensei, se eu usar os conhecimentos em java que tenho será que conseguiria acionar o arduino e acionar o ar condicinado?  :D.
implementei um servidor soquete em JAVA, para comunicação com o APP Android e sim ele é controlado pelo pelo celular, usei a porta Serial do arduino pra fazer a escuta com o servidor e... Bingo!!
já tinha um meio de comunicação entre eles. 
O Servidor recebe o soquete do App Android, ler e enviar pela Serial ao arduino que enviar o comando infravermelho acionando o Ar condicionado. :D

### Assistir ao Vídeo de exemplo.
[![Clique aqui para assistir o vídeo..!](http://img.youtube.com/vi/QEv3DW897bA/0.jpg)](http://www.youtube.com/watch?v=QEv3DW897bA "Clique aqui para assistir o vídeo..!")
[![Acionando Ar condicionado pela internet (Remoto) - App Android - JAVA - Arduino.](http://img.youtube.com/vi/Zf3eASwBFTs/0.jpg)](http://www.youtube.com/watch?v=Zf3eASwBFTs "Clique para Assistir")
#
Obs: este projeto, tem por finalidade ser um objeto de estudo e Conhecimento.
