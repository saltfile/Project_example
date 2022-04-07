package Service.SendSer;

import Config.MqttConfigs;
import Service.SendSer.CallBack.SeCallBack;
import com.google.gson.Gson;
import lab.SerCallBack;
import lab.mqttser;
import org.eclipse.paho.client.mqttv3.*;
import org.eclipse.paho.client.mqttv3.persist.MemoryPersistence;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.net.Socket;
import java.util.Scanner;

public class MqttSend extends Thread{
    static MqttConfigs config = new MqttConfigs();
    public static final String hostUrl = config.hostUsl;
    //
//    public static String hsot = ;
    public String topic1 = "";
    public static String clientID = "S1";
    public int keelive = config.keepalive;
    public int timeout = config.timeout;
    public String username = config.username;
    public  String password = config.password;
    public static MqttTopic topicw2;
    public static MqttClient client2;
    public  static MqttMessage message;

    public MqttSend(String topic1){
        this.topic1 = topic1;
    }

    public void connect2() throws MqttException {
        client2 = new MqttClient(hostUrl,clientID,new MemoryPersistence());
        MqttConnectOptions options = new MqttConnectOptions();
        options.setCleanSession(false);
        options.setConnectionTimeout(timeout);
        options.setKeepAliveInterval(keelive);
        try {
            client2.setCallback(new SeCallBack());
            client2.connect(options);
            topicw2 = client2.getTopic(topic1);
        } catch (MqttSecurityException e) {
            e.printStackTrace();
        } catch (MqttException e) {
            e.printStackTrace();
        }
    }

    public static void publish(MqttTopic topic,MqttMessage message) throws MqttException {
        MqttDeliveryToken token = topic.publish(message);
        token.waitForCompletion();

    }
    public void send(String msg) throws MqttException {
        message = new MqttMessage();
        message.setQos(1);
        message.setRetained(true);
        String str = msg;
        message.setPayload(str.getBytes());
        publish(topicw2, message);

    }

    //TODO：这里是链接win上面的Socket读过来然后发送

    class Read implements Runnable {
        private Socket socket;

        public Read(Socket socket) {
            this.socket = socket;
        }
        public  void run() {
            try {
                InputStreamReader Rear = new InputStreamReader(socket.getInputStream());
                BufferedReader bufferedReader = new BufferedReader(Rear);
                String str = "";
                //send("aaa","192.168.1.123");
                System.out.println("开始接收消息");
                while ((str = bufferedReader.readLine()) != null) {
                    System.out.println(str);
                    send(str);
                }
                Rear.close();
                bufferedReader.close();
                socket.close();
            } catch (IOException e) {
                e.printStackTrace();
            } catch (MqttException e) {
                e.printStackTrace();
            }
//            catch (JsonSyntaxException e){
//                System.out.println("日志:目标机器输出错误类.异常过滤");
//            }
        }
    }
    //TODO:暂时不启动以后把win写完了在做测试
    public void ServerRun() throws IOException {
        int port = 8887;
        String host = "192.168.43.208";
        Socket socket = new Socket(host,port);
        //TODO:明天这里用线程试一下
        new Read(socket).run();
    }

    public void run() {
        try {

            connect2();
            ServerRun();

        } catch (MqttException e) {
            e.printStackTrace();
        } catch (IOException e) {
            e.printStackTrace();
        }

    }
}



