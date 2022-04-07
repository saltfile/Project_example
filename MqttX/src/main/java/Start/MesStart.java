package Start;

import Service.IPsend.MqttIP;
import Service.Regist.mqttReist;

public class MesStart extends Thread{

    private void TaskStart() throws InterruptedException {
        Thread IP = new Thread(new MqttIP("192.168.43.208"));
        Thread Res = new Thread(new mqttReist());
        Res.start();
        Thread.sleep(10);
        IP.start();
    }




    @Override
    public synchronized void start() {
        try {
            TaskStart();
        } catch (InterruptedException e) {
            e.printStackTrace();
        }
    }
}
