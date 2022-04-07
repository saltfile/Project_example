package lab;

import org.eclipse.paho.client.mqttv3.IMqttDeliveryToken;
import org.eclipse.paho.client.mqttv3.MqttCallback;
import org.eclipse.paho.client.mqttv3.MqttMessage;

public class SerCallBack implements MqttCallback {
    public void connectionLost(Throwable throwable) {
        System.out.println("zzzz");
    }

    public void messageArrived(String s, MqttMessage mqttMessage) throws Exception {

    }

    public void deliveryComplete(IMqttDeliveryToken iMqttDeliveryToken) {
        System.out.println("交付完成---------> "+iMqttDeliveryToken.isComplete());
    }
}
