package Service.SendSer.CallBack;

import org.eclipse.paho.client.mqttv3.IMqttDeliveryToken;
import org.eclipse.paho.client.mqttv3.MqttCallback;
import org.eclipse.paho.client.mqttv3.MqttMessage;

import java.io.BufferedWriter;
import java.io.IOException;
import java.io.OutputStreamWriter;
import java.net.Socket;



public class SeCallBack implements MqttCallback {

    public void connectionLost(Throwable throwable) {
        System.out.println("目前send前置机断开");

    }

    public void messageArrived(String s, MqttMessage mqttMessage) throws Exception {

    }

    public void deliveryComplete(IMqttDeliveryToken iMqttDeliveryToken) {
        System.out.println("信息发送状态 ："+iMqttDeliveryToken.isComplete());
    }
}
