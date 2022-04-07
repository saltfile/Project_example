import Service.IPsend.MqttIP;
import Service.Regist.mqttReist;
import Service.SendSer.MqttSend;
import Start.MesStart;
import org.eclipse.paho.client.mqttv3.MqttException;

import java.util.Scanner;

public class LabMain {
    public static void main(String[] args) throws MqttException {
//        MqttIP mqttIP = new MqttIP("192.168.43.208");
//        mqttReist reist = new mqttReist();
//        reist.run();
        //这里是开始的主要线程‘
        MesStart mes = new MesStart();
        mes.start();


    }

}
