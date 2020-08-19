/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package servidor;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.io.ObjectInputStream;
import java.io.ObjectOutputStream;
import java.io.OutputStream;
import java.net.ServerSocket;
import java.net.Socket;
import java.util.logging.Level;
import java.util.logging.Logger;
import gnu.io.CommPortIdentifier;
import gnu.io.SerialPort;
import static java.awt.image.ImageObserver.ERROR;
import java.io.OutputStream;
import java.net.HttpURLConnection;
import java.net.URL;
import java.util.Enumeration;
import javax.swing.JOptionPane;
/**
 *
 * @author Jhonn
 */
public class Servidor {
    
    
    
 //Variaveis de Conexao Serial
 private ServerSocket serverSocket;

  static InputStreamReader mobileStream ;
  static BufferedReader mobileBufferStream ;
 static String mobileMsg;
 
    //Variaveis de Conexao Serial
    private OutputStream output = null;
    SerialPort serialPort;
    private final String porta="COM6";
    private static final int timeOut = 2000; //2 segundos
    private static final int dataRate = 9600;
    private Runnable mostraIP;
    
 
   public void iniciarConexao(){
        CommPortIdentifier portaId = null;
        Enumeration portaEnum = CommPortIdentifier.getPortIdentifiers();
        
        while(portaEnum.hasMoreElements()){
            CommPortIdentifier atualPortaId =(CommPortIdentifier) portaEnum.nextElement();
            if(porta.equals(atualPortaId.getName())){
                portaId=atualPortaId;
                break;
            }
        }
        if(portaId == null){
          //  mostrarErro("Não se pode conectar a porta");
            System.exit(ERROR);
        }
        
        try{
            serialPort = (SerialPort) portaId.open(this.getClass().getName(), timeOut);
            //parametros da porta serial
            
            serialPort.setSerialPortParams(dataRate, SerialPort.DATABITS_8, SerialPort.STOPBITS_1, SerialPort.PARITY_NONE);
            output = serialPort.getOutputStream();
        }catch(Exception e){
          //  mostrarErro(e.getMessage());
            System.exit(ERROR);
        }
    }
    
    private void enviarDados(String dados){
        try{
        output.write(dados.getBytes());            
        }catch(Exception e){
          //  mostrarErro("Erro");
            System.exit(ERROR);
        }
    }
    
 public void mostraIP(){
      
     String ip = "Não definido"; 
                        try { URL whatismyip = new URL("http://checkip.amazonaws.com"); 
                        BufferedReader in = null;
                        in = new BufferedReader(new InputStreamReader(whatismyip.openStream())); 
                        ip = in.readLine(); 
                        JOptionPane.showMessageDialog(null, ip);
                        System.out.println(ip);
                        } 
                        
                        
         
	catch (Exception e) 
	{
		e.printStackTrace();
	}
         
 }
  private void criarServerSocket(int porta) throws IOException
   {
      serverSocket = new ServerSocket(porta);
   }
 
private Socket esperaConexao() throws IOException
  {
   Socket socket = serverSocket.accept();
   return socket;
  }
 

private void fechaSocket(Socket s) throws IOException
{
   s.close();
}


private void trataConexao(Socket socket) throws IOException 
{
  
  try {
         // protocolo da aplicacao
      
       
         //ObjectOutputStream output = new ObjectOutputStream(socket.getOutputStream());
        //ObjectInputStream input = new ObjectInputStream(socket.getInputStream() );
         mobileStream = new InputStreamReader(socket.getInputStream());
         mobileBufferStream = new BufferedReader(mobileStream);
         mobileMsg = mobileBufferStream.readLine();
         
      // String mensagem = input.readUTF();
         enviarDados(mobileMsg);
         System.out.println( "do Celular recebeu " + mobileMsg);
         
         //output.writeUTF("Recebido");
         //output.flush();
         // input.close();
          mobileStream.close();
          //output.close();
         
     
      } catch (IOException e) {
          System.out.println("cliente enderenço:" + socket.getInetAddress());
          System.out.print("Erro no output input stream" + e);
      } finally{
         fechaSocket(socket);     
      
               }
     
    
 }




    public static void main(String[] args) {
     
     String get = null;
            try {
        
           Servidor server = new Servidor();
           server.iniciarConexao();
           server.criarServerSocket(6000);
           Thread threadMostrarIP = new Thread((Runnable) server.mostraIP);
           threadMostrarIP.start();
         server.mostraIP();
           
          while(true){
           System.out.println("===================================");
           System.out.println("Aguardando Conexao");
           Socket socket = server.esperaConexao();
            get = socket.getRemoteSocketAddress().toString();
           System.out.println("Cliente conectado > " + get);
          
           server.trataConexao(socket);
           System.out.println("cliente Finalizado > " + get);
        
         }
            } catch (IOException ex) 
                     {
        System.out.print("Erro ao criar socket" + ex.getMessage());
                     }
   
     }       
  
}
