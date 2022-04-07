package Service.Regist.CallBack;

import Service.Reciveder.MqttRevic;
import Service.SendSer.MqttSend;
import org.eclipse.paho.client.mqttv3.IMqttDeliveryToken;
import org.eclipse.paho.client.mqttv3.MqttCallback;
import org.eclipse.paho.client.mqttv3.MqttMessage;

import java.util.ArrayList;
import java.util.HashMap;

public class CilCallback implements MqttCallback {

    private static HashMap ResMap = new HashMap();


    //TODO:这里两个Str开头的是用来拆取注册信息的函数
    public boolean StrQ(String s){
        char c = s.charAt(0);
        if(c=='q'){
            return true;
        }
        return false;
    }

    public String StrMsg(String s){
        String[] str = s.split("\\{");
        String[] str2 =str[1].split("}");
        String requst = str2[0];

        return requst;
    }




    public void connectionLost(Throwable throwable) {

    }

    public void messageArrived(String s, MqttMessage mqttMessage) throws Exception {
        String msg = new String(mqttMessage.getPayload());

        if(StrQ(msg)){

            String topic =  StrMsg(msg);

            if( ResMap.get(topic) == null) {
                MqttSend send = new MqttSend(topic);
                send.start();
                send.send(topic+"主题已开启");
                MqttRevic revic = new MqttRevic("b/"+topic);
                revic.start();
                ResMap.put(topic,topic);
                System.out.println(ResMap.get(topic));
            }else {
                System.out.println("错误：QID重复");
            }

        }else {
//            if(msg.equals(new String("close"))){
//            System.out.println("排除错误信息："+msg);
//            }
        }
    }

    public void deliveryComplete(IMqttDeliveryToken iMqttDeliveryToken) {

    }

}
