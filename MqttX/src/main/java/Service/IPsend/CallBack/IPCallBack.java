package Service.IPsend.CallBack;

import org.eclipse.paho.client.mqttv3.IMqttDeliveryToken;
import org.eclipse.paho.client.mqttv3.MqttCallback;
import org.eclipse.paho.client.mqttv3.MqttMessage;

public class IPCallBack implements MqttCallback {
    public void connectionLost(Throwable throwable) {
        System.out.println("IP前置机断开");
    }

    public void messageArrived(String s, MqttMessage mqttMessage) throws Exception {



    }

    public void deliveryComplete(IMqttDeliveryToken iMqttDeliveryToken) {
        System.out.println("IP交付完成---------> "+iMqttDeliveryToken.isComplete());
    }
}
