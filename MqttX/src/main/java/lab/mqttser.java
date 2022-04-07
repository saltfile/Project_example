package lab;

import Config.MqttConfigs;
import com.google.gson.Gson;
import org.eclipse.paho.client.mqttv3.*;
import org.eclipse.paho.client.mqttv3.persist.MemoryPersistence;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.net.Socket;
import java.util.Scanner;

public class mqttser {
    static MqttConfigs config = new MqttConfigs();
    public static final String hostUrl = config.hostUsl;
    //
//    public static String hsot = ;
    public String topic1 = "aaa";
    public static String clientID = "C1";
    public int keelive = config.keepalive;
    public int timeout = config.timeout;
    public static MqttTopic topicw2;
    public static MqttClient client2;
    public  static MqttMessage message;

    public void connect2() throws MqttException {

        MqttConnectOptions options = new MqttConnectOptions();
        options.setCleanSession(false);
        options.setConnectionTimeout(timeout);
        options.setKeepAliveInterval(keelive);
        try {
            client2.setCallback(new SerCallBack());
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
        System.out.println("message is published compelete  "+token.isComplete());

    }
    public void send(String msg) throws MqttException {

        System.out.println("执行开始链接");
        message = new MqttMessage();
        message.setQos(1);
        message.setRetained(true);
        String str = msg;
        message.setPayload(str.getBytes());
        publish(topicw2, message);

    }

    public static void main(String[] args) throws MqttException {
        client2 = new MqttClient(hostUrl,clientID,new MemoryPersistence());
        mqttser mqttser = new mqttser();
        Scanner scanner = new Scanner(System.in);
        mqttser.connect2();
        while (true) {
            String str = scanner.nextLine();
            mqttser.send(str);
        }
    }
}
