package Service.Regist;

import Config.MqttConfigs;
import Service.Regist.CallBack.CilCallback;
import lab.CilCallBack;
import org.eclipse.paho.client.mqttv3.MqttClient;
import org.eclipse.paho.client.mqttv3.MqttConnectOptions;
import org.eclipse.paho.client.mqttv3.MqttException;
import org.eclipse.paho.client.mqttv3.MqttTopic;
import org.eclipse.paho.client.mqttv3.persist.MemoryPersistence;

import java.io.IOException;

public class mqttReist implements Runnable{
    static MqttConfigs sss = new MqttConfigs();
    public static final String host = sss.hostUsl;
    public String Defult ="b/regist";
    public String clientId  = "R1";
    public String username = sss.username;
    public  String password = sss.password;
    public int timeout = sss.timeout;
    public int keeplive = sss.keepalive;
    public MqttClient client;
    public MqttConnectOptions options;


    public  void contect() throws IOException {
        try{
            client = new MqttClient(host,clientId,new MemoryPersistence());
            options = new MqttConnectOptions();
            options.setCleanSession(false);
            options.setUserName(username);
            options.setPassword(password.toCharArray());
            options.setConnectionTimeout(timeout);
            options.setKeepAliveInterval(keeplive);
            options.setAutomaticReconnect(true);

            client.setCallback(new CilCallback());


            MqttTopic Deflect = client.getTopic(Defult);
            options.setWill(Deflect,"close".getBytes(),1,true);
            client.connect(options);
            //订阅消息
            int[] Qos = {1};
            //在这里添加订阅消息
            String[] topics = {Defult};
            client.subscribe(topics,Qos);

        }catch (MqttException e) {
            e.printStackTrace();
        }
    }


    public void run() {
        try {
            contect();



        } catch (IOException e) {
            e.printStackTrace();
        }
    }
}
