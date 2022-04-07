package Service.Reciveder.CallBack;

import Service.SendSer.CallBack.SeCallBack;
import org.eclipse.paho.client.mqttv3.IMqttDeliveryToken;
import org.eclipse.paho.client.mqttv3.MqttCallback;
import org.eclipse.paho.client.mqttv3.MqttMessage;

import java.io.BufferedWriter;
import java.io.IOException;
import java.io.OutputStreamWriter;
import java.net.Socket;

public class ReCallBack implements MqttCallback {
    public String strs = "";
    public String str = "";
    public ReCallBack() throws IOException {
        String host = "192.168.43.208";
        int port = 8889;
        Socket socket = new Socket(host,port);

        Thread th = new Thread(new Write(socket));
        th.start();

    }

    //TODO：这里是在往WIN上传前置机收到边缘服务器b/qid的东西
    public  class Write implements Runnable {
        private Socket socket;

        public Write(Socket socket) {
            this.socket = socket;
        }

        public Write() {
        }
        public void Witer() throws InterruptedException {
            try {
                OutputStreamWriter Wrte = new OutputStreamWriter(socket.getOutputStream());
                BufferedWriter bufferedWriter = new BufferedWriter(Wrte);

                while (true) {

                    if (!strs.equals(str)) {
                        System.out.println(strs+":"+str);
                        bufferedWriter.write("\n"+str+"\r\n");
                        bufferedWriter.flush();
                        strs = str;
                    }
                    if (socket.isClosed())
                        break;
                }
                bufferedWriter.close();
                Wrte.close();

            } catch (IOException e) {
                e.printStackTrace();
            }
        }

        public void run() {
            try {
                Witer();
            } catch (InterruptedException e) {
                e.printStackTrace();
            }
        }
    }
    public void connectionLost(Throwable throwable) {
        System.out.println("目前recive前置机断开");

    }

    public void messageArrived(String s, MqttMessage mqttMessage) throws Exception {
        String sss = new String(mqttMessage.getPayload());
        if(!sss.equals("close"))
        this.str = sss;
    }

    public void deliveryComplete(IMqttDeliveryToken iMqttDeliveryToken) {
        System.out.println("信息发送状态 ："+iMqttDeliveryToken.isComplete());
    }
}
