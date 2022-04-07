package Config;

import lombok.Data;

@Data
public class MqttConfigs {

    public String username = "admin";
    public String password = "public";
    public String hostUsl = "tcp://127.0.0.1:1883";
    public String clientId = "mqtt";
    public String deflutTopic = "regist";
    public int timeout = 10;
    public int keepalive = 20;

}
