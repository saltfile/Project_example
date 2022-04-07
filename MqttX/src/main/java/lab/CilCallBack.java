package lab;

import lombok.SneakyThrows;
import org.eclipse.paho.client.mqttv3.IMqttDeliveryToken;
import org.eclipse.paho.client.mqttv3.MqttCallback;
import org.eclipse.paho.client.mqttv3.MqttMessage;

import java.io.BufferedWriter;
import java.io.IOException;
import java.io.OutputStreamWriter;
import java.net.ServerSocket;
import java.net.Socket;

public class CilCallBack implements MqttCallback {
    String strs = "";
    String str ;


    public void connectionLost(Throwable throwable) {
        System.out.println("....");
    }

    public void messageArrived(String s, MqttMessage mqttMessage) throws Exception {

        System.out.println("消息主题是：" + s);
        System.out.println("接收到的消息Qos是:" + mqttMessage.getQos());
        System.out.println("内容: " + new String(mqttMessage.getPayload()));
    }

    public void deliveryComplete(IMqttDeliveryToken iMqttDeliveryToken) {
        System.out.println("交付完成---------> "+iMqttDeliveryToken.isComplete());
    }
}
